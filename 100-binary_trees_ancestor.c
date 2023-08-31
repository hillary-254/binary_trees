#include "binary_trees.h"

/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to the lowest common ancestor, or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	const binary_tree_t *node1 = first;
	const binary_tree_t *node2 = second;

	while (node1 != node2)
	{
		node1 = (node1 != NULL) ? node1->parent : second;
		node2 = (node2 != NULL) ? node2->parent : first;
	}

	return ((binary_tree_t *)node1);
}
