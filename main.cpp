#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);//// 초기화 모두 지우겟다

	SDL_Window* MyWindow = SDL_CreateWindow("HelloWorld", 100, 100, 800, 600, SDL_WINDOW_OPENGL);  //////  앞에 2자리는 얼만큼 떨어지는지 뒤에 두자리는 해상도 
	

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED); //SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_TARGETTEXTURE
	
	SDL_Event MyEvent;
	bool IsRunning = true;
	while (IsRunning)/// message loop
	{
		SDL_PollEvent(&MyEvent);
		switch (MyEvent.type)
		{
		case SDL_QUIT:
		 IsRunning = false;
		 break;
		case SDL_KEYDOWN:
			if (MyEvent.key.keysym.sym == SDLK_ESCAPE)
			{
				IsRunning = false;
			}
			break;
		}
		// 명령어 죄다 저장 
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0xff, 0);
		SDL_RenderClear(MyRenderer);

		SDL_RenderPresent(MyRenderer); /// 알파는 배경색
	}

	SDL_Quit();///
	return 0;
}