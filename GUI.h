#include <gtkmm.h>

class Fader : public Gtk::Grid {
  public:
    Fader();
    virtual ~Fader();
    Gtk::VScale slider;
    Gtk::Button mute;
    bool Muted;
    void updateFader(double);
    void MutePressed();
    int index;
};

class MyWindow : public Gtk::Window{
  public:
    MyWindow();
  protected:
    // Put all elements and components in here
    Fader* faders;
    int numFaders = 24;
    Gtk::Box Faderbox;
    Gtk::Box vBox;
    Gtk::Separator topMargin;
    
};