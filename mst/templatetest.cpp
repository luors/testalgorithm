#include<iostream>
#include<map>
#include<memory>
using namespace std;

class BaseValue{
public:	
	BaseValue(){
	}
	virtual ~BaseValue(){
	}
};

class IntValue:public BaseValue{
public:
	IntValue(){
		std::cout<< "IntValue()"<< endl;
	}
	
	~IntValue(){
		std::cout<< "~IntValue()"<< endl;
	}

};

class StringValue:public BaseValue{
public:
	StringValue(){
		std::cout<< "StringValue()"<< endl;
	}
	
	~StringValue(){
		std::cout<< "~StringValue()"<< endl;
	}

};


template < class T>
class ValueFactory{
public:
	BaseValue* create() = 0;
	~ValueFactory(){}
};

template <>
class ValueFactory<int>{

public:
	virtual BaseValue* create() {
		return new IntValue();
	};
	~ValueFactory(){}

};

template <>
class ValueFactory<string>{

public:
	BaseValue* create() {
		std::cout<< "ValueFactory<string> create"<< endl;
		return new StringValue();
	};
	~ValueFactory(){}

};



class Player{
public:
	template<typename T>
	void Set(const char* Key, T val)
	{
		ValueFactory<T> _creator;
		Data[Key] = shared_ptr<BaseValue>(_creator.create());
		
	}
	
	virtual ~Player(){
		std::cout  << "~Player()" << endl;
		Data.clear();
	}
	
private:
	std::map<string,shared_ptr<BaseValue>> Data;
};

int main(int argc, char* argv[]){
	
	
	Player obj;
	obj.Set<int>("ID",1001);
	obj.Set<string>("Name","Tom");
	
	return 1;

}

















