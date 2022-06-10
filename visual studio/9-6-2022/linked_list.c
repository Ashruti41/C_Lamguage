#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	char data;
	struct node *nextPtr;
}node_t;

typedef node_t *ListNodePtr;

//prototypes
void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char val);
void insertAtBeginning(ListNodePtr *head, char val);
char delete(ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);

int main(void) {
	ListNodePtr head =NULL; //initially there are no nodes
	int choice = 0; //user's choice
	char item = '\0';  //char entered by user

	//display the menu
	printf("ENter your choice:\n"
		" 1 to insert an element into the list in alphabetical order.\n"
		" 2 to insert an element at the end of the list. \n"
		" 3 to insert an element at the beginning of the list. \n"
		" 4 to delete an element from the list. \n"
		" 5 to delete an element from the beggining of the list.\n"
		" 6 to end. \n" );

	printf(":: ");
	scanf("%d",&choice);

	//loop while user does not choose 3
	while (choice!=6) {
		switch(choice) {
			case 1:
				printf("Enter a character: ");
				scanf("\n%c",&item);
				insert(&head,item);
				printList(head);
				break;

			case 2:
				printf("Enter a character: ");
				scanf("\n%c",&item);
				insertAtEnd(&head,item);
				printList(head);
				break;

			case 3:
				printf("Enter a character: ");
				scanf("\n%c",&item);
				insertAtBeginning(&head,item);
				printList(head);
				break;

			case 4:
				//if list is not empty
				if(!isEmpty(head)) {
					printf("Enter character to be deleted: ");
					scanf("\n%c",&item);

				//if character is found, remove it
					if(delete (&head, item)) {
						printf("%c deleted.\n",item);
						printList(head);
					}
					else {
						printf("%c not found.\n\n",item);
					}
				}
				else {
					printf("List is empty.\n\n");
				}
			break;

			case 5:
				if(!isEmpty(head)) {
						deleteAtBeginning(&head);
						printf("%c deleted.\n",item);
						printList(head);
				}
				else {
					printf("List is empty.\n\n");
				}

			break;

			default:
				printf("Invalid choice.\n\n");
				printf("Enter your choice:\n"
					" 1 to insert an element into the list.\n"
					" 2 to delete an element from the list.\n"
					"3 to end.\n");
			break;
		}

		printf("? ");
		scanf("%d", &choice);
	}
	printf("End of run.\n");
	return 0;
}

void insertAtBeginning(ListNodePtr *head, char val) {
	ListNodePtr new_node = malloc(sizeof(node_t));
	new_node->data = val;
	new_node->nextPtr = *head;
	*head = new_node;
}

void insertAtEnd(ListNodePtr *head, char val) {
	ListNodePtr current = *head;
		if(current!=NULL) {
		while(current->nextPtr != NULL) {
			current = current->nextPtr;
		}

	//now we can add a new variable
		current->nextPtr = malloc(sizeof(node_t));
		current->nextPtr->data = val;
		current->nextPtr->nextPtr = NULL;
		}
		else {
			current = malloc(sizeof(node_t));
			current->data = val;
			current->nextPtr = NULL;
			*head = current;
		}
}

void insert(ListNodePtr *head, char value) {
	ListNodePtr newPtr;   //pointer to new node
	ListNodePtr previousPtr; //pointer to previous node in list
	ListNodePtr currentPtr;   //pointer to current node in list

	newPtr = malloc(sizeof(node_t));   //create node

	if(newPtr !=NULL) {     //is space avilable
		newPtr->data = value;       //place value in node
		newPtr->nextPtr = NULL;  //node does not link to another node

		previousPtr = NULL;
		currentPtr = *head;

		//loop to find the correct location in the list
		while(currentPtr!=NULL && value >currentPtr->data)  {
			previousPtr = currentPtr; 
			currentPtr = currentPtr->nextPtr;

		}

		//insert new node at beginning of list
		if(previousPtr ==NULL) {
			newPtr->nextPtr =*head;
			*head = newPtr;
		}
		else{   //insert new node between previousPtr and currentPtr
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	
	else{
		printf("%c not inserted. No memory available.\n",value);
	}
}

void deleteAtBeginning(ListNodePtr *head)  {
	ListNodePtr tempPtr = NULL;
	if(head == NULL) {
		return;
	}

	else {
		tempPtr = *head;  //hold onto node being removed
		*head = (*head)->nextPtr; //de-thread the node
		free(tempPtr);
	}
}

//delete a list element
char delete(ListNodePtr *head, char value) {
	ListNodePtr previousPtr; //pointer to previous node in list
	ListNodePtr currentPtr;  //pointer to current node in list
	ListNodePtr tempPtr;   //temporary node pointer

	//delete first node
	if(value == (*head)->data) {
		tempPtr = *head;   //hold onto being removed
		*head = (*head) ->nextPtr;    //de-thread the node
		free(tempPtr); 
		return value;
	}
	else {
		previousPtr = *head;
		currentPtr = (*head)->nextPtr;

	//loop to find the correct location in the list
		while(currentPtr !=NULL && currentPtr->data!= value) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

	//delete node at currentPtr
		if(currentPtr !=NULL) {
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			return value;
		}
	}
	return '\0';
}

//print the list
void printList(ListNodePtr currentPtr) {

	//if list is empty
	if(currentPtr ==NULL) {
		printf("List is empty.\n\n");
	}

	else {
		printf("The list is: \n");

	//while not the end of the list
	while(currentPtr !=NULL) {
		printf("%c --->", currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}
	printf("NULL\n\n");
	}
}

int isEmpty(ListNodePtr head) {
	return head == NULL;
}
 
		
		


