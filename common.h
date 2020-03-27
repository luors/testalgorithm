#ifndef __COMMON_H__
#define __COMMON_H__
#include <iostream>
using namespace std;



template < class T>
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

#endif
