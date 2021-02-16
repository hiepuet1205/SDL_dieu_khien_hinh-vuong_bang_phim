#include <iostream>
#include <SDL.h>
using namespace std;
void logSDLError(std::ostream& os,const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, string WINDOW_TITLE);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();

/* // xóa màn hình
    int SDL_RenderClear(SDL_Renderer* renderer)
     // đặt màu vẽ r: red, g: green, b: blue, a: alpha opaque (255: mầu đặc nhất)
    int SDL_SetRenderDrawColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    // vẽ điểm
    int SDL_RenderDrawPoint(SDL_Renderer* renderer, int x, int y)
    // vẽ đoạn thẳng
    int SDL_RenderDrawLine(SDL_Renderer* renderer, int x1, int y1, int x2, int y2)
    // vẽ hình chữ nhật rỗng
    int SDL_RenderDrawRect(SDL_Renderer* renderer, const SDL_Rect* rect)
    // vẽ hình chữ nhật đặc
    int SDL_RenderFillRect(SDL_Renderer* renderer, const SDL_Rect* rect)
        // hiển thị màn hình
    //Khi thông thường chạy với môi trường bình thường ở nhà, với trước đó khởi tạo dùng
    // renderer = SDL_CreateRenderer(...)
    void SDL_RenderPresent(SDL_Renderer* renderer)*/

