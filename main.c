#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myTunes.h"
#include "tunesList.h"

int main() {
	struct song_node *list = NULL;
	
	char* n1 = "awake";
	char* a1 = "bts";
	list = insert_front(list, n1, a1);

	char* a2 = "eve";
	char* n2 = "leo";
	list = insert_front(list, n2, a2);

	char* a3 = "bts";
	char* n3 = "dynamite";
	list = insert_front(list, n3, a3);

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
	
}