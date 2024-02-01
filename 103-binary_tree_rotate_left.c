#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 *
 * @tree: A pointer to the root node of the tree to rotate
 *
 * Return: A pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || !tree->right)
		return (NULL);
	if (tree->right->left)
		tree->right->left->parent = tree;

	new_root = tree->right;
	new_root->parent = NULL;
	tree->right = new_root->left;
	new_root->left = tree;
	tree->parent = new_root;

	return (new_root);

}
