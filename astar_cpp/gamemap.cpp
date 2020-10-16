

#include "gamemap.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<map>
using namespace std;
int make_map_arr(ScensePosList& vec, const char* file_name)
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

static inline bool check_search_pos(const ScensePosList& map_arr, const Pos& start_pos, const Pos& end_pos){
	return true;
}

static inline void make_open_list(
	const ScensePosList& map_arr, 
	PosList& open_list,PosMapType& open_map,
	PosMapType& close_map,int x, int y)
{
	for ( int i = -1; i< 1;i++ ){
		for (int j = -1; j < 1; j++){
			int tmp_x = x + i;
			int tmp_y = y + j;
			PairType tmp_pos_pair(tmp_x,tmp_y);
			if (tmp_y >= 0 and tmp_y < map_arr.size() \
				and tmp_x >= 0 and tmp_x < map_arr[x].size() \
				and open_map.find(tmp_pos_pair) != close_map.end() \
				and close_map.find(tmp_pos_pair) != close_map.end() \
			){
				if (map_arr[x][y] == 1){
					open_list.push_back(tmp_pos_pair);
					open_map.insert(make_pair(tmp_pos_pair,1));
				}else{
					close_map.insert(make_pair(tmp_pos_pair,1));
				}
			} 
			
		}
	}
}



PosList search_path(const ScensePosList& map_arr, const Pos& start_pos, const Pos& end_pos)
{
	PosList Path;
	assert(map_arr.size() > 0);
	if (!check_search_pos( map_arr, start_pos, end_pos))
	{
		Pos p;
		p.x = start_pos.x;
		p.y = start_pos.y;
		Path.push_back(p);
		return Path;
	}
	PosMapType close_map,open_map;
	PosList open_list;
	open_list.push_back(start_pos);
	make_open_list(map_arr, open_list, open_map, close_map, start_pos.x, start_pos.y);
	
	return Path;
} 













