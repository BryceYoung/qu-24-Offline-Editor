#ifndef GUI
#define GUI
#include <gtkmm.h>
#include "QU24-Offline-Editor.h"
#include <iostream>
#include <fstream>


class GUIScene : public Gtk::ListBoxRow {
  public:
    GUIScene(qu_scene_t* scene , int sceneID);
    GUIScene(int sceneID);
    GUIScene();
    int getID() {return sceneID;}
    void setID(int i_ID){sceneID = i_ID;}
    void onDrag(const Glib::RefPtr<Gdk::DragContext>& context, Gtk::SelectionData& selection_data,guint info, guint time);
    void onDrop(const Glib::RefPtr<Gdk::DragContext>& context, int x, int y, const Gtk::SelectionData& selection_data, guint info, guint time);
    void beginDrag(const Glib::RefPtr<Gdk::DragContext>& context);
    void focus();
    void setScene(qu_scene_t* i_scene);
    qu_scene_t* getScene() {return scene;}
    void update(qu_scene_t* scene);
  private:
    qu_scene_t* scene;
    int sceneID;
    Gtk::Label sceneName;
    Gtk::Label sceneNumber;
    Gtk::Grid grid;
};


class Fader : public Gtk::Grid {
  public:
    Fader();
    virtual ~Fader();
    void updateFader(double);
    void setFader(double val){slider.set_value(val);}
    void MutePressed();
    void SelectPressed();
    void Deselect(){selected =  false; select.get_style_context()->add_class("select");select.get_style_context()->remove_class("selected");}
    void setIndex(int i){index = i;}
    int getIndex(){return index;}
    void setMuted(qu_scene_t::channel_entry_t::Mute mute_on_off){
      Muted = mute_on_off;
      mute.get_style_context()->remove_class("Muted");
      mute.get_style_context()->remove_class("Unmuted");
      if(Muted == qu_scene_t::channel_entry_t::Muted) mute.get_style_context()->add_class("Muted"); 
      else mute.get_style_context()->add_class("Unmuted"); 
      }
    qu_scene_t::channel_entry_t::Mute getMuted(){return Muted;}
    void setChannel(qu_scene_t::channel_entry_t*);
    qu_scene_t::channel_entry_t* getChannel(){return channel;}
    void update();
  protected:
    int index;
    qu_scene_t::channel_entry_t::Mute Muted = qu_scene_t::channel_entry_t::UnMuted;
    qu_scene_t::channel_entry_t* channel;
    Gtk::VScale slider;
    Gtk::Button mute;
    Gtk::Button select;
    bool selected = false;
};

class MyWindow : public Gtk::Window{
  public:
    MyWindow(Show*);
    void LoadGUIScene(qu_scene_t* scene); // Loads a scene into the GUI
    void SaveGUIScene();
    void nextSceneButton();
    void prevSceneButton();
    void GoSceneButton();
    void UpdateSceneButton();
    void MoveSceneUpButton();
    void MoveSceneDownButton();
    qu_scene_t* getCurrentScene(){return current_scene;}
    void DeselectFaders(int);
  protected:
    Show* WindowShow;
    // Put all elements and components in here
    qu_scene_t* current_scene;
    Fader* faders;
    Fader mainFader;
    int numFaders = 24;
    Gtk::Box Faderbox;
    Gtk::Box vBox;
    Gtk::Separator topMargin;
    Gtk::VSeparator inputSeperator;
    Gtk::ScrolledWindow scroll_window;
    Gtk::ListBox list;
    GUIScene* GUIscenes;
    int numScenes;
    Gtk::Button nextScene;
    Gtk::Button prevScene;
    Gtk::Button GoScene;
    Gtk::Button UpdateScene;
    Gtk::Grid sceneGrid;
    Gtk::Entry sceneNameEntry;
    Gtk::Button MoveSceneUp;
    Gtk::Button MoveSceneDown;
};

qu_scene_t* Copy(qu_scene_t* scene){
  if(scene == NULL) return NULL;
  scene->Write("temp.scene");
  return LoadScene("temp.scene");
}

#endif