#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>



typedef struct Node{
	char id[10];
	struct Node *ref;
} Node;

Node *root;


void init(char *id_desc){
	root = malloc(sizeof(Node));
	strcpy( root -> id , id_desc);
	root -> ref = NULL;
}

void add_node(char *id_desc){
	/*1 Take Root Node and make copy of it */
	/*2  Create a new Node for the root*/
	/*3 Populate that node*/
	/*4 Take the tmp node and make that the ref node for the root*/
	if(root == NULL){
		init(id_desc);
	}
	else{	
		Node *tmp;
		tmp = root;
		root  = malloc(sizeof(Node));
		strcpy( root -> id , id_desc);
		root -> ref =  tmp;
	}

}

bool remove_node(char *id_desc){

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
	}	
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

bool findNode(char *id_desc){

	if(root == NULL){
		return false;
	}

	Node *explore;
	explore = root;
	while( explore != NULL){
		if(strcmp(explore -> id,id_desc)){
			return true;
		}
		explore = explore -> ref;
	}

	return false;
}

void iterate_Nodes(){

	if(root == NULL){
		printf("Nothing to iterate over\n");
	}
	else{
		int counter = 0;
		Node *explore;
		explore = root;
		while( explore != NULL){
			printf("Node %d : %s\n",counter,explore -> id );
			counter++;
			explore = explore -> ref;
		}
	}
}


int main(){
	

	printf("in the midnight hour she asked more more more");
	printf("Im all alone\n");
	FILE *fp;
	
	fp = fopen("./testFile.txt","r");
	printf("file pointer address%x\n" , (int) &fp);
	printf("dereference pointer%s\n",  fp);

	printf("slowly but surely\n");		
	/*if( fp == NULL){
		fclose(fp);
		printf("Dont fuck with me!!");
		printf("ERROR ERROR IO ISSYE\n");
		fprintf(stderr, "Cant open file!!!!");
		return 0;
	}else{
		printf("File was found");
	}
	*/
	/* Lesson fscanf wont work with if the char pointer
	 * Has not been allocated any memory explicitely"
	 */

	char code[8];
	char *txt = malloc(sizeof(char)*5);
	char *fromTxt;
	int i;
	for(i = 0 ; fscanf(fp, "%s", txt) != EOF; i++ ){
		printf("%d : %s\n", i, txt);
	}
	fclose(fp);
}


