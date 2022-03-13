/* Algorithm

01. Iterate through all elements in the list.
02. Compare the current element to its predecessor.
03. If the current element is smaller (greater) than its predecessor, compare it to the elements before.  
04. Move the greater (smaller) elements one position up to make space for the swapped element.
*/

# include <stdio.h>
int main(void) {
  int input[10] = {10, 9, 8, 7, 6, 5, 1, 2, 3, 4};
  // Elements are hard coded

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
  return 0;  
}

/* Observations and Output

*/