/*

int	closest_pushable(t_node *stack, int pivot)
{
	t_node	*front;
	t_node	*back;
	int		front_counter;
	int		back_counter;

	front = stack->next;
	front_counter = 0;
	while (front != NULL && front_counter < (get_list_size(stack) - 1) / 2)
	{
		if (front->content < pivot)
			break ;
		front_counter++;
		front = front->next;
	}

	back = get_last_node(stack);
	back_counter = 0;
	while (back != NULL && back_counter < (get_list_size(stack) - 1) / 2)
	{
		if (back->content < pivot)
			break ;
		back_counter++;
		back = back->previous;
	}
	if (front_counter < back_counter)
		return (1);
	return (0);
}

*/