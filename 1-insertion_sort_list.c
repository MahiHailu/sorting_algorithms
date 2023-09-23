#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using an insertion sort algorithm.
 * @list: doubly linked list of integers to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *lead, *follow, *new, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;

	/* Dance start first from the left */
	follow = (*list);
	/* And the next dancer heading to the house on the right */
	lead = (*list)->next;
	while (lead)
	{
		new = lead->next;
		while (follow && lead->n < follow->n)
		{
			/* swap lead and follow positions */
			if (follow->prev)
				follow->prev->next = lead;
			else
				/* Once to lead reaches the house on the left,towards it this time */
				*list = lead;
			if (lead->next)
				lead->next->prev = follow;
			temp = lead->next;
			lead->next = follow;
			lead->prev = follow->prev;
			follow->next = temp;
			follow->prev = lead;
			print_list(*list);
			/* compare next pair, flowing the left house */
			follow = lead->prev;
		}
		/* lead sorted to left, new cycle starts @ right leading edge */
		lead = new;
		if (lead)
			follow = lead->prev;
	}
}
