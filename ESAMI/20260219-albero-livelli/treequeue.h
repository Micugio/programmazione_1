
#include <iostream>

struct Node;

struct Queue;

Node * getLeftChild(Node* node);
Node * getRightChild(Node* node);
int getValue(Node* node);
void printNode(Node* node);
Node * createNode(int value);
Node * createNodeV(int value, Node* left, Node* right);
void deleteTree(Node* & root);
void printTreeDepth(Node* root, int depth = 0);
void printTree(Node* root);
int sizeOfTree(Node* root);

Queue* createQueue(int capacity);
int queueSize(Queue* queue);
bool isFull(Queue* queue);
bool isEmpty(Queue* queue);
void enqueue(Queue* queue, Node* item);
Node* dequeue(Queue* queue);
Node* front(Queue* queue);
Node* rear(Queue* queue);
void deleteQueue(Queue* queue);
void printQueue(Queue* queue);

