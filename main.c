#include "myallocator.h"
#include "tll.h"

int main(int argc, char** argv)
{
    int * f0 = allocation(sizeof(int));
    int * f1 = allocation(sizeof(int));
    int * f2 = allocation(sizeof(int));
    int * f3 = allocation(sizeof(int));
    int * f4 = allocation(sizeof(int));
    int * f5 = allocation(sizeof(int));
    int * f6 = allocation(sizeof(int));
    int * f7 = allocation(sizeof(int));

    print_chunks();

    deallocation(f2);

    print_chunks();

    return 0;
}