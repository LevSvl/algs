#include "stdio.h"
#include "stdlib.h"

// O(n^2)

typedef struct Node{
  int data;
  struct Node *next;
} node_t;

typedef struct List{
  node_t *head;
  node_t *tail;
} list_t;

void init(list_t **list);
void push(list_t *list, int data);
void removeDubplicates(list_t *list);
void printList(list_t *list);

int main(int argc, char const *argv[])
{
  list_t *list;
  int n;

  printf("size of list: ");
  scanf("%d", &n);

  init(&list);

  for(int i = 0; i < n; i++){
    int data;
    
    printf("%d: data: ", i);
    scanf("%d", &data);

    push(list, data);

  }

  printList(list);
  
  removeDubplicates(list);
  
  printList(list);

  return 0;
}

void init(list_t **listptr)
{
  *listptr = (list_t*)malloc(sizeof(list_t));
  (*listptr)->head = (*listptr)->tail = NULL;

}

void printList(list_t *list)
{
  node_t *p;
  p = list->head;

  while (p->next)
  {
    printf("%d-->", p->data);
    p = p->next;
  }
  printf("%d", p->data);
  printf("\n");
}

void push(list_t *list, int data)
{
  node_t *newNode;
  
  newNode = (node_t*)malloc(sizeof(node_t));
  
  if(list->tail != NULL)
    newNode->next = list->head;
  else
    list->tail = newNode;
  
  list->head = newNode;
  newNode->data = data;
};

void removeDubplicates(list_t *list)
{
  node_t *p;

  p = list->head;
  
  while(p->next){
    node_t* pp, *ppPrev;

    pp = list->head;

    while (pp){
      if (pp->data == p->data && pp != p){
        if(pp->next)
          ppPrev->next = pp->next;
      }
      else
        ppPrev = pp;
      
      pp = pp->next;
    }
    p = p->next;
  }
}