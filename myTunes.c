#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node{
	char artist[100];
  	char song[100];
  
  	struct song_node *next;
};

struct song_node * make_song(char *song, char *artist) {
  struct song_node *n;
  n = malloc(sizeof(struct song_node));

  strncpy(n->song, song, 100);
  strncpy(n->artist, artist, 100);

  return n;
}

struct song_node * insert_front(struct song_node *front, char *song, char *artist) {
    struct song_node *n = make_song(song, artist);
    n->next = front;
    return n;
}

//*****STILL NEED TO COMPLETE****
struct song_node * insert_order(struct song_node *order, char *artist, char *name) {
	struct song_node *n = make_song(name, artist);
	
    return n;
}
//USE HELPER FUNCTION TO EFFECTIVELY COMPARE SONG NODES
// struct song_node * cmp_artist(struct song_node *front, char *artist) {
// 	struct song_node *n = 
// 	/*
// 	- use strcmpi to compare artist with each artist in the array
//	- artist -> list[]
// 	*/
// }

void print_node(struct song_node * s) {
   printf("song name: '%s'\tartist: '%s' \n", s->song, s->artist);
}

void print_list(struct song_node * current) {
   while (current != NULL) {
      print_node(current);
      current = current->next;
   }
}

struct song_node * find(struct song_node *s, char *song, char *artist) {
	while(s) {
		if ((strcmp(s->song, song) == 0) && (strcmp(s->artist, artist) == 0)) {
			return s;
		}
		s = s->next;
	}
	return s;
}

struct song_node * find_artist(struct song_node *s, char *artist) {
	while(s) {
		if (strcmp(s->artist, artist) == 0) {
			return s;
		}
		s = s->next;
	}
	return s;
}

int listlength(struct song_node *front) {
	int length = 0;
	while (front) {
		length++;
		front = front->next;
	}
	return length;
}

struct song_node * return_random(struct song_node *front) {
	int randInd = rand() % (listlength(front));
	//printf("%d", randInd);
	//int randInd = 2;
	int i = 0;

	if (i == randInd) return front;

	while(i < randInd) {
		front = front->next;
		i++;
	}
	return front;
}

struct song_node * remove_node(struct song_node *current, char *song, char *artist) {
	struct song_node * front = current;
	struct song_node * temp;
	if ((current->song == song) && (current->artist == artist)) {
		temp = current->next;
		free(current);
		return temp;
	}
	while (current) {
		if ((current->song == song) && (current->artist == artist)) {
			temp->next = current->next;
			free(current);
		}
		temp = current;
		current = current->next;
	}
	return front;
}

struct song_node *free_list(struct song_node *s) {
	struct song_node * temp = s;
	while(s) {
		s = s->next;
		free(temp);
		temp = s;
	}
	return s;
}

