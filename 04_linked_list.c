# include <stdio.h>
# include <stdlib.h>

int choice;

struct singly_node{
  int data;
   struct singly_node *next;
};

struct doubly_node{
  int data;
   struct doubly_node *next, *prev;
};

void menu(void) {
  printf("\n1. Singly Linked List \n2. Doubly Linked List \n3. Circular Linked List \n4. Exit");
  printf("\nChoose an option: ");
  scanf("%d", &choice);
}

void singly_linked_list(){
  printf("\n*** Singly Linked List ***");
  int choice = 1;
  struct singly_node *head = NULL, *new_node, *temp;
  while (choice == 1) {
    new_node = (struct singly_node *)malloc(sizeof(struct singly_node));
    printf("\nEnter node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (head == NULL)
      head = temp = new_node;
    else {
      temp->next = new_node;
      temp = new_node;
    }
    printf("\nTo insert a new node press 1 else any other integer: ");
    scanf("%d", &choice);
  } 

  printf("\nThe elements in the Singly Linked list are...");
  temp = head;
  while (temp != NULL) {
    printf("\n%d", temp->data);
    temp = temp->next;
  }
}

void doubly_linked_list(){
// Incomplete code
  printf("\n*** Doubly Linked List ***");
  int choice = 1;
  struct doubly_node *head = NULL, *new_node, *temp;
  while (choice == 1) {
    new_node = (struct singly_node *)malloc(sizeof(struct singly_node));
    printf("\nEnter node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (head == NULL)
      head = temp = new_node;
    else {
      temp->next = new_node;
      temp = new_node;
    }
    printf("\nTo insert a new node press 1 else any other integer: ");
    scanf("%d", &choice);
  } 

  printf("\nThe elements in the Singly Linked list are...");
  temp = head;
  while (temp != NULL) {
    printf("\n%d", temp->data);
    temp = temp->next;
  }
}

void circular_linked_list(){
  printf("\n*** Circular Linked List ***");
}

int main() {
  while (1)  {
    menu();
    switch(choice) {
      case 1: singly_linked_list();
              break;
      case 2: doubly_linked_list();
              break;
      case 3: circular_linked_list();
              break;
      case 4: return 0;
      default: printf("\nInvalid Option");
    }
  }
    
}