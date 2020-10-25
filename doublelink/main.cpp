
#include "doublelink.h"
using namespace std;

int main(int argc, char* argv[]){
	
	typedef DLINK::DoubleLinkNode* pNode;
	pNode root = DLINK::CreateNode(11);
	
	DLINK::HeadInsert(root,12);
	DLINK::HeadInsert(root,9);
	DLINK::HeadInsert(root,33);
	DLINK::Print(root);
	
	DLINK::clear( root);
	
	
	pNode root2 = DLINK::CreateNode(11);
	
	DLINK::SortInsert(root2,12);
	DLINK::SortInsert(root2,9);
	DLINK::SortInsert(root2,33);
	DLINK::SortInsert(root2,9);
	DLINK::SortInsert(root2,1);
	DLINK::Print(root2);
	
	DLINK::clear( root2);
	
	
	return 0;
}