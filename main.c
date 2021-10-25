#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "myTunes.h"
#include "tunesList.h"

int main() {
	srand(time(NULL));
	struct song_node *list = NULL;
	
	char* a1 = "bts";
	char* s1 = "awake";
	//list = insert_front(list, s1, a1);
	list = insert_order(list, s1, a1);
	print_list(list);

	char* a2 = "exo";
	char* s2 = "leo";
	//list = insert_front(list, s2, a2);
	list = insert_order(list, s2, a2);
	print_list(list);

	char* a3 = "bts";
	char* s3 = "dynamite";
	//list = insert_front(list, s3, a3);
	list = insert_order(list, s3, a3);
	print_list(list);

	char* a4 = "blackpink";
	char* s4 = "kill this love";
	//list = insert_front(list, s4, a4);
	list = insert_order(list, s4, a4);
	print_list(list);

	char* a7 = "BLackpink";
	char* s7 = "kill this love";
	//list = insert_front(list, s7, a7);
	list = insert_order(list, s7, a7);
	print_list(list);

	char* a5 = "blackpink";
	char* s5 = "boombayah";
	//list = insert_front(list, s5, a5);
	list = insert_order(list, s5, a5);
	print_list(list);

	char* a6 = "backstreet boys";
	char* s6 = "everybody";
	//list = insert_front(list, s6, a6);
	list = insert_order(list, s6, a6);
	print_list(list);

	struct song_node *a = make_song("awake", "bts");
	struct song_node *b = make_song("exo", "leo");
	struct song_node *c = make_song("blackpink", "kill this love");
	struct song_node *d = make_song("BLackpink", "kill this love");

	printf("LINKED LIST TESTS\n");
	printf("====================================\n");
	printf("Testing compare_nodes (helper function):\n");
	printf("%d\n", compare_nodes(a, b));
	printf("%d\n", compare_nodes(b, c));
	printf("%d\n", compare_nodes(c, a));
	printf("%d\n", compare_nodes(c, c));
	printf("%d\n", compare_nodes(c, d));

	printf("====================================\n");
	printf("Testing print_list:\n");
	print_list(list);

	printf("====================================\n");
	printf("Testing print_node:\n");
	print_node(list);

	printf("====================================\n");
	printf("Testing find:\n");
	printf("looking for eve: leo \n");
	print_node(find(list, "leo", "exo"));

	printf("====================================\n");
	printf("Testing find_artist:\n");
	printf("looking for first song bts \n");
	print_node(find_artist(list, "bts"));

	printf("====================================\n");
	printf("Testing return_random:\n");
	print_node(return_random(list));
	print_node(return_random(list));
	print_node(return_random(list));

	printf("====================================\n");
	printf("Testing remove_node:\n");
	printf("[Removing dynamite by bts] \n");
	list = remove_node(list, "dynamite", "bts");
	print_list(list);

	printf("[Removing awake by bts] \n");
	list = remove_node(list, "awake", "bts");
	print_list(list);

	printf("[Removing everybody by backstreet boys] \n");
	list = remove_node(list, "everybody", "backstreet boys");
	print_list(list);

	printf("[Removing dynamite by bts] (no longer in list) \n");
	list = remove_node(list, "dynamite", "bts");
	print_list(list);
	
	printf("====================================\n");
	printf("Testing free_list:\n");
	printf("List before freeing:\n");
	print_list(list);
	list = free_list(list);
	printf("Freed list:\n");
	print_list(list);

	
	///*
	printf("====================================\n");
	printf("MUSIC LIBRARY TESTS\n");
	printf("====================================\n");
	
	struct song_node ** library = make_library();

	library = add_song(library, s1, a1);

	library = add_song(library, s2, a2);

	library = add_song(library, s3, a3);

	library = add_song(library, s4, a4);

	library = add_song(library, s7, a7);

	library = add_song(library, s5, a5);

	library = add_song(library, s6, a6);
	//*/

	/*
	printf("Testing print_letter before adding:\n");

	printf("====================================\n");
	printf("Testing print_library before adding:\n");
	*/

	printf("====================================\n");
	printf("Testing print_letter:\n");
	printf("For artists of letter b: \n");
	print_letter(library, 'b');

	printf("For artists of letter e: \n");
	print_letter(library, 'e');

	printf("====================================\n");
	printf("Testing print_artist:\n");
	printf("For artist bts: \n");
	print_artist(library, "bts");

	printf("====================================\n");
	printf("Testing print_library:\n");
	print_library(library);

	printf("====================================\n");
	printf("Testing find:\n");
	printf("looking for boombayah by blackpink \n");
	print_node(lib_find(library, "boombayah", "blackpink"));

	printf("looking for wings by bts (not found): \n");
	print_node(lib_find(library, "wings", "bts"));

	printf("====================================\n");
	printf("Testing find artist:\n");
	printf("looking for exo \n");
	print_node(lib_find_artist(library, "exo"));

	printf("looking for bieber (not found): \n");
	print_node(lib_find_artist(library, "bieber"));

	printf("====================================\n");
	printf("Testing remove song:\n");
	printf("removing everybody by backstreet boys\n");
	library = delete_song(library, "everybody", "backstreet boys");
	printf("library after removing:\n");
	print_library(library);

	printf("====================================\n");
	printf("Testing shuffle:\n");
	shuffle(library, 5);
	
	printf("====================================\n");
	printf("Testing clear_library:\n");
	printf("Library before clear:\n");
	print_library(library);
	library = clear(library);
	printf("Library after clear:\n");
	print_library(library);
	/*
	printf("====================================\n");
	printf("Adding songs to empty library:\n");
	*/
}