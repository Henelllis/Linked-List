#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>



typedef struct Node{
	char id[10];
	struct Node *nextRef;
	struct Node *prevRef;
} Node;

Node *root_header;
Node *root_trailer;

void init(char *id_desc){
	root_header = malloc(sizeof(Node));
	strcpy( root_header -> id , id_desc);
	root_header -> nextRef = NULL;
	root_header -> prevRef = NULL;
	root_trailer = root_header;
}

void add_node(char *id_desc){
	/*1 Take Root Node and make copy of it */
	/*2  Create a new Node for the root*/
	/*3 Populate that node*/
	/*4 Take the tmp node and make that the ref node for the root*/
	if(root_header == NULL){
		init(id_desc);
	}
	else{	
		Node *tmp;
		tmp = root_header;
		root_header  = malloc(sizeof(Node));
		tmp -> nextRef = root_header;
		strcpy( root_header -> id , id_desc);
		root_header -> prevRef =  tmp;
		root_header -> nextRef = NULL;
	}

}

/*bool remove_node(char *id_desc){

	//If Node does not exist
	//why bother trying to remove it
	if(root == NULL){
		return false;
	}

	Node *node_root;
	Node *node_ref;

	node_root = root;
	node_ref = node_root -> ref;

	if(strcmp(node_root -> id, id_desc) == 0 && node_root -> ref == NULL){
		printf("Root node is to be removed and its the only node in the chain\n");
		root = NULL;
		free(root);
		return true;
	}
	else if (strcmp(node_root -> id , id_desc) && node_root -> ref == NULL ){
		printf("Root Node does not match and its the only Node in the chain\n");
		return false;
	
	else if(strcmp(node_root -> id, id_desc) == 0 && node_root -> ref != NULL){
		printf("Root node is to be removed and is the first one on the chain\n");
		root = node_ref;
		return true;
	}

	while(node_root -> ref != NULL){

		if(strcmp(node_ref -> id , id_desc) == 0){
			
			Node *tmp;
			tmp = node_root -> ref -> ref;
			free(node_root -> ref);
			//node_ref = NULL;

			node_root -> ref = tmp;

			return true; 
		}
		else{
			node_root = node_root -> ref;
			node_ref = node_root -> ref;
		}

	}

	return false;

}*/

bool findNode(char *id_desc){

	if(root_header == NULL){
		return false;
	}

	Node *explore;
	explore = root_header;
	while( explore != NULL){
		if(strcmp(explore -> id,id_desc)){
			return true;
		}
		explore = explore -> nextRef;
	}

	return false;
}

void iterate_Nodes(){

	if(root_header == NULL){
		printf("Nothing to iterate over\n");
	}
	else{
		int counter = 0;
		Node *explore;
		explore = root_header;
		while( explore != NULL){
			printf("Node %d : %s\n",counter,explore -> id );
			counter++;
			explore = explore -> prevRef;
		}
	}
}


void iterateBack_Nodes(){

	if(root_trailer == NULL){
		printf("Nothing to iterate over\n");
	}
	else{
		int counter = 0;
		Node *explore;
		explore = root_trailer;
		while( explore != NULL){
			printf("Node %d : %s\n",counter,explore -> id );
			counter++;
			explore = explore -> nextRef;
		}
	}
}


int main(){
	
	add_node("tacitus");
	add_node("Livy");
	add_node("Horace");
	iterate_Nodes();
	iterateBack_Nodes();
	
 

}


