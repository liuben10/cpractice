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

int hasCycle(LinkedList * ll) {
	LLNode * slow = ll->hp;
	if (slow->next == NULL) {
		return 0;
	}
	LLNode * fast = slow->next;
	while (fast != NULL && fast != slow) {
		if (fast->next == NULL) {
			return 0;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	if (fast == NULL) {
		return 0;
	} else {
		return 1;
	}
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

void checkReverse() {
	printf("\n==Reverse==\n");
	LinkedList * linkedList = newLinkedList(10);
	LLNode * firstAdd = addLLNode(linkedList->hp, 66);
	addLLNode(firstAdd, 55);
	reverseList(linkedList);
	printLL(linkedList);
	printf("\n===========\n");
}

void checkCycle() {
	printf("\n==Cycle==\n");
	LinkedList * linkedList = newLinkedList(500);
	LLNode * firstAdd = addLLNode(linkedList->hp, 66);
	LLNode * secondAdd = addLLNode(firstAdd, 55);
	addLLNode(secondAdd, 27);
	printf("Has Cycle: %d", hasCycle(linkedList));
	printf("\n=========\n");
}

int main() {
	checkReverse();
	checkCycle();
	return 0;
}
