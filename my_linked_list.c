#include <stdio.h>
#include <stdlib.h>

struct node {
  int i;
  struct node * next; // pointer to next node
};

// Should take a pointer to a node struct and print out all of the data in the list
void print_list(struct node * start) {
  while (start) {
    printf("%d\n", start->i);
    start = start->next;
  }
  //printf("%d\n",start->i);
}

/*
- Should take a pointer to the existing list and the data to be added, create a new node and put it at the beginning of the list.
- The second argument should match whatever data you contain in your nodes.
- Returns a pointer to the beginning of the list.
*/
struct node * insert_front (struct node * current_front, int val) {
  struct node * new_front = (struct node *)malloc(sizeof(struct node));
  new_front->i = val;
  new_front->next = current_front;
  return new_front;
}
// Should take a pointer to a list as a parameter and then go through the entire list freeing each node and return a pointer to the beginning of the list (which should be NULL by then).
struct node * free_list(struct node * front) {
  struct node * temp;
  while (front) {
    temp = front->next;
    free(front);
    front = temp;
  }
  return front;
}

// create a null node, each node you insert = new front node, starting node = NAME OF LL!!
int main() {
  struct node * nodee;
  nodee = NULL;
  nodee = insert_front(nodee,0);
  printf("List v1:\n");
  print_list(nodee);
  struct node * n1;
  nodee = insert_front(nodee, 1);
  printf("List v2:\n");
  print_list(nodee);
  nodee = insert_front(nodee, 2);
  printf("List v3:\n");
  print_list(nodee);
  nodee = insert_front(nodee, 3);
  printf("List v4:\n");
  print_list(nodee);
  nodee = insert_front(nodee, 4);
  printf("List v5:\n");
  print_list(nodee);
  nodee = free_list(nodee);
  printf("List v5:\n");
  print_list(nodee);
  //printf("%d\n", nodee->i);
  /*struct node n2;
  n2.i = 2;
  n2.next = NULL;
  struct node n1;
  n1.i = 1;
  n1.next = &n2;
  struct node nodee;
  nodee.i = 0;
  nodee.next = &n1;
  printf("List v1:\n");
  print_list(&nodee);
  printf("-------------------\nList v2:\n");
  print_list(insert_front(&nodee, 3));
  //free_list(&nodee); */

  return 0;
}
