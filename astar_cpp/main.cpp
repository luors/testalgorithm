
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "gamemap.h"
using namespace std;
int main(int argc ,char* argv[]){
	
	MapPosList arr;
	if (make_map_arr(arr,"test.txt"))
		std::cout << "make map error " << endl;
	
	int row = arr.size();
	for( int x=0; x < row; x++){
		for (int y=0; y<arr[x].size() ;y++){
			std::cout << arr[x][y] << "-";
		}
		std::cout << endl;
	}
	return 1;
}









