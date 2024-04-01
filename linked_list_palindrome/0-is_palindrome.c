#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: pointer to pointer to the head of the list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *current = *head;
    int length = 0, i = 0;
    int *array;

    if (!head || !*head)
        return (1);

    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    array = malloc(sizeof(int) * length);
    if (!array)
        return (0);

    current = *head;
    while (current != NULL)
    {
        array[i] = current->n;
        current = current->next;
        i++;
    }

    for (i = 0; i < length / 2; i++)
    {
        if (array[i] != array[length - i - 1])
        {
            free(array);
            return (0);
        }
    }

    free(array);
    return (1);
}
