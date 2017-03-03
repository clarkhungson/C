#include <stdio.h>
#include <stdlib.h>

struct node_s {
	int data;
	struct node_s * next_node;
};
typedef struct node_s node_t;

int list_len = 0;
node_t *head = NULL;

node_t *create_node(int num) {
	node_t *node = (node_t *) malloc(sizeof(node_t));
	node->data = num;
	return node;
}

int is_empty() {
	if(head == NULL) {
		return 1;
	}
	return 0;
}

node_t *get_node_at_index(int index) {
	if (index < 0 || index > list_len - 1) {
		printf("Index must be in range [0, %d] \n", list_len - 1);
		return NULL;
	}
	else
	{
		int i;
		node_t *temp = head;
		for (i = 0; i < index; i++)
		{
			temp = temp->next_node;
		}
		return temp;
	}

}

void insert_at_begin(node_t *node) {
	if (head == NULL) {
		head = node;
	}
	else
	{
		node->next_node = head->next_node;
		head->next_node = node;
	}
	list_len++;
	printf("Insert %d at begin\n", node->data);
}

void insert_at_index(node_t *node, int index)
{
	if (index == 0)
	{
		insert_at_begin(node);
	}
	else
	{
		node_t *node_of_index = get_node_at_index(index - 1);
		if(node_of_index != NULL)
		{
			node->next_node = node_of_index->next_node;
			node_of_index->next_node = node;
			printf("Insert %d at index %d\n", node->data, index);
			list_len++;
		}
	}
}

void delete_at_index(int index)
{
	node_t *deleted_node;
	if(index == 0)
	{
		if(list_len == 0)
		{
			printf("Invalid index\n");
		}
		else
		{
			deleted_node = head;
			head = head -> next_node;
			free(deleted_node);
			printf("Delete node at index %d\n", index);
			list_len--;
		}
	}
	else
	{
		node_t *node_of_index = get_node_at_index(index - 1);
		if(node_of_index != NULL)
		{
			deleted_node = node_of_index->next_node;
			node_of_index->next_node = deleted_node->next_node;
			free(deleted_node);
			printf("Delete node at index %d\n", index);
			list_len--;
		}
	}
}

void delete_all()
{
	node_t *temp;
	while (!is_empty())
	{
		temp = head;
		head = temp->next_node;
		free(temp);
	}
	list_len = 0;
	printf("Delete all elements..\n");
}

void print_list()
{
	node_t *temp = head;
	printf("Linked list is:  ");
	if(is_empty())
	{
		printf("Empty\n");
	}
	else
	{
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next_node;
		}
	}
	printf("\n-----------------------------\n");
}

int main()
{
	// Initial data for linked list
	int arr[5] = {1, 2, 3, 4, 5};
	int i;
	print_list();

	// Create linked list
	for (i = 0; i < 5; i++)
	{
		node_t *new_node = create_node(arr[i]);
		insert_at_index(new_node, i);
	}
	print_list();

	// Insert index
	node_t *new_node = create_node(10);
	insert_at_index(new_node, 3);
	print_list();

	// Delete node at index 2
	delete_at_index(2);
	print_list();

	//Free linked list
	delete_all();
	print_list();


	return 0;
}