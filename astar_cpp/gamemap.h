
#ifndef __GAME_MAP_H__
#define __GAME_MAP_H__
#include<stdio.h>
#include<vector>
#include<list>
#include<map>
#include<hash_map>
using namespace std;
typedef std::vector< char > arr_type;
typedef std::vector<arr_type>  ScensePosList;
typedef std::pair<int,int> PairType;
typedef std::map<PairType,char> PosMapType;

typedef struct _pos {
	int x;
	int y;
}Pos;
typedef std::list<Pos> PosList;

int make_map_arr(ScensePosList& vec, const char* file_name);
PosList search_path(const ScensePosList& vec, const Pos& start_pos, const Pos& end_pos);

#endif

