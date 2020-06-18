//thuyvy nguyen
//assignment 5
//10 june 2018
//everything about  linked lists
//input - nums for list
//output - ordered lists



#include "list.h"
#include <stdio.h>
#include <stdlib.h>


//function: length
//description: returns length of linked list
//parameters: the linked list
//pre: no length of linked list
//post: returns length of linked list

int length(struct node * head){ //get the length of the list
  struct node * current = head;
  int n = 0;
  while (current != NULL){
    n++;
    current = current->next;
  }
  return n;
}


//function: print
//description: prints out all the values at the nodes
//parameters: linked list and length of linked list
//pre: not printed out
//post: printed out
void print(struct node * head, int j){ //print a certain number of elements from the list starting with the first node
  int i;
  struct node * temp = head;
  for (i = 0; i < j; i++ ){
    printf("Node at: %d = %d \n",i, temp->val);
    temp = temp -> next;
  }
}


//function: push
//description: adds a new node at the beginning of the list
//parameters: linked list and the number
//pre: node not added
//post: node added
struct node * push(struct node * head, int i){ //put at front
  struct node * temp = malloc(sizeof(struct node));
  temp-> val = i;
  temp->next = head;
  head = temp;
  return head;

}

//function: append
//description: adds a  node at the end of the list
//parameters: linked list and value to add
//pre: node not added
//post:node added
struct node * append(struct node * head, int i){ //put at back
  struct node * temp = malloc(sizeof(struct node));
  struct node * current = head;
  temp-> val = i;
  temp->next = NULL;

  if (head == NULL){
    head = temp;
    return head;
  }



  while (current-> next != NULL){
    current = current-> next;
  }
  current-> next = temp;
  return head;

}

//function:clear
//description: deletes entire list
//parameters: linked list
//pre: has memory
//post: memory deleted

struct node * clear(struct node * head){ //delete entire list
  struct node * current = head;
  struct node * temp;

  while (current != NULL){
    temp = current-> next;
    free(current);
    current = temp;
  }
  head = NULL;

  return head;
}

//function: remove_node
//description: deletes a specific node from a linked list
//parameters: linked list and index
//pre: node is there
//post: node is not there

struct node * remove_node(struct node * head, int i){ //delete a particular node
  int c;
  struct node * current = head;
//  struct node * after_deleted = malloc(sizeof(struct node));
  struct node * delete = malloc(sizeof(struct node));

  for (c = 0; c < i-1; c++){
    current = current-> next;
  }
  delete = current->next;
  current->next =  delete->next;
  free(delete);
  free(current);
  return head;

}

//function: sort_ascending
//description: sorts the lined list in ascending order
//parameters: linked list
//pre: list not sorted
//post: list sorted
struct node * sort_ascending(struct node * head){ //sort the nodes in ascending order
  struct node * current, * temp, * move;
  current = head;
  head = NULL;

  while (current != NULL){
    temp = current;
    current = current-> next;
    if (head != NULL){
      if (temp-> val > head->val){
        move = head;
        while (( move->next != NULL) && (temp->val > move ->next->val)){
          move = move->next;
        }
        temp-> next = move->next;
        move->next = temp;
      }
      else{
        temp-> next = head;
        head = temp;
      }
    }
    else{
        temp-> next = NULL;
        head = temp;
    }
  }
    return head;
}

//function: sort_descending
//description: sorts the lined list in ascending order
//parameters: linked list
//pre: list not sorted
//post: list sorted
struct node * sort_descending(struct node * head){ //sort the nodes in descending order
  struct node * current, * temp, * move;
  current = head;
  head = NULL;

while (current != NULL){
  temp = current;
  current = current-> next;
  if (head != NULL){
    if (temp-> val < head->val){
      move = head;
      while (( move->next != NULL) && (temp->val > move ->next->val)){
        move = move->next;
      }
      temp-> next = move->next;
      move->next = temp;
    }
    else{
      temp-> next = head;
      head = temp;
    }
  }
  else{
      temp-> next = NULL;
      head = temp;
  }
}
  return head;
}

//function: insert_middle
//description: inserts node in the middle of the list
//parameters: linked list int val and int index
//pre: no int at index
//post: int added at index
struct node * insert_middle(struct node * head, int val, int idx){
  struct node * current = head;
  struct node * after;
  struct node * temp = malloc(sizeof(struct node));
  int i = 0;
  idx = idx -1;

  temp->val = val;

  for (i = 0; i < idx ; i++){
    current = current->next;
  }
  after = current->next;
  current-> next = temp;
  temp ->next = after;
  return head;
}
