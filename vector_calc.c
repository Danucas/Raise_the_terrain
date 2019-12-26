#include "libs_eng.h"
/**
 *sum_vec - sum 2 3x3 vectors
 *@vec1: first
 *@vec2: second
 *Return: the added vector
 */

vert_t sum_vec(vert_t vec1, vert_t vec2)
{
	double x = vec1.x + vec2.x;
	double y = vec1.y + vec2.y;
	double z = vec1.z + vec2.z;
	vert_t result = {x, y, z, NULL};

	return (result);
}
/**
 *sus_vec - sum 2 3x3 vectors
 *@vec1: first
 *@vec2: second
 *Return: the added vector
 */
vert_t sus_vec(vert_t vec1, vert_t vec2)
{
	double x = vec1.x - vec2.x;
	double y = vec1.y - vec2.y;
	double z = vec1.z - vec2.z;
	vert_t result = {x, y, z, NULL};

	return (result);

}
/**
 *mul_vec - sum 2 3x3 vectors
 *@vec1: first
 *@vec2: second
 *Return: the added vector
 */
vert_t mul_vec(vert_t vec1, vert_t vec2)
{
	double x = vec1.x * vec2.x;
	double y = vec1.y * vec2.y;
	double z = vec1.z * vec2.z;
	vert_t result = {x, y, z, NULL};

	return (result);

}
/**
 *div_vec - sum 2 3x3 vectors
 *@vec1: first
 *@vec2: second
 *Return: the added vector
 */
vert_t div_vec(vert_t vec1, vert_t vec2)
{
	double x = vec1.x / vec2.x;
	double y = vec1.y / vec2.y;
	double z = vec1.z / vec2.z;
	vert_t result = {x, y, z, NULL};

	return (result);

}
