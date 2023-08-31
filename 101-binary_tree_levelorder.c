#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through binary tree using levelorder traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *));
	size_t front = 0, rear = 0;

	queue[rear] = (binary_tree_t *)tree;
	rear++;

	while (front < rear)
	{
		binary_tree_t *node = queue[front];

		front++;
		func(node->n);
		if (node->left != NULL)
		{
			queue = realloc(queue, sizeof(binary_tree_t *) * (rear + 1));
			queue[rear] = node->left;
			rear++;
		}
		if (node->right != NULL)
		{
			queue = realloc(queue, sizeof(binary_tree_t *) * (rear + 1));
			queue[rear] = node->right;
			rear++;
		}
	}
	free(queue);
}
