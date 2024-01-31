#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 *
 * @tree: A pointer to the root node of the tree
 *
 * Return: the count of leaves or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t r_leaves, l_leaves;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL  && tree->right == NULL)
		return (1);

	l_leaves = binary_tree_leaves(tree->left);
	r_leaves = binary_tree_leaves(tree->right);

	return (l_leaves + r_leaves);
}
