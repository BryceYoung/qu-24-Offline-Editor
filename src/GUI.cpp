#include "../include/GUI.h"

//g++ myfirstprogram.cpp -o myfirstprogram `pkg-config gtkmm-3.0 --cflags --libs

int SceneFocused = 0;
static MyWindow* window;

void MyWindow::nextSceneButton(){
  if(SceneFocused >= 99) return;
  GUIscenes[SceneFocused+1].activate();
}
void MyWindow::prevSceneButton(){
  if(SceneFocused <= 0) return;
  GUIscenes[SceneFocused-1].activate();
}
void MyWindow::GoSceneButton(){
  LoadGUIScene(Copy(GUIscenes[SceneFocused].getScene()));
}
void MyWindow::UpdateSceneButton(){
  SaveGUIScene();
  delete WindowShow->scenes[SceneFocused];
  WindowShow->scenes[SceneFocused] = current_scene;
  GUIscenes[SceneFocused].setScene(current_scene);
}

void MyWindow::MoveSceneDownButton(){
  if(SceneFocused >= 100) return;
  qu_scene_t* temp = WindowShow->scenes[SceneFocused];
  WindowShow->scenes[SceneFocused] = WindowShow->scenes[SceneFocused+1];
  GUIscenes[SceneFocused].setScene(WindowShow->scenes[SceneFocused+1]);
  WindowShow->scenes[SceneFocused+1] = temp;
  GUIscenes[SceneFocused+1].setScene(temp);
  GUIscenes[SceneFocused+1].activate();
  std::cout << SceneFocused << std::endl;
}

void MyWindow::MoveSceneUpButton(){
  if(SceneFocused <=0) return;
  qu_scene_t* temp = WindowShow->scenes[SceneFocused];
  WindowShow->scenes[SceneFocused] = WindowShow->scenes[SceneFocused-1];
  GUIscenes[SceneFocused].setScene(WindowShow->scenes[SceneFocused-1]);
  WindowShow->scenes[SceneFocused-1] = temp;
  GUIscenes[SceneFocused-1].setScene(temp);
  GUIscenes[SceneFocused-1].activate();
  std::cout << SceneFocused << std::endl;
}

void MyWindow::DeselectFaders(int dontSelect){
  for(int i = 0;i<numFaders;i++){
    if(i==dontSelect) continue;
    faders[i].Deselect();
  }
}

void GUIScene::setScene(qu_scene_t* i_scene) {
  if(i_scene==NULL) {
    scene = i_scene;
    sceneName.set_text("");
    return;
  }; 
  scene=i_scene;
  sceneName.set_text(scene->header()->getName());
}

void GUIScene::update(qu_scene_t* i_scene){
  if(i_scene==NULL) return;
  if(scene !=NULL) delete[] scene;
  scene = i_scene;
  sceneName.set_text(scene->header()->getName());
}

void GUIScene::onDrag(const Glib::RefPtr<Gdk::DragContext>&,
        Gtk::SelectionData& selection_data, guint, guint){
          selection_data.set(selection_data.get_target(),8/* 8 bits format*/,(const guchar*)"I'm Data!",9/* the length of I'm Data! in bytes*/);
          std::cout << "DRAG" << std::endl;
        }
void GUIScene::onDrop(const Glib::RefPtr<Gdk::DragContext>& context, int, int,
        const Gtk::SelectionData& selection_data, guint, guint time){
  const int length = selection_data.get_length();
  if((length>=0) && (selection_data.get_format() == 8)){
    std::cout << "Recieved: " << selection_data.get_data_as_string() << std::endl;
  }
  context->drag_finish(false,false,time);

}

void GUIScene::beginDrag(const Glib::RefPtr<Gdk::DragContext>& context){
  std::cout << "DRAG BEGIN" << std::endl;
}
    

void GUIScene::focus(){
  SceneFocused = getID()-1;
  std::cout << SceneFocused << std::endl;
}

GUIScene::GUIScene(qu_scene_t* i_scene, int id): sceneName(),sceneNumber(), grid(){ 
  //Gtk::EventBox handle();
  //handle.add()
  scene = i_scene;
  sceneID = id;
  sceneNumber.set_text(std::to_string(id));
  if(i_scene != NULL){
    sceneName.set_text(scene->header()->getName());
  }else{
    sceneName.set_text("");
  }
  grid.attach(sceneNumber,1,1);
  grid.set_column_homogeneous(true);
  grid.insert_column(1);
  grid.attach_next_to(sceneName,Gtk::PositionType::POS_RIGHT,3,1);
  grid.get_style_context()->add_class("bordered");
  add(grid);
  
  set_size_request(50,50);
}

GUIScene::GUIScene(int id) : GUIScene(NULL,id){}

GUIScene::GUIScene() : GUIScene(0){}

Fader::Fader():
  slider(), mute(), select(){
  select.get_style_context()->add_class("select");
  slider.set_range(-100,10);
  slider.set_draw_value(false);
  slider.set_inverted(true);
  mute.signal_pressed().connect(sigc::mem_fun(*this,&Fader::MutePressed));
  slider.signal_adjust_bounds().connect((sigc::mem_fun(*this,&Fader::updateFader)));
  select.signal_pressed().connect(sigc::mem_fun(*this,&Fader::SelectPressed));
  set_row_spacing(10);
  std::cout << "space:" << get_row_spacing() << std::endl;
  set_size_request(30,50);
  attach(mute,2,2);
  set_row_homogeneous(true);
  attach_next_to(select,mute,Gtk::PositionType::POS_TOP,1,1);
  attach_next_to(slider,mute,Gtk::PositionType::POS_BOTTOM,1,6);
  }

void Fader::updateFader(double value){
  if(value < -100) value = -100;
  std::cout << index << " ";
  std::cout << value << std::endl;
}

void Fader::MutePressed(){
  std::cout << SceneFocused << std::endl;
  if(Muted == qu_scene_t::channel_entry_t::UnMuted){
   mute.get_style_context()->add_class("Muted"); 
   mute.get_style_context()->remove_class("Unmuted");
   Muted = qu_scene_t::channel_entry_t::Muted;
  }else{
    mute.get_style_context()->remove_class("Muted");
    mute.get_style_context()->add_class("Unmuted");
    Muted = qu_scene_t::channel_entry_t::UnMuted;
  }
  getChannel()->setMute(Muted);
  std::cout << index << " Pressed" << ": " << Muted << std::endl;
}

void Fader::update(){
  channel->setMute(Muted);
  channel->setFader((slider.get_value() + 100) / 110 * 32000);
}

void Fader::SelectPressed(){
  window->DeselectFaders(index);
  selected = true;
  select.get_style_context()->remove_class("select");
  select.get_style_context()->add_class("selected");
}

Fader::~Fader(){
    slider.unparent();
    mute.unparent();
    select.unparent();
}

MyWindow::MyWindow(Show* show): 
  Faderbox(Gtk::ORIENTATION_HORIZONTAL,10), 
  vBox(Gtk::ORIENTATION_VERTICAL,50), 
  topMargin(), 
  scroll_window(), 
  list(), 
  nextScene("NEXT SCENE"), 
  prevScene("PREV SCENE"), 
  GoScene("GO"), 
  UpdateScene("Update"), 
  sceneGrid(),
  sceneNameEntry(),
  MoveSceneUp("Move Up"),
  MoveSceneDown("Move Down")
{
  WindowShow = show;
  std::vector<Gtk::TargetEntry> entries;
  entries.push_back(Gtk::TargetEntry("GUIScene",Gtk::TargetFlags::TARGET_SAME_APP));
  //entries.push_back(Gtk::TargetEntry("test/plain"));
  current_scene = Copy(show->current);
  auto css = Gtk::CssProvider::create();
  css->load_from_path("./src/GUI.css");
  get_style_context()->add_provider_for_screen(Gdk::Screen::get_default(), css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  faders = new Fader[numFaders];
  for(int i = 0;i<numFaders;i++){
    faders[i].setIndex(i);
    faders[i].setChannel(current_scene->inputs()->at(i));
    faders[i].setMuted(faders[i].getChannel()->getMute());
    faders[i].setFader(((faders[i].getChannel()->getFader() / 32000.0) * 110)-100);
    
    Faderbox.add(faders[i]);
  }
  Faderbox.set_valign(Gtk::Align::ALIGN_FILL);
  Faderbox.set_halign(Gtk::Align::ALIGN_CENTER);
  scroll_window.set_valign(Gtk::Align::ALIGN_FILL);
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
    GUIscenes[i] = GUIScene(i+1);
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
    //delete current_scene;
    current_scene = scene;
  }
  sceneNameEntry.set_text(scene->header()->getName());
  std::cout << (int)scene->header()->id();
  for(int i = 0;i<numFaders;i++){
    faders[i].setChannel(scene->inputs()->at(i));
    faders[i].setMuted(faders[i].getChannel()->getMute());
    faders[i].setFader(((faders[i].getChannel()->getFader() / 32000.0) * 110)-100);
  }
  
}
void MyWindow::SaveGUIScene(){
  current_scene->header()->setName(sceneNameEntry.get_text());
  for(int i = 0;i<numFaders;i++){
    faders[i].update();
  }
}

int main(int argc,char* argv[]){
  struct Show* show = LoadShow("AHQU/SHOWS/SHOW0008");
  auto app = Gtk::Application::create("org.gtkmm.examples.base");
  window = new MyWindow(show);
  PrintScene(LoadScene("Scenes/NVDATA.DAT"));
  /*for(const auto &myPar : show->scenes){
    //std::cout << myPar.first << ": " << (int)myPar.second->inputs()->at(6)->getMute() << std::endl;
  }*/
  window->SaveGUIScene();
  show->scenes[98] = Copy(window->getCurrentScene());
  SaveShow(show,"Temp");
  return app->run(*window,argc,argv);
}