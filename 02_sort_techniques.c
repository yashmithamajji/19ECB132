
# include <stdio.h>

int input[10] = {10, 9, 8, 7, 6, 5, 1, 2, 3, 4};
  // Elements are hard coded
void menu() {
  printf("\n1. Insertion Sort \n2. Merge Sort \n3. Quick Sort \n9. Exit");
}

/* Insertion Sort Algorithm

01. Iterate through all elements in the list.
02. Compare the current element to its predecessor.
03. If the current element is smaller (greater) than its predecessor, compare it to the elements before.  
04. Move the greater (smaller) elements one position up to make space for the swapped element.
*/

void insertion_sort() {
  for (int i=1; i<10; i++) {
    int element = input[i];
    int j = i-1;
    while ( j >= 0 && input[j] > element) {
      input[j+1] = input[j];
      j--;
    }
    input[j+1] = element;
  }

  printf("\nElements after sorting are ...\n");
  for(int i=0; i<10; i++)
    printf("%d\t", input[i]);
}

int main(void) {
  int choice=0;
  while (1) {
    menu();
    printf("\nSelect the sorting technique: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1: printf("\n**Insertion Sort**");
              insertion_sort();
              break;
      case 2: printf("\n**Merge Sort**");
              break;
      case 3: printf("\n**Quick Sort**");
              break;
      case 9: return 0;
      
      default: printf("Invalid choice");
      
    }
  }
}




  
  /* Observations and Output

*/