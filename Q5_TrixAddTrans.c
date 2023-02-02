// Matrix addition and Transpose

#include<stdio.h>

void createMatrix(int matrix[][20], int rows, int cols){
    
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            printf("Element %d%d : ", r, c);
            scanf("%d", &matrix[r][c]);
        }
    }
    printf("\n");
}

void displayMatrix(int matrix[][20], int rows, int cols){
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            printf("%02d  ", matrix[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrix(int A[][20], int B[][20], int SUM[][20], int rows, int cols){
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            SUM[r][c] = A[r][c] + B[r][c];
        }
    }
}

void transMatrix(int M[][20], int TR[][20], int rows, int cols){
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            TR[c][r] = M[r][c];
        }
    }
}
int main(){

    int A[20][20], B[20][20], SUM[20][20], TR[20][20];
    int rows, cols;

    printf("Enter number of Rows(<20) : ");
    scanf("%d", &rows);

    printf("Enter number of Columns(<20) : ");
    scanf("%d", &cols);

    //creating matrix
    printf("Enter elements for Matrix 1 : \n");
    createMatrix(A, rows, cols);

    printf("Enter elements for Matrix 1 : \n");
    createMatrix(B, rows, cols);
    
    //displaying matrix
    printf("Matrix A :: \n");
    displayMatrix(A, rows, cols);

    printf("Matrix B :: \n");
    displayMatrix(B, rows, cols);

    //additing A and B
    addMatrix(A, B, SUM, rows, cols);
    printf("Sum of matrix A and B :: \n");
    displayMatrix(SUM, rows, cols);

    //Transpose of A
    transMatrix(A, TR, rows, cols);
    printf("Transpose of matrix A :: \n");
    displayMatrix(TR, rows, cols);

    //Transpose of B
    transMatrix(B, TR, rows, cols);
    printf("Transpose of matrix B :: \n");
    displayMatrix(TR, rows, cols);

    return 0;
}