

#ifndef TNODE_H_
#define TNODE_H_

#include<assert.h>
#include<queue>
#include<stack>
using namespace std;
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


template<typename T>
void tree_level(TNode<T> *root, std::queue<std::queue<T> > q)
{//BFS 广度优遍历 层级遍历
	
	typedef std::queue<T> Q;
	if (root == NULL) return;
	Q q1,q2;
	q1.push(root->val);
	while(!q1.empty()){
		q2.push(q1.front());
		q1.pop();
		if(root->_left) q1.push(root->_left->val);
		if(root->_right) q1.push(root->_right->val);
	}
}


#endif






