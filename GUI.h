#include <gtkmm.h>

class Fader : public Gtk::Widget{
  public:
    Fader();
    virtual ~Fader();

    void set_child_widgets(Gtk::Widget& i_slider, Gtk::Widget& i_mute);
  protected:
    Gtk::SizeRequestMode get_request_mode_vfunc() const override;
    void measure_vfunc(Gtk::Orientation orientation, int for_size, int& minimum, int& natural, int& minimum_baseline, int& natural_baseline) const override;    
    void size_allocate_vfunc(int width, int height, int baseline) override;
#if 0
  void forall_vfunc(const ForeachSlot& slot) override;

  void on_add(Gtk::Widget* child) override;
  void on_remove(Gtk::Widget* child) override;
  GType child_type_vfunc() const override;
#endif
  Gtk::Widget* slider;
  Gtk::Widget* mute;
};

class MyWindow : public Gtk::Window{
  public:
    MyWindow();
  protected:
    // Put all elements and components in here
    Gtk::VScale slider;
    Fader fader;
    
};