#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	/* Recursively measure the height of left and right subtrees */
	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	/* Return the greater height */
	return (left_height > right_height ? left_height : right_height);
}

/**
 * is_perfect_helper - Helper function to check if a tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 * @height: Height of the tree.
 * @level: Current level during traversal.
 *
 * Return: 1 if tree is perfect, 0 otherwise.
 */
int is_perfect_helper(const binary_tree_t *tree, size_t height, size_t level)
{
	if (tree == NULL)
		return (1);

	/* Check if the node is a leaf node at the correct level */
	if (tree->left == NULL && tree->right == NULL)
		return (height == level + 1);

	/* Check if the node has both children */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Recursively check left and right subtrees */
	return (is_perfect_helper(tree->left, height, level + 1) &&
		is_perfect_helper(tree->right, height, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;

	if (tree == NULL)
		return (0);

	/* Calculate the height of the tree */
	height = binary_tree_height(tree);

	/* Check if the tree is perfect using the helper function */
	return (is_perfect_helper(tree, height, 0));
}
