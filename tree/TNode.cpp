
#include "TNode.h"

#include<iostream>

using namespace std;
//using namespace TNodeSP;

typedef struct TNodeSP::TNode<int> IntNode;



void VisitNode( void* p)
{	
	std::cout << ( (IntNode*)p)->val << "->";
	//return p;
}

void tnode_test()
{
	IntNode *head = TNodeSP::CreateNode(3);
	IntNode*L1 = TNodeSP::l_insert(head,9);
	IntNode*L2 = TNodeSP::r_insert(head,20);
	IntNode*L3 = TNodeSP::l_insert(L1,15);
	IntNode*L4 = TNodeSP::r_insert(L1,7);
	IntNode*L5 = TNodeSP::l_insert(L2,111);
	IntNode*L6 = TNodeSP::r_insert(L2,71);
	std::cout << "Tree Depth：" << TNodeSP::getDepth(head) << endl;
	
	TNodeSP::VisitFunc func = VisitNode;
	TNodeSP::tree_preOrder(head,func);
	std::cout<< endl;
	TNodeSP::tree_midOrder(head,func);
	std::cout<< endl;
	TNodeSP::tree_postOrder(head,func);
	std::cout<< endl;
	TNodeSP::tree_levelOrder(head,func);
	std::cout<< endl;
	
	TNodeSP::FreeNode(head);
	TNodeSP::FreeNode(L1);
	TNodeSP::FreeNode(L2);
	TNodeSP::FreeNode(L3);
	TNodeSP::FreeNode(L4);
	
}




















