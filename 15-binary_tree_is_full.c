#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: pointer to the root node of the tree.
 * Return: 0 if binary tree isn't full, 1 otherwise.
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    if (!(tree->right) && !(tree->left))
        return (1);
    return (binary_tree_is_full(tree->right) && binary_tree_is_full(tree->left));
}
