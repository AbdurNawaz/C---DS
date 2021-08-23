#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define ROWS 2
#define COLS 3

int compute_rank(float A[ROWS][COLS]);
void swap(float A[ROWS][COLS], int row1, int row2, int col);

int main()
{

	float a[ROWS][COLS] = {
		{1, 2, 3},
		{4, 8, 12},
	};

	int rank = compute_rank(a);


	 if(rank!=COLS)
	 	printf("Linearly Dependent");
	 else
	 	printf("Linearly Independent");

	 printf("\nRank: %d", rank);

}

void swap(float A[ROWS][COLS], int row1, int row2, int col)
{
    for (int i = 0; i < col; i++)
    {
        int temp = A[row1][i];
        A[row1][i] = A[row2][i];
        A[row2][i] = temp;
    }
}

int compute_rank(float A[ROWS][COLS]) {

    int rank = COLS;

    for(int row=0;row<rank;row++){

        if(A[row][row]){

            for(int i=0;i<ROWS;i++){

                if(i!=row){
                    float temp = A[i][row]/A[row][row];

                    for(int j=0;j<rank;j++)
                        A[i][j] -= temp*A[row][j];
                }
            }
        }

        else{
            bool flag = true;

            for(int i=row+1;i<ROWS;i++){
                if(A[i][row]){
                    flag = false;
                    swap(A, row, i, rank);
                    break;
                }
            }

            if(flag){
                rank--;

                for(int i=0;i<ROWS;i++)
                    A[i][row] = A[i][rank];
            }

            row--;
        }
    }

    return rank;
}
