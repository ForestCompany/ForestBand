#include<SDL.h>
#include<SDL_image.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#include"map.h"
const unsigned int size = 20;


const int WIDTH = 800;
const int HEIGHT = 600;


const double fps = 120;



SDL_Window*   window;
SDL_Surface*  screensurface;
SDL_Surface*  hello;
SDL_Texture*  texture;
SDL_Renderer* renderer;

Map* map;


void init() {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("123", 1920 / 4, 1080 / 4, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	map = (Map*)malloc(sizeof(Map));
	InitMap(map,size);
}

void close() {
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	DestroyMap(map);
}

SDL_Texture* loadTexture(const char* path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);

	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, SDL_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void loadmedia() {
	const char* path = "../images/tirion.png";
	texture = loadTexture(path);
}

int main(int argc,char* args[]) {
	

	


	init();

	loadmedia();

	/*ShowMap(map);*/

	SDL_Event e;
	int quit = 0;
	//While application is running
	while (quit != 1)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = 1;
			}
			else if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					quit = 1;
				}
			}
		}

		//Clear screen
		SDL_RenderClear(renderer);

		//Render texture to screen
		

		SDL_RenderCopy(renderer, texture, NULL, NULL);

		//Update screen
		SDL_RenderPresent(renderer);
		SDL_Delay((1/fps)*1000);
	}
	close();
}