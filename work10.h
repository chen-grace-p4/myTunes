struct shapes *make_shape(int i, char *c, double d);
void print_shapes(struct shapes *x);
void print_list(struct shapes *n);
struct shapes * insert_front(struct shapes *front, int sides, char *s, double area);
struct shapes *free_list(struct shapes *n);
struct menu * remove_node(struct shapes *s, int sides);