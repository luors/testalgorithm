


#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<algorithm>
#include<sstream>
#include<memory>
#include<functional>
using namespace std;

template < typename T>
void printarr(const T a[],int len)
{	
	for (int i=0 ;i < len;i++)
	{
		std::cout << a[i] ;
		if (i < len-1)
			std::cout << " " ;
	}
	std::cout << endl;
}


template<typename T> 
T FindMinK_Val(T a[], int left,int right, int k){
	std::cout << "FindMinK_Val" << endl;
	if(right - left < 1)
		//printf("----%d,%d,%d\n",k,left,right);
		return (k==1)?min(a[right],a[left]):max(a[right],a[left]);
	int ls = left,rs=right+1;
	T mid = a[left];
	std::cout << "mid=" << mid << endl;
	while(true){
		do{
			ls ++;
		}while(a[ls] < mid);
		do{
			rs --;
		}while(a[rs] > mid);
		if (ls >= rs){
			break;
		}
		swap(a[ls],a[rs]);
	}
	a[left] = a[rs];
	a[rs] = mid;
	//swap(a[left],a[rs]);
	printarr(a,12);
	if(k -1 == rs){
		return a[rs];
	}
	if (k -1 < rs){
		return FindMinK_Val(a,left,rs,k);
	}
	return FindMinK_Val(a,rs+1,right,k-rs);	//k-1 > rs  => k > rs+1
}

template< typename T> 
void vec_print(const std::vector<T> &vec ){

		ostringstream o;
		size_t sz = vec.size();
		for ( int i = 0;i< sz;i++){
			o << vec[i];
			if (i < sz - 1) o << "  ";
		}
		std::cout << o.str() << endl;
}

template< class T> 
bool _cmp( T a , T b ){
	return a < b;
}

int main(int argc, char* argv[]){

	typedef std::vector<int> VType;
	int a [] = {11,22,3,44,99,23,0,9,88};
	int size = sizeof(a)/sizeof(int);
	VType arr(&a[0],&a[size]);
	make_heap(arr.begin(),arr.end(),greater<int>());
	
	arr.push_back(999);
	push_heap(arr.begin(),arr.end(),greater<int>());
	std::cout << "11============" << endl;
	vec_print(arr);
	size = arr.size();
	vec_print(arr);
	while( size > 0){
		pop_heap(arr.begin(),arr.end());
		std::cout << "POP HEAP--->" <<arr[size-1] << endl;
		arr.pop_back();
		//make_heap(arr.begin(),arr.end(),greater<int>());
		size --;
	}
	sort_heap(arr.begin(), arr.end());
	std::cout << "============" << endl;
	vec_print(arr);
	#ifdef WIN32
		system("pause");
	#endif
	return 1;
}
