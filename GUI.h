#ifndef GUI
#define GUI
#include <gtkmm.h>
#include "QU24-Offline-Editor.h"

class Fader : public Gtk::Grid {
  public:
    Fader();
    virtual ~Fader();
    Gtk::VScale slider;
    Gtk::Button mute;
    void updateFader(double);
    void setFader(double val){slider.set_value(val);}
    void MutePressed();
    void setIndex(int i){index = i;}
    int getIndex(){return index;}
    void setMuted(qu_scene_t::channel_entry_t::Mute mute_on_off){
      Muted = mute_on_off;
      if(Muted == qu_scene_t::channel_entry_t::Muted) mute.get_style_context()->add_class("Muted"); 
      else mute.get_style_context()->add_class("Unmuted"); 
      }
    qu_scene_t::channel_entry_t::Mute getMuted(){return Muted;}
    void setChannel(qu_scene_t::channel_entry_t* chan){channel = chan;}
    qu_scene_t::channel_entry_t* getChannel(){return channel;}
  protected:
    int index;
    qu_scene_t::channel_entry_t::Mute Muted = qu_scene_t::channel_entry_t::UnMuted;
    qu_scene_t::channel_entry_t* channel;
};

class MyWindow : public Gtk::Window{
  public:
    MyWindow(qu_scene_t*);
  protected:
    // Put all elements and components in here
    Fader* faders;
    int numFaders = 24;
    Gtk::Box Faderbox;
    Gtk::Box vBox;
    Gtk::Separator topMargin;
    
};
#endif