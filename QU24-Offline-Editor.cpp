#include "QU24-Offline-Editor.h"
#include <cstring>
#include <unistd.h>

bool fileExists(std::string filename){
  return ( access( filename.c_str(), F_OK ) != -1 );
}

qu_scene_t* LoadScene(std::string filename){
  if(!fileExists(filename))return NULL;
  std::istream* file = new std::ifstream(filename,std::ios::binary);
  kaitai::kstream* stream = new kaitai::kstream(file);
  return new qu_scene_t(stream);
}

struct Show* LoadShow(std::string filepath){
  struct Show* show = new struct Show;
  show->readPath = filepath;
  char filename[14] = "/SCENE000.DAT";
  for(int i = 0;i<10;i++){
    for(int j = 0;j<10;j++){
      filename[7] = i + '0';
      filename[8] = j + '0';
      show->scenes[i*10+j] = LoadScene(filepath + filename);
    }
  }
  return show;
}


int main(){
  struct Show* show = LoadShow("Scenes");
  for(int i = 0;i<100;i++){
    if(show->scenes[i]==NULL) continue;
    std::cout << i << ": " << (int)show->scenes[i]->inputs()->at(0)->GetMute() << std::endl;
  }
}