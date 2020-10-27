
#include<iostream>
#include<sstream>
#include<memory>
using namespace std;
template < class T> 
shared_ptr<string>
toString(const T &v){
	std::ostringstream oss;
	oss << v;
	//std::cout << oss.str() << endl;
	string *p = new string(oss.str());
	//std::cout << *p << endl;
	return shared_ptr<string>( p );
}

class Test
{
public:
	friend ostream& operator <<( ostream& out,const Test &obj)
	{
		out << "this is class Test obj";
		return out;
	}
	Test(){ std::cout << "create Test obj " << endl ;}
	~Test(){ std::cout << "release Test Obj" << endl;}
};

shared_ptr<Test> func(){
	return shared_ptr<Test>(new Test());
}



int main(int argc, char* argv[])
{	
	shared_ptr<string> p(toString(Test()));// = std::make_shared<string>();
	std::cout << *p << endl;
	
	shared_ptr<Test> pt(new Test());
	pt.reset();
	unique_ptr<string> upt(new string("hello world"));
	unique_ptr<string> upt2 = move(upt);
	//std::move(upt,upt2);
	
	
	return 0;
}





