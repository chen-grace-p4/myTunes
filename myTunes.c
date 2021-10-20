#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

