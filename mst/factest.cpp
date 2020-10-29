
#include<iostream>
#include<map>
#include <typeinfo>
using namespace std;
class DataBaseValue;

typedef map<int,DataBaseValue*> M;


class TValueBase{
public:
	TValueBase() {};
	virtual ~TValueBase() {}
	//void create(const char* Key,T val) = 0;
	virtual  void Get() = 0;
};

class TValueInt : public TValueBase
{
public:
		virtual  void Get(){};
		TValueInt(int val){

			m_Value = val; 
			std::cout <<"TValueInt create" << endl;
		}
		~TValueInt(){};
private:
	int m_Value;
};

class TValueString : public TValueBase{
public:
	virtual  void Get(){};
	TValueString(const char* p) {
		m_Value = string(p);
		std::cout <<"TValueString create" << endl;
	}
	~TValueString() {
	}
private:
	string m_Value;
};



/*

template < class TValue_t>
class IFac
{
public:
	virtual TValue_t* create() = 0;
	~IFac(){}
};

template< class TValue_t, class T>
class Fac:public IFac<TValue_t>{
public:
	TValueBase<T> *create(){
		return new TValueBase<T>();
	}
};


class User{
	
public:
	template<class T>
	void Set(string Key, T val){
		Fac<TValueBase<T>, T> o;
		o.create();
		std::cout << "Set=====" << typeid(o).name() << endl;
		//m_Data.insert(make[Key] = o.create();
		//Fac<TValueBase<T> ,ValueFac<T> > o;
	}

private:
	M m_Data;
};

*/
class ABC{

};
int main(int argc, char* argv[]){
	
	std::cout << typeid(ABC).name() << endl;
	std::cout << typeid(string).name() << endl;
	return 0;
}





