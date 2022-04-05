// Demo of Singly Linked List in C
# include <stdio.h>
# include <stdlib.h>  // stdlib header file is used for malloc()

struct singly_node{
  int data;
  struct singly_node *next;
};


int main() {
  printf("\n*** Singly Linked List with 3 nodes***");
  struct singly_node *head = NULL, *new_node, *temp;
  for (int counter = 0; counter < 3; counter++) {
    //Allocating memory for the node using dynamic memory allocation
    new_node = (struct singly_node *)malloc(sizeof(struct singly_node));
    new_node->data = counter;
    new_node->next = NULL;
    if (head == NULL)
      head = temp = new_node;
    else {
      temp->next = new_node;
      temp = new_node;
    }  // end of else
  }  // end of for loop
  
  printf("\n*** Traversing the elements in the Singly Linked List***");
  temp = head;
  while (temp != NULL) {
    printf("\n%d", temp->data);
    temp = temp->next;
  } // end of while
  
} // end of main
