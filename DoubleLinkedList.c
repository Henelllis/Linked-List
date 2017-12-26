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

bool remove_node(char *id_desc){

	//If Node does not exist
	//why bother trying to remove it
	if(root_header == NULL){
		return false;
	}

	//remove corner case for only one node in the list
	if(strcmp(root_header -> id, id_desc) == 0 && root_header == root_trailer){
	 	//There is only one entry in the chain
	 	root_header = NULL;
	 	root_trailer = NULL;
	 	return true;
	}

	//remove corner case that the last node is being removed
	if(strcmp(root_trailer -> id, id_desc) == 0 ){
		//assumption that root_trailer always has a Prev pointer to
		// Null pointer 

		//Find the root trailers Next Reference Node and make that the
		// new root trailer node
		root_trailer = root_trailer -> nextRef; 

		//now the next block is the trailer we must free the memory
		// from the previous node that was the Node
		free(root_trailer -> prevRef);

		//now that we took care of a potentional memory leak 
		//we move onto assigned the prev of this root trailer
		//to be null
		root_trailer -> prevRef = NULL;

		return true;
	}


	//remove corner case that the header node is being removed
	if(strcmp( root_header -> id, id_desc) == 0 ){
		//assumption that root_trailer always has a Prev pointer to
		// Null pointer 

		//Find the header trailers prev Reference Node and make that the
		// new root geader node
		root_header = root_header -> prevRef; 

		//now the next block is the trailer we must free the memory
		// from the previous node that was the Node
		free(root_header -> nextRef);

		//now that we took care of a potentional memory leak 
		//we move onto assigned the next of this root header
		//to be null
		root_header -> nextRef = NULL;

		return true;
	}

	//now we must iterate through chain until we find the node we need
	//take a node that we need

	Node *iterate;
	Node *prevIterate;
	Node *nextIterate;

	//we can work foward even though we can go back and forth
	// MY LIST MY RULES!!!!!!!!!!!!!!!!!

	iterate = root_header -> prevRef;

	while( iterate != NULL){
		
		prevIterate = iterate -> prevRef;
		nextIterate = iterate -> nextRef;

		if(strcmp(iterate -> id, id_desc) == 0){
			prevIterate -> nextRef = nextIterate;
			nextIterate -> prevRef = prevIterate;
			free(iterate);
			return true;
		}

		iterate = iterate -> prevRef;
	}




	return false;
}

	/*

	if(strcmp(root_trailer -> id, id_desc) == 0 ){
		//assumption that root_trailer always has a Prev pointer to
		// Null pointer 

		//The next block upwards in 
		root_trailer = root_trailer -> nextRef; 

	}

	//Check to see if the trailer node contains the removed key word idn
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

}
*/

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
//	add_node("Livy");
//	add_node("Horace");
	iterate_Nodes();
//	iterateBack_Nodes();!
	printf("What is the result : %d \n", remove_node("tacitus"));

	
 	iterate_Nodes();

 	add_node("Livy");
 	add_node("Horace");
	add_node("tacitus");

 	iterate_Nodes();
 	iterateBack_Nodes();

	printf("What is the result : %d \n", remove_node("Livy"));

	iterate_Nodes();
	iterateBack_Nodes();

	add_node("Suetonius");
	add_node("pickle");
	add_node("carrit");
	add_node("Plato");

	 	
	iterate_Nodes();
	iterateBack_Nodes();

/*
	printf("What is the result : %d \n", remove_node("Plato"));


 	iterate_Nodes();
	iterateBack_Nodes();
*/

	printf("What is the result : %d \n", remove_node("carrit"));

 	iterate_Nodes();
	iterateBack_Nodes();

	printf("What is the result : %d \n", remove_node("tacitus"));

 	iterate_Nodes();
	iterateBack_Nodes();


}


