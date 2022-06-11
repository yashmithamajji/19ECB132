
# include <stdio.h>

int input[10] = {10, 9, 8, 7, 6, 5, 1, 2, 3, 4};
  // Elements are hard coded
void menu() {
  printf("\n1. Insertion Sort \n2. Merge Sort \n3. Quick Sort \n4. Selection Sort  \n5. Shell Sort  \n6. Heap Sort  \n9. Exit");
}

void print_array(){
  printf("\nElements after sorting are ...\n");
  for(int i=0; i<10; i++)
    printf("%d\t", input[i]);
  printf("\n");
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
}

void selection_sort() {
  int minimum_value_index;
  for (int i=0; i<9; i++) {
     minimum_value_index = i;
    for (int j = i+1; j<10; j++) {
      if (input[j] < input[minimum_value_index])
          minimum_value_index = j;
    }
    // swap the minimum element with the first element
    int temp = input[minimum_value_index];
    input[minimum_value_index] = input[i];
    input[i] = temp;
    print_array();
  }
}


void merging(int low, int mid, int high) {
   int l1, l2, i;
   int b[10];
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(input[l1] <= input[l2])
         b[i] = input[l1++];
      else
         b[i] = input[l2++];
   }
   while(l1 <= mid)    
      b[i++] = input[l1++];
   while(l2 <= high)   
      b[i++] = input[l2++];
   for(i = low; i <= high; i++)
      input[i] = b[i];
}

void merge_sort(int low, int high) {
   int mid;
   if(low < high) {
      mid = (low + high) / 2;
      merge_sort(low, mid);
      merge_sort(mid+1, high);
      merging(low, mid, high);
     print_array();
   } else { 
      return;
   }   
}

void quick_sort(int first,int last) {
  int i, j, pivot, temp;
  if(first<last) {
    pivot=first;
    i=first;
    j=last;
   while(i<j) {
      while(input[i]<=input[pivot]&&i<last)
        i++;
      while(input[j]>input[pivot])
        j--;
    if(i<j) {
      temp=input[i];
      input[i]=input[j];
      input[j]=temp;
     }
    }
    temp=input[pivot];
    input[pivot]=input[j];
    input[j]=temp;
    quick_sort(first,j-1);
    print_array();
    quick_sort(j+1,last);
    
  }
}

void shell_sort(int n) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = input[i];
      int j;
      for (j = i; j >= interval && input[j - interval] > temp; j -= interval) {
        input[j] = input[j - interval];
      }
      input[j] = temp;
    }
    print_array();
  }
}

void swap(int *a, int *b) {
 int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int n, int i) {
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2; 
if (left < n && input[left] > input[largest])
  largest = left;
if (right < n && input[right] > input[largest])
  largest = right;
if (largest != i) {
 swap(&input[i], &input[largest]);
 heapify(n, largest);
 }
}

void heap_sort(int n) {
 for (int i = n / 2 - 1; i >= 0; i--)
   heapify(n, i);
  for (int i = n - 1; i >= 0; i--) {
     swap(&input[0], &input[i]);
   heapify(i, 0);
  }
}

int main(void) {
  int choice=0;
    menu();
    printf("\nSelect the sorting technique: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1: printf("\n**Insertion Sort**");
              insertion_sort();
              break;
      case 2: printf("\n**Merge Sort**");
              merge_sort(0, 9);
              break;
      case 3: printf("\n**Quick Sort**");
              quick_sort(0, 9);
              break;
      case 4: printf("\n**Selection Sort**");
              selection_sort();
              break;
      case 5: printf("\n**Shell Sort**");
              shell_sort(10);
              break;
      case 6: printf("\n**Heap Sort**");
              heap_sort(10);
              break;
      case 9: return 0;
      
      default: printf("Invalid choice");
      
    }
  print_array();

}




  
  /* Observations and Output

*/