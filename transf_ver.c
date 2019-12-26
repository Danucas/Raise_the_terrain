#include "libs_eng.h"
vert_t rotate(vert_t vertex, mesh *obj);
vert_t scalar(vert_t vert, float scale);
vert_t translate(vert_t vert, vert_t trans);
vert_t *add_vertex_node(vert_t **newlist, vert_t vertex);
/**
 *list_size - transform each vertex to a rotated one
 *@vertx: the vertex to meassure
 *Return: the center point
 */
int list_size(vert_t **vertx)
{
	vert_t *v = *vertx;
	int counter = 0;

	while (v != NULL)
	{
		counter++;
		v = v->next;
	}
	return (counter);
}

/**
 *rotate - transform each vertex to a rotated one
 *@vertex: the vertex to meassure
 *@obj: the object to transform with it's options
 *Return: the center point
 */
vert_t rotate(vert_t vertex, mesh *obj)
{
	double tempx = vertex.x;
	double tempy = vertex.y;
	double tempz = vertex.z;
	vert_t result;
	double overx = obj->transform->rotation->x;
	double overy = obj->transform->rotation->y;
	double overz = obj->transform->rotation->z;
	double i = (1) * (tempx) + (0) * (tempy) + (0) * (tempz);
	double j = (0) * (tempx) + (cos(overx)) * (tempy) + (sin(overx)) * (tempz);
	double k = (0) * (tempx) + (sin(overx)) * (tempy) + (cos(overx)) * (tempz);

	tempx = i;
	tempy = j;
	tempz = k;

	i = (cos(overy)) * (tempx) + (0) * (tempy) + (sin(overy)) * (tempz);
	j = (0) * (tempx) + (1) * (tempy) + (0) * (tempz);
	k = (-(sin(overy))) * (tempx) + (0) * (tempy) + (cos(overy)) * (tempz);

	tempx = i;
	tempy = j;
	tempz = k;

	i = (cos(overz)) * (tempx) + (-(sin(overz))) * (tempy) + (0) * (tempz);
	j = (sin(overz)) * (tempx) + (cos(overz)) * (tempy) + (0) * (tempz);
	k = (0) * (tempx) + (0) * (tempy) + (1) * (tempz);

	tempx = i;
	tempy = j;
	tempz = k;
	result = (vert_t) {tempx, tempy, tempz, NULL};
	return (result);

}
/**
 *scalar - scale the object
 *@vert: the vertex to meassure
 *@scale: the object scalar function
 *Return: the center point
 */
vert_t scalar(vert_t vert, float scale)
{
	vert_t scal = {scale, scale, scale, NULL};

	return (mul_vec(vert, scal));
}
/**
 *translate - translate the vertex
 *@vert: the vertex to meassure
 *@trans: the transformation vertex
 *Return: the center point
 */
vert_t translate(vert_t vert, vert_t trans)
{
	vert_t res = sum_vec(vert, trans);

	return (res);
}
/**
 *add_vertex_node - transform each vertex to a rotated one
 *@newlist: the vertex to meassure
 *@vertex: the object to transform with it's options
 *Return: the center point
 */
vert_t *add_vertex_node(vert_t **newlist, vert_t vertex)
{

	vert_t *new_vertex = malloc(sizeof(vert_t));
	vert_t *giro = *newlist;

	if (new_vertex == NULL)
	{
		return (NULL);
	}

	new_vertex->x = vertex.x;
	new_vertex->y = vertex.y;
	new_vertex->z = vertex.z;
	new_vertex->next = NULL;

	if (*newlist == NULL)
	{

		new_vertex->next = *newlist;
		*newlist = new_vertex;
	}
	else
	{

		while (giro->next != NULL)
		{
			giro = giro->next;
		}
		giro->next = new_vertex;
	}

	return (new_vertex);
}
