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
    Node* head = NULL;
    insert(head,1);

    print_chunks();

    return 0;
}