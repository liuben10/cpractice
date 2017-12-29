#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

LinkedList * newLinkedListInternal(LLNode * llNode) {
	LinkedList * newLL = malloc(sizeof(LinkedList));
	newLL->hp = llNode;
	return newLL;
}

LinkedList * newLinkedList(int val) {
	return newLinkedListInternal(newLLNode(val));
}

LLNode * newLLNode(int val) {
	LLNode * res = malloc(sizeof(LLNode));
	res->val = val;
	res->next = NULL;
	return res;
}

LLNode * addLLNode(LLNode *list,  int val) {
	LLNode * node = newLLNode(val);
	list->next = node;
	return node;
}


LLNode * push(LinkedList *linkedList, int val) {
	LLNode * node = newLLNode(val);
	LLNode * iter = linkedList;
	while(iter->next != NULL) {
		iter = iter->next;
	}
	iter->next = node;
	return node;
}

void printLL(LinkedList * linkedList) {
	LLNode * iter = linkedList->hp;

	while(iter != NULL) {
		printf("%d->", iter->val);
		iter = iter->next;
	}
	printf("\n");
}

void reverseList(LinkedList * ll) {
	LLNode * reversed = reverseInternal(ll->hp);
	ll->hp = reversed;
}

LLNode * reverseInternal(LLNode * node) {
	LLNode * prev = NULL;
	LLNode * iter = node;
	while (iter != NULL) {
		LLNode * tmp = iter;
		iter = iter->next;
		tmp->next = prev;
		prev = tmp;
	}
	return prev;
}


int main() {
	LinkedList * linkedList = newLinkedList(10);
	LLNode * firstAdd = addLLNode(linkedList->hp, 66);
	addLLNode(firstAdd, 55);
	reverseList(linkedList);
	printLL(linkedList);
	return 0;
}
