#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node {

	int val;
	struct node *next;
};

struct node *head = NULL;
struct node *curr = NULL;

struct node *create_list(int val){

	printf("\n Creating list with headnode as [%d]\n", val);
	struct node *ptr = (struct node*) malloc (sizeof(struct node));

	if(NULL == ptr){

		printf("\n Node creation failed \n");
		return NULL;
	}

	ptr -> val = val;
	ptr -> next = NULL;

	head = curr = ptr;
	return ptr;
}

struct node * add_to_list(int val, bool add_to_end){

	if(NULL == head){

		return (create_list(val));
	}

	if(add_to_end)
		printf("\n Adding node to end of list with value [%d]\n", val);

	else
		printf("\n Adding node to beginning of list with value [%d]\n", val);

	struct node *ptr = (struct node*) malloc (sizeof(struct node*));
	if(NULL == ptr){

		printf("\n Node creation failed \n");
		return NULL;
	}

	ptr -> val = val;
	ptr -> next = NULL;

	if(add_to_end){

		curr -> next = ptr;
		curr = ptr;
	}
	else{

		ptr -> next = head;
		head = ptr;
	}

	return ptr;

}

struct node * search_in_list(int val, struct node **prev){

	struct node * ptr = head;
	struct node * tmp = NULL;
	bool found = false;

	printf("\n Searching the list for value [%d] \n", val);

	while(ptr != NULL){

		if (ptr -> val == val) {

			found = true;
			break;
		}

		else{

			tmp = ptr;
			ptr = ptr -> next;
		}
	}
	if (true == found){
		
		if(prev)
			*prev = tmp;
		return ptr;
	}

	else
		return NULL;
}

int delete_from_list(int val){

	struct node *prev = NULL;
	struct node *del = NULL;

	printf("\n Deleting value [%d] from list\n", val);

	del = search_in_list(val, &prev);
	
	if(del == NULL)
		return -1;
	else{
		if (prev != NULL)
			prev -> next = del -> next;
		if (del == curr)
			curr = prev;
		else if(del == head)
			head = del -> next;
	}

	free(del);
	del = NULL;

	return 0;
}

void print_list(void){

	struct node *ptr = head;

	printf("\n -----Printing List Start------- \n\n");

	while(ptr != NULL){

		printf("[%d] \n", ptr -> val);
		ptr = ptr -> next;
	}

	printf("\n -----Printing List End--------- \n");

	return;
}

int main(void){

	int i = 0, ret = 0;
	struct node *ptr = NULL;

	print_list();

	for(i = 5; i < 10; i++)
		add_to_list(i, true);

	print_list();

	for(i = 4; i > 0; i--);
		add_to_list(i, false);

	print_list();

	for(i = 1; i < 10; i +=4){

		ptr = search_in_list(i, NULL);
		if (NULL == ptr)
			printf("\n Search [val = %d] failed, no such element found\n", i);
		else
			printf("\n Search [val = %d] passed \n", i);

		print_list();

		ret = delete_from_list(i);

		if (ret != 0)
			printf("\n delete [val = %d] failed, no such element found\n", i);
		else
			printf("\n delete [val = %d] passed \n", i);

		print_list();
	}
	
	return 0;
}

