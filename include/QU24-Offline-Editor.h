#ifndef HEADER_QU24SHOW
#define HEADER_QU24SHOW

#include "qu_scene.h"
#include <map>
#include <filesystem>

typedef std::map<int, qu_scene_t*> Scenes;

struct Show{
  Scenes scenes;
  qu_show_t* show;
  qu_scene_t* current;
  std::string readPath;
  std::string writePath;
  std::string Showname;
};

bool fileExists(std::string);
struct Show* LoadShow(std::string);
qu_scene_t* LoadScene(std::string);
void SaveShow(Show*,std::string);
void PrintScene(qu_scene_t* scene);

#endif