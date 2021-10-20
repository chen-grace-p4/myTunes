#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node * make_song(char *name, char *artist) {
  struct song_node *n;
  n = malloc(sizeof(struct song_node));

  strncpy(n->name, name, 100);
  strncpy(n->artist, artist, 100);

  return n;
}

struct song_node * insert_front(struct song_node *front, char *name, char *artist) {
    struct song_node *n = make_song(name, artist);
    n->next = front;
    return n;
}

struct song_node * insert_order(struct song_node *front, char *name, char *artist) {
	struct song_node *n = make_song(name, artist);
    return n;
}
//USE HELPER FUNCTION TO EFFECTIVELY COMPARE SONG NODES

void print_song(struct song_node * s) {
   printf("song name: '%s'\tartist: '%s' \n", s->name, s->artist);
}

void print_list(struct song_node * current) {
   while (current != NULL) {
      print_song(current);
      current = current->next;
   }
}

struct song_node * find(struct song_node *s, char *name, char *artist) {
	struct song_node *n = make_song(name, artist);
    return n;
}
struct song_node * find_artist(struct song_node *s, char *artist) {
	struct song_node *n = make_song("placeholder", artist);
    return n;
}

struct song_node * return_random(struct song_node *front) {
	struct song_node *n = make_song("placeholder", "placeholder");
    return n;
}
struct song_node * remove_node(struct song_node *s, char *name, char *artist) {
	struct song_node *n = make_song("placeholder", "placeholder");
    return n;
}
struct song_node *free_list(struct song_node *s) {
	struct song_node *n = make_song("placeholder", "placeholder");
    return n;
}

