#include "libs_eng.h"
vert_t *zoom_p(camara *cam, vert_t *vertice);
vert_t *translate_p(camara *cam, vert_t *vertice);
vert_t *rotate_p(camara *cam, vert_t *vertice);
vert_t *pr(viewport *viewp, vert_t *point);
/**
 *project - project the matrix vertex by vertex
 *@vertice: the vertex
 *@cam: the camera object
 *@viewp: the viewport
 *Return: a verttex pointer
 */
vert_t *project(vert_t *vertice, camara *cam, viewport *viewp)
{

	vert_t *p = vertice;
	double inc = 0.6;

	p->x = (inc * p->x) - (inc * p->y) + (width / 2);
	p->y = ((1 - inc) * p->x) + ((1 - inc) * p->y) - p->z + (height / 2);
	p = translate_p(cam, p);

	(void) viewp;
	(void) cam;
	return (p);
}
/**
 *pr - project the matrix vertex by vertex
 *@viewp: the vertex
 *@point: the camera object
 *Return: a verttex pointer
 */
vert_t *pr(viewport *viewp, vert_t *point)
{
	point->x = ((point->x * 400) / viewp->width) + (width / 2);
	point->y = ((point->y * 400) / viewp->height) + (height / 2);
	if (point->x > width)
		point->x = width;
	if (point->x < 0)
		point->x = 0;

	if (point->y > height)
		point->y = height;
	if (point->y < 0)
		point->y = 0;
	return (point);

}
/**
 *zoom_p - project the matrix vertex by vertex
 *@cam: the vertex
 *@vertice: the camera object
 *Return: a verttex pointer
 */
vert_t *zoom_p(camara *cam, vert_t *vertice)
{

	float scale = powf(cam->zoom, 2);

	vertice->x = vertice->x * scale;
	vertice->y = vertice->y * scale;
	vertice->z = vertice->z * 1;
	return (vertice);
}
/**
 *translate_p - project the matrix vertex by vertex
 *@cam: the vertex
 *@vertice: the camera object
 *Return: a verttex pointer
 */
vert_t *translate_p(camara *cam, vert_t *vertice)
{
	vertice->x += cam->transform->translation->x;
	vertice->y += cam->transform->translation->y;
	return (vertice);
}
/**
 *rotate_p - project the matrix vertex by vertex
 *@cam: the vertex
 *@vertice: the camera object
 *Return: a verttex pointer
 */
vert_t *rotate_p(camara *cam, vert_t *vertice)
{
	float tempx = vertice->x - cam->transform->translation->x;
	float tempy = vertice->y - cam->transform->translation->y;
	float tempz = vertice->z - cam->transform->translation->z;
	float overx = cam->transform->rotation->x;
	float overy = cam->transform->rotation->y;
	float overz = cam->transform->rotation->z;
	float i = (1) * (tempx) + (0) * (tempy) + (0) * (tempz);
	float j = (0) * (tempx) + (cos(overx)) * (tempy) + (-(sin(overx))) * (tempz);
	float k = (0) * (tempx) + (sin(overx)) * (tempy) + (cos(overx)) * (tempz);

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

	vertice->x = tempx;
	vertice->y = tempy;
	vertice->z = tempz;
	return (vertice);

}
