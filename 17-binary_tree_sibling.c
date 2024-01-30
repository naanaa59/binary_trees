#include "binary_trees.h"
/**
 * binary_tree_sibling - finds the sibling of a node.
 * @node: pointer to the node to find the sibling.
 * Return: NULL if there was no siblings or the tree was empty.
*/

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (!node || !(node->parent) || !(node->parent->left) || !(node->parent->right))
        return (NULL);

    if (node == node->parent->left)
        return (node->parent->right);
    return (node->parent->left);
}
