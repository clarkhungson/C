#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node * tail;
	int data;
};
void addList(int data, struct Node *head){
	struct Node * newNode;
	newNode -> data = data;
	newNode -> tail = NULL;

}
void showList(struct Node *head){

}

void removeList(struct Node *head){

}

int main(){
	struct Node * head;
	head -> data = NULL;
	head -> tail = NULL;
	if (head == NULL) printf("NULL\n");

	printf("Have a nice day!\n");
	return 0;
}