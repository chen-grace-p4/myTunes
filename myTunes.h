struct song_node{
	char artist[100];
  	char song[100];
  
  	struct song_node *next;
};

struct song_node *make_song(char *song, char *artist);

struct song_node * insert_front(struct song_node *front, char *song, char *artist);

//HELPER FOR INSERT ORDER
int compare_nodes(struct song_node *song1, struct song_node *song2);
int string_cmp (char *song1,char *song2);

struct song_node * insert_order(struct song_node *front, char *song, char *artist);


void print_node(struct song_node *s);
void print_list(struct song_node *current);

struct song_node * find(struct song_node *s, char *song, char *artist);
struct song_node * find_artist(struct song_node *s, char *artist);

//HELPER FOR RANDOM
int listlength(struct song_node *front);

struct song_node * return_random(struct song_node *front);
struct song_node * remove_node(struct song_node *current, char *song, char *artist);
struct song_node *free_list(struct song_node *n);