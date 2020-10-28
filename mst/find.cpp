

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<algorithm>
#include<stdio.h>
#include<sstream>
#include<set>
using namespace std;

typedef std::vector<int> VecType;
VecType
FindLestCount(vector<int> & vec, const int t_val){
	VecType ret;
	int n = vec.size();
	for (int i=0;i<n;i++){
		if ( vec[i] < t_val){
			ret.push_back(vec[i]);
		}
	}
	return ret;
}


int main1(int argc, char* argv[]){
	int size = 10;
	srand((unsigned int) time(NULL));
	VecType v1(size,0);
	for (int i = 0; i < size; i++){
		int r = rand()%100;
		std::cout << r << endl;
		v1[i] = r;
	}
	VecType v = FindLestCount(v1,50);
	std::cout << "v size=" << v.size() << endl;
	return 0;
}


typedef vector<std::pair<int,int>> PairVec;

PairVec
FindSumPair(const VecType vec, int sum){
	
	typedef std::map<int,VecType> MTYPE;
	
	MTYPE PosMap;
	for (int i= 0; i < vec.size(); i++){
			auto iter2 = PosMap.find(vec[i]);
			if (iter2 != PosMap.end()){
				iter2->second.push_back(i);
			}
			else
			{
				VecType tmp(1,i);
				PosMap.insert( std::make_pair( vec[i], tmp) );
			}
	}
	MTYPE::iterator tt;
	for ( auto tt : PosMap){
		std::cout << tt.first << ":(";
		for(auto tt2 : tt.second){
			std::cout << tt2 << ",";
		}
		std::cout << ")" << endl;
	}
	
	
	PairVec ret;
	for ( auto it : PosMap){
		 auto it2 = PosMap.find( sum - it.first );
		 if (it2 != PosMap.end()){
			 for (auto i :it.second)
				 for (auto j : it2->second){
					ret.push_back( std::make_pair( i,j) );
				 }
		 }
	}
	return ret;
}


int main2(int argc, char* argv[]){
	
	int nums[] = {2, 7, 11, 15,7,9,0};
	int size = sizeof(nums)/sizeof(int);
	std::cout << "===============" << size << endl;
	int	target = 9;
	VecType vec(&nums[0],&nums[size]);
	PairVec  ret = FindSumPair(vec,target);
	for (auto it : ret){
		std::cout << "(" << it.first << "," << it.second << "),";
		
	}
	std::cout << endl;
	return 0;
}


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

int main_FindMinK(int argc, char* argv[]){
	int arr[] = {1,121,99,11,88,2,44,7,12,22,5,33};
	int size = sizeof(arr)/sizeof(int);
	std::cout << FindMinK_Val(arr,0,size-1,3) << endl;
	std::sort(&arr[0],&arr[size]);
	for (int i = 0 ;i < size ; i++ )
		std::cout << arr[i] << "-";
	std:cout << endl;
	std::cout << "???" << arr[2] <<endl;
	return 0;
}



class OutOfBounds 
{
   public:
      OutOfBounds
            (string theMessage = "Matrix index out of bounds")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

template <class T>
T
_Select( T a[], int left,int right,int k){
	if (left >= right){
		return a[left];
	}
	int ls =left,rs=right+1;
	T mid = a[left];
	while(true){
		do {
			ls ++;
			
		}while(a[ls] < mid);
		
		do {
			rs--;
		}while(a[rs] > mid);
		
		if (ls >= rs){
			break;
		}
		swap(a[ls],a[rs]);
	}
	if(rs-left+1 == k){
		return mid;
	}
	a[left] = a[rs];
	a[rs] = mid;
	if( rs - left + 1 < k){
		return _Select(a, rs+1, right, k - ( rs - left + 1) );
	}else{
		
		return _Select(a , left, rs-1, k);
	}
}

template <class T>
T
Select( T a[], int n, int k){
	
	if (k<1 || k > n)
		throw OutOfBounds();
	return _Select(a,0,n-1,k);
}


void testmap(){
	typedef std::map<int,int> M;
	typedef M::iterator MIT;
	M m;
	m.insert( make_pair(1,1));
	m.insert( M::value_type(11,22));
	for (auto v : m)
	{
		std::ostringstream o;
		o << typeid(v).name() << " first=" << v.first << " second=" << v.second; 
		std::cout << o.str() << endl;
	}
	for (MIT it=m.begin(); it != m.end(); it++){
		ostringstream o;
		o << typeid(it).name() << " first=" << it->first << " second=" << it->second; 
		std::cout << o.str() << endl;
	}
}


typedef std::multiset<int, greater<int>> SET;
typedef SET::iterator SETITR;


int
SelectBySet(int arr[],int n, int k){
	if (k > n)
		throw OutOfBounds();
	SET s;
	for(int i=0;i<n;i++){
		if (s.size() < k){
			s.insert(arr[i]);
		}else{
			SETITR it = s.begin();
			if( *it > arr[i] ){
				s.erase(it);
				s.insert(arr[i]);
			}
		}
	}
	return *(s.begin());
}

void InsertBySort(std::vector<int> vec, int Max,int val)
{
	std::vector<int>:: iterator itr;
	for ( itr = vec.begin(); itr != vec.end(); itr++){
		if( *itr < val)
		{
			vec.insert(itr,val);
			break;
		}
	}
	if (vec.size() > Max)
		vec.erase(vec.begin());
}




int main(int argc, char* argv[]){
	int arr[] = {1,121,99,11,77,88,2,44,7,12,22,5,33};
	int size = sizeof(arr)/sizeof(int);
	int  k = 10;
	std::cout << Select(arr,size,k) << endl;
	std::sort(&arr[0],&arr[size]);
	for (int i = 0 ;i < size ; i++ )
		std::cout << arr[i] << "-";
	std:cout << endl;
	std::cout << "???" << arr[k-1] <<endl;
	std::cout << "SelectBySet:" << SelectBySet(arr,size,k) << endl;
	//testmap();
}















