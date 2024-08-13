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
int getHeight(node_t *rootNode);
int isBalanced(node_t *rootNode);
void balance(node_t **tree);
node_t* getGreaterChild(node_t *rootNode);

// операции для работы с деревом
void push(node_t **tree, int dstData);
node_t* freeNode(node_t **tree, int dstData);
node_t* findClosest(node_t *rootNode, int x);

// получение информации о дереве
void peek(node_t *rootNode);
int countNodes(node_t *rootNode);
void getTreeInfo(node_t *rootNode);

// операции вращения для балансировки
node_t* smallRightRotate(node_t *rootNode);
node_t* smallLeftRotate(node_t *rootNode);

// тесты
void rightSmallRotationTest(node_t **tree);
void rightBigRotationTest(node_t **tree);
void removeNodeTest(node_t **tree);
void findClosestTest(node_t** tree);

int main(int argc, char const *argv[])
{
  node_t* tree = 0L;
  rightBigRotationTest(&tree);
  getTreeInfo(tree);

  tree = 0L;
  rightSmallRotationTest(&tree);
  getTreeInfo(tree);

  tree = 0L;
  removeNodeTest(&tree);
  getTreeInfo(tree);

  tree = 0L;
  findClosestTest(&tree);
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
  balance(tree);
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
  peek(rootNode);
  printf("\n");
  printf("is balanced: %d\n", isBalanced(rootNode));
  printf("nodes nums: %d\n", countNodes(rootNode));
  printf("root node data: %d\n", rootNode->data);
}

void balance(node_t **tree)
{
  node_t *rootNode;

  rootNode = *tree;
  int lh, rh, ch;

  if (rootNode->left){
    int llh;

    rh = getHeight(rootNode->right); // правое поддерево
    lh = getHeight(rootNode->left); // левое поддерево
    llh = getHeight(rootNode->left->left); // левое поддерево lh
    ch = getHeight(rootNode->left->right); // правое поддерево lh
  
    if (lh - rh == 2 && (ch <= llh))
      *tree = smallRightRotate(*tree);
    else if (lh - rh == 1 && ch - rh == 2){
      *tree = smallLeftRotate(*tree);
      *tree = smallRightRotate(*tree);
    }
  }
  if (rootNode->right){
    int rrh;

    rh = getHeight(rootNode->right); // правое поддерево
    lh = getHeight(rootNode->left); // левое поддерево
    rrh = getHeight(rootNode->right->right); // правое поддерево rh
    ch = getHeight(rootNode->right->left); // левое поддерево rh
  
    if (rh - lh == 2 && (ch <= rrh))
      *tree = smallLeftRotate(*tree);
    else if (rh - lh == 1 && ch - lh == 2){
      *tree = smallRightRotate(*tree);
      *tree = smallLeftRotate(*tree);
    }
  }
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

node_t* smallLeftRotate(node_t *rootNode){
  node_t *a, *b, *c;

  a = rootNode;
  b = a->right;
  c = b->left;

  a->right = c;
  b->left = a;

  return b;  
}

node_t* freeNode(node_t **tree, int dstData)
{
  node_t *rootNode;

  rootNode = *tree;

  if(!rootNode)
    return rootNode;
  if(dstData < rootNode->data){
    rootNode->left = freeNode(&rootNode->left, dstData);
  }
  else if(dstData > rootNode->data){
    rootNode->right = freeNode(&rootNode->right, dstData);
  }
  else{
    if (!rootNode->left) {
      node_t* tmp = rootNode->right;
      free(rootNode);
      return tmp;
    }

    if (!rootNode->right) {
      node_t* tmp = rootNode->left;
      free(rootNode);
      return tmp;
    }

    node_t* nodeWithGreaterData = getGreaterChild(rootNode);
    rootNode->data = nodeWithGreaterData->data;
    rootNode->right = freeNode(&rootNode->right, nodeWithGreaterData->data);
  }
  balance(&rootNode);
  return rootNode;
}

node_t* getGreaterChild(node_t *rootNode) 
{
  rootNode = rootNode->right;
  while (rootNode != NULL && rootNode->left != NULL)
    rootNode = rootNode->left;
  return rootNode;
}

node_t* findClosest(node_t *rootNode, int x)
{
  if (!rootNode)
    return NULL;
  
  node_t *xNodeOrClosest;

  if(x < rootNode->data)
    xNodeOrClosest = findClosest(rootNode->left, x);
  else if(x > rootNode->data)
    xNodeOrClosest = findClosest(rootNode->right, x);
  else{
    return rootNode;
  }

  if(!xNodeOrClosest)
    return rootNode;
  if(xNodeOrClosest->data == x)
    return rootNode;
  else{
    int parentData, closestData;

    parentData = rootNode->data;
    closestData = xNodeOrClosest->data;

    if(abs(parentData - x) < abs(closestData - x))
      return rootNode;
    else
      return xNodeOrClosest;
  }
}

void rightBigRotationTest(node_t **tree)
{
  push(tree, 13);
  push(tree, 15);
  push(tree, 10);
  push(tree, 11);
  push(tree, 16);
  push(tree, 5);
  push(tree, 4);
  push(tree, 6);
  push(tree, 18);

  if(isBalanced(*tree))
    printf("Right big rotation Test is OK\n");
  else
    printf("Right big rotation Test is FAILED\n");
}

void rightSmallRotationTest(node_t **tree)
{
  push(tree, 10);
  push(tree, 12);
  push(tree, -2);
  push(tree, 1);
  push(tree, -3);
  push(tree, -50);
  push(tree, -500);

  if(isBalanced(*tree))
    printf("Right small rotation Test is OK\n");
  else
    printf("Right small rotation Test is FAILED\n");
}

void removeNodeTest(node_t **tree)
{
  int oldSize, newSize;
  node_t *oldRoot, *newRoot;

  push(tree, 10);
  push(tree, 12);
  push(tree, -2);
  push(tree, 1);
  push(tree, -3);
  push(tree, -50);
  push(tree, -500);
  
  oldSize = countNodes(*tree);
  *tree = freeNode(tree, -50);
  newSize = countNodes(*tree);

  oldRoot = *tree;
  *tree = freeNode(tree, -23232);
  *tree = freeNode(tree, -22);
  *tree = freeNode(tree, 22);
  newRoot = *tree;

  *tree = freeNode(tree, -2);

  if(oldRoot != newRoot || (oldSize - newSize != 1) || isBalanced(*tree))
    printf("Remove Node Test is OK\n");
  else
    printf("Remove Node Test is FAILED\n");
}

void findClosestTest(node_t** tree)
{
  push(tree, 4);
  push(tree, 2);
  push(tree, 7);
  push(tree, 1);
  push(tree, 3);
  push(tree, 6);
  push(tree, 8);

  node_t* result;
  int x, target;
  x = 0;
  target = 1;

  result = findClosest(*tree, x);
  if(!result){
    printf("Find closest Test is FAILED\n");
    return;
  }

  printf("target: %d, finded: %d \n", target, result->data);
  if(result->data != target){
    printf("Find closest Test is FAILED\n");
  }else{
    printf("Find closest Test is OK\n");
  }
}