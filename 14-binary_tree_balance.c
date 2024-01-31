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
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: A pointer to the root node of the tree
 *
 * Return: The balance factor or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int bal_factor = 0, l_height = -1, r_height = -1;

	if (tree == NULL)
		return (0);

	if (tree->left)
		l_height = binary_tree_height(tree->left);
	if (tree->right)
		r_height = binary_tree_height(tree->right);
	bal_factor = l_height - r_height;

	return (bal_factor);
}
