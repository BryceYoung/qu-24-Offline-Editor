#ifndef GUISCENE_H
#define GUISCENE_H

#include "GUI.h"

class GUIScene : public Gtk::ListBoxRow {
  public:
    GUIScene(qu_scene_t* scene , int sceneID);
    GUIScene(int sceneID) : GUIScene(NULL,sceneID){}
    GUIScene() : GUIScene(0){}
    ~GUIScene();
    int getID() {return sceneID;}
    qu_scene_t* getScene() {return scene;}
    void setID(int i_ID){sceneID = i_ID;sceneNumber.set_text(std::to_string(sceneID));std::cout << sceneID << std::endl;}
    void setScene(qu_scene_t* i_scene);
    void update(qu_scene_t* scene);
    void focus();
    void beginDrag(const Glib::RefPtr<Gdk::DragContext>& context);
    void onDrag(const Glib::RefPtr<Gdk::DragContext>& context, Gtk::SelectionData& selection_data,guint info, guint time);
    void onDrop(const Glib::RefPtr<Gdk::DragContext>& context, int x, int y, const Gtk::SelectionData& selection_data, guint info, guint time);
  private:
    int sceneID;
    qu_scene_t* scene;
    Gtk::Label sceneName;
    Gtk::Label sceneNumber;
    Gtk::Grid grid;
};

#endif