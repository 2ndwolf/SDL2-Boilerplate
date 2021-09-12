//=================================
// include guard
#ifndef _ddd
#define _ddd

#include <SDL2/SDL.h> 
#include "constants.h"

#include <vector>
#include <map>
#include <iostream>



namespace Rendering {
  

  struct Position{
    int x, y, screenX, screenY;
  };

  struct SpriteInfo{
    std::string fileName;
    int offX = 0, offY = 0, width = 0, height = 0, layer = 0;
  };

  struct SDLSurface{
    SDL_Surface* sur;
    int useCount;
  };

  class Renderable{
    private:
    SDL_Texture* sdlTexture;
    SDL_Rect sdlRect;
    SDL_Rect srcRect;
    public:
    int layer, frame;
    bool hidden;
    std::string fileName;
    Position offset;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    double angle = 0;

    Renderable(SpriteInfo info);
    ~Renderable();

    SDL_Texture* getSDLTexture(){return sdlTexture;};
    SDL_Rect* getSDLRect(){return &sdlRect;};
    void updatePosition(int x, int y){sdlRect.x=x;sdlRect.y=y;};
    void moveFromPosition(int x, int y){sdlRect.x+=x;sdlRect.y+=y;};
    SDL_Rect* getSRCRect(){return &srcRect;};
    double getAngle(){return angle;};
    SDL_RendererFlip getFlip(){return flip;};
  };
  
  class Render{
    private:
      static SDL_Window* sdlWindow;
      static SDL_Renderer* sdlRenderer;
      static std::vector<std::vector<Renderable*>> layers;
      static std::map<std::string, SDLSurface*> surfaces;
      // static SurfaceList *surfaceList;
      
    public:
      static int  init();
      static void kill();
      static void loop();
      static Renderable* addRenderable(SpriteInfo info);
      static SDL_Window* getWindow(){return sdlWindow;};
      static SDL_Renderer* getRenderer(){return sdlRenderer;};
      static std::vector<std::vector<Renderable*>>& getLayers() {return layers;};
      static std::map<std::string, SDLSurface*>* getSurfaces(){return &surfaces;};
      static SDLSurface* getSurface(std::string fileName){return surfaces[fileName];};
  };

}



#endif