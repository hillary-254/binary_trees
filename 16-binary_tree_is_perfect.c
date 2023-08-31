#include "binary_trees.h"

/**
 * find_depth - Finds the depth of the leftmost leaf in a binary tree
 * @node: Pointer to the node from which to start measuring the depth
 * Return: The depth of the leftmost leaf in the binary tree
 */
int find_depth(const binary_tree_t *node)
{
	int d = 0;

	while (node != NULL)
	{
		d++;
		node = node->left;
	}
	return (d);
}

/**
 * is_perfect_rec - Recursively checks if a binary tree is perfect
 * @root: Pointer to the root node of the tree to check
 * @d: The depth of the leftmost leaf in the tree
 * @level: The current level in the tree (root is level 0)
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int is_perfect_rec(const binary_tree_t *root, int d, int level)
{
	if (root == NULL)
		return (1);

	if (root->left == NULL && root->right == NULL)
		return (d == level + 1);

	if (root->left == NULL || root->right == NULL)
		return (0);

	return (is_perfect_rec(root->left, d, level + 1) &&
	is_perfect_rec(root->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (tree == NULL)
		return (0);

	d = find_depth(tree);
	return (is_perfect_rec(tree, d, 0));
}
