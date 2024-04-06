// Program to demonstrate all the tree traversal techniques and print the time complexity of each traversal

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

void postOrder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}

// Function for finding number of leaf nodes in a binary tree
int leafNodes(struct Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return leafNodes(root->left) + leafNodes(root->right);
}

// Function for finding total number of nodes in a binary tree
int totalNodes(struct Node *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

int main() {
    struct Node *root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->left = createNode('F');
    root->right->right = createNode('G');
    root->left->left->left = createNode('H');
    root->left->left->right = createNode('I');
    root->left->right->left = createNode('J');
    root->left->right->right = createNode('K');

    clock_t start, end;

    start = clock();
    printf("Preorder traversal: ");
    preOrder(root);
    end = clock();
    printf("\nPreorder time complexity: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("\nInorder traversal: ");
    inOrder(root);
    end = clock();
    printf("\nInorder time complexity: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("\nPostorder traversal: ");
    postOrder(root);
    end = clock();
    printf("\nPostorder time complexity: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("\nNumber of leaf nodes: %d\n", leafNodes(root));
    printf("Total number of nodes: %d\n", totalNodes(root));

    return 0;
}

/*
// Adit's code 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

struct node{
    char val;
    struct node* left;
    struct node* right;
};

struct node* createNode(char val){
    struct node* head = malloc(sizeof(struct node));
    head->val = val;
    head->left = NULL;
    head->right = NULL;
}

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

int height(struct node* head){
    if(head==NULL){
        return 0;
    }
    return 1+max(height(head->left),height(head->right));
}

int counter = 0;

int count = 0;

void display(struct node* head){
    if(head==NULL){
        return;
    }
    counter++;
    printf("(%c,%d) ", head->val, height(head));
    if(height(head)==1){
        count++;
    }
    display(head->left);
    display(head->right);
}

void main(){
    clock_t start,end;
    start = clock();
    struct node* head = malloc(sizeof(struct node));
    head->val = 'A';
    head->left = createNode('B');
    head->right = createNode('C');
    head->left->left = createNode('D');
    head->left->right = createNode('E');
    head->right->left = createNode('F');
    head->right->right = createNode('G');
    head->left->left->left = createNode('R');
    head->left->left->right = createNode('I');
    head->left->right->left = createNode('J');
    head->left->right->right = createNode('K');
    display(head);
    printf("\n%d %d\n", counter, count);
    end = clock();
    double time_taken = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time taken is %f\n",time_taken);
}
*/



/*
// GPT code
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* newNode(char data) 
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to traverse the binary tree in inorder
// Time complexity: O(n), Space complexity: O(h)
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// Function to traverse the binary tree in preorder
// Time complexity: O(n), Space complexity: O(h)
void preorder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to traverse the binary tree in left order (root, left, right)
// Time complexity: O(n), Space complexity: O(h)
void leftOrder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        leftOrder(root->left);
        leftOrder(root->right);
    }
}

// Function to count total nodes in the binary tree
// Time complexity: O(n), Space complexity: O(h)
int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count the number of left child nodes
// Time complexity: O(n), Space complexity: O(h)
int countLeftNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    return (root->left != NULL) + countLeftNodes(root->left) + countLeftNodes(root->right);
}

// Function to count the number of right child nodes
// Time complexity: O(n), Space complexity: O(h)
int countRightNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    return (root->right != NULL) + countRightNodes(root->left) + countRightNodes(root->right);
}

int main() {
    // Constructing the binary tree with character data values
    struct TreeNode* root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->left = newNode('F');
    root->right->right = newNode('G');
    root->left->left->left = newNode('H');
    root->left->left->right = newNode('I');
    root->left->right->left = newNode('J');
    root->left->right->right = newNode('K');

    // Displaying the binary tree
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Left order traversal: ");
    leftOrder(root);
    printf("\n");

    // Counting total nodes
    printf("Total nodes: %d\n", countNodes(root));

    // Counting left and right child nodes
    printf("Left nodes: %d\n", countLeftNodes(root));
    printf("Right nodes: %d\n", countRightNodes(root));

    return 0;
}
*/