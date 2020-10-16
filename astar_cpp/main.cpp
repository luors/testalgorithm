
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#include "gamemap.h"
using namespace std;
int main(int argc ,char* argv[]){
	
	ScensePosList arr;
	if (make_map_arr(arr,"test.txt"))
		std::cout << "make map error " << endl;
	
	int row = arr.size();
	for( int x=0; x < row; x++){
		for (int y=0; y<arr[x].size() ;y++){
			std::cout << arr[x][y] << "-";
		}
		std::cout << endl;
	}
	
	/*PosMapType m;
	m.insert(make_pair(make_pair(1,1),1));
	m.insert(make_pair(make_pair(1,1),1));
	std::cout << "testmap" << m.size() << endl; */
	
	return 1;
}









