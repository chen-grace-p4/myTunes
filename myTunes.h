struct song_node *make_song(char *name, char *artist);

struct song_node * insert_front(struct song_node *front, char *name, char *artist);
struct song_node * insert_order(struct song_node *front, char *name, char *artist);

void print_node(struct song_node *s);
void print_list(struct song_node *current);

struct song_node * find(struct song_node *s, char *name, char *artist);
struct song_node * find_artist(struct song_node *s, char *artist);

struct song_node * return_random(struct song_node *front);
struct song_node * remove_node(struct song_node *current, char *name, char *artist);
struct song_node *free_list(struct song_node *n);