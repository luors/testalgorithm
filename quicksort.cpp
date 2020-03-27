
#include<iostream>
#include<stdio.h>
using namespace std;

template < class T>
void printarr(const T a[],int len)
{
	for (int i=0 ;i < len;i++)
		std::cout << a[i] << " " ;
	std::cout << endl;
}


template<class T>
void qsort( T a[], int L, int R)
{	
	printf("R=%d,L=%d\n",L,R);
	if ( L >= R) 
		return;
	int LS = L,RS=R;
	T M = a[L];
	printf("Mid=%d\n",M);
	while(true){
		do{
			RS--;
		}while( a[RS] > M);
		
		do{
			LS++;
		}while( a[LS] < M);
		if(LS >= RS)
			break;
		swap(a[RS],a[LS]);
	}
	a[L] = a[RS];
	a[RS] = M;
	printf("LS=%d RS=%d\n",LS,RS);
	printarr(a,9);
	qsort(a,L,RS);
	qsort(a,RS+1,R);
	
}

int main(int argc , char* argv[])
{
	int arr[] = {8,1,2,4,7,11,12,22,5,3};
	int size = sizeof(arr)/sizeof(int);
	printarr(arr,size);
	std::cout << "Begin" << endl;
	qsort(arr,0,size);
	printarr(arr,size);
	return 0;
}






