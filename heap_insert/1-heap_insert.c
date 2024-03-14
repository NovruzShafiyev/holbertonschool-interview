#include "binary_trees.h"

/**
 * heapify_up - Restores the Max Heap property after insertion
 * @node: Pointer to the newly inserted node
 */
void heapify_up(heap_t *node)
{
    int temp;
    heap_t *parent;

    while (node->parent && node->n > node->parent->n)
    {
        parent = node->parent;
        temp = parent->n;
        parent->n = node->n;
        node->n = temp;
        node = parent;
    }
}

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
    parent = *root;
    while (parent->left != NULL && parent->right != NULL)
    {
        if (parent->left != NULL && parent->right != NULL)
            parent = parent->left;
        else
            parent = parent->right;
    }

    /* Insert the new node as left child if the parent's left child is NULL */
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
