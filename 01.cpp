#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
  SDL_Window* window = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError()
      << std::endl;
  } else {
    window = SDL_CreateWindow(
      "SDL Tutorial",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN
    );

    if (window == NULL) {
      std::cout << "Window could not be created! SDL_Error: "
        << SDL_GetError() << std::endl;
    } else {
      SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

      // 白で塗りつぶす
      SDL_FillRect(
        screenSurface,
        NULL,
        SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF)
      );

      SDL_UpdateWindowSurface(window);

      SDL_Delay(2000);
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
}
