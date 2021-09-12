#include <iostream>
#include <stdexcept>
#include <iterator>
#include <string>
#include <vector>


#define SDL_MAIN_HANDLED
#include "input.h"
#include "rendering.h"
#include "preferences.h"
#include "audio.h"


using namespace std;





int main() {

  // std::uint64_t dt = 16;

  int close = Rendering::Render::init();
  Audio::init();

  Preferences::userPreferences uPrefs = Preferences::parseIni("assets/uPref.ini");

  Input::initKeyBinds(uPrefs.keys);

  Rendering::SpriteInfo info;
  info.fileName = uPrefs.images["PLAYER"];
  Rendering::Renderable* r = Rendering::Render::addRenderable(info);

  while (!close) { 

    close = Input::pollEvents();
    if(Input::keyPressed("UP")) r->moveFromPosition(1,0);
    if(Input::keyDown("UP")) Audio::play(uPrefs.sounds["DEFAULT"]);
    r->angle += 1;
    Rendering::Render::loop();

  } 

  Rendering::Render::kill();
  return 0; 
}