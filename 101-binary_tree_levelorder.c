#include "binary_trees.h"


int helper(const binary_tree_t *tree, void (*func)(int), int level);

/**
 * helper - helps process the level for each node
 *
 * @tree: tree
 *
 * @func: A pointer to a function
 *
 * @level: the level of the node
 *
 * Return: 1 if node got processed
 */

int helper(const binary_tree_t *tree, void (*func)(int), int level)
{
	int l_helper, r_helper;

	if (tree == NULL)
		return (0);
	if (level == 1)
	{
		func(tree->n);
		return (1);
	}
	else if (level > 1)
	{
		l_helper = helper(tree->left, func, level - 1);
		r_helper = helper(tree->right, func, level - 1);
		return (l_helper || r_helper);

	}
	return (0);
}
/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 *
 * @tree: A pointer to the root node of the tree
 *
 * @func: A pointer to a function to call for each node
 *
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int level;

	if (tree == NULL || func == NULL)
		return;
	for (level = 1;; level++)
	{
		if (helper(tree, func, level) == 0)
			break;
	}
}


