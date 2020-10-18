#include<iostream>
#include<stdio.h>
#include "common.h"

using namespace std;

template<class T>
void bbsort( T a[], int len)
{
	for( int i = 0;i<len-1;i++)
	{
		for (int j=i+1;j<len;j++)
		{
			if (a[i] > a[j])
				swap(a[i],a[j]);
		}
	}
	
}

int main(int argc , char* argv[])
{
	int arr[] = {55,8,1,2,4,7,11,12,22,5,3,55};
	int size = sizeof(arr)/sizeof(int);
	printarr(arr,size);
	std::cout << "Begin" << endl;
	bbsort(arr,size);
	printarr(arr,size);
	return 0;
}






