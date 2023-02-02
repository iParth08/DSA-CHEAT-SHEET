// Matrix Multiplication


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

void multiplyMatrix(int A[][20], int B[][20], int MUL[][20], int rowsA, int colsA, int rowsB, int colsB){
    
    int i, j, k;

    //initializing all elements of MUL to 0
    for(j=0; j<rowsA; j++){
        for(k=0; k<colsB; k++){
            MUL[j][k] = 0;
        }
    }

    //Multiply and get result
    for(j=0; j<rowsA; j++){
        for(k=0; k<colsB; k++){
            for(i=0; i<colsA; i++){
                MUL[j][k] += A[j][i] * B[i][k];
            }
        }
    }
}


int main(){

    int A[20][20], B[20][20], MUL[20][20];
    int rowsA, colsA, rowsB, colsB;

    printf("Enter number of Rows of Matrix A(<20) : ");
    scanf("%d", &rowsA);

    printf("Enter number of Columns of Matrix A(<20) : ");
    scanf("%d", &colsA);

    printf("Enter number of Rows of Matrix B(<20) : ");
    scanf("%d", &rowsB);

    printf("Enter number of Columns of Matrix B(<20) : ");
    scanf("%d", &colsB);

    if(colsA != rowsB){
        printf("Error! column of first matrix not equal to row of second.");
        return 1;
    }

    //creating matrix
    printf("Enter elements for Matrix 1 : \n");
    createMatrix(A, rowsA, colsA);

    printf("Enter elements for Matrix 1 : \n");
    createMatrix(B, rowsB, colsB);
    
    //displaying matrix
    printf("Matrix A :: \n");
    displayMatrix(A, rowsA, colsA);

    printf("Matrix B :: \n");
    displayMatrix(B, rowsB, colsB);

    //additing A and B
    multiplyMatrix(A, B, MUL, rowsA, colsA, rowsB, colsB);
    printf("Sum of matrix A and B :: \n");
    displayMatrix(MUL, rowsA, colsB);


    return 0;
}