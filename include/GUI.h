#ifndef GUI
#define GUI
#include <gtkmm.h>
#include "QU24-Offline-Editor.h"
#include <iostream>
#include <fstream>

class Fader : public Gtk::Grid {
  public:
    Fader();
    virtual ~Fader();
    qu_scene_t::channel_entry_t::Mute getMuted(){return Muted;}
    qu_scene_t::channel_entry_t* getChannel(){return channel;}
    int getIndex(){return index;}
    void setFader(double val){slider.set_value(val);}
    void setIndex(int i){index = i;}
    void setMuted(qu_scene_t::channel_entry_t::Mute mute_on_off);
    void setChannel(qu_scene_t::channel_entry_t*);
    void update();
    void updateFader(double);
    void MutePressed();
    void SelectPressed();
    void Deselect();
  protected:
    int index;
    qu_scene_t::channel_entry_t* channel;
    qu_scene_t::channel_entry_t::Mute Muted = qu_scene_t::channel_entry_t::UnMuted;
    Gtk::Button mute;
    Gtk::VScale slider;
    Gtk::Button select;
    bool selected = false;
};

class GUIScene : public Gtk::ListBoxRow {
  public:
    GUIScene(qu_scene_t* scene , int sceneID);
    GUIScene(int sceneID) : GUIScene(NULL,sceneID){}
    GUIScene() : GUIScene(0){}
    ~GUIScene();
    int getID() {return sceneID;}
    qu_scene_t* getScene() {return scene;}
    void setID(int i_ID){sceneID = i_ID;}
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

class MyWindow : public Gtk::Window{
  public:
    MyWindow(Show*);
    qu_scene_t* getCurrentScene(){return current_scene;}
    void LoadGUIScene(qu_scene_t* scene); // Loads a scene into the GUI
    void SaveGUIScene();
    void nextSceneButton();
    void prevSceneButton();
    void GoSceneButton();
    void UpdateSceneButton();
    void MoveSceneUpButton();
    void MoveSceneDownButton();
    void DeselectFaders(int);
  protected:
    Show* WindowShow;
    qu_scene_t* current_scene;
    Gtk::Box Faderbox;
    int numFaders = 24;
    Fader* faders;
    Fader mainFader;
    Gtk::ListBox list;
    int numScenes;
    GUIScene* GUIscenes;
    Gtk::Box vBox;
    Gtk::Separator topMargin;
    Gtk::VSeparator inputSeperator;
    Gtk::ScrolledWindow scroll_window;
    Gtk::Grid sceneGrid;
    Gtk::Entry sceneNameEntry;
    Gtk::Button nextScene;
    Gtk::Button prevScene;
    Gtk::Button GoScene;
    Gtk::Button UpdateScene;
    Gtk::Button MoveSceneUp;
    Gtk::Button MoveSceneDown;
};

qu_scene_t* Copy(qu_scene_t* scene){
  if(scene == NULL) return NULL;
  scene->Write("temp.scene");
  return LoadScene("temp.scene");
}

#endif