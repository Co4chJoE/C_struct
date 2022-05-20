#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

Node* initList(){
	Node* L=(Node*)malloc(sizeof(Node));
	L -> data = 0;
	L -> pre = NULL;
	L -> next = NULL;
	return L;
}

void headInsert(Node* L,int data){
	Node* node=(Node*)malloc(sizeof(Node));
	node -> data = data;
	if(L -> data == 0){
		//list null
		node -> next = L -> next;
		node -> pre = L;
		L -> next = node;
	}
	else{
		node -> pre = L;
		node -> next = L -> next;
		L -> next -> pre = node;
		L -> next = node;
	}
	L -> data++;
}

void tailInsert(Node* L,int data){
	Node* node = L;
	Node* n = (Node*)malloc(sizeof(Node));
	n -> data=data;
	//to tail
	while(node->next){
		node = node -> next;
	}
	n -> next = node ->next;
	node -> next = n;
	n -> pre =node;
	L -> data++;
}

int delete(Node* L,int data){
	Node* node = L -> next;
	while(node){
		//delete
		if (node -> data == data){
			node -> pre -> next = node -> next;
			node -> next -> pre = node -> pre;
			L -> data--;
			free(node);
			return TRUE;
		}
		node = node -> next;
	}
	return FALSE;
}

void printList(Node* L){
	Node* node = L -> next;
	while(node){
		printf("%d ->",node ->data);
		node = node -> next;
	}
	printf("NULL\n");
}


int main(){
	Node* L = initList();
	headInsert(L,1);
	headInsert(L,2);
	headInsert(L,3);
	headInsert(L,4);
	tailInsert(L,6);
	printList(L);
	delete(L,1);
	printList(L);
	return 0;
}