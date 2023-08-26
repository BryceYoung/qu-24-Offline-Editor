#include "../include/QU24-Offline-Editor.h"
#include <cstring>
#include <unistd.h>
#include <iostream>

bool fileExists(std::string filename){
  return ( access( filename.c_str(), F_OK ) != -1 );
}

qu_scene_t* LoadScene(std::string filename){
  std::istream* file = new std::ifstream(filename,std::ios::binary);
  kaitai::kstream* stream = new kaitai::kstream(file);
  return new qu_scene_t(stream);
}

qu_scene_t* Copy(qu_scene_t* scene){
  if(scene == NULL) return NULL;
  scene->Write("temp.scene");
  return LoadScene("temp.scene");
}

struct Show* LoadShow(std::string filepath){
  std::istream* file = new std::ifstream(filepath + "/SHOW.DAT",std::ios::binary);
  kaitai::kstream* stream = new kaitai::kstream(file);
  struct Show* show = new struct Show;
  show->show = new qu_show_t(stream);
  show->current = LoadScene(filepath + "/NVDATA.DAT");
  show->readPath = filepath;
  char filename[14] = "/SCENE000.DAT";
  for(int i = 0;i<10;i++){
    for(int j = 0;j<10;j++){
      filename[7] = i + '0';
      filename[8] = j + '0';
      if(!fileExists(filepath + filename)) continue;
      show->scenes[i*10+j] = LoadScene(filepath + filename);
    }
  }
  return show;
}

void SaveShow(Show* show,std::string filepath){
  std::filesystem::create_directory(filepath);
  char filename[14] = "/SCENE000.DAT";
  for(const auto &myPar : show->scenes){
    filename[7] = (myPar.first/10) + '0';
    filename[8] = (myPar.first % 10) + '0';
    myPar.second->Write(filepath + filename);
  }
  show->show->Write(filepath);
  show->current->Write(filepath + "/NVDATA.DAT");
}

void PrintScene(qu_scene_t* scene){
  std::cout << "channels: " << std::endl;
  std::cout << "Name: ";
  for(int i = 0;i<24;i++){
    std::cout << scene->inputs()->at(i)->name() << " ";
  }
  std::cout << std::endl;
  std::cout << "Gain: ";
  for(int i = 0;i<24;i++){
    std::cout << scene->inputs()->at(i)->gain() << " ";
  }
  std::cout << std::endl;
  std::cout << "Fader Val: ";
  for(int i = 0;i<24;i++){
    std::cout << scene->inputs()->at(i)->getFader() << " ";
  }
  std::cout << std::endl;
  std::cout << "Mute: ";
  for(int i = 0;i<24;i++){
    std::cout << scene->inputs()->at(i)->getMute() << " ";
  }
  std::cout << std::endl;
  std::cout << "Trim: ";
  for(int i = 0;i<24;i++){
    std::cout << scene->inputs()->at(i)->trim() << " ";
  }
  std::cout << std::endl;
  std::cout << "Left Right Fader: " <<scene->lr()->getFader() << std::endl; 
}