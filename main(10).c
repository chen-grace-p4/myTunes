#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "work10.h"

int main() {
    srand(time(NULL));
    struct shapes *list = NULL;

    int side1 = 4;
    char *s1 = "square";
    double a1 = rand() % 100;
    list = insert_front(list, side1, s1, a1);

    int side2 = 6;
    char *s2 = "hexagon";
    double a2 = rand() % 100;
    list = insert_front(list, side2, s2, a2);

    int side3 = 9;
    char *s3 = "nonagon";
    double a3 = rand() % 100;
    list = insert_front(list, side3, s3, a3);
    
    printf("Print Linked List:\n");
    print_list(list);
    list = remove_node(list, side1);
    printf("Removed Node 1:\n");
    print_list(list);

    list = remove_node(list, side2);
    printf("Removed Node 2:\n");
    print_list(list);
    
    printf("Print Freed List:\n");
    printf("%p\n", free_list(list));
    print_list(list);
    return 0;
}