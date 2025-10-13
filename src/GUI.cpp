#include "GUI.h"
//g++ myfirstprogram.cpp -o myfirstprogram `pkg-config gtkmm-3.0 --cflags --libs


int SceneFocused = 0;
MyWindow* window;
bool debug = false;



bool DEBUG = false;
int debugIndex = 0;

void Debug(std::string string){
  if(DEBUG){
    std::cout << debugIndex << ": " << string << std::endl;
    debugIndex++;
  }
}

int main(int argc,char* argv[]){
  if(argc > 1){
    if (strcmp("debug",argv[1]) == 0){
      debug = true;
    }
  }
  struct Show* show = LoadShow("AHQU/SHOWS/SHOW0008");
  auto app = Gtk::Application::create("org.gtkmm.examples.base");
  MyWindow* window;
  int appret = app->make_window_and_run<MyWindow>(0,nullptr,show,window);
  PrintScene(LoadScene("Scenes/NVDATA.DAT"));
  window->SaveGUIScene();
  show->scenes[98] = Copy(window->getCurrentScene());
  SaveShow(show,"Temp");
  Debug("show->current->groups()->at(1)->gate(ERROR)");
  return appret;
}
