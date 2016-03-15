/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) 
{
	if (head == NULL)
		return -1;
	else{
		struct node *curr, *temp;
		int i, j, k=0,median;
		curr = head;
		for (i = 0; curr != NULL;curr=curr->next){
			i++;
		}
		
		if (i % 2 == 0)
			k = 1;
		i /= 2;
		curr = head;
		if (k==0)
			for (j = 1; j <= i; j++, curr = curr->next){
				 
			}
		else{
			for (j = 1; j < i; j++, curr = curr->next){

			}
		}
		median = curr->num;
		if (k == 1){
			curr = curr->next;
			median += curr->num;
			median /= 2;
		}
		return median;


	}
}
