#ifndef MYWINDOW_H
#define MYWINDOW_H

#include "GUI.h"

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
    MainFader mainFader;
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

#endif