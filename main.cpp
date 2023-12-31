#include <iostream>
#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")


int SDL_main(int argc, char* argv[])

{
	srand((unsigned int)(time(nullptr)));

	SDL_Init(SDL_INIT_EVERYTHING);//// 초기화 모두 지우겟다

	SDL_Window* MyWindow = SDL_CreateWindow("HelloWorld", 100, 100, 800, 600, SDL_WINDOW_OPENGL);  ////// SDL창을 만들겠다   앞에 거리, 그다음 2자리는 크기 , 마지막은 해상도 

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED); //SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_TARGETTEXTURE
	
	SDL_Event MyEvent;
	bool IsRunning = true;
	while (IsRunning)/// message loop
	{
		SDL_PollEvent(&MyEvent);
		switch (MyEvent.type) //// tick
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
		// 붓
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0xff, 0x00);
		SDL_RenderClear(MyRenderer);
		// Actors -> Render();
		for (int i = 0; i < 100; ++i)
		{
			int X = rand() % 800;
			int Y = rand() % 600;
			int W = rand() % 200; + 10;
			int H = rand() % 200; + 10;
			int R = rand() % 256;
			int G = rand() % 256;
			int B = rand() % 256;
			int A = rand() % 256;

			SDL_SetRenderDrawColor(MyRenderer, R, G, B, A);
			SDL_Rect MyRect = {X,Y,W,H};
			SDL_RenderFillRect(MyRenderer, &MyRect);
		}
		SDL_RenderPresent(MyRenderer);
	}

	SDL_Quit();///
	return 0;
}