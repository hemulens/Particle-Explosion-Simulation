#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace simulation {
  
  class Screen {
    public:
      Screen();
      ~Screen();
      bool init();
      void close();
      bool processEvents();
      void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
      void update();
      void boxBlur();
      // void clear();

      const static int SCREEN_WIDTH = 800;
      const static int SCREEN_HEIGHT = 600;

    private: 
      SDL_Window *_window;
      SDL_Renderer *_renderer;
      SDL_Texture *_texture;
      Uint32 *_buffer1;
      Uint32 *_buffer2;
  };

} /* namespace simulation */

#endif /* SCREEN_H_ */