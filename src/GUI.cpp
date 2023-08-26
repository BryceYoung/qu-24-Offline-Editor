#include "GUI.h"

//g++ myfirstprogram.cpp -o myfirstprogram `pkg-config gtkmm-3.0 --cflags --libs


int SceneFocused = 0;
MyWindow* window;



bool DEBUG = false;
int debugIndex = 0;

void Debug(std::string string){
  if(DEBUG){
    std::cout << debugIndex << ": " << string << std::endl;
    debugIndex++;
  }
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  MAIN  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int main(int argc,char* argv[]){
  struct Show* show = LoadShow("AHQU/SHOWS/SHOW0008");
  auto app = Gtk::Application::create("org.gtkmm.examples.base");
  window = new MyWindow(show);
  PrintScene(LoadScene("Scenes/NVDATA.DAT"));
  window->SaveGUIScene();
  show->scenes[98] = Copy(window->getCurrentScene());
  SaveShow(show,"Temp");
  Debug("show->current->groups()->at(1)->gate(ERROR)");
  return app->run(*window,argc,argv);
}