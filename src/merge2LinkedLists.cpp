/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

void swap(struct node *node1, struct node *node2){
	int temp;
	temp = node1->num;
	node1->num = node2->num;
	node2->num = temp;
}

struct node *merge(struct node *head1, struct node *head2)
{
	struct node *temp3;
	if (head2->num < head1->num){
		temp3 = head1;
		head1 = head2;
		head2 = temp3;
	}
	struct node *current1 = head1, *current2 = head2, *temp1, *temp2;
	temp1 = current1->next;
	temp2 = current2->next;
	while (temp1 != NULL && temp2 != NULL)
	{
		if (current1->num <= current2->num && current2->num <= temp1->num && temp2 != NULL)
		{
			current1->next = current2;
			current2->next = temp1;
			current1 = current2;
			current2 = temp2;
			temp2 = temp2->next;
		}
		else
		{
			current1 = temp1;
			temp1 = temp1->next;
		}
	}
	if (temp1 != NULL&&temp2 == NULL){
		while (current1->num < current2->num&&temp1 != NULL){
			current1 = current1->next;
			temp1 = temp1->next;
		}
		if (current1->num > current2->num){
			swap(current1, current2);
		}
		current1->next = current2;
		current2->next = temp1;
		current1 = current2;
	}
	else if (temp2 != NULL&&temp1 == NULL){
		current1->next = current2;
	}
	return head1;
}

struct node * merge2LinkedLists(struct node *head1, struct node *head2)
{
	struct node *res,*head;
	if (head1 == NULL&&head2 == NULL){
		return NULL;
	}
	else if (head1 == NULL){
		return head2;
	}
	else if (head2 == NULL){
		return head1;
	}
	else{
		head1 = merge(head1, head2);
		}
	return head1;
}