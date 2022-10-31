#include "myallocator.h"

typedef struct Node
{
    int value;
    struct Node* next;
}Node;

void insert(Node* firstnode, int newvalue)
{
    Node* newnode = allocation(sizeof(Node));
    newnode->value=newvalue;
    newnode->next=NULL;
    if (firstnode==NULL)
    {
        firstnode=newnode;
        return;
    }
}

int main(int argc, char** argv)
{

	//CHECK COMPILED PROGRAM WITH ONLY PRINTF WITH VALGRIND DO SEE THAT PRINTF DOES ALLOCATES 1024 BYTS!!!!
/*
    Node* head = NULL;
    insert(head,1);

    print_chunks();
*/ 
	//FPRINTF DOES NOT ALLOCETS ANY BYTES !!!

	fprintf(stderr,"FGFDGFSGD\n");

    return 0;
}
