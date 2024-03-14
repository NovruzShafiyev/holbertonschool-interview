#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the new node
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    /* Create a new node */
    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    /* If the heap is empty, the new node becomes the root */
    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    /* Find the parent of the new node */
    parent = find_parent(*root);

    /* If the parent's left child is NULL, insert the new node as left child */
    if (parent->left == NULL)
        parent->left = new_node;
    /* Otherwise, insert the new node as right child */
    else
        parent->right = new_node;

    /* Set the parent of the new node */
    new_node->parent = parent;

    /* Restore the Max Heap property */
    heapify_up(new_node);

    return (new_node);
}
