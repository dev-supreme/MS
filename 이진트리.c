#include <stdio.h>
#include <stdlib.h>
#include <strings.h> 
 
typedef struct {
int data;
struct Node* leftChild;
struct Node* rightChild;
} Node;



//이진트리 삽입 
Node* insertNode(Node* root, int data) {
if (root == NULL) {
root = (Node*)malloc(sizeof(Node));
root->leftChild = root->rightChild = NULL;
root->data = data;
return root;
}
else {
if (root->data > data) {
root->leftChild = insertNode(root->leftChild, data);
}
else {
root->rightChild = insertNode(root->rightChild, data);
}
}
return root;
}

// 이진트리 탐색 
Node* searchNode(Node* root, int data) {
if (root == NULL) return NULL;
if (root->data == data) return root;
else if (root->data > data) return searchNode(root->leftChild, data);
else return searchNode(root->rightChild, data);
}


//이진트리 삭제

Node* deleteNode(Node* root, int data) {
Node* node = NULL;
if (root == NULL) return NULL;
if (root->data > data) root->leftChild = deleteNode(root->leftChild, data);
else if (root->data < data) root->rightChild = deleteNode(root->rightChild, data);
else {
if (root->leftChild != NULL && root->rightChild != NULL) {
node = findMinNode(root->rightChild);
root->data = node->data;
root->rightChild = deleteNode(root->rightChild, node->data);
}
else {
node = (root->leftChild != NULL) ? root->leftChild : root->rightChild;
free(root);
return node;
}
}
return root;
}

int main(void) {
Node* root = NULL;
root = insertNode(root, 30);
root = insertNode(root, 17);
root = insertNode(root, 48);
root = insertNode(root, 5);
root = insertNode(root, 23);
root = insertNode(root, 37);
root = insertNode(root, 50);
root = deleteNode(root, 30);
system("pause");
}
