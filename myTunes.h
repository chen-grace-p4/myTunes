struct song_node *make_song(int i, char *c, double d);
void print_songs(struct song_node *x);
void print_list(struct song_node *n);
struct song_node * insert_front(struct song_node *front, int i, char *c, double d);
struct song_node *free_list(struct song_node *n);
struct song_node * remove_node(struct song_node *s, int i);