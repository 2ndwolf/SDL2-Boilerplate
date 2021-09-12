
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

    // std::map<std::string, std::vector<SDL_Scancode>>::iterator it;
    // for (it = iniDefinedKeys.begin(); it != iniDefinedKeys.end(); it++){
    //   Keybinds::keys.insert({it->first, it->second});
    // }

    // // Take keybinds from user preferences
    Keybinds::keys["UP"] = {SDL_SCANCODE_UP, SDL_SCANCODE_W};
    // Keybinds::keys["LEFT"] = {SDL_SCANCODE_LEFT, SDL_SCANCODE_A};
    // Keybinds::keys["DOWN"] = {SDL_SCANCODE_DOWN, SDL_SCANCODE_S};
    // Keybinds::keys["RIGHT"] = {SDL_SCANCODE_RIGHT, SDL_SCANCODE_D};
  }


}