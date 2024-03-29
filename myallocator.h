#ifndef __MYALLOCATOR_H__
#define __MYALLOCATOR_H__

#include <assert.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define MY_HEAP_SIZE 100000

int freememory;

void* botptr;
void* currptr;
void* topptr;

typedef struct Chunk
{
    size_t bytes;
    void * address;
}Chunk;

Chunk array_of_chunks[MY_HEAP_SIZE];

int cnt;

bool allocated;

void base_allocation();
void base_deallocation();
void* allocation(size_t bytes);
void deallocation(void * ptr);
void print_chunks();

#endif