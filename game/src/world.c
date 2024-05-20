#include "world.h"
#include "body.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

ncBody* ncBodies = NULL;
int ncBodyCount = 0;

Vector2 ncGravity;

/**
 * @brief Create a ncBody object
 *
 * @return ncBody*
 *
 * Allocate memory for new ncBody
 * Check if allocation is successful
 * Initialize 'prev' to NULL and 'next' to the head of the list
 * If list is not empty, update 'prev' of existing head
 * Update head of the list to new ncBody
 * Increment body count
 * Return new ncBody
*/
ncBody* CreateBody(Vector2 position, float mass, ncBodyType bodyType)
{
	ncBody* body = (ncBody*)malloc(sizeof(ncBody));
	assert(body);

	memset(body, 0, sizeof(ncBody));
	body->position = position;
	body->mass = mass;
	body->inverseMass = (bodyType == BT_DYNAMIC) ? 1.0f / mass : 0;
	body->type = bodyType;

	return body;
}

void AddBody(ncBody* body)
{
	assert(body);

	body->prev = NULL;
	body->next = ncBodies;

	if (ncBodies){ ncBodies->prev = body; }

	ncBodies = body;
	ncBodyCount++;
}

/**
 * @brief Destroy a ncBody object
 *
 * @param body
 *
 * Assert if provided ncBody is not NULL
 * If 'prev' is not NULL, set 'prev->next' to 'body->next'
 * If 'next' is not NULL, set 'next->prev' to 'body->prev'
 * If body is the head, update head to 'body->next'
 * Decrement body count
 * Free the body
*/

void DestroyBody(ncBody* body)
{
	assert(body);

	if (body->prev)
	{
		body->prev->next = body->next;
	}

	if (body->next)
	{
		body->next->prev = body->prev;
	}

	if (ncBodies == body)
	{
		ncBodies = body->next;
	}

	ncBodyCount--;
	free(body);
}

void DestroyAllBodies()
{
	ncBody* body = ncBodies;
	while (body)
	{
		ncBody* next = body->next;
		free(body);
		body = next;
	}
	ncBodies = NULL;
	ncBodyCount = 0;
}