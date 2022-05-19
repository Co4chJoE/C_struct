#include <stdio.h>
#include <stdlib.h>

/**
 * define the struct of list node
 */
typedef struct Node {
    int data;
    struct Node* next;
}Node;

/**
 * init a link list
 * @return the head pointer of link list's head
 */
Node* initList() {
    Node* L = (Node*)malloc(sizeof(Node));
    L -> data = 0;
    L -> next = NULL;
    return L;
}

/**
 * insert item in link list's head
 * @param L the head pointer of link list
 * @param data  the data you want to insert
 */
void headInsert(Node* L, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = L->next;
    L -> next = node;
    L -> data ++;
}

/**
 * insert item in link list's tail
 * @param L the head pointer of link list
 * @param data the data you want to insert
 */
void tailInsert(Node* L, int data) {
	Node* head=L;
	Node* node=(Node*)malloc(sizeof(Node));
	node -> data =data;
	node -> next =NULL;
	L = L -> next;
	while (L->next){
	L=L -> next;
	}
	L -> next =node;
	head -> data++;
}
/**
 * delete item in link list
 * @param L the head pointer of link list
 * @param data the data you want to delete
 * @return success flag
 */
int delete(Node* L, int data) {
    Node* preNode = L;
    Node* node = L -> next;
    while(node){
        if(node -> data == data) {
            preNode -> next = node->next;
            free(node);
            L -> data --;
            break;
        }
        preNode = node;
        node = node -> next;
    }
}

/**
 * print all items in a link list
 * @param L the head pointer of link list
 */
void printList(Node* L) {
    Node* node = L -> next;
    while(node){
        printf("%d ", node -> data);
        node = node -> next;
    }
    printf("\n");
}

/**
 * main function
 * @return null
 */
int main() {
    Node* L = initList();
    headInsert(L, 1);
    headInsert(L, 3);
    headInsert(L, 4);
    tailInsert(L,3);
    tailInsert(L, 6);
    tailInsert(L, 7);
    printList(L);

    delete(L, 3);
    printList(L);
    return 0;
}