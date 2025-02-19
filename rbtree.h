#ifndef _RBTREE_H
#define _RBTREE_H

#include<iostream>

using namespace std;

struct node
{#ifndef RBTREE_H
#define RBTREE_H


#include <iostream>

using namespace std;

#define RED 1
#define BLACK 0

struct Node {
	int key;
	Node *parent; 
	Node *left;
	Node *right; 
	int color; // 1 -> Red, 0 -> Black
};


class RBtree {
private:
	Node* root;
	Node* NIL;

	void preOrderTraverse(Node* node);
	void inOrderTraverse(Node* node);
	void postOrderTraverse(Node* node);

	Node* searchTreeHelper(Node* node, int key);


	void fixRemove(Node* x);
	void transplant(Node* u, Node* v);
	void removeNodeRecursive(Node* node, int key);
	
	void fixInsert(Node* k);

	void printTraverse(Node* root, string indent, bool last);

public:

	RBtree();
	~RBtree();
	void preorder();
	void inorder();
	void postorder();
	Node* searchTree(int k);
	Node* minimum(Node* node);
	Node* maximum(Node* node);
	Node* successor(Node* x);
	Node* predecessor(Node* x);
	void leftRotate(Node* x);
	void rightRotate(Node* x);
	void insert(int key);
	Node* getRoot();
	void remove(int key);
	void prettyPrint();

};





#endif // RBTREE_H

       int key;
       node *parent;
       char color;
       node *left;
       node *right;
};
class RBtree
{
      node *root;
      node *q;
   public :
      RBtree()
      {
              q=NULL;
              root=NULL;
      }
      void insert();
      void leftrotate(node *);
      void rightrotate(node *);
      void del();
      node* successor(node *);
      void display( node *);
      void search();
};

#endif
