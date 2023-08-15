#include "GUI.h"
#include <iostream>

//g++ myfirstprogram.cpp -o myfirstprogram `pkg-config gtkmm-3.0 --cflags --libs


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
  std::cout << index << " ";
  std::cout << value << std::endl;
}

void Fader::MutePressed(){
  if(Muted == qu_scene_t::channel_entry_t::UnMuted){
   mute.get_style_context()->add_class("Muted"); 
   mute.get_style_context()->remove_class("Unmuted");
   Muted = qu_scene_t::channel_entry_t::Muted;
  }else{
    mute.get_style_context()->remove_class("Muted");
    mute.get_style_context()->add_class("Unmuted");
    Muted = qu_scene_t::channel_entry_t::UnMuted;
  }
  getChannel()->setMute(Muted);
  std::cout << index << " Pressed" << ": " << Muted << std::endl;
}

Fader::~Fader(){
    slider.unparent();
    mute.unparent();
}

MyWindow::MyWindow(qu_scene_t* scene): Faderbox(Gtk::ORIENTATION_HORIZONTAL,10), vBox(Gtk::ORIENTATION_VERTICAL,50), topMargin()
  {
  auto css = Gtk::CssProvider::create();
  css->load_from_path("./GUI.css");
  get_style_context()->add_provider_for_screen(Gdk::Screen::get_default(), css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  faders = new Fader[numFaders];
  for(int i = 0;i<numFaders;i++){
    faders[i].setIndex(i);
    faders[i].setChannel(scene->inputs()->at(i));
    faders[i].setMuted(faders[i].getChannel()->getMute());
    faders[i].setFader(((faders[i].getChannel()->getFader() / 32000.0) * 110)-100);
    faders[i].mute.get_style_context()->add_class("Unmuted");
    faders[i].mute.signal_pressed().connect(sigc::mem_fun(faders[i],&Fader::MutePressed));
    faders[i].slider.signal_adjust_bounds().connect((sigc::mem_fun(faders[i],&Fader::updateFader)));
    Faderbox.add(faders[i]);
  }
  vBox.add(topMargin);
  vBox.add(Faderbox);
  add(vBox);
  set_title("QU-24 Offline Editor");
  set_default_size(100,100);
  show_all_children();
}

int main(int argc,char* argv[]){
  struct Show* show = LoadShow("Scenes");
  auto app = Gtk::Application::create("org.gtkmm.examples.base");
  MyWindow window(show->scenes[68]);
  for(const auto &myPar : show->scenes){
    //std::cout << myPar.first << ": " << (int)myPar.second->inputs()->at(6)->getMute() << std::endl;
  }
  return app->run(window,argc,argv);
}