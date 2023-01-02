#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HIGHT 600

int main(int argc, char* argv[]){
	if(SDL_Init(SDL_INIT_EVERYTHING)<0){
		printf("SDL error: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_Window* window= SDL_CreateWindow("First Window", 0,0, SCREEN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_RESIZABLE);
	if(window==NULL){
		printf("SDL error: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer==NULL){
		printf("SDL error: %s\n", SDL_GetError());
		exit(1);
	}

	int quit=0;
	while(!quit){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_QUIT:{
		     		quit=1;
			} break;
			}
		}


		if(SDL_SetRenderDrawColor(renderer, 18, 18, 18, 255)<0){
			printf("SDL error: %s\n", SDL_GetError());
			exit(1);
		}

		if(SDL_RenderClear(renderer)<0){
			printf("SDL error: %s\n", SDL_GetError());
			exit(1);
		}

		SDL_RenderPresent(renderer);
	}

	SDL_Quit();
	return 0;
}
