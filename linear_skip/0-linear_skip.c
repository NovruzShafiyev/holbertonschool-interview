#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @head: Pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: Pointer on the first node where value is located, or NULL if value
 *         is not present or head is NULL.
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *node = head, *express = NULL;

	if (!head)
		return (NULL);

	while (node && node->express && node->express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			node->express->index, node->express->n);
		node = node->express;
	}

	if (node && node->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			node->express->index, node->express->n);
		express = node->express;
	}
	else
	{
		express = node;
		while (express->next)
			express = express->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		node->index, express->index);

	while (node && node->index <= express->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			node->index, node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}

	return (NULL);
}
