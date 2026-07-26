
#include <iostream>
#include "treequeue.h"

struct Node {
    int value;
    Node* left;
    Node* right;
};

struct Queue {
    Node** data;
    int front;
    int rear;
    int capacity;
    int size;
};

int getValue(Node* node) {
    return node ? node->value : 0;
}

Node * getLeftChild(Node* node) {
    return node ? node->left : nullptr;
}
Node * getRightChild(Node* node) {
    return node ? node->right : nullptr;
}
void printNode(Node* node) {
    if (node) {
        std::cout << node->value << " ";
    } else {
        std::cout << "null ";
    }
}

Node * createNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node * createNodeV(int value, Node* left, Node* right) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

void deleteTree(Node* & root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

void printTreeDepth(Node* root, int depth) {
    if (root == nullptr) {
        return;
    }
    printTreeDepth(root->right, depth + 1);
    for (int i = 0; i < depth; ++i) {
        std::cout << "   ";
    }
    printNode(root);
    std::cout << std::endl;
    printTreeDepth(root->left, depth + 1);
}

void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    printNode(root);
    printTree(root->left);
    printTree(root->right);
}
int sizeOfTree(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

Queue* createQueue(int capacity) {
    Queue* queue = new Queue;
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = new Node*[capacity];
    return queue;
}

int queueSize(Queue* queue) {
    return queue->size;
}

bool isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}
bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}
void enqueue(Queue* queue, Node* item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size++;
}
Node* dequeue(Queue* queue) {
    if (isEmpty(queue))
        return nullptr;
    Node* item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}
Node* front(Queue* queue) {
    if (isEmpty(queue))
        return nullptr;
    return queue->data[queue->front];
}
Node* rear(Queue* queue) {
    if (isEmpty(queue))
        return nullptr;
    return queue->data[queue->rear];
}
void deleteQueue(Queue* queue) {
    delete[] queue->data;
    delete queue;
}

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        return;
    }
    int count = queue->size;
    int index = queue->front;
    while (count--) {
        Node* node = queue->data[index];
        // Assuming a function printNode exists to print Node details
        printNode(node);
        index = (index + 1) % queue->capacity;
    }
    std::cout << std::endl;
}

