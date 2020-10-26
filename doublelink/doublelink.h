#ifndef __DoubleLinkNode_H_
#define __DoubleLinkNode_H_
#include<iostream>
#include<assert.h>
using namespace std;

namespace DLINK{

typedef struct DoubleLinkNode{
	int val;
	DoubleLinkNode *PreNode;
	DoubleLinkNode *NextNode;
	DoubleLinkNode():val(0),PreNode(nullptr),NextNode(nullptr){
	};
	~DoubleLinkNode(){
		PreNode = nullptr;
		NextNode = nullptr;
		std::cout << "~DoubleLinkNode" << endl;
	}
}DoubleLinkNode;


DoubleLinkNode*
CreateNode( const int &val)
{
	DoubleLinkNode* N = new DoubleLinkNode();
	N->val = val;
	return N;
}


DoubleLinkNode* HeadInsert(DoubleLinkNode* &root, const int &val){
	DoubleLinkNode*N = CreateNode(val);	
	N->NextNode = root;
	if (root != nullptr){
		root->PreNode = N;
	}
	root = N;
	return root;
}


DoubleLinkNode*
SortInsert(DoubleLinkNode* &root,const int & val){
	DoubleLinkNode*N = CreateNode(val);	
	if(root == nullptr || root->val > val){		//insert to head
		return HeadInsert(root,val);
	}
	DoubleLinkNode *p1 = root, *p2 = root;
	while(p1 != nullptr && p1->val <= val){
		p2 = p1;
		p1 = p1->NextNode;
	}
	p2->NextNode = N;
	N->PreNode = p2;
	N->NextNode = p1;
	if(p1 != nullptr)	//end of the link
		p1->PreNode = N;		
	return N;
}

DoubleLinkNode* DelHead(DoubleLinkNode* &root){
	std::cout << "del head" << endl;
	if(root == nullptr) return nullptr;
	DoubleLinkNode* p = root;
	root = root->NextNode;
	delete p;
	if (root != nullptr) root->PreNode = nullptr;
	return root;
} 

bool
DelNode(DoubleLinkNode* &root, const int &val){
	std::cout << "DelNode  " << val << endl;
	
	if (root == nullptr) return false;
	
	if(root->val == val){		//注意有可能删除头结点
		DelHead(root);
		return true;
	}
	
	DoubleLinkNode *p1 = root, *p2 = root;
	while(p1 != nullptr && p1->val != val){
		p2 = p1;
		p1 = p1->NextNode;
	}
	if (p1==nullptr) return false;
	
	DoubleLinkNode* NextNode = p1->NextNode;
	p2->NextNode = NextNode;
	delete p1;
	if(NextNode != NULL) NextNode->PreNode = p2;
	return true;
}

void
Print(const DoubleLinkNode* root){
	const DoubleLinkNode* p = root;
	while( p != nullptr){
		std::cout << p->val << "  ";
		p=p->NextNode;
	}
	std::cout << endl;
}


void
clear( DoubleLinkNode* &root ){
	DoubleLinkNode* p = root;
	//DoubleLinkNode* p2 = nullptr;
	while( p != nullptr){
		DoubleLinkNode *p2 = p;
		p = p->NextNode;
		//if( p != nullptr){
		//	p->PreNode = NULL;
		//}
		delete p2;
		p2 = nullptr;
	}
	root = nullptr;
}



}
#endif
