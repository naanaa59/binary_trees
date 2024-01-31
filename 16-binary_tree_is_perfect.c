#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: The size of the tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = binary_tree_height(tree->left) + 1;
	if (tree->right)
		right_height = binary_tree_height(tree->right) + 1;

	return (left_height > right_height ? left_height : right_height);

}

/**
 * binary_tree_is_perfect - Checks if a inary tree is perfect
 *
 * @tree: A pointer to the root node of the tree
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int per_right, per_left;
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	if (r_height == l_height)
	{
		if (!tree->right && !tree->left)
			return (1);
		if (tree->right && tree->left)
		{
			per_left = binary_tree_is_perfect(tree->left);
			per_right = binary_tree_is_perfect(tree->right);
			return (per_left && per_right);
		}
	}
	return (0);


}

