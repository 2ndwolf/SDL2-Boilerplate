#include <string>
#include <vector>
#include <map>

#include "input.h"

// for params
// Input::Keybinds::keys[PARAM1].push_back(PARAMX)

namespace Preferences {
  struct userPreferences {
    std::string playerImage;
    std::map<std::string, std::vector<SDL_Scancode>> keys;
  };

  userPreferences parseIni(const std::string &fileName);

}