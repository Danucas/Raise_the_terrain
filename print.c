#include <stdio.h>
#include "libs_eng.h"
void print_faces(face **faces);
/**
 *print_vertex - print the vertex positions
 *@vertices: los vertices
 */
void print_vertex(const vert_t *vertices)
{
	int pos = 0;
	const vert_t *v = vertices;

	while (v != NULL)
	{
		printf("Vertex %d x: %9f, y: %9f, z: %9f\n", pos, v->x, v->y, v->z);
		if (v->next == NULL)
			return;
		v = v->next;
		pos++;
	}
}
/**
 *print_polygons - print the vertex positions
 *@polygons: los vertices
 */
void print_polygons(polygon **polygons)
{
	int pos = 1;
	polygon *p = *polygons;

	if (p == NULL)
		printf("pailas");

	while (p != NULL)
	{
		printf("polygon: %d ", pos);
		print_faces(&p->faces);
		p = p->next;
		pos++;
	}
}
/**
 *print_faces - print the vertex positions
 *@faces: los vertices
 */
void print_faces(face **faces)
{
	int counter = 0;
	face *f = *faces;

	while (f != NULL)
	{
		printf("%d/%d ", f->a, f->b);
		f = f->next;
		counter++;
	}
	printf(" size: %d\n", counter);
}
