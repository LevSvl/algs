#include "string.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct Node{
  int data;
  struct Node *left;
  struct Node *right;
} node_t;

typedef struct Tree{
  node_t* root;
  size_t level;
} tree_t;

node_t* add(node_t *root, int dstData);

int main(int argc, char const *argv[])
{
  tree_t *tree = (tree_t*)malloc(sizeof(tree_t));
  
  tree->root = add(tree->root, 6);

  printf("%d\n",tree->root->data);

  return 0;
}

node_t* add(node_t *root, int dstData)
{
  if(!root){
    root = (node_t*)malloc(sizeof(node_t));
    root->data = dstData;
    root->left = NULL;
    root->right = NULL;
    return root;
  }

  node_t *x;

  if (dstData < root->data)
    x = root->left;
  else 
    x = (dstData > root->data) ? root->right: root;

  return add(x, dstData);

}
