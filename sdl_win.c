#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs_eng.h"


/**
 *init_loop - engine main function
 *@renderer: arguments count
 *@scn: arguments count
 *Return: 0 if success
 */
int init_loop(SDL_Renderer *renderer, scene *scn)
{
	SDL_Event event;
	int go = 1, res;

	printf("Press %d to quit\n", SDL_QUIT);
	while (go)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
		{	printf("Key Pressed %d\n", event.key.keysym.sym);
			fflush(stdout);
			res = key_pressed((int) event.key.keysym.sym, scn);
			if (res != -1)
				rend(renderer, scn);
			else
				return (0);
		}
		else if (event.type == SDL_QUIT)
			return (0);

	}
	return (go);
}


/**
 *main - engine main function
 *@ac: arguments count
 *@av: arguments list
 *Return: 0 if success
 */
int main(int ac, char **av)
{
	int go, rd;
	size_t le = 99;
	SDL_Window *win;
	scene *scn;
	Uint32 render_flags;
	SDL_Renderer *renderer;

	printf("%s\n", av[0]);
	if (ac > 1)
		filename = av[1];
	else
	{
		filename = malloc(sizeof(char) * 100);
		le = 99;
		printf("File to load: ");
		rd = getline(&filename, &le, stdin);
		filename[rd - 1] = '\0';
		(void) rd;
	}
	width = 600;
	height = 450;
	scn = init_engine();
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("Error initializing");
	win = SDL_CreateWindow("Raise the terrain",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		0);
	render_flags = SDL_RENDERER_ACCELERATED;
	renderer = SDL_CreateRenderer(win, -1, render_flags);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	rend(renderer, scn);
	go = init_loop(renderer, scn);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (go);
}
