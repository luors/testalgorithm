
#include "TNode.h"

typedef struct TNode<int> IntNode;



void VisitNode( void* p)
{	
	std::cout << ( (IntNode*)p)->val << "->";
	//return p;
}

void Test()
{
	IntNode *head = CreateNode(3);
	IntNode*L1 = l_insert(head,9);
	IntNode*L2 = r_insert(head,20);
	IntNode*L3 = l_insert(L1,15);
	IntNode*L4 = r_insert(L1,7);
	IntNode*L5 = l_insert(L2,111);
	IntNode*L6 = r_insert(L2,71);
	std::cout << "Tree Depth：" << getDepth(head) << endl;
	
	VisitFunc func = VisitNode;
	tree_preOrder(head,func);
	std::cout<< endl;
	tree_midOrder(head,func);
	std::cout<< endl;
	tree_postOrder(head,func);
	std::cout<< endl;
	tree_levelOrder(head,func);
	std::cout<< endl;
	
	FreeNode(head);
	FreeNode(L1);
	FreeNode(L2);
	FreeNode(L3);
	FreeNode(L4);
	
}




















