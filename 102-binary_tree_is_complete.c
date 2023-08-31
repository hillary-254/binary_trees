#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	binary_tree_t *queue[1024];
	int rear = 0, front = 0;
	binary_tree_t *temp_node = NULL;
	int flag = 0;

	queue[rear] = (binary_tree_t *)tree;
	rear++;

	while (front != rear)
	{
		temp_node = queue[front];
		front++;

		if (temp_node->left)
		{
			if (flag == 1)
				return (0);

			queue[rear] = temp_node->left;
			rear++;
		}
		else
			flag = 1;

		if (temp_node->right)
		{
			if (flag == 1)
				return (0);

			queue[rear] = temp_node->right;
			rear++;
		}
		else
			flag = 1;
	}

	return (1);
}
