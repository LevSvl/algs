#include "string.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct Node{
  int data;
  struct Node *left;
  struct Node *right;
} node_t;

// вспомогательные операции
#define MAX(x, y) ((x > y) ? x: y)
node_t* createNode(int dstData);
int getHeight(node_t* rootNode);

// операции для работы с деревом
void push(node_t **tree, int dstData);
void freeNode(node_t **tree, int dstData);

// получение информации о дереве
void peek(node_t *rootNode);
int countNodes(node_t *rootNode);
void getTreeInfo(node_t *rootNode);

// операции вращения для балансировки
node_t* smallRightRotate(node_t *rootNode);
void smallLeftRotate(node_t *rootNode);
void bigRightRotate(node_t *rootNode);
void bigLeftRotate(node_t *rootNode);

int main(int argc, char const *argv[])
{
  node_t* tree = 0L;

  push(&tree, 10);
  push(&tree, 12);
  push(&tree, -2);
  push(&tree, 1);
  push(&tree, -3);

  push(&tree, -50);
  push(&tree, -500);
  
  peek(tree);
  printf("\n");

  getTreeInfo(tree);

  return 0;
}

node_t* createNode(int dstData)
{
  node_t *newNode;

  if ((newNode = (node_t*)malloc(sizeof(node_t)))==0){
    printf("error: malloc\n");
    exit(1);
  }

  newNode->data = dstData;
  newNode->left = newNode->right = NULL;

  return newNode;
}

void push(node_t **tree, int dstData)
{
  node_t *rootNode;
  
  rootNode = *tree;

  if(!rootNode){
    *tree = createNode(dstData);
  }else if(dstData < rootNode->data){
    if(!rootNode->left)
      rootNode->left = createNode(dstData);
    else 
      push(&rootNode->left, dstData);
  }else if(dstData > rootNode->data){
    if(!rootNode->right)
      rootNode->right = createNode(dstData);
    else 
      push(&rootNode->right, dstData);
  }

  rootNode = *tree;
  int lh, llh, rh, ch;

  if (rootNode->left){
    rh = getHeight(rootNode->right); // правое поддерево
    lh = getHeight(rootNode->left); // левое поддерево
    llh = getHeight(rootNode->left->left); // левое поддерево lh
    ch = getHeight(rootNode->left->right); // правое поддерево lh
  
    if (abs(lh - rh) == 2)
      if(ch <= llh)
        *tree = smallRightRotate(rootNode);
  }
}

void peek(node_t *rootNode)
{
  if (rootNode != NULL){
    peek(rootNode->left);
    printf("%d\t", rootNode->data);
    peek(rootNode->right);
  }
}

int getHeight(node_t* rootNode)
{
  if (!rootNode)
    return 0;

  return 1 + MAX(getHeight(rootNode->left), getHeight(rootNode->right));
}

int isBalanced(node_t *rootNode)
{
  if (!rootNode)
    return 1;

  int lh, rh;

  lh = getHeight(rootNode->left);
  rh = getHeight(rootNode->right);
  
  if(abs(lh - rh) <= 1 && isBalanced(rootNode->left) && isBalanced(rootNode->right))
    return 1;

  return 0;
}

int countNodes(node_t *rootNode)
{
  if(!rootNode)
    return 0;
  return countNodes(rootNode->left) + countNodes(rootNode->right) + 1;
}

void getTreeInfo(node_t *rootNode)
{
  printf("\n");
  printf("is balanced: %d\n", isBalanced(rootNode));
  printf("nodes nums: %d\n", countNodes(rootNode));
  printf("root node data: %d\n", rootNode->data);
}

node_t* smallRightRotate(node_t *rootNode){
  node_t *a, *b, *c;

  a = rootNode;
  b = a->left;
  c = b->right;

  a->left = c;
  b->right = a;

  return b;
}