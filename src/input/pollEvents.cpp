#include <iostream>

#include <SDL2/SDL.h> 


#include "constants.h"

#include "rendering.h"

#include "input.h"


int Input::Mouse::x;
int Input::Mouse::y;
std::map<int, int> Input::Mouse::clicks;
Input::MouseMode Input::Mouse::mouseMode = Input::MouseMode::DEFAULT;
int8_t Input::KeyStates::keycodeStates[SDL_NUM_SCANCODES];



namespace Input {

  int pollEvents () {
    SDL_Event event;

    // Increment pressed state, or -1 if released during previous frame
    // updateInputStates(Mouse::clicks);
    updateInputStates();

    while (SDL_PollEvent(&event)) { 
      switch (event.type) { 

      case SDL_WINDOWEVENT:

        if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
            // logFileStderr("MESSAGE:Resizing window...\n");
            // resizeWindow(event.window.data1, event.window.data2);
        }
          
        break;
      case SDL_QUIT:
        return 1;

      case SDL_KEYDOWN:
        if(KeyStates::keycodeStates[event.key.keysym.scancode] == 0) KeyStates::keycodeStates[event.key.keysym.scancode] = 1; 
        break;

      case SDL_KEYUP:
        KeyStates::keycodeStates[event.key.keysym.scancode] = -1;
        break;

      case SDL_MOUSEBUTTONDOWN:
        switch(event.button.button){
          case SDL_BUTTON_LEFT:
            Mouse::clicks[SDL_BUTTON_LEFT] =  1;
            break;
          case SDL_BUTTON_RIGHT:
            Mouse::clicks[SDL_BUTTON_RIGHT] =  1;
            break;
        }

        break;

      case SDL_MOUSEBUTTONUP:
        switch(event.button.button){
          case SDL_BUTTON_LEFT:
            Mouse::clicks[SDL_BUTTON_LEFT] = -1;
          break;
          case SDL_BUTTON_RIGHT:
            Mouse::clicks[SDL_BUTTON_RIGHT] = -1;
          break;
        }
        break;

      case SDL_MOUSEMOTION:
        Mouse::x = event.motion.x;
        Mouse::y = event.motion.y;
        break;
      }
    }

    // Input::updateMouse();

    return 0;
  }

  void updateInputStates(){
    for(int i = 0; i < SDL_NUM_SCANCODES; i++){
      if(KeyStates::keycodeStates[i] == 0) continue;
      else if (KeyStates::keycodeStates[i] == 1) KeyStates::keycodeStates[i] = 2;
      else if (KeyStates::keycodeStates[i] == -1) KeyStates::keycodeStates[i] = 0;
    }
  }

  //void keypressed, keyheld, keyup, keydown
  bool keyPressed(std::string key){
    for(int i = 0; i < Input::Keybinds::keys[key].size(); i++){
      if(Input::KeyStates::keycodeStates[Input::Keybinds::keys[key][i]] > 0) return true;
    }
    return false;
  }

  bool keyHeld(std::string key){
    for(int i = 0; i < Input::Keybinds::keys[key].size(); i++){
      if(Input::KeyStates::keycodeStates[Input::Keybinds::keys[key][i]] == 2) return true;
    }
    return false;
  }

  bool keyUp(std::string key){
    for(int i = 0; i < Input::Keybinds::keys[key].size(); i++){
      if(Input::KeyStates::keycodeStates[Input::Keybinds::keys[key][i]] == -1) return true;
    }
    return false;
  }

  bool keyDown(std::string key){
    for(int i = 0; i < Input::Keybinds::keys[key].size(); i++){
      if(Input::KeyStates::keycodeStates[Input::Keybinds::keys[key][i]] == 1) return true;
    }
    return false;
  }
}
