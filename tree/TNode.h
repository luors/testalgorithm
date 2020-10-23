

#ifndef TNODE_H_
#define TNODE_H_

#include<assert.h>
#include<queue>
#include<stack>
using namespace std;
namespace TNodeSP{
template<typename T>
struct TNode{
	T val;
	struct TNode* _left;
	struct TNode* _right;
	
};

//typedef struct TNode TNode;

//create new_node


template<typename T>
TNode<T> *CreateNode(const T& val){
	TNode<T> *o = new TNode<T>;
	o->val = val;
	o->_left = NULL;
	o->_right = NULL;
	//std::cout << "create node " << val << " " << o->val << endl;
	return o;
}
template<typename T>
void FreeNode(TNode<T> *node){
	
	if (node == NULL) return;
	delete node;
	node = NULL;
}

//insert new_node to left child and return it
template<typename T>
TNode<T>* l_insert(TNode<T>* cur,const T& val){
	assert(cur->_left == NULL);
	TNode<T>* new_node = CreateNode(val);
	cur->_left = new_node;
	return new_node;
}

//insert new_node to right child and return it
template<typename T>
TNode<T>* r_insert(TNode<T>* cur,const T& val){
	assert(cur->_right == NULL);
	TNode<T>* new_node = CreateNode(val);
	cur->_right = new_node;
	return new_node;
}

template<typename T>
int getDepth(TNode<T> *root){
	if(root == NULL) return 0;
	//std::cout << "????" << root->val << endl;
	int l = getDepth(root->_left);
	int r = getDepth(root->_right);
	return 1 + ((l >= r)?l:r);
}

typedef void (*VisitFunc)(void*);

//先序遍历
template<typename T>
void tree_preOrder(TNode<T> *root, VisitFunc f){
	
	if (root == NULL) return;
	(*f)((void*)root);
	tree_preOrder(root->_left,f);
	tree_preOrder(root->_right,f);
}

//中序遍历
template<typename T>
void tree_midOrder(TNode<T> *root, VisitFunc f){
	
	if (root == NULL) return;
	tree_midOrder(root->_left,f);
	(*f)((void*)root);
	tree_midOrder(root->_right,f);
}

//后序遍历
template<typename T>
void tree_postOrder(TNode<T> *root, VisitFunc f){
	if (root == NULL) return;
	tree_postOrder(root->_left,f);
	tree_postOrder(root->_right,f);
	(*f)((void*)root);
}

template<typename T>
void tree_levelOrder(TNode<T> *root, VisitFunc f)
{//BFS 广度优先遍历 层级遍历
	
	typedef std::queue<TNode<T>*> QTYPE;
	QTYPE q;
	while(root != NULL)
	{
		(*f)( (void*)root);
		if (root->_left != NULL){
			q.push(root->_left);
		}
		if (root->_right != NULL){
			q.push(root->_right);
		}
		
		if ( !q.empty()){
			root = q.front();
			q.pop();
		}
		else return;
	}
}


void tnode_test();

}
#endif






