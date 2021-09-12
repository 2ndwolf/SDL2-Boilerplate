//=================================
// include guard
#ifndef _audio_h_
#define _audio_h_

#include <vector>
#include <map>
#include <string>

#include "SDL2/SDL_audio.h"


namespace Audio{

  class Device{
    public:
    static SDL_AudioSpec AudioSpecWant, AudioSpecHave;
    static SDL_AudioDeviceID deviceId;
    static std::vector<SDL_AudioDeviceID> deviceIds;
    static int currentId;

  };
  
  class Sound{
    public:
    Uint32 wav_length;
    Uint8 *wav_buffer;
  };

  void init();
  void devices();

  void play(std::string sound);
  void closeAllAudioDevices();


}

#endif