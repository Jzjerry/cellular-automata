#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<windows.h>

#define MAP_SIZE 30

int map[MAP_SIZE][MAP_SIZE];

int map_cache[MAP_SIZE][MAP_SIZE];

int vec[]={-1,0,1};

char c0[]="¡õ";
char c1[]="¡ö";
void refresh()
{	
	for(int i=0;i<MAP_SIZE;i++)
	{
		for(int j=0;j<MAP_SIZE;j++)
		{
			int count=0;
			if(map[i][j]==1)
			{
				for(int k=0;k<3;k++)
				{
					for(int l=0;l<3;l++)
					{
						int ni,nj;
						ni=i+vec[k];
						nj=j+vec[l];
						if(ni<MAP_SIZE&&ni>-1&&nj<MAP_SIZE&&nj>-1)
						{
							count+=map[ni][nj];
						}
					}
				}
				count--;
				if(count<2) map_cache[i][j]=0;
				else if(count<=3) map_cache[i][j]=1;
				else map_cache[i][j]=0;
			}
			else if(map[i][j]==0)
			{
				for(int k=0;k<3;k++)
				{
					for(int l=0;l<3;l++)
					{
						int ni,nj;
						ni=i+vec[k];
						nj=j+vec[l];
						if(ni<MAP_SIZE&&ni>-1&&nj<MAP_SIZE&&nj>-1)
						{
							count+=map[ni][nj];
						}
					}
				}
				if(count==3) map_cache[i][j]=1;
				else map_cache[i][j]=0;
			}
		}
	}
	for(int i=0;i<MAP_SIZE;i++)
	{
		for(int j=0;j<MAP_SIZE;j++)
		{
			map[i][j]=map_cache[i][j];
		}
	}
	return;
}


int main()
{
	time_t t;
	srand((unsigned) time(&t));
	for(int i=0;i<MAP_SIZE;i++)
	{
		for(int j=0;j<MAP_SIZE;j++)
		{
			map[i][j]=rand()%2;
		}
	}
	for(int n=1;n<=60;n++)
	{
	for(int i=0;i<MAP_SIZE;i++)
	{
		for(int j=0;j<MAP_SIZE;j++)
		{
			if(map[i][j])
			{
				printf("%s",c1);
			}
			else
			{
				printf("%s",c0);
			}
		}
		std::cout<<"\n";
	}
		refresh();
		Sleep(1000);
		system("cls");
	}
	return 0;
} 
