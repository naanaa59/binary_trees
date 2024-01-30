#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: ponter to the root node of the tree.
 * Return: the height of a binary tree.
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree || (!tree->right && !tree->left) )
        return(0);
    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return ((left_height > right_height ? left_height : right_height) + 1);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance
 * factor.
 * Return: 0 if tree is NULL, othewise it'll return the balance factor.
*/

int binary_tree_balance(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (!tree || (!(tree->left) && !(tree->right)))
        return (0);
    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);
    if (!tree->left)
        left_height = -1;
    if (!tree->right)
        right_height = -1;
    return (left_height - right_height);

}
