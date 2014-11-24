#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// SDL 起動、ウィンドウ作成
bool init();
// メディアを読み込む
bool loadMedia();
// メディアの解放と SDL の終了
void close();

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gXOut = NULL;

int main(int argc, char* args[]) {
  if (!init()) {
    std::cout << "Failed to initialize!" << std::endl;
  } else {
    if (!loadMedia()) {
      std::cout << "Failed to load media!" << std::endl;
    } else {
      bool quit = false;
      SDL_Event e;

      while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
          if (e.type == SDL_QUIT) {
            quit = true;
          }
        }

        SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
      }
    }
  }

  close();
}

bool init() {
  bool success = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialze! SDL_Error: "
      << SDL_GetError() << std::endl;
    success = false;
  } else {
    gWindow = SDL_CreateWindow(
      "SDL Tutorial",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN
    );

    if (gWindow == NULL) {
      std::cout << "Window could not be created! SDL_Error: "
        << SDL_GetError() << std::endl;
      success = false;
    } else {
      gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
  }

  return success;
}

bool loadMedia() {
  const char* filename = "03_event_driven_programming/x.bmp";
  bool success = true;

  gXOut = SDL_LoadBMP(filename);
  if (gXOut == NULL) {
    std::cout << "Unable to load image " << filename << "! SDL Error: "
      << SDL_GetError() << std::endl;
    success = false;
  }

  return success;
}

void close() {
  SDL_FreeSurface(gXOut);
  gXOut = NULL;

  SDL_DestroyWindow(gWindow);
  gWindow = NULL;

  SDL_Quit();
}
