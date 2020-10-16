
#ifndef __GAME_MAP_H__
#define __GAME_MAP_H__
#include<stdio.h>

#define MAX_ROW 1024
#define Max_COL 1024

typedef struct __pos {
	int x;
	int y;
	char val;
}Pos;

typedef struct _Map{
	unsigned int map_id;
	int row_size;
	int col_size;
	Pos* pos_arr;
}Map;

void make_map_arr(const char* map_name);

#endif

