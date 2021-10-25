#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

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

//USE HELPER FUNCTION TO EFFECTIVELY COMPARE SONG NODES
// int string_cmp (char *song1,char *song2) {
//     int i = 0, diff = 0;
//     for(i = 0; song1[i] != '\0'; i++) {
//         if(toupper(song1[i])!=toupper(song2[i])) {
// 			diff += 1;
// 		}
// 	}
//     return diff;           
// }

int compare_nodes(struct song_node *song1, struct song_node *song2) {
	int cmp = strcasecmp(song1->artist, song2->artist);
	if(cmp) return cmp;
	else {
		cmp = strcasecmp(song1->song, song2->song);
		if(cmp) return cmp;
		else return 0;
	}
}


struct song_node * insert_order(struct song_node *front, char *name, char *artist) {
	struct song_node *n = make_song(name, artist); // creates a song
	if (front == NULL) return n; // if there's no song in the front of the list, then just return the node
	int cmp = compare_nodes(n, front); // stores the differences between the song n and song in the front into int cmp
	if (cmp < 0) { // if the differences is negative, then song1 has n less characters than song2, so it will go 
		n->next = front; 
		front = n;
		return front;
	}
	struct song_node *temp;
	temp = front;
	while (temp->next) {
		if(compare_nodes(n, temp) < 0) {
			n->next = temp->next;
			temp->next = n;
			return front;
		}
		temp = temp->next;
	}
	n->next = temp->next;
	temp->next = n;
	return front;
}


void print_node(struct song_node * s) {
   if (s == NULL) printf("song not found!\n");
   else printf("{song name: '%s'\tartist: '%s' }\n", s->song, s->artist);
}

void print_list(struct song_node * current) {
	printf("[  ");
   while (current != NULL) {
      print_node(current);
      current = current->next;
   }
   printf("]\n");
}

struct song_node * find(struct song_node *s, char *song, char *artist) {
	while(s) {
		if ((strcasecmp(s->song, song) == 0) && (strcasecmp(s->artist, artist) == 0)) {
			return s;
		}
		s = s->next;
	}
	//return s;
	return NULL;
}

struct song_node * find_artist(struct song_node *s, char *artist) {
	while(s) {
		if (strcasecmp(s->artist, artist) == 0) {
			return s;
		}
		s = s->next;
	}
	//return s;
	return NULL;
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
	if ((strcasecmp(current->song, song) == 0) && (strcasecmp(current->artist, artist) == 0)) {
		temp = current->next;
		free(current);
		return temp;
	}
	while (current) {
		if ((strcasecmp(current->song, song) == 0) && (strcasecmp(current->artist, artist) == 0)) {
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

