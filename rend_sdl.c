#include "libs_eng.h"

/**
 *rend - render the scene
 *@renderer: the renderer
 *@scn: the scene
 */
void rend(SDL_Renderer *renderer, scene *scn)
{
	vert_t *vrtx;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	*(scn->camara->target) = get_target_origin(scn->obj);
	vrtx = draw_vertex(&(scn->obj), scn->camara, scn->viewp);
	printf("Scanline\n");
	scanline(&(scn->obj->polys), &vrtx, renderer);
}
/**
 *get_vertx - render the scene
 *@pos: the position to get
 *@list: the list to choose from
 *Return: obtained pointer
 */

vert_t *get_vertx(int pos, vert_t *list)
{
	int indx = 1;

	while (list)
	{
		if (pos == indx)
		{
			return (list);
		}
		else
		{
			indx++;
			list = list->next;
		}
	}
	return (NULL);
}

/**
 *scanline - render the scene
 *@polys: the position to get
 *@list: the list to choose from
 *@renderer: the list to choose from
 */
void scanline(polygon **polys, vert_t **list, SDL_Renderer *renderer)
{
	polygon *ps = *polys;
	vert_t *vrtx = *list;
	vert_t *arr[3];
	int position = 1;

	while (ps != NULL)
	{
		vrtx = *list;
		arr[0] = get_vertx(ps->faces->a, vrtx);
		arr[1] = get_vertx(ps->faces->next->a, vrtx);
		arr[2] = get_vertx(ps->faces->next->next->a, vrtx);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer, arr[0]->x, arr[0]->y, arr[1]->x, arr[1]->y);
		SDL_RenderDrawLine(renderer, arr[1]->x, arr[1]->y, arr[2]->x, arr[2]->y);
		SDL_RenderDrawLine(renderer, arr[2]->x, arr[2]->y, arr[0]->x, arr[0]->y);
		SDL_RenderPresent(renderer);
		position++;
		ps = ps->next;
	}
}
