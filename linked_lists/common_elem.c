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
void destroy(list_t **list);
void push(list_t *list, int data);
void outputCommonELem(list_t *list1, list_t *list2);
void printList(list_t *list);

int main(int argc, char const *argv[])
{
  list_t *list1, *list2;
  int n, m;

  printf("size of list 1: ");
  scanf("%d", &n);

  printf("size of list 2: ");
  scanf("%d", &m);

  init(&list1);
  init(&list2);

  printf("input data for list 1\n");
  for(int i = 0; i < n; i++){
    int data;
    
    printf("%d: data: ", i);
    scanf("%d", &data);

    push(list1, data);

  }

  printf("input data for list 2\n");
  for(int i = 0; i < m; i++){
    int data;
    
    printf("%d: data: ", i);
    scanf("%d", &data);

    push(list2, data);

  }

  printList(list1);
  printList(list2);

  outputCommonELem(list1, list2);


  destroy(&list1);
  destroy(&list2);
  
  return 0;
}

void init(list_t **listptr)
{
  *listptr = (list_t*)malloc(sizeof(list_t));
  (*listptr)->head = (*listptr)->tail = NULL;
}

void destroy(list_t **listptr)
{
  node_t *p;
  p = (*listptr)->head;
  
  while(p){
    node_t* tmp = p->next;
    (*listptr)->head = tmp;

    free(p);

    p = tmp;
  }
  free(*listptr);
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

void outputCommonELem(list_t *list1, list_t *list2)
{
  node_t *p1, *p2;

  p1 = list1->head;

  while (p1){
    p2 = list2->head;
    while(p2){
      if(p1->data == p2->data)
        printf("%d is common elem\n", p1->data);
      p2 = p2->next;
    }
    
    p1 = p1->next;
  }
  
}