#include "SDLWindow.h"
#include <SDL.h>
#include <cstdio>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void windowMain() {
    //The window we'll be rendering to
    SDL_Window* window = nullptr;

    //The surface contained by the window
    SDL_Surface* screenSurface = nullptr;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );

    else {
        window = SDL_CreateWindow( "Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == nullptr )
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );

        else {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, nullptr, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Hack to get window to stay up
            SDL_Event e;
            bool quit = false;
            while(!quit) {
                while( SDL_PollEvent(&e ) ) {
                    if(e.type == SDL_QUIT )
                        quit = true;
                }
            }
        }
    }

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();
}
