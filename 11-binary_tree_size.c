#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure the size
 *
 * Return: the size or NULL if tree is null
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_tree = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
	{
		size_tree += binary_tree_size(tree->left);
	}
	if (tree->right)
	{
		size_tree += binary_tree_size(tree->right);
	}
	return (size_tree + 1);
}
