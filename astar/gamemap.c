
#include "gamemap.h"
#include <assert.h>
void make_map_arr(const char* map_name){
	Map m;
	FILE* fp = fopen(map_name,"r");
	if (fp == NULL){
		printf("open map source file error\n");
		return;
	}
	char a[1024];
	char* l = fgets(a,1024,fp);
	int row=0;
	int col = 0;
	while(l != NULL){
		char* p = l;
		int tmpcol = 0;
		//printf("%s\n",l);
		while(*p != '\r' && *p != '\n')
		{
			char t[1];
			t[0] = *p;
			//assert(t == l);
			printf("%d-----%s(%d)\n",tmpcol,t,sizeof(t));
			++p;
			tmpcol++;
		}
		row++;
		col = (tmpcol > col)?tmpcol:col;
		l = fgets(a,1024,fp);
	}
	printf("row=%d col=%d\n",row,col);
	fclose(fp); 
}






