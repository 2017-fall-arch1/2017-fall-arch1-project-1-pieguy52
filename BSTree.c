#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BSTree.h"

//bst implemintation derived from old CS 2/3 notes, lectures, labs, etc


//allocates the memory to the tree to be made
//although the *char may not have a value given immediatly storage given when called
treeNode *BSTreeAlloc(){
  treeNode *root = (treeNode *)malloc(sizeof(treeNode));
  root->lChild = NULL;
  root->rChild = NULL;
  root->name = (char *) malloc(sizeof(char)*100);
  return root;
}


//code to insert names into tree
treeNode *insertion(treeNode *node, char *nameIn){
  int len;
  char *scopy;

  //code given in insertion of ll in demo code
  for(len =0; nameIn[len]; len++)
    ;
  scopy = (char *) malloc(len+1);
  for(len = 0; nameIn[len]; len++)
    scopy[len] = nameIn[len];
  scopy[len] = 0;

  if(node == NULL){
    node = BSTreeAlloc();
    node->name = scopy;
  }else{
    int isLeft = 0;
    int comparison = 0;
    treeNode *current = node;
    treeNode *previous = NULL;

    while(current != NULL){
      comparison = strcmp(nameIn, current->name);
      previous = current;
      if(comparison < 0){
	isLeft = 1;
	current = current->lChild;
      }else{
	isLeft = 0;
	current = current->rChild;
      }
    }
    if(isLeft){
      previous->lChild = BSTreeAlloc();
      previous->lChild->name = scopy;
    }else{
      previous->rChild = BSTreeAlloc();
      previous->rChild->name = scopy;
    }
  }
  return node;
}

//deletes names from the tree
treeNode *deletion(treeNode *node, char *name){
  if(node == NULL)
    return NULL;

  treeNode *current;
  int comparison = strcmp(name, node->name);
  if(comparison < 0)
    node->lChild = deletion(node->lChild, name);
  else if(comparison > 0)
    node->rChild = deletion(node->rChild, name);
  else{ // recursive calls to delete the children nodes that get promoted as nodes get erased
    if(node->lChild == NULL){
      current = node->rChild;
      free(node);
      node = current;
    }else if(node->rChild == NULL){
      current = node->lChild;
      free(node);
      node = current;
    }else{
      current = node->rChild;
      treeNode *parent = NULL;
      while(current->lChild != NULL){
	parent = current;
	current = current->lChild;
      }
      node->name = current->name;
      if(parent != NULL)
	parent->lChild = deletion(parent->lChild, parent->lChild->name);
      else
	node->rChild = deletion(node->rChild, node->rChild->name);
    }
  }
  return node;
}

//Prints the tree recursively
//states root and both children, if applicable, and recursivley calls to said children
void printTree(treeNode *cNode){
  if(cNode == NULL)
    return;

  printf("%s", cNode->name);

  if(cNode->lChild != NULL)
    printf("\n Left Child: %s", cNode->lChild->name);
  if(cNode->rChild != NULL)
    printf("\n Right Child: %s", cNode->rChild->name);
  printf("\n");
  printTree(cNode->lChild);
  printTree(cNode->rChild);
}

//prints existing tree into file, appending to file with each print
//fputs funcitonality and usage found at tutorialspoint C - File I/O
void fprintTree(treeNode *cNode){
  if(cNode == NULL)
    return;
  
  FILE *fp;
  fp = fopen("bstOut.txt", "a");
  
  fputs(cNode->name, fp);

  if(cNode->lChild != NULL){
    fputs("\n Left Child: ", fp);
    fputs(cNode->lChild->name, fp);
  }
  if(cNode->rChild != NULL){
    fputs("\n Right Child: ", fp);
    fputs(cNode->rChild->name, fp);
  }
  
  fputs("\n", fp);
  fclose(fp);
  
  fprintTree(cNode->lChild);
  fprintTree(cNode->rChild);
}
