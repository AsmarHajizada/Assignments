#include <stdio.h> 
#include <string.h>
#include <stdbool.h> 
#include <stdlib.h> 

bool Err = false;

typedef struct node 
{
	char name[100];   
	struct node * next;
} node_p;


//printing the list 
void printList(node_p *iter)
{
	while (iter != NULL)
	{
		printf("%s ", iter -> name);
		iter = iter -> next;
		if(iter != NULL)
		printf(", ");    
	}
	printf("\n"); 
}

//removing the first person from the queue
void removeFirst(node_p **head)
{
	if (*head == NULL)
	{
		printf("There's no one in the queue.\n");
		return;
	}
	node_p * next_person = (*head) -> next;
	free(*head);
	*head = next_person;                                                   
}


void addToTail(node_p **head,  char *key)
{
	node_p *new_node = (node_p *) malloc(sizeof(node_p));
	node_p *last = *head;
	strcpy(new_node -> name, key);
	new_node -> next = NULL;

	
	while(last->next != NULL)	
	{
     	last = last -> next;
	}
	last -> next = new_node;
}


void lucky(node_p ** head, char *key)
{
	node_p *temp = *head;
	node_p *prev;

	if (temp != NULL && strcmp(temp -> name, key) == 0) { 
     	*head = temp->next;  
     	free(temp);              
     	return; 
	} 
	while (temp != NULL && strcmp(temp -> name, key) != 0) { 
     	prev = temp; 
     	temp = temp->next; 
	} 
	if (temp == NULL){ 
     	printf("There is no such user \n");
     	Err = true;
     	return; 
	}
	prev->next = temp->next; 
	free(temp); 
}


int main()
{
	node_p *head = (node_p *) malloc(sizeof(node_p));
	
	strcpy(head -> name, "Turgut");
	head -> next = NULL;

	char input[256];
	bool quit = 0;
	
	node_p *tail = head;
	
	addToTail(&tail, "Nazrin");
	addToTail(&tail, "Nigar");
	addToTail(&tail, "Kamran");
	addToTail(&tail, "Eljan");
	
	printList(head);
	printf("\n");
	
	while(!quit)
	{
		printf("Enter your command: ");
		scanf("%s", input);
		if (strcmp(input, "quit") == 0)
		{
			quit = 1;    	
		}
		else if (strcmp(input, "admit") == 0)
		{
			removeFirst(&head);
		}
		else
		{
			lucky(&head, input);
			if(!Err)	
			{
				addToTail(&head, input);
			}
			Err = false;
		}
		printList(head); 
	}
	free(head);
	head = NULL; 
	
	
	return 0;
}
