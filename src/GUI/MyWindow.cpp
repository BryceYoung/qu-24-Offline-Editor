#include "MyWindow.h"

MyWindow::MyWindow(Show* show):
  Faderbox(Gtk::ORIENTATION_HORIZONTAL,10), 
  mainFader(),
  list(), 
  vBox(Gtk::ORIENTATION_VERTICAL,50), 
  topMargin(),
  inputSeperator(),
  scroll_window(), 
  sceneGrid(),
  sceneNameEntry(),
  nextScene("NEXT SCENE"), 
  prevScene("PREV SCENE"), 
  GoScene("GO"), 
  UpdateScene("Update"), 
  MoveSceneUp("Move Up"),
  MoveSceneDown("Move Down")
{
  WindowShow = show;
  std::vector<Gtk::TargetEntry> entries;
  //entries.push_back(Gtk::TargetEntry("GUIScene",Gtk::TargetFlags::TARGET_SAME_APP));
  //entries.push_back(Gtk::TargetEntry("test/plain"));
  current_scene = Copy(show->current);
  auto css = Gtk::CssProvider::create();
  css->load_from_path("./src/GUI.css");
  get_style_context()->add_provider_for_screen(Gdk::Screen::get_default(), css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  mainFader.setChannel(current_scene->lr());
  faders = new Fader[numFaders];
  for(int i = 0;i<numFaders;i++){
    faders[i].setIndex(i);
    faders[i].setChannel(current_scene->inputs()->at(i));    
    Faderbox.add(faders[i]);
  }
  Faderbox.add(inputSeperator);
  Faderbox.add(mainFader);
  Faderbox.set_valign(Gtk::Align::ALIGN_CENTER);
  Faderbox.set_halign(Gtk::Align::ALIGN_CENTER);
  scroll_window.set_valign(Gtk::Align::ALIGN_CENTER);
  scroll_window.set_halign(Gtk::Align::ALIGN_CENTER);
  scroll_window.set_size_request(100,200);
  scroll_window.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
  scroll_window.add(list);
  scroll_window.get_style_context()->add_class("bordered");
  sceneNameEntry.set_text(current_scene->header()->getName());
  sceneNameEntry.set_max_length(13);
  GUIscenes = new GUIScene[100];
  for(int i = 0;i<100;i++){
    numScenes++;
    GUIscenes[i].setID(i+1);
    //std::cout << GUIscenes[i].getID() << ": ID" << std::endl;
    /*GUIscenes[i].drag_source_set(entries,Gdk::ModifierType::MODIFIER_MASK,Gdk::ACTION_MOVE);
    GUIscenes[i].drag_dest_set(entries,Gtk::DestDefaults::DEST_DEFAULT_HIGHLIGHT,Gdk::DragAction::ACTION_MOVE);
    GUIscenes[i].signal_drag_data_get().connect(sigc::mem_fun(GUIscenes[i],&GUIScene::onDrag));
    GUIscenes[i].signal_drag_data_received().connect(sigc::mem_fun(GUIscenes[i],&GUIScene::onDrop));
    GUIscenes[i].signal_drag_begin().connect(sigc::mem_fun(GUIscenes[i],&GUIScene::beginDrag));*/
    GUIscenes[i].signal_grab_focus().connect(sigc::mem_fun(GUIscenes[i],&GUIScene::focus));
    list.append(GUIscenes[i]);
  }
  for(const auto &item : show->scenes){
    GUIscenes[item.first].setScene(item.second);
  }
  prevScene.signal_clicked().connect(sigc::mem_fun(*this,&MyWindow::prevSceneButton));
  nextScene.signal_clicked().connect(sigc::mem_fun(*this,&MyWindow::nextSceneButton));
  GoScene.signal_clicked().connect(sigc::mem_fun(*this,&MyWindow::GoSceneButton));
  UpdateScene.signal_clicked().connect(sigc::mem_fun(*this,&MyWindow::UpdateSceneButton));
  MoveSceneDown.signal_clicked().connect(sigc::mem_fun(*this,&MyWindow::MoveSceneDownButton));
  MoveSceneUp.signal_clicked().connect(sigc::mem_fun(*this,&MyWindow::MoveSceneUpButton));
  sceneGrid.attach(scroll_window,0,0,4,6);
  sceneGrid.attach_next_to(sceneNameEntry,scroll_window,Gtk::PositionType::POS_RIGHT,2,1);
  sceneGrid.attach_next_to(prevScene,sceneNameEntry,Gtk::PositionType::POS_BOTTOM,1,1);
  sceneGrid.attach_next_to(nextScene,prevScene,Gtk::PositionType::POS_RIGHT,1,1);
  sceneGrid.attach_next_to(GoScene,prevScene,Gtk::PositionType::POS_BOTTOM,1,1);
  sceneGrid.attach_next_to(UpdateScene,GoScene,Gtk::PositionType::POS_RIGHT,1,1);
  sceneGrid.attach_next_to(MoveSceneDown,GoScene,Gtk::PositionType::POS_BOTTOM,1,1);
  sceneGrid.attach_next_to(MoveSceneUp,MoveSceneDown,Gtk::PositionType::POS_RIGHT,1,1);
  sceneGrid.set_halign(Gtk::Align::ALIGN_CENTER);
  vBox.add(sceneGrid);
  vBox.add(Faderbox);
  add(vBox);
  set_title("QU-24 Offline Editor: " + show->show->getName());
  set_default_size(100,50);
  show_all_children();
}

void MyWindow::LoadGUIScene(qu_scene_t* scene){
  if(scene==NULL) return;
  if(current_scene!=NULL && current_scene !=scene){
    current_scene = scene;
  }
  sceneNameEntry.set_text(scene->header()->getName());
  for(int i = 0;i<numFaders;i++){
    faders[i].setChannel(scene->inputs()->at(i));
  }
  mainFader.setChannel(scene->lr());
}

void MyWindow::SaveGUIScene(){
  current_scene->header()->setName(sceneNameEntry.get_text());
  for(int i = 0;i<numFaders;i++){
    faders[i].update();
  }
  mainFader.update();
}

void MyWindow::nextSceneButton(){
  if(SceneFocused >= 99) return;
  GUIscenes[SceneFocused+1].activate();
}

void MyWindow::prevSceneButton(){
  if(SceneFocused <= 0) return;
  GUIscenes[SceneFocused-1].activate();
}

void MyWindow::GoSceneButton(){
  std::cout << SceneFocused << std::endl;
  LoadGUIScene(Copy(GUIscenes[SceneFocused].getScene()));
}

void MyWindow::UpdateSceneButton(){
  SaveGUIScene();
  delete WindowShow->scenes[SceneFocused];
  WindowShow->scenes[SceneFocused] = current_scene;
  GUIscenes[SceneFocused].setScene(current_scene);
}

void MyWindow::MoveSceneUpButton(){
  if(SceneFocused <=0) return;
  qu_scene_t* temp = WindowShow->scenes[SceneFocused];
  WindowShow->scenes[SceneFocused] = WindowShow->scenes[SceneFocused-1];
  GUIscenes[SceneFocused].setScene(WindowShow->scenes[SceneFocused-1]);
  WindowShow->scenes[SceneFocused-1] = temp;
  GUIscenes[SceneFocused-1].setScene(temp);
  GUIscenes[SceneFocused-1].activate();
}

void MyWindow::MoveSceneDownButton(){
  if(SceneFocused >= 100) return;
  qu_scene_t* temp = WindowShow->scenes[SceneFocused];
  WindowShow->scenes[SceneFocused] = WindowShow->scenes[SceneFocused+1];
  GUIscenes[SceneFocused].setScene(WindowShow->scenes[SceneFocused+1]);
  WindowShow->scenes[SceneFocused+1] = temp;
  GUIscenes[SceneFocused+1].setScene(temp);
  GUIscenes[SceneFocused+1].activate();
}

void MyWindow::DeselectFaders(int dontSelect){
  for(int i = 0;i<numFaders;i++){
    if(i==dontSelect) continue;
    faders[i].Deselect();
  }
  mainFader.Deselect();
}