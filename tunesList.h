struct song_node ** make_library();

int find_ind(char * artist);
struct song_node ** add_song(struct song_node **library, char *song, char *artist);

struct song_node * lib_find(struct song_node ** lib, char * songname, char * artist);
struct song_node * lib_find_artist(struct song_node ** lib, char * artist);

void print_letter(struct song_node ** lib, char letter);
void print_artist(struct song_node ** lib, char * artist);
void print_library(struct song_node ** lib);

void shuffle(struct song_node ** lib, int num);

struct song_node ** delete_song(struct song_node ** lib, char * song, char * artist);

struct song_node ** clear(struct song_node ** lib);