#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "myTunes.h"
#include "tunesList.h"

int main() {
	srand(time(NULL));
	struct song_node *list = NULL;
	
	char* s1 = "awake";
	char* a1 = "bts";
	list = insert_front(list, s1, a1);

	char* a2 = "eve";
	char* s2 = "leo";
	list = insert_front(list, s2, a2);

	char* a3 = "bts";
	char* s3 = "dynamite";
	list = insert_front(list, s3, a3);

	char* a4 = "blackpink";
	char* s4 = "kill this love";
	list = insert_front(list, s4, a4);

	printf("LINKED LIST TESTS\n");
	printf("====================================\n");
	printf("Testing print_list:\n");
	print_list(list);

	printf("====================================\n");
	printf("Testing print_node:\n");
	print_node(list);

	printf("====================================\n");
	printf("Testing find:\n");
	printf("looking for eve: leo \n");
	print_node(find(list, "leo", "eve"));

	printf("====================================\n");
	printf("Testing find_artist:\n");
	printf("looking for first song bts \n");
	print_node(find_artist(list, "bts"));

	printf("====================================\n");
	printf("Testing return_random:\n");
	print_node(return_random(list));
	print_node(return_random(list));
	print_node(return_random(list));
	
}