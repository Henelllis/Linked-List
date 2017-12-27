#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include "Linked_list.h"



int main(void){
	printf("Tried and trur\n");
	Linked_List *ll;

	ll = malloc(sizeof(Linked_List));
	init("Test");
	iterate_Nodes();


}