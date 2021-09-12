#include <string>
#include <vector>
#include <map>

#include "input.h"


namespace Preferences {
  struct userPreferences {
    // std::string playerImage;
    std::map<std::string, std::string> sounds, images;
    std::map<std::string, std::vector<SDL_Scancode>> keys;
  };

  userPreferences parseIni(const std::string &fileName);

}