#include "qu_scene.h"

struct Show{
  qu_scene_t* scenes[100];
  std::string readPath;
  std::string writePath;
  std::string Showname;
};

Show show = {NULL};

bool fileExists(std::string);

// Load Scenes from folder
struct Show* LoadShow(std::string);

qu_scene_t* LoadScene(std::string);