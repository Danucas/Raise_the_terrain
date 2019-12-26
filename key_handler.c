#include "libs_eng.h"

/**
 *key_pressed - pressed key handler
 *@code: the of from the key
 *Return: state 1 if succes
 */
int key_pressed(int code, scene *scn)
{
	int steps = 10;

	printf("Key pressed: code %d\n", code);
	switch (code)
	{
	case 27:  /* ESC */
		return (-1);
	case 97: /* A */
		printf("==  <  ==\n");
		scn->camara->transform->translation->x -= steps;
		return (1);
	case 100: /* D */
		printf("==  >  ==\n");
		scn->camara->transform->translation->x += steps;
		return (1);
	case 119: /* W */
		printf("==  n  ==\n");
		scn->camara->transform->translation->y -= steps;
		scn->viewp->pos->z += 1;
		return (1);
	case 115: /* S */
		printf("==  u  ==\n");
		scn->camara->transform->translation->y += steps;
		scn->viewp->pos->z -= 1;
		return (1);
	case 103: /* G */
		scn->obj->transform->rotation->z += M_PI / 180;
		return (1);
	default:
		break;
	}
	return (0);
}
