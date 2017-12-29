typedef struct LLNode {
	int val;
	struct LLNode * next;
} LLNode;

typedef struct LinkedList {
	struct LLNode * hp;
} LinkedList;

LinkedList * newLinkedList(int val);

void printLL(LinkedList * linkedList);

void reverseList(LinkedList * linkedList);

LLNode * addLLNode(LLNode *list,  int val);

LLNode * push(LinkedList *linkedList, int val);

LLNode * reverseInternal(LLNode * node);

LLNode * newLLNode(int val);


