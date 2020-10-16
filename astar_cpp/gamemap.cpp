

#include "gamemap.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int make_map_arr(MapPosList& vec, const char* file_name)
{
	ifstream in(file_name);
	if( !in.is_open())
	{
		std::cout << "open map file error" << endl;
		return -1;
	}
	int idx = 0;
	while(!in.eof())
	{
		char buff[1024];
		in.getline(buff,1024);
		if( strlen(buff) < 1)
			break;
		arr_type arr;
		for (int i = 0; i < strlen(buff) -1;i++){
			arr.push_back(buff[i]);
		}
		vec.push_back(arr);
	}
	return 0;
}

static inline bool check_search_pos(const MapPosList& map_arr, const Pos& start_pos, const Pos& end_pos){
	return true;
}


PosList search_path(const MapPosList& map_arr, const Pos& start_pos, const Pos& end_pos)
{
	PosList Path;
	assert(map_arr.size() > 0);
	if (!check_search_pos( map_arr, start_pos, end_pos))
	{
		Pos p;
		p.x = start_pos.x;
		p.y = start_pos.y;
		Path.push_back(Pos);
		return Path;
	}
	typedef std::map<std::pair<int,int>,char flag> CloseListType;
	typedef PosList OpenListType;
	CloseListType close_list;
	OpenListType open_list(start_pos);
	
	
	
	return Path;
} 













