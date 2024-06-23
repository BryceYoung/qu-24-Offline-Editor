#include "Fader.h"
#include "Global.h"

Fader::Fader():
  mute(), slider(), select()
  {
  widget = new Gtk::Label();
  select.get_style_context()->add_class("select");
  slider.set_range(-100,10);
  slider.set_draw_value(false);
  slider.set_inverted(true);
  mute.signal_clicked().connect(sigc::mem_fun(*this,&Fader::MutePressed));
  slider.signal_adjust_bounds().connect((sigc::mem_fun(*this,&Fader::updateFader)));
  select.signal_clicked().connect(sigc::mem_fun(*this,&Fader::SelectPressed));
  set_row_spacing(10);
  set_column_spacing(10);
  set_size_request(50,50);
  attach(mute,2,2,1,1);
  set_row_homogeneous(true);
  attach_next_to(select,mute,Gtk::PositionType::BOTTOM,1,1);
  attach_next_to(*widget,select,Gtk::PositionType::BOTTOM,2,1);
  attach_next_to(slider,*widget,Gtk::PositionType::BOTTOM,1,6);
}

Fader::~Fader(){
    slider.unparent();
    mute.unparent();
    select.unparent();
    widget->unparent();
    delete widget;
    delete channel;
}

void Fader::setMuted(qu_scene_t::channel_entry_t::Mute mute_on_off){
  Muted = mute_on_off;
  mute.get_style_context()->remove_class("Muted");
  mute.get_style_context()->remove_class("Unmuted");
  if(Muted == qu_scene_t::channel_entry_t::Muted) mute.get_style_context()->add_class("Muted"); 
  else mute.get_style_context()->add_class("Unmuted"); 
}

void Fader::setChannel(qu_scene_t::channel_entry_t* chan){
  channel = chan;
  setMuted(channel->getMute());
  setFader(((channel->getFader() / 32000.0) * 110)-100);
  ((Gtk::Label*)widget)->set_text(channel->name());
}

void Fader::update(){
  channel->setMute(Muted);
  channel->setFader((slider.get_value() + 100) / 110 * 32000);
}

void Fader::updateFader(double value){
  if(value < -100) value = -100;
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
}

void Fader::SelectPressed(){
  window->DeselectFaders(index);
  selected = true;
  select.get_style_context()->remove_class("select");
  select.get_style_context()->add_class("selected");
}

void Fader::Deselect(){
  selected =  false;
  select.get_style_context()->add_class("select");
  select.get_style_context()->remove_class("selected");
}

MainFader::MainFader(): 
  m1("1"),
  m2("2"),
  m3("3"),
  m4("4"),
  m56("5&6"),
  m78("7&8"),
  m910("9&10")
{
  remove(*widget);
  delete widget;
  //set_column_homogeneous(true);
  widget = new Gtk::Button();
  widget->get_style_context()->add_class("bselect");
  m1.get_style_context()->add_class("bselect");
  m2.get_style_context()->add_class("bselect");
  m3.get_style_context()->add_class("bselect");
  m4.get_style_context()->add_class("bselect");
  m56.get_style_context()->add_class("bselect");
  m78.get_style_context()->add_class("bselect");
  m910.get_style_context()->add_class("bselect");
  attach_next_to(*widget,select,Gtk::PositionType::BOTTOM,1,1);
  attach_next_to(m1,mute,Gtk::PositionType::RIGHT,1,1);
  attach_next_to(m2,m1,Gtk::PositionType::BOTTOM,1,1);
  attach_next_to(m3,m2,Gtk::PositionType::BOTTOM,1,1);
  attach_next_to(m4,m3,Gtk::PositionType::BOTTOM,1,1);
  attach_next_to(m56,m4,Gtk::PositionType::BOTTOM,1,1);
  attach_next_to(m78,m56,Gtk::PositionType::BOTTOM,1,1);
  attach_next_to(m910,m78,Gtk::PositionType::BOTTOM,1,1);
}

void MainFader::setChannel(qu_scene_t::channel_entry_t* chan){
  channel = chan;
  setMuted(channel->getMute());
  setFader(((channel->getFader() / 32000.0) * 110)-100);
}
