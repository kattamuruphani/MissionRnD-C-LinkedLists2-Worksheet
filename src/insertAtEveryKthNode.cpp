/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head==NULL||K<=0)
		return NULL;
	else{
		int i, count=0;
		struct node *temp,*curr;
		curr = head;
		while (curr != NULL){
			for (i = 1; i < K&&curr != NULL; i++){
				curr = curr->next;
			}
	
			if (i == K&&curr!=NULL){
				temp = (struct node*)malloc(sizeof(struct node));
				temp->num = K;
				temp->next = curr->next;

				curr->next = temp;
				curr = curr->next;
				curr = curr->next;
			}
		}
	}
	return head;
}
