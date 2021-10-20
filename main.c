#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myTunes.h"
#include "tunesList.h"

int main() {
	struct song_node *list = NULL;
	

	printf("LINKED LIST TESTS\n");
	printf("====================================\n");
	printf("Testing print_list:\n");
	print_list(list);
	
}