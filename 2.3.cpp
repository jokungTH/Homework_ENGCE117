#include <stdio.h>
#include <string.h>

void explode( char str1[], char splitter, char str2[][10], int *count ) ;

int main() {
    char out[ 20 ][ 10 ] ;
    int num ;
    explode("I/Love/You", '/', out, &num);
    return 0 ;
}//end function

void explode( char str1[], char splitter, char str2[][10], int *count ) {
    *count = 0;
    char collect[strlen(str1) + 1];
    strcpy(collect, str1);

    char *collectone = strtok(collect, &splitter);

    while (collectone != NULL) {
        strcpy(str2[*count], collectone);
        (*count)++;
        collectone = strtok(NULL, &splitter);
    }

    for (int i = 0; i < *count; i++) {
        printf("str2[%d] = \"%s\"\n", i, str2[i]);
    }

    printf("count = %d\n", *count);
}