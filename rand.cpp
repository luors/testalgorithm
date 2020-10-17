
#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;


int main(int argc , char* argv[])
{	
	srand((unsigned int) time(NULL));
	for (int i=0;i<10;i++)
		std::cout << rand()%1000 << " ";
	std::cout<<endl;
	return 0;
}






