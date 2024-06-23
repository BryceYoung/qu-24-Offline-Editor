#ifndef FADER_H
#define FADER_H

#include "QU24-Offline-Editor.h"
#include <gtkmm.h>

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
    Gtk::Scale slider;
    Gtk::Button select;
    bool selected = false;
    Gtk::Widget* widget;
};

class MainFader: public Fader{
  public:
    MainFader();
    void setChannel(qu_scene_t::channel_entry_t*);
  protected:
    Gtk::Button m1;
    Gtk::Button m2;
    Gtk::Button m3;
    Gtk::Button m4;
    Gtk::Button m56;
    Gtk::Button m78;
    Gtk::Button m910;
};


#endif
