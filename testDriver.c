#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include "Linked_list.h"



int main(void){
	printf("Tried and trur\n");
	Linked_List *ll_1;
	Linked_List *ll_2;

	ll_1 = malloc(sizeof(Linked_List));
	init("Test");
	add_node("dodod");
	add_node("kangaroo");
	iterate_Nodes();
	save_linked_list(ll_1);
	reset_linked_list();
	ll_2 = malloc(sizeof(Linked_List));
	init("Crab_Cake");
	iterate_Nodes();
	save_linked_list(ll_2);
	set_linked_list(ll_1);
	iterate_Nodes();

}