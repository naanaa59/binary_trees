#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: pointer to the root node of the tree.
 * Return: the size of a binary tree.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->right) + binary_tree_size(tree->left));
}


/**
 * is_completed_helper - checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 * @index: the index of the node.
 * @nodes: the size of nodes.
 * Return: 1 if the binary tree is completed, 0 otherwise.
 */
is_completed_helper(const binary_tree_t *tree, size_t index, size_t nodes)
{
	if (!tree)
		return (1);
	if (index >= nodes)
		return (0);
	return (is_completed_helper(
				tree->left, 2 * index + 1, nodes) && is_completed_helper(
					tree->left, 2 * index + 2, nodes));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if the binary tree is completed, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_completed_helper(tree, 0, binary_tree_size(tree)));
}
