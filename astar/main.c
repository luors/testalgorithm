
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROW 1024

int main(int argc ,char* argv[]){
	
	FILE* fp = fopen("test.txt","r");
	if (fp == NULL){
		printf("open map error\n");
		return -1;
	}else{
		printf("open map file\n");
	}
	char a[MAX_ROW];
	char arr[MAX_ROW][MAX_ROW] = {0};
	char* l = fgets(a,MAX_ROW,fp);
	int row=0;
	while(l != NULL){
		//printf("%d---%s\n",strlen(l),l);
		char* p = l;
		char c = *p ;
		int col = 0;
		printf("%s\n",l);
		while(c != '\r' && c != '\n')
		{	
			arr[row][col] = c;
			printf("%d-----%d\n",col,c);
			c=*(++p);
			col++;
		}
		printf("\n");
		row++;
		l = fgets(a,MAX_ROW,fp);
	}
	fclose(fp);
	return 1;
}









