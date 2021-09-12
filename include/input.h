//=================================
// include guard
#ifndef _input_h_
#define _input_h_

#include <string>
#include <vector>
#include <map>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_scancode.h> 

namespace Input{

  void initKeyBinds(std::map<std::string, std::vector<SDL_Scancode>> &iniDefinedKeys);
  void loadScancodes();
  std::vector<SDL_Scancode> findScancode(std::vector<std::string> keycodeAsStr);

  int pollEvents();
  void updateInputStates();
  bool keyPressed(std::string key);
  bool keyHeld(std::string key);
  bool keyUp(std::string key);
  bool keyDown(std::string key);

  enum MouseMode{
    DEFAULT
  };

  class Mouse{
    public:
    static int x, y;
    static std::map<int, int> clicks;
    static MouseMode mouseMode;
  };

  class KeyStates{
    public:
    static int8_t keycodeStates[SDL_NUM_SCANCODES];
  };

  class Keybinds{
    public:
    static std::map<std::string, std::vector<SDL_Scancode>> keys;
  };
}

#endif