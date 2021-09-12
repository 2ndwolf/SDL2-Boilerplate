#include <vector>
#include <string>

#include <fstream>
#include <sstream>

#include "input.h"
#include "utility.h"
#include "preferences.h"

namespace Preferences {
  userPreferences parseIni(const std::string &fileName){
    userPreferences uPrefs;

    Input::loadScancodes();

    std::ifstream infile(fileName);
    std::string line;
    while (std::getline(infile, line))
    {
        // std::istringstream line(line);
        if(Utility::split(line, ' ')[0] == "#") continue;
        std::vector<std::string> params = Utility::split(line, ':');

        if(params[0]=="IMAGE"){
          uPrefs.playerImage = Utility::strip(params[1], ' ');
        }

        if(params[0]=="KEY"){
          std::vector<std::string> keyPrefs = Utility::split(params[1], ' ');
          uPrefs.keys.insert({Utility::split(params[0], ' ')[1], Input::findScancode(keyPrefs)});
          // std::string[std::size(keyPrefs)] keyPrefsArr;

          // for(int i = 0; i < std::size(keyPrefs); i++){
          //   keyPrefsArr[i] = keyPrefs[i];
          // }

        }
    }

    return uPrefs;
  }
}