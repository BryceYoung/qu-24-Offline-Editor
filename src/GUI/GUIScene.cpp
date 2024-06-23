#include "GUIScene.h"
#include "Global.h"

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
  grid.attach_next_to(sceneName,Gtk::PositionType::RIGHT,3,1);
  grid.get_style_context()->add_class("bordered");
  set_child(grid);
  
  set_size_request(50,50);
}

GUIScene::~GUIScene(){
  delete scene;
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

void GUIScene::focus(){
  SceneFocused = getID()-1;
  std::cout << "FOCUSED" << SceneFocused << std::endl;
}
/*
void GUIScene::beginDrag(const Glib::RefPtr<Gdk::DragContext>& context){
  //std::cout << "DRAG BEGIN" << std::endl;
}

void GUIScene::onDrag(const Glib::RefPtr<Gdk::DragContext>&,
        Gtk::SelectionData& selection_data, guint, guint){
          selection_data.set(selection_data.get_target(),8// 8 bits format//,(const guchar*)"I'm Data!",9// the length of I'm Data! in bytes);
          //std::cout << "DRAG" << std::endl;
        }

void GUIScene::onDrop(const Glib::RefPtr<Gdk::DragContext>& context, int, int,
        const Gtk::SelectionData& selection_data, guint, guint time){
  const int length = selection_data.get_length();
  if((length>=0) && (selection_data.get_format() == 8)){
    std::cout << "Recieved: " << selection_data.get_data_as_string() << std::endl;
  }
  context->drag_finish(false,false,time);
}*/
