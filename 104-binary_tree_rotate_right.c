#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 *
 * @tree: A pointer to the root node
 *
 * Return: A pointer to the new root one rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || !tree->left)
		return (NULL);

	if (tree->left->right)
		tree->left->right->parent = tree;

	new_root = tree->left;
	new_root->parent = NULL;
	tree->left = new_root->right;
	new_root->right = tree;
	tree->parent = new_root;

	return (new_root);
}

