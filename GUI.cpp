#include "GUI.h"
#include <iostream>

//g++ myfirstprogram.cpp -o myfirstprogram `pkg-config gtkmm-2.4 --cflags --libs


Fader::Fader():
  slider(), mute(){
  slider.set_range(-100,10);
  slider.set_draw_value(false);
  slider.set_inverted(true);
  set_size_request(50,200);
  attach(mute,2,2);
  set_row_homogeneous(true);
  attach_next_to(slider,mute,Gtk::PositionType::POS_BOTTOM,1,8);
  }

void Fader::updateFader(double value){
  if(value < -100) value = -100;
  std::cout << index;
  std::cout << value << std::endl;
}

void Fader::MutePressed(){
  Muted = !Muted;
  if(Muted){
   mute.get_style_context()->add_class("Muted"); 
   mute.get_style_context()->remove_class("Unmuted");
  }else{
    mute.get_style_context()->remove_class("Muted");
    mute.get_style_context()->add_class("Unmuted");
  }
  std::cout << index << " Pressed" << std::endl;
}

Fader::~Fader(){
    slider.unparent();
    mute.unparent();
}

MyWindow::MyWindow(): Faderbox(Gtk::ORIENTATION_HORIZONTAL,10), vBox(Gtk::ORIENTATION_VERTICAL,50), topMargin()
  {
  auto css = Gtk::CssProvider::create();
  css->load_from_path("./GUI.css");
  get_style_context()->add_provider_for_screen(Gdk::Screen::get_default(), css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  faders = new Fader[numFaders];
  for(int i = 0;i<numFaders;i++){
    faders[i].index = i;
    faders[i].mute.get_style_context()->add_class("Unmuted");
    Faderbox.add(faders[i]);
    faders[i].mute.signal_pressed().connect(sigc::mem_fun(faders[i],&Fader::MutePressed));
    faders[i].slider.signal_adjust_bounds().connect((sigc::mem_fun(faders[i],&Fader::updateFader)));
  }
  vBox.add(topMargin);
  vBox.add(Faderbox);
  add(vBox);
  set_title("QU-24 Offline Editor");
  set_default_size(100,100);
  show_all_children();
}

int main(int argc, char* argv[]){
  auto app = Gtk::Application::create("org.gtkmm.examples.base");
  MyWindow window;
  return app->run(window,argc,argv);
}