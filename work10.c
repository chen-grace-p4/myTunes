#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct shapes {
    int sides; 
    char s[100];
    double area; 
    struct shapes *next;
};

void print_shapes(struct shapes *x) {
    printf("shape: %s\t# of sides: %d\tarea: %f units squared\n", x->s, x->sides, x->area);
}

void print_list(struct shapes *n) {
    while(n != NULL) {
        print_shapes(n);
        n = n->next;
    }
    printf("\n");
}

struct shapes *make_shape(int i, char *c, double d) {
    struct shapes *n = malloc(sizeof(struct shapes));
    strncpy(n->s, c, 100);
    n->area = d;
    n->sides = i;
    return n;
};

struct shapes * insert_front(struct shapes *front, int sides, char *s, double area) {
    struct shapes *n = make_shape(sides, s , area);
    n->next = front;
    return n;
};
 
struct shapes *free_list(struct shapes *n) {
    struct shapes * temp = n;
    while(n) {
   	n = n->next;
   	free(temp);
   	temp = n;
	}
	return n;
};

struct shapes * remove_node(struct shapes *s, int sides) {
    struct shapes * front = s;
    struct shapes * temp;

    if(s->sides == s) {
        temp = s->next;
        free(s);
        return temp;
    }
    while(s) {
        if (s->sides == sides) {
            temp->next = s->next;
            free(s);
        }
        temp = s;
        s = s->next;
    }
    return front;
};
