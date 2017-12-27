#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct Linked_List{
	struct Node *header;
	struct Node *trailer;
} Linked_List;


void init( char *desc);


void add_node(char *desc);


bool remove_node(char *desc);

bool find_node(char *desc);

void iterate_Nodes();

void iterateBack_Nodes();


#endif
