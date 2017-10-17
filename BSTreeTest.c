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

  while(gets_n(buf, 100))
    root = insertion(root, buf);

  printTree(root);
}
