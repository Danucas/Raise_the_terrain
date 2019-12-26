#include "libs_eng.h"
/**
 *transf_vertex - handle an entire object
 *@obj: the object to transform with it's options
 *@new_vertlist: the vertex to meassure
 *Return: the center point
 */
vert_t *transf_vertex(mesh **obj, vert_t **new_vertlist)
{
	vert_t *vertices = (*obj)->vertx;
	vert_t *newlist;
	vert_t  dummy;
	int pos = 0;

	newlist = NULL;

	while (vertices != NULL)
	{

		dummy = translate(
			rotate(
				scalar(*vertices, (*obj)->scala),
				*obj),
			*((*obj)->transform->translation));
		add_vertex_node(&newlist, dummy);
		vertices = vertices->next;
		pos++;
	}
	if (newlist != NULL)
	{       *new_vertlist = newlist;
		return (newlist);
	}
	else
	{       return (NULL);
	}
}

/**
 *set_center_origin - set the object's center point
 *@vertx: the vertex list to meassure
 *Return: the center point
 */
vert_t *set_center_origin(vert_t **vertx)
{
	int size = list_size(vertx);
	double *xs = malloc(sizeof(double) * size);
	double *ys = malloc(sizeof(double) * size);
	double *zs = malloc(sizeof(double) * size);
	(void) xs;
	(void) ys;
	(void) zs;

	return (*vertx);
}
