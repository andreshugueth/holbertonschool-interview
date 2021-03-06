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

	current = *head;
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	if (!*head)
	{
		new->n = number;
		new->next = NULL;
		*head = new;
		return (new);
	}
	new->n = number;
	while (current)
	{
		prev_number = current->n;
		if (prev_number >= number)
		{
			new->next = current;
			*head = new;
			return (new);
		}
		else if(!current->next && prev_number <= number)
		{
			current->next = new;
			new->next = NULL;
			return (new);
		}
		else if (prev_number <= number && current->next->n >= number)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
	}
	return (NULL);
}
