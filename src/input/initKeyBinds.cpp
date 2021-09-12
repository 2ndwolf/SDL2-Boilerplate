
#include <map>
#include <string>
#include <vector>

#include "SDL2/SDL.h"
#include "SDL2/SDL_scancode.h"


#include "input.h"

// using namespace CustomizeComponent;

std::map<std::string, std::vector<SDL_Scancode>> Input::Keybinds::keys;

namespace Input{
  // Keybinds::keys;

  void initKeyBinds(std::map<std::string, std::vector<SDL_Scancode>> &iniDefinedKeys){
    
    std::map<std::string, std::vector<SDL_Scancode>>::iterator it;
    for (it = iniDefinedKeys.begin(); it != iniDefinedKeys.end(); it++){
      Keybinds::keys.insert({it->first, it->second});
    }
  }

}