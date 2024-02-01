#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the
 * right-child of another node.
 * @parent: pointer to the node to insert the right-child in.
 * @value: value to store in the new node.
 * Return: the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (new_node == NULL || parent == NULL)
		return (NULL);
	new_node->n = value;
	new_node->right = NULL;
	new_node->left = NULL;

	if (parent->right)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;
	return (new_node);
}
