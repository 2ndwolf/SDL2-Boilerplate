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
  // delete uPref;

  Rendering::SpriteInfo info;
  info.fileName = uPrefs.playerImage;
  Rendering::Renderable* r = Rendering::Render::addRenderable(info);
  // Rendering::Render();

  // Customize::initDefaultImages();
  // FileInfo::path = "assets/";
  // FileInfo::name = "yay.gani";
 
  // Assembler::ganiEditMode(registry);

  // Window::close = 0;

// std::cout << std::distance(mymap.begin(),mymap.find(Input::Keybinds::keys["UP"][0]));
//   std::cout << std::endl << Input::KeyStates::keycodeStates.find((int)Input::Keybinds::keys["UP"][0]) << std::endl;

  while (!close) { 

    close = Input::pollEvents();
    // for(Input::Keybinds::keys["UP"])
    // std::cout << (int) Input::KeyStates::keycodeStates[Input::Keybinds::keys["UP"][0]] << std::endl;
    if(Input::keyPressed("UP")) r->moveFromPosition(1,0);
    if(Input::keyDown("UP")) Audio::play("assets/BasicMeow.wav");
    r->angle += 1;
    // Input::updateSquare(registry);
    // Input::updateMouse(registry);
    // System::update(registry);
    Rendering::Render::loop();

  } 

  Rendering::Render::kill();



  return 0; 
}


  // GaniInformation currentAni = Opening::open("assets/test.serverbsp");

  // Saving::save(currentAni, "test", "serverbsp");

//   return 0;
// }

  //   GaniBuilding::GaniInformation currentAni = Opening::open("assets/yay.gani");
  // Entities::createFileManagement(registry);
  // Entities::createGaniEntity(registry);

  // std::string fileName = "assets/gen_specialchest.gif";
  // PbRender::createRenderable(fileName);

  // Saving::save(currentAni, "test", "bs");

  // std::cout << "COUT";