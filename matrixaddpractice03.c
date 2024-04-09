#include <stdio.h>

#define ROWS 2
#define COLS 2

void addMatrices(int mat1[][COLS], int mat2[][COLS], int result[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

int main() {
    int mat1[ROWS][COLS] = {{1, 2}, {3, 4}};
    int mat2[ROWS][COLS] = {{5, 6}, {7, 8}};
    int result[ROWS][COLS];

    addMatrices(mat1, mat2, result);

    printf("Resultant matrix after addition:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
