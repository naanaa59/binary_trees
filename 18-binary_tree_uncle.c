#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 *
 * @node: a pointer to the node to find the sibling
 *
 * Return: A pointer to the sibling node or NULL if parent or node NULL
 * if node has no sibling return NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
	{
		if (node->parent->right)
		{
			return (node->parent->right);
		}
	}
	if (node->parent->right == node)
	{
		if (node->parent->left)
		{
			return (node->parent->left);
		}
	}
	return (NULL);

}

/**
 * binary_tree_uncle - finds the uncle of a node
 *
 * @node: A pointer to the node to find the uncle
 *
 * Return: The pointer of the uncle or NULL if node is NULL or has no uncle
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	uncle = binary_tree_sibling(node->parent);
	return (uncle);
}
