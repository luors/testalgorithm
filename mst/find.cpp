

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<map>
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


template<typename T> 
T FindMinK_Val(T a[], int left,int right, int k){
	//if (left >= right) return;
	int ls = left+1,rs=right;
	T mid = a[left];
	while(true){
		while(ls < right){
			if (a[ls] > mid || ls>=right) break;
			ls ++;
		}
		while(rs > ls && a[rs] > mid){
			rs --;
		}
		if (ls >= rs){
			break;
		}
		swap(a[ls],a[rs]);
	}
	swap(a[left],a[rs]);
	if(k == rs+1){
		return a[rs];
	}
	if (k < rs+1){
		return FindMinK_Val(a,0,rs,k);
	}
	return FindMinK_Val(a,rs,right,k-ls);
}

int main(int argc, char* argv[]){
	int arr[] = {8,1,2,44,7,11,12,22,5,3};
	int size = sizeof(arr)/sizeof(int);
	std::cout << FindMinK_Val(arr,0,size-1,3);
}












