#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: A pointer to the root node
 *
 * Return: 1 is tree is full or 0 if not full or tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_full, right_full;

	if (tree == NULL)
		return (0);

	if ((!tree->left && tree->right) || (!tree->left && tree->right))
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	left_full = binary_tree_is_full(tree->left);
	right_full = binary_tree_is_full(tree->right);

	return (left_full && right_full);
}
