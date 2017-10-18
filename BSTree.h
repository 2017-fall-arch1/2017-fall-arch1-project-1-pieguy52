#ifndef BSTree_included
#define BSTree_included

typedef struct BSTreeNode{
  struct BSTreeNode *rChild;
  struct BSTreeNode *lChild;
  char *name;
} treeNode;

treeNode *BSTreeAlloc();

treeNode *insertion(treeNode *node, char *nameIn);

treeNode *deletion(treeNode *node, char *name);

void printTree(treeNode *cNode);

void fprintTree(treeNode *cNode);
#endif 
