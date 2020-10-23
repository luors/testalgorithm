


#include<iostream>
#include<memory>
#include "TNode.h"
//#include "smartptr.h"
using namespace std;

class A{
public:
	virtual ~A(){
		std::cout << "class A ~A call" << endl;
			
	}
		virtual void func(){
			std::cout << "class A func call" << endl;
		}
	
};



class A1:virtual public A{
public:
	virtual ~A1(){
		std::cout << "class A1 ~A1 call" << endl;
			
	}
	virtual void func(){
		std::cout << "class A1 func call" << endl;
	}
	
};



class A2:virtual public A{
public:
		virtual ~A2(){
			std::cout << "class A2 ~A2 call" << endl;
		
		}
		virtual void func(){
			std::cout << "class A2 func call" << endl;
		}
	
};
class B:public A1,public A2{
public:
	B():m_ptr(new string("aaaa")){
	}
	virtual ~B(){
		delete m_ptr;
		std::cout << "class B ~B call" << endl;
		
	}
	virtual void func(){
			std::cout << "class B func call" << endl;
		}

private:
	string* m_ptr;
	
};

int main(int argc , char* argv[]){
	
	//Tnode
	//TNodeSP::tnode_test();
	//test_smart_ptr();
	A* p = new B();
	delete p;
	p = NULL;
	/*shared_ptr<B> p1(new B());
	shared_ptr<B> p2(p1);
	shared_ptr<A> p3 = make_shared<B>();
	p3->func();*/
	return 0;
};











