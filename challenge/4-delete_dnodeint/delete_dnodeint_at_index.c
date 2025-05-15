#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node = *head;
	unsigned int i;

	if (!head || !*head)
		return (-1);

	/* Go to the node at index */
	for (i = 0; node && i < index; i++)
		node = node->next;

	if (!node)
		return (-1);

	/* If node to delete is head */
	if (node->prev)
		node->prev->next = node->next;
	else
		*head = node->next;

	if (node->next)
		node->next->prev = node->prev;

	free(node);
	return (1);
}