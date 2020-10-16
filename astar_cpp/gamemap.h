
#ifndef __GAME_MAP_H__
#define __GAME_MAP_H__
#include<stdio.h>
#include<vector>
#inlcude<list>
using namespace std;
typedef std::vector< char > arr_type;
typedef std::vector<arr_type>  MapPosList;
typedef struct _pos {
	int x;
	int y;
}Pos;
typedef std:list<Pos> PosList;

int make_map_arr(MapPosList& vec, const char* file_name);
PosList search_path(const MapPosList& vec, const Pos& start_pos, const Pos& end_pos);

#endif

