#include <stdio.h>
#include "libs_eng.h"
vert_t *project_vertex(vert_t **vertx, camara *cam, viewport *view);
/**
 *draw_polygons - draw polygons
 *@vertex: the vertex list
 */
void draw_polygons(vert_t **vertex)
{
	(void) vertex;
}
/**
 *draw_vertex - draw polygons
 *@obj: the vertex list
 *@cam: the camera
 *@view: the viewport
 *Return:  transformed vertexs
 */
vert_t *draw_vertex(mesh **obj, camara *cam, viewport *view)
{
	vert_t *transformed_vertx, *head;

	transformed_vertx = NULL;
	head = transf_vertex(obj, &transformed_vertx);
	project_vertex(&head, cam, view);
	return (head);
}
/**
 *project_vertex - draw polygons
 *@vertx: the vertex list
 *@cam: the camera
 *@view: the viewport
 *Return:  transformed vertexs
 */
vert_t *project_vertex(vert_t **vertx, camara *cam, viewport *view)
{
	vert_t *list = *vertx;
	vert_t *pr;

	while (list != NULL)
	{
		pr = project(list, cam, view);

		list->x = pr->x;
		list->y = pr->y;
		list->z = pr->z;
		list = list->next;
	}
	return (*vertx);
}
