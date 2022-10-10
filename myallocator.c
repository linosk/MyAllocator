#include "myallocator.h"

int freememory = MY_HEAP_SIZE;
void* botptr = NULL;
void* currptr = NULL;
void* topptr = NULL;
bool allocated=false;
int cnt = 0;

void base_allocation()
{
    printf("Allocation.\n");
    botptr = sbrk(0);
    assert(botptr!=(void*)-1);
    currptr = botptr;
    topptr = ((void*)(char*)botptr+MY_HEAP_SIZE);
    int check = brk(topptr);
    assert(check!=-1);
}

void base_deallocation()
{
    printf("Deallocation.\n");
    int check = brk(botptr);
    assert(check!=-1);
}

void* allocation(size_t bytes)
{
    if(allocated==false)
    {
        base_allocation();
        allocated=true;
    }
    assert(freememory-(int)bytes>=0);
    freememory=freememory-(int)bytes;
    void * tmpptr = currptr;
    currptr = currptr + bytes;
    Chunk chunk = {

        .address = tmpptr,
        .bytes = bytes,
    };
    array_of_chunks[cnt]=chunk;
    cnt++;
    return tmpptr;
}

void deallocation(void * ptr)
{
    int i = 0;
    while (array_of_chunks[i].address!=ptr)
    {
        i++;
    }
    freememory=freememory+array_of_chunks[i].bytes;
    cnt--;
    for(i;i<cnt;i++)
    {
        array_of_chunks[i]=array_of_chunks[i+1];
    }
}

void print_chunks()
{
    if (cnt==0)
    {
        printf("There are no allocated chunks.\n");
        return;
    }

    for(int i=0;i<cnt;i++)
    {
        printf("Chunk number %d resides at address %p and occupies %zu bytes.\n",i+1,array_of_chunks[i].address,array_of_chunks[i].bytes);   
    }

    printf("Currently there are %d bytes of free memory on my heap.\n", freememory);
}