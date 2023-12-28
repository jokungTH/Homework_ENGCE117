#include <stdio.h>
#include <string.h>

char* reverse( char str1[]) ;

int main() {
    char text[ 50 ] = "I Love You" ;
    char *out ;
    out = reverse( text ) ;
}//end function

char* reverse( char str1[]) {
    
    int length = strlen(str1);
    char *str2 = new char [length+1];
    for (int i = 0; i < length; i++) {
        str2[length - 1 - i] = str1[i];
    }
    str2[length] = '\0';
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    
    return str2;
}