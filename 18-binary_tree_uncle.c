#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: Pointer to the node to find the uncle.
 *
 * Return: Pointer to the uncle node. If node is NULL or has no uncle, return NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if the node or its parent is NULL */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* If the node's parent is the left child, return the right child of the grandparent */
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);

	/* If the node's parent is the right child, return the left child of the grandparent */
	if (node->parent == node->parent->parent->right)
		return (node->parent->parent->left);

	/* If the node has no uncle, return NULL */
	return (NULL);
}
