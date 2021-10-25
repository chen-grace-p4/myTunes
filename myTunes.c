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

int compare_nodes(struct song_node *song1, struct song_node *song2) {
	int cmp = strcasecmp(song1->artist, song2->artist);
	if(cmp != 0) return cmp;
	else {
		cmp = strcasecmp(song1->song, song2->song);
		//printf("%d", cmp);
		return cmp;
	}
}

struct song_node * insert_order(struct song_node *front, char *name, char *artist) {
	struct song_node *n = make_song(name, artist); 	
	struct song_node *temp = front;
	
	if (front == NULL) {
		front = insert_front(front, name, artist);
		return front; 
	} 
	int cmp = compare_nodes(n, front); 
	if (cmp <= 0) {
		front = insert_front(front, name, artist);
		return front;
	}
	
	while (front->next) {
		if(compare_nodes(n, front->next) <= 0) {
			n->next = front->next;
			front->next = n;
			return temp;
		} 
		front = front->next;
	}

	if(compare_nodes(n, front) <=0 ) {
		front = insert_front(front,name,artist);
       	return front;
	}

	front->next = n;
	n->next = NULL;
	return temp;
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
	return NULL;
}

struct song_node * find_artist(struct song_node *s, char *artist) {
	while(s) {
		if (strcasecmp(s->artist, artist) == 0) {
			return s;
		}
		s = s->next;
	}
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
	if (!front) return front;
	int randInd = rand() % (listlength(front));
	int i = 0;
	if (i == randInd) return front;
	while(i < randInd) {
		front = front->next;
		i++;
	}
	return front;
}

struct song_node * remove_node(struct song_node *current, char *song, char *artist) {
	if (!current) return current;
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