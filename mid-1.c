/*A left rotation operation on an array of size  shifts each of the array's elements  unit to the left. Given an integer, , rotate the array that many steps left and return the result.
Example
After  rotations, .
Returns
int[n]: the rotated array
Input Format
The first line contains two space-separated integers that denote , the number of integers, and , the number of left rotations to perform.
The second line contains  space-separated integers that describe .
Constraints
Sample Input
5 4
1 2 3 4 5
Sample Output
5 1 2 3 4
Explanation
*/



# include <stdio.h>
# include <stdlib.h>
int main(void) {
    int n, d;
    scanf("%d %d", &n, &d);
    int * arr = (int *)malloc(n * sizeof(int));
    for(int i=0; i<n; i++)
      scanf("%d", &arr[i]);
    for (int i=0; i<d; i++) {
        int temp = arr[0];
        for (int j=1; j<n; j++)
          arr[j-1] = arr[j];
        arr[n-1] = temp;
    }
    for(int i=0; i<n; i++)
      printf("%d ", arr[i]);
}
