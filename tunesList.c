#include <stdio.h>
#include <stdlib.h>
#include "myTunes.h"

struct song_node ** make_library() {
	struct song_node ** library;
	library = calloc(27, sizeof(struct song_node *));
	return library;
}
/*
add_song method
*/