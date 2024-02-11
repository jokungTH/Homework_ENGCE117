#include <stdio.h>
#include <string.h>

struct studentNode {
 char name[20] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
 struct studentNode *back ;
} ;



struct studentNode *AddNode ( struct studentNode **walk ,char nameadd[], int ageadd, char sexadd, float gpaadd ); // addnode
void InsNode (struct studentNode *walk , char nameadd[], int ageadd, char sexadd, float gpaadd, struct studentNode **begin); // insnode
void DelNode(struct studentNode **walk, struct studentNode **begin ){
	
	struct studentNode *temp;
	

	
	if( ( *walk ) -> back != NULL ) {
		( *walk ) -> back -> next = ( *walk ) -> next;
	} else {
		*begin = ( *walk ) -> next;	
	}
	
	if( ( *walk ) -> next != NULL ){
		(*walk) -> next ->back = (*walk) -> back;
		temp = (*walk) -> next;
		
		
	}else{
		
		temp = (*walk) -> back;
		
	}
	delete *walk;
	*walk = temp;
	
}


void ShowAll( struct studentNode *walk ) ;  // show



int main() {
 struct studentNode *start, *now ;
 start = NULL ;
 
 printf("|--- Add node \n");
 now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
 now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;
 printf("------------------------\n");
 
 printf("|--- Insert node \n");
 InsNode( now, "three", 10, 'M', 3.33, &start ) ; ShowAll( start ) ;
 InsNode( now, "four", 12, 'F', 3.44,  &start) ; ShowAll( start ) ;
 printf("------------------------\n");

  printf("|--- Deletle node \n");
 now = start ->next -> next;
 DelNode( &now , &start) ; ShowAll( start ) ;
 return 0 ;
}//end function


void InsNode (struct studentNode *walk , char nameadd[], int ageadd, char sexadd, float gpaadd, struct studentNode **begin){
	
	if(walk -> back != NULL ){
		
		walk -> back -> next = new struct studentNode;
		
		strcpy( walk -> back -> next -> name, nameadd ) ;
		walk -> back -> next -> next = walk;
		walk -> back -> next ->back = walk->back;
		walk -> back = walk -> back -> next;
	
		
	} else {
		
		*begin = new struct studentNode ;
		
		strcpy( (*begin) -> name , nameadd  ) ;
		(*begin) -> next = walk ;
		(*begin) ->back  = NULL ;
		walk -> back = *begin ;	
	}
	
	
}




struct studentNode *AddNode ( struct studentNode **walk ,char nameadd[], int ageadd, char sexadd, float gpaadd ){
		
	struct studentNode *temp = NULL ;
		
	while ( *walk != NULL ){
			
		temp = *walk;
		walk = &(*walk) -> next ;
			
	}//end while
		
	*walk = new struct studentNode;

	strcpy( (*walk)->name, nameadd ) ;
	(*walk) -> age = ageadd;
	(*walk) -> sex = sexadd;
	(*walk) -> gpa = gpaadd;
	
	(*walk) -> next = NULL;
	(*walk) -> back = temp;
	return *walk;
		
}	
	




void ShowAll( struct studentNode *walk ) {
 while( walk != NULL ) {
  printf( " %s ", walk->name) ;
 // printf( " %d ", walk->age) ;
  //printf( " %c ", walk->sex) ;
  //printf( " %.2f ", walk->gpa) ;
  walk = walk->next ;
 }//end while
 printf( "\n" ) ;
}//end function


