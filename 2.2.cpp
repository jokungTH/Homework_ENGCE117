#include <stdio.h>
#include <string.h>

void reverse( char str1[], char str2[] ) ;

int main() {
    char text[ 50 ] = "I Love You" ;
    char out[ 50 ] ;
    reverse( text, out ) ;
}//end function

void reverse(char str1[], char str2[]) {
    int length = strlen(str1);
    for (int i = 0; i < length; i++) {
        str2[length - 1 - i] = str1[i];
    }
    str2[length] = '\0';
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
}