#include "binary_trees.h"
#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree.
 * Return: the height of a binary tree.
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree || (!tree->right && !tree->left) )
        return (0);
    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree.
 * Return: 1 if binary tree isn't perfect, 0 otherwise.
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t left_height = 0, right_height = 0;

    if (!tree || (!(tree->right) || !(tree->left)))
        return (0);
    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);
    if (left_height == right_height)
        return (1);
    return (binary_tree_is_perfect(tree->right) && binary_tree_is_perfect(tree->left));
}
