// Demo of Doubly Linked List in C
# include <stdio.h>
# include <stdlib.h>  // stdlib header file is used for malloc()

struct doubly_node{
  int data;
   struct doubly_node *next, *prev;
};

int main() {
  printf("\n*** Doubly Linked List with 3 nodes***");
  struct doubly_node *head = NULL, *new_node, *temp;
  for (int counter = 0; counter < 3; counter++) {
    //Allocating memory for the node using dynamic memory allocation
    new_node = (struct doubly_node *)malloc(sizeof(struct doubly_node));
    new_node->data = counter;
    new_node->next = new_node->prev= NULL;
    if (head == NULL) {
      head = temp = new_node;
	  new_node->prev = head;
	} // end of if
    else {
      temp->next = new_node;
	  new_node->prev = temp;
      temp = new_node;
    }  // end of else
  }  // end of for loop
  
  printf("\n*** Traversing the elements in the Doubly Linked List***");
  temp = head;
  while (temp != NULL) {
    printf("\n%d", temp->data);
    temp = temp->next;
  } // end of while
  
} // end of main
