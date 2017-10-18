#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BSTree.h"

int gets_n(char *s, int limit){
  char *p = s;
  char c;
  if(fgets(s, limit, stdin)){
    while((c = *p) && c != '\n')
      p++;
    if(c == '\n')
      *p = 0;
  }
  return(p-s);
}

int main(){
  char buf[100];
  treeNode *root = NULL;
  char ans[100];
  
  while(ans[0] != '9'){
    printf("Would you like to 1: Insert names, 2: Delete names, 3: Print all names in tree, 9: exit. (1, 2, 3, 9)\n");
    printf("Enter selection: ");
    fgets(ans, 100, stdin);
    switch(ans[0]){
    case '1':
      printf("Start inputing names: ");
      while(gets_n(buf, 100))
	root = insertion(root, buf);
      break;
    case '2':
      printf("Insert name to delete: ");
      while(gets_n(buf, 100))
	root = deletion(root, buf);
      break;
    case '3':
      printTree(root);
      break;
    case '9':
      printf("Goodbye, closing.\n");
      break;
    default:
      printf("Invalid input. Valid inputs 1, 2, 3, or 9.\n");
      break;
    }
  }
  
}
