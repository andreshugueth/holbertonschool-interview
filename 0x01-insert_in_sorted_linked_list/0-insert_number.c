#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: head of the linked list
 * @number: number to be inserted
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current, *new;
	int prev_number;

	if (!head)
		return (NULL);

	current = *head;
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	while (current)
	{
		prev_number = current->n;
		if (prev_number < number && current->next->n > number)
		{
			new->n = number;
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
	}
	return (NULL);
}
