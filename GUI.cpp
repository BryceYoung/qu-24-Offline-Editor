#include "GUI.h"

//g++ myfirstprogram.cpp -o myfirstprogram `pkg-config gtkmm-2.4 --cflags --libs

Fader::Fader():
  slider(nullptr), mute(nullptr){}

Fader::~Fader(){
  if(slider){
    slider->unparent();
  }
  if(mute){
    slider->unparent();
  }
}

void Fader::set_child_widgets(Gtk::Widget& i_slider, Gtk::Widget& i_mute){
  slider = &i_slider;
  mute = &i_mute;
  slider->set_parent(*this);
  mute->set_parent(*this);
}

Gtk::SizeRequestMode Fader::get_request_mode_vfunc() const{
  return Gtk::SizeRequestMode::SIZE_REQUEST_HEIGHT_FOR_WIDTH;
}

void Fader::measure_vfunc(Gtk::Orientation orientation, int for_size, int& minimum, int& natural, int& minimum_baseline, int& natural_baseline) const{
  minimum_baseline = -1;
  natural_baseline = -1;

  int dummy_minimum_baseline = 0;
  int dummy_natural_baseline = 0;
  if(orientation == Gtk::Orientation::ORIENTATION_HORIZONTAL){
    int height_per_child = for_size;

    if(for_size >=0){
      int nvis_children = 0;
      if(slider && slider->get_visible()){
        nvis_children++;
      }
      if(mute && mute->get_visible()){
        nvis_children++;
      }

      if(nvis_children > 0){
        height_per_child = for_size/nvis_children;
      }
    }
    int child_minimum_width[2] = {0,0};
    int child_natural_width[2] = {0,0};

    if(slider && slider->get_visible()){
      slider.get
      slider->measure(orientation, height_per_child, child_minimum_width[1],child_natural_width[1],dummy_minimum_baseline,dummy_natural_baseline);
    }

    if(mute && mute->get_visible()){
      mute->measure(orientation, height_per_child, child_minimum_width[0],child_natural_width[0],dummy_minimum_baseline,dummy_natural_baseline);
    }

    minimum = std::max(child_minimum_width[0],child_minimum_width[1]);
    natural = std::max(child_natural_width[0],child_natural_width[1]);
  }
  else{ // Gtk::Orientation::Vertical
    int child_minimum_height[2] = {0,0};
    int child_natural_height[2] = {0,0};
    int nvis_children = 0;
    if(slider && slider->get_visible()){
      nvis_children++;
      slider->measure(orientation, for_size, child_minimum_height[0],child_natural_height[0],dummy_minimum_baseline,dummy_natural_baseline);
    }

    if(mute && mute->get_visible()){
      nvis_children++;
      mute->measure(orientation, for_size, child_minimum_height[1],child_natural_height[1],dummy_minimum_baseline,dummy_natural_baseline);
    }

    minimum = nvis_children * std::max(child_minimum_height[0],child_minimum_height[1]);
    natural = nvis_children * std::max(child_natural_height[0],child_natural_height[1]);
  }
}

void Fader::size_allocate_vfunc(int width, int height, int baseline){
  const bool visible_slider = slider && slider->get_visible();
  const bool visible_mute = mute && mute->get_visible();
  int nvis_children = 0;
  if(visible_slider) nvis_children++;
  if(visible_mute) nvis_children++;
  if(nvis_children <=0) return;

  Gtk::Allocation slider_allocation;
  Gtk::Allocation mute_allocation;
  slider_allocation.set_x(0);
  slider_allocation.set_y(0);

  slider_allocation.set_width(width);
  if(visible_slider){
    slider_allocation.set_height(height/nvis_children);
    slider->size_allocate(slider_allocation,baseline);
  }else{
    slider_allocation.set_height(0);
  }
  mute_allocation.set_x(0);
  mute_allocation.set_y(slider_allocation.get_height());
  mute_allocation.set_width(width);
  mute_allocation.set_height(height-slider_allocation.get_height());

  if(visible_mute){
    mute->size_allocate(mute_allocation,baseline);
  }

}
#if 0
void Fader::forall_vfunc(const ForeachSlot& slot){
  if(slider) slot(*slider);
  if(mute) slot(*mute);
}

void Fader::on_add(Gtk::Widget* child){
  if(!slider){
    slider = child;
    slider->set_parent(*this);
  }else if(!mute){
    mute = child;
    mute->set_parent(*this);
  }
}

void Fader::on_remove(Gtk::Widget* child){
  if(child){
    const bool visible = child->get_visible();
    bool found = false;
    if(slider==child){
      slider = nullptr;
      found = true
    }else if(mute==child){
      mute = nullptr;
      found = true;
    }
    if(found){
      child->unparent();
      if(visible){
        queue_resize();
      }
    }
  }
}

GType Fader::child_type_vfunc() const{
  if(!slider || !mute) return Gtk::Widget::get_type();
  else return G_TYPE_NONE;
}
#endif
MyWindow::MyWindow():
  slider()
{
  slider.set_range(-100,10);
  slider.set_draw_value(false);
  slider.set_inverted(true);
  add(slider);
  set_title("QU-24 Offline Editor");
  set_default_size(1200,600);
  show_all_children();
}

int main(int argc, char* argv[]){
  auto app = Gtk::Application::create("org.gtkmm.examples.base");
  MyWindow window;

  return app->run(window,argc,argv);
}