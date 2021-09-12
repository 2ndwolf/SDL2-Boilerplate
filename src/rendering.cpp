#include <map>
#include <vector>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 

// #include "components/renderComponent.h"

#include "constants.h"

#include "rendering.h"


// std::vector<Rendering::Renderable*> 

// int *layers[] = {
//   std::vector<Rendering::Renderable*>,
//   std::vector<Rendering::Renderable*>,
//   std::vector<Rendering::Renderable*>,
//   std::vector<Rendering::Renderable*>
// }; 

SDL_Window* Rendering::Render::sdlWindow;
SDL_Renderer* Rendering::Render::sdlRenderer;
std::map<std::string, Rendering::SDLSurface*> Rendering::Render::surfaces;
std::vector<std::vector<Rendering::Renderable*>> Rendering::Render::layers(LAYERCOUNT);


namespace Rendering {

  int Render::init() {
    // returns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        printf("error initializing SDL: %s\n", SDL_GetError()); 
    }

    // sdlWindow = NULL;
    sdlWindow = SDL_CreateWindow("GAME",
                            SDL_WINDOWPOS_CENTERED, 
                            SDL_WINDOWPOS_CENTERED, 
                            WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE); 

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED; 
  
    // creates a renderer to render our images 
    sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, render_flags); 

    // layers[4];
    // Render::surfaceList = new SurfaceList;

    return 0;
  }


  void Render::loop(){
    SDL_RenderClear(sdlRenderer);

    for (std::vector<Rendering::Renderable*> l : layers){
      for(Rendering::Renderable* r : l){
        SDL_RenderCopyEx(sdlRenderer, r->getSDLTexture(), r->getSRCRect(), r->getSDLRect(), r->getAngle(), NULL, r->getFlip());
      }
    }

    SDL_RenderPresent(sdlRenderer); 

    // calculates to 60 fps 
    SDL_Delay(1000 / 60); 
  }


  void Render::kill(){
    for (std::vector<Rendering::Renderable*> l : layers){
      for(Rendering::Renderable* r : l){
        SDL_DestroyTexture(r->getSDLTexture()); 
      }
    }

    std::map<std::string, SDLSurface*>::iterator it;
    for (it = surfaces.begin(); it != surfaces.end(); it++){
      SDL_FreeSurface(it->second->sur);
    }

    // destroy renderer 
    SDL_DestroyRenderer(sdlRenderer); 

    // destroy window 
    SDL_DestroyWindow(sdlWindow);
  }


  Renderable* Render::addRenderable(SpriteInfo info){
    if(info.layer > LAYERCOUNT) info.layer = LAYERCOUNT;
    else if (info.layer < 0)    info.layer = 0;
    Renderable* renderable = new Renderable(info);

    layers[info.layer].push_back(renderable);
    return renderable;
  }

  // Constructor for Renderable
  Renderable::Renderable(SpriteInfo info){
    std::cout << info.fileName << std::endl;
    if(!Render::getSurfaces()->count(info.fileName)){
      SDLSurface* newSur;
      newSur->sur = IMG_Load(info.fileName.c_str());
      newSur->useCount = 1;
      // std::cout << "YO";
      // SDL_Surface* image = IMG_Load(fileName.c_str());
      Render::getSurfaces()->insert({info.fileName, newSur}); 
      // image->
    } else Render::getSurface(info.fileName)->useCount += 1;

    fileName = info.fileName;
    layer = info.layer;
    // loads image to our graphics hardware memory. 
    sdlTexture = SDL_CreateTextureFromSurface(Render::getRenderer(), Render::getSurface(info.fileName)->sur);
  
    srcRect.x = info.offX;
    srcRect.y = info.offY;

    if(info.width != 0 && info.height != 0){
      srcRect.w = info.width;
      srcRect.h = info.height;
      sdlRect.w = info.width;
      sdlRect.h = info.height;
      sdlRect.x = 0;
      sdlRect.y = 0;
      SDL_QueryTexture(sdlTexture, NULL, NULL, &info.width, &info.height); 
    } else {
      SDL_QueryTexture(sdlTexture, NULL, NULL, &sdlRect.w, &sdlRect.h); 
      srcRect.w = sdlRect.w;
      srcRect.h = sdlRect.h;
      sdlRect.x = 0;
      sdlRect.y = 0;
    }
  
    // Entity position component + x, y

    // i++;
  }


  //// Destructor for Renderable
  Renderable::~Renderable(){
    SDL_DestroyTexture(sdlTexture);
    if(Render::getSurface(fileName)->useCount > 1) Render::getSurface(fileName)->useCount -= 1;
    else SDL_FreeSurface(Render::getSurface(fileName)->sur);
  }

}