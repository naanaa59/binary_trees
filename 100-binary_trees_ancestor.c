#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 * Return: pointer to the lowest common ancestor node of the two given nodes.
 * otherwise it returns NULL.
 */

binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *fstpar, *secpar;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	fstpar = first->parent;
	secpar = second->parent;

	if (!fstpar || first == secpar || (!(fstpar->parent) && secpar))
		return (binary_trees_ancestor(first, secpar));
	else if (!secpar || fstpar == second || (fstpar && !(secpar->parent)))
		return (binary_trees_ancestor(fstpar, second));
	return (binary_trees_ancestor(fstpar, secpar));
}
