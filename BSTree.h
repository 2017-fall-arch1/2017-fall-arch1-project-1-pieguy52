#ifndef BSTree_included
#define BSTree_included

//type that makes the bst
typedef struct BSTreeNode{
  struct BSTreeNode *rChild;
  struct BSTreeNode *lChild;
  char *name;
} treeNode;

//allocates memory to nodes
treeNode *BSTreeAlloc();

//inserts names into the tree
treeNode *insertion(treeNode *node, char *nameIn);

//removes nodes via name
treeNode *deletion(treeNode *node, char *name);

//prints the tree to the user
void printTree(treeNode *cNode);

//prints the tree to an output file
void fprintTree(treeNode *cNode);
#endif 
