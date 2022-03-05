# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node * ptr;
};

// Required Functions for PUSH
int Is_Empty( struct Node * stack_pointer);
int Is_Full( struct Node * stack_pointer);
int Linkedlist_traversal( struct Node * stack_pointer);
struct Node *PUSH(struct Node *stack_pointer, int value);

// NOW WE WILL WRITE CODE FOR OUR PEEK OPERATION

int PEEK( struct Node * TOP,int position){

    struct Node * Peek = TOP;

    for( int i = 0; (i < position-1 && Peek != NULL); i++){
        Peek= Peek->ptr;
    }
    if( Peek != NULL){
        return Peek->data;
    }
    
}
int main(){
    // Now we will make a pointer which will point to the top of the element of the stack

    struct Node * Top;
    
    // Since we don't have any elements in the stack so its NULL

    Top = NULL;

    // PUSHING ELEMENTS INTO STACK
    Top = PUSH( Top , 100 );
    Top = PUSH( Top , 200 );
    Top = PUSH( Top , 300 );
    Top = PUSH( Top , 400 );
    Top = PUSH( Top , 500 );

    // PRINTING STACK ELEMENTS 
    //Linkedlist_traversal( Top );

    // PEEKING IN OUR LIST

    printf("%d\t", PEEK(Top,1));
    printf("%d\t", PEEK(Top,2));
    printf("%d\t", PEEK(Top,3));
    printf("%d\t", PEEK(Top,4));
    printf("%d\t", PEEK(Top,5));


   
    return 0;
}

int Is_Empty( struct Node * stack_pointer){
    if(stack_pointer == NULL){
        printf("\n\n\t !!!  S T A C K   U N D E R F L O W  !!!");
        return 1;
    }
    else{
        return 0;
    }
}

int Is_Full( struct Node * stack_pointer){
    
    // WE WILL MAKE A POINTER TO SEE IF WE CAN ALLOCATE MEMORY TO OUR STACK OR NOT
    // IF IT IS EQUALS TO NULL MEANS THE STACK IS FULL

    struct Node * p = (struct Node * ) malloc ( sizeof(struct Node));

    if( p == NULL){
        printf("\n\n\t !!!  S T A C K   O V E R F L O W  !!!"); 
        return 1;
    }
    else{
        return 0;
    }   
}
int Linkedlist_traversal( struct Node * stack_pointer){
    while( stack_pointer != NULL){
        printf("%d\t\t", stack_pointer->data);
        stack_pointer = stack_pointer->ptr;
    }
}
struct Node *PUSH(struct Node *stack_pointer, int value){
    if (Is_Full(stack_pointer))
    {
        printf("\n\n\t !!! S T A C K   O V E R F L O W !!!\n");
    }
    else
    {

        // Now we will make a pointer which will push our elements and allocate memory to it
        struct Node *push = (struct Node *)malloc(sizeof(struct Node));

        // Now we will pass value to our pointer to push
        push->data = value;

        // Now we will make our new pointer point to top of the stack
        push->ptr = stack_pointer;

        //Now since this is the last added element of our stack so it will be on the top of the stack so
        // We will make the Top equals to this element
        stack_pointer = push;
    }
}