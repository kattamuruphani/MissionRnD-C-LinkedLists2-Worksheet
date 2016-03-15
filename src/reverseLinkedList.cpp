/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node *reverse_SLL_tail_recursive(struct node* head, struct node *last);
//struct node *reverse_list(struct node*,stuct node*,struct node*);
struct node *reverse_list(struct node*, struct node*);



struct node {
	int num;
	struct node *next;
}*end;



struct node * reverseLinkedList(struct node *head)
{
	if (head == NULL)
		return  NULL;
	
	struct node *newhead;
	newhead = (struct node*)malloc(sizeof(struct node));
	//reverse_list(NULL,head,&newhead);
	newhead=reverse_list(NULL, head);
	return newhead;
}

/*
void reverse_list(struct node *head, struct node *curr, struct node **end){
	if (curr->next== NULL){
		end = curr;
		curr->next = head;
	}
	else{
		reverse_list(curr, curr->next, end);
		curr->next = head;

	}

}
*/
struct node *reverse_list(struct  node *head, struct node *curr){
	if (curr->next == NULL){
		
		end = (struct node*)malloc(sizeof(struct node));
		end = curr;
		curr->next = head;
	}
	else{
		reverse_list(curr, curr->next);
		curr->next = head;
		if (head == NULL){
			return end;
		}

	}
}