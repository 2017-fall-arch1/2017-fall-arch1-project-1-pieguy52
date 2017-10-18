#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BSTree.h"

//funciton for reading keyboard inputs and cutting off trailing \n provided
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

//Holds the user interface and the tree which is to be made and used for all operations
//File type, fopen, feof all gotten from the YouTuber 'thenewboston' and his video C Programming Tutorial - 51 - How to Read Files
//strtok functionality and explination found on stack overflow
//Basic funcitonality learned and used, rest of implementation my own

int main(){
  int limit = 100;
  char buf[limit];
  treeNode *root = NULL;
  char ans[limit];
  char fileRead[limit];
  FILE* fp;

  while(ans[0] != '9'){
    
    printf("Would you like to 1: Insert names, 2: Delete names, 3: Print all names in tree, 4: Read from a file, 5: Write tree into file, 9: exit. (1, 2, 3, 4, 5, 9)\n");
    printf("Enter selection: ");
    fgets(ans, limit, stdin);

    switch(ans[0]){
    case '1':
      printf("Start inputing names: ");
      while(gets_n(buf, limit))
	root = insertion(root, buf);
      break;
    case '2':
      printf("Insert name to delete: ");
      while(gets_n(buf, limit))
	root = deletion(root, buf);
      break;
    case '3':
      printTree(root);
      break;
    case '4':
      printf("File being read is 'bstFile.txt'.\n");
      fp = fopen("bstFile.txt", "r");
      while(!feof(fp)){
	fgets(fileRead, limit, fp);
	strtok(fileRead, "\n");
	root = insertion(root, fileRead);
      }
      fclose(fp);
      break;
    case '5':
      printf("Printing tree to file 'bstOut.txt'.");
      fprintTree(root);
      break;
    case '9':
      printf("Goodbye, closing.\n");
      break;
    default:
      printf("Invalid input. Valid inputs 1, 2, 3, or 9.\n");
      break;
    }
  }
  return 0;
}
