#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: ponter to the root node of the tree.
 * Return: the height of a binary tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree || (!tree->right && !tree->left))
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}
/**
 * binary_tree_levelorder_helper - helps
 * the binary_tree_levelorder function
 * to be printed in a good order.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node.
 * The value in the node must
 * be passed as a parameter to this function.
 * @level: the level of the tree.
 */
void binary_tree_levelorder_helper(
		const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (!tree)
		return;
	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		binary_tree_levelorder_helper(tree->left, func, level - 1);
		binary_tree_levelorder_helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node.
 * The value in the node must
 * be passed as a parameter to this function.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, height = binary_tree_height(tree);

	if (!tree || !func)
		return;

	for (level = 0; level <= height; level++)
		binary_tree_levelorder_helper(tree, func, level);
}
