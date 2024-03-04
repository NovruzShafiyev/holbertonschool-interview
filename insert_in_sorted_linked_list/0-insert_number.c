#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: double pointer of singly linked list.
 * @number: value of node to insert
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		while (current->next != NULL)
		current = current->next;
		current->next = new;
	}

	return (new);
}