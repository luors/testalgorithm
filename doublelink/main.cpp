
#include "doublelink.h"
using namespace std;

int main(int argc, char* argv[]){
	
	typedef DLINK::DoubleLinkNode* pNode;
	/* pNode root = DLINK::CreateNode(11);
	
	DLINK::HeadInsert(root,12);
	DLINK::HeadInsert(root,9);
	DLINK::HeadInsert(root,33);
	DLINK::Print(root);
	
	DLINK::clear( root);
	 */
	
	pNode root2 = DLINK::CreateNode(11);
	int a[] = {12,9,33,9,1};
	for (int i=0;i<sizeof(a)/sizeof(int);i++){
		//std::cout << "bbbbbbbbbbbbbbbbbbb" << i << "--->" << a[i]<< endl;
		DLINK::SortInsert(root2,a[i]);
	}
	
	DLINK::Print(root2);
	root2 = DLINK::DelHead(root2);
	DLINK::Print(root2);
	DLINK::DelNode(root2,9);
	DLINK::DelNode(root2,99);
	DLINK::DelNode(root2,12);
	
	
	std::cout << "==============" << endl;
	DLINK::Print(root2);
	
	
	DLINK::clear( root2);
	
	char *p = nullptr;
	*p = 'a';
	
	return 0;
}