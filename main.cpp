#include <iostream>
#include <SDL.h>
#include "ham_ve.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "An Implementation of Code.org Painter";

struct Box{
    int x, y;
    int size=10;
    int stepX=0, stepY=0;

    void renderbox(SDL_Renderer* renderer){
        SDL_Rect filled_rect;
        filled_rect.x = x;
        filled_rect.y = y;
        filled_rect.w = size;
        filled_rect.h = size;
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // green
        SDL_RenderFillRect(renderer, &filled_rect);
    }

    void move(){
        x += stepX;
        y += stepY;
    }

    void turnleft(){
        stepX = -10;
        stepY = 0;
    }
    void turnright(){
        stepX = 10;
        stepY = 0;
    }
    void turndown(){
        stepX = 0;
        stepY = 10;
    }
    void turnup(){
        stepX = 0;
        stepY = -10;
    }

    bool inside(int minX, int minY, int maxX, int maxY){
        return x>=minX && y>=minY && x+size<=maxX && y+size<=maxY;
    }
};

int main(int argc, char* argv[])
{
     SDL_Window* window;
     SDL_Renderer* renderer;
     initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
     // Your drawing code here
     // use SDL_RenderPresent(renderer) to show it

     Box box;
     box.x=10;
     box.y=10;

     SDL_Event e;

     while(box.inside(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)){
        box.move();
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_RenderClear(renderer);

        box.renderbox(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(10);

        if ( SDL_PollEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE: break;
        		case SDLK_LEFT: box.turnleft(); break;
            	case SDLK_RIGHT: box.turnright(); break;
            	case SDLK_DOWN: box.turndown(); break;
            	case SDLK_UP: box.turnup(); break;
        		default: break;
			}
        }
     }

     // waitUntilKeyPressed();
     quitSDL(window, renderer);
     return 0;
}
