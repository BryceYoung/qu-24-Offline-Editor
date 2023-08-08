
#include "QU24-Offline-Editor.h"
int main(){
  std::istream* ifs = new std::ifstream("SCENE004.DAT",std::ios_base::binary);
  kaitai::kstream* val = new kaitai::kstream(ifs);
  qu_scene_t g = qu_scene_t(val);
  for(int i = 0;i<24;i++){
    (*g.inputs())[i]->SetMute(qu_scene_t::channel_entry_t::Muted);
  }
  kaitai::kstream* ret = g.Write("SCENE004.DAT");
  ret->getFStream()->close();
    qu_scene_t* scenes[72];
    char string[] = "Scenes/SCENE004.DAT";
    int index = 0;
    for(int i = 0;i<10;i++){
      for (int j = 0;j<10;j++){
        if(i*10+j < 4) continue;
        if(i*10+j > 71) continue;
        string[13] = i + '0';
        string[14] = j + '0';
        //std::cout << string << std::endl;
        std::istream* ifs = new std::ifstream(string,std::ios_base::binary);
        kaitai::kstream* val = new kaitai::kstream(ifs);
        scenes[index] = new qu_scene_t(val);
        //(*scenes[index]->inputs())[0]->SetMute(qu_scene_t::channel_entry_t::UnMuted);
        for(int k = 0;k<24;k++){
          std::cout << (int)(*scenes[index]->inputs())[k]->GetMute() << " ";
        }
        std::cout << std::endl;
        index++;
      }
    }
}