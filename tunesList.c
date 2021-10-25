#include <stdio.h>
#include <stdlib.h>
#include "myTunes.h"
#include "tunesList.h"
#include <ctype.h>
#include <string.h>
#include <time.h>

struct song_node ** make_library() {
	struct song_node ** library;
	library = calloc(27, sizeof(struct song_node *));
	return library;
}

//finds index in lib of the artist based on first letter
int find_ind(char * artist) {
	char first = tolower(artist[0]);
	if ((int)first >= 97 && (int)first <=122) {
		return (int)first - 97;
	} 
	return 26;
}

struct song_node ** add_song(struct song_node **library, char * song, char * artist) {
	int index = find_ind(artist);
	//TEMPOERARILY INSERT FRONT BELOW, CHANGE TO INSERT ORDER LATER
	//library[index] = insert_order(library[index], song, artist);
	library[index] = insert_front(library[index], song, artist);
	return library;
}
//returns pointer to found song
struct song_node * lib_find(struct song_node ** lib, char * song, char * artist) {
	int index = find_ind(artist);
	return find(lib[index], song, artist);
}
//returns pointer to found first song of artist
struct song_node * lib_find_artist(struct song_node ** lib, char * artist) {
	int index = find_ind(artist);
	return find_artist(lib[index], artist);
}

//prints all songs with artists whose name begin with letter
void print_letter(struct song_node ** lib, char letter) {
	char let = tolower(letter);
	int index = 0;
	if ((int)let >= 97 && (int)let <=122) {
		index = (int)let - 97;
	} else {
		index = 26;
	}

	print_list(lib[index]);
}
//prints all songs from the artist
void print_artist(struct song_node ** lib, char * artist) {
	int index = find_ind(artist);
	struct song_node *n = lib[index];

	while (n) {
		if(strcasecmp(n->artist, artist) == 0) {
			print_node(n);
		}
		n = n->next;
	}
}
//prints entire library
void print_library(struct song_node ** lib) {
	int i;
	for (i = 0; i < 26; i++) {
		if (lib[i]) {
			printf("%c:", i+97);
			print_list(lib[i]);
		} 
	}
	if (lib[26]) {
		printf("Symbols:");
		print_list(lib[26]);
	}
}

//randomly 
void shuffle(struct song_node ** lib, int num) {
	int i;
	for (i = 0; i < num; i++) {
		struct song_node * rand_ind = NULL;
		while (rand_ind == 0) {
			rand_ind = lib[rand() % 27];
		}
		print_node(return_random(rand_ind));
	}
}

//deletes a song 
struct song_node ** delete_song(struct song_node ** lib, char * song, char * artist) {
	int index = find_ind(artist);
	lib[index] = remove_node(lib[index], song, artist);
	return lib;
}

//clears everything
struct song_node ** clear(struct song_node ** lib) {
	int i;
	for (i = 0; i < 27; i++) {
		lib[i] = free_list(lib[i]);
		printf("freed\n");
	}
	return lib;
}

