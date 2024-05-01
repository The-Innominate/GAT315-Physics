#include "world.h"
#include <stdlib.h>
#include <assert.h>

Body* bodies = NULL;
int bodyCount = 0;


/**
 * @brief Create a Body object
 *
 * @return Body*
 *
 * Assert if provided Body is not NULL
 * If 'prev' is not NULL, set 'prev->next' to 'body->next'
 * If 'next' is not NULL, set 'next->prev' to 'body->prev'
 * If body is the head, update head to 'body->next'
 * Decrement body count
 * Free the body
*/
Body* CreateBody()
{
	Body* body = (Body*)malloc(sizeof(Body));
	assert(body);

	body->next = bodies;
	body->prev = NULL;

	if (bodies)
	{
		bodies->prev = body;
	}

	bodies = body;
	bodyCount++;

	return body;
}

/**
 * @brief Destroy a Body object
 *
 * @param body
 *
 * Assert if provided Body is not NULL
 * If 'prev' is not NULL, set 'prev->next' to 'body->next'
 * If 'next' is not NULL, set 'next->prev' to 'body->prev'
 * If body is the head, update head to 'body->next'
 * Decrement body count
 * Free the body
*/

void DestroyBody(Body* body)
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

	if (bodies == body)
	{
		bodies = body->next;
	}

	bodyCount--;
	free(body);
}
