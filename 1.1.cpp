#include <stdio.h>
int main(){
	int n;
	int i;
	
	printf("Hello world Number : ");
	scanf( "%d" , &n);
	for(i = 1; i <= n; i++ ){
		printf("[%d]Hello world" , i );
	}
	return 0;
}