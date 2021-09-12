#include <string>
#include <iostream>

#include "SDL2/SDL_audio.h"
#include "SDL2/SDL_stdinc.h"

#include "audio.h"

using namespace std;

SDL_AudioSpec Audio::Device::AudioSpecWant;
std::vector<SDL_AudioDeviceID> Audio::Device::deviceIds;
int Audio::Device::currentId;
SDL_AudioDeviceID Audio::Device::deviceId;

// std::map<SDL_Scancode, char*> Audio::MeowCtave::octave;


namespace Audio{

  void init(){
    devices();
  }

  void devices(){
    SDL_memset(&Device::AudioSpecWant, 0, sizeof(Device::AudioSpecWant));
    Device::AudioSpecWant.freq = 44100;
    Device::AudioSpecWant.format = AUDIO_S16;
    Device::AudioSpecWant.channels = 2;
    Device::AudioSpecWant.samples = 4096;

    Device::currentId = -1;
  }

}