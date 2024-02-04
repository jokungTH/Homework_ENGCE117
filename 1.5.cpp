#include <stdio.h>

void GetMatrix( int value[], int *row, int *col ) ;

int main() {
    int *data, m, n ;
    GetMatrix( &data, &m, &n ) ;
    return 0 ;
}//end function

void GetMatrix( int value[], int *row, int *col ){
    printf("How many row, col ?: ");
    scanf("%d %d", row, col);
    
    for (int i = 0; i < *row; ++i) {
        for (int j = 0; j < *col; ++j) {
            printf("Membership fee [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &value[i * *col + j]);
        }
    }
    
    printf("Number of members :[%d][%d]", *row, *col);
    for (int i = 0; i < *row; ++i) {
        for (int j = 0; j <= *col; ++j) {
            printf("\n");
            printf("Member [%d][%d]: %d", i + 1, j + 1, value[i * *col + j]);
        }
    }
}

