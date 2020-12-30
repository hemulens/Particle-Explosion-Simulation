#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace simulation {
  
  class Screen {
    public:
      Screen();
      bool init();
      bool processEvents();
      void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
      void update();
      void close();

      const static int SCREEN_WIDTH = 800;
      const static int SCREEN_HEIGHT = 600;

    private: 
      SDL_Window *_window;
      SDL_Renderer *_renderer;
      SDL_Texture *_texture;
      Uint32 *_buffer;
  };

} /* namespace simulation */

#endif /* SCREEN_H_ */