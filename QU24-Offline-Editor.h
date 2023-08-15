#ifndef QU24SHOW
#define QU24SHOW

#include "qu_scene.h"
#include <map>

typedef std::map<int, qu_scene_t*> Scenes;

struct Show{
  Scenes scenes;
  std::string readPath;
  std::string writePath;
  std::string Showname;
};

//Show show = {NULL};

bool fileExists(std::string);

// Load Scenes from folder
struct Show* LoadShow(std::string);

qu_scene_t* LoadScene(std::string);

#endif