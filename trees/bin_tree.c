#include "string.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct Node{
  int data;
  struct Node *left;
  struct Node *right;
} node_t;

node_t* createNode(int dstData);
void push(node_t **tree, int dstData);
void peek(node_t *rootNode);

int main(int argc, char const *argv[])
{
  node_t* tree = NULL;

  push(&tree, 10);
  push(&tree, 12);
  push(&tree, 112);
  push(&tree, -2);
  push(&tree, 1);
  push(&tree, 10000);

  peek(tree);

  printf("\n");

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
  node_t *newNode, *rootNode;
  
  newNode = createNode(dstData);
  rootNode = *tree;

  if(!rootNode){
    *tree = newNode;
  }else if(dstData < rootNode->data){
    if(!rootNode->left)
      rootNode->left = newNode;
    else 
      push(&rootNode->left, dstData);
  }else if(dstData > rootNode->data){
    if(!rootNode->right)
      rootNode->right = newNode;
    else 
      push(&rootNode->right, dstData);
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
