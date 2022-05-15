#include<stdio.h>
int main()
{
	char arr[20][20];
	int x,y,o,x1,y1,foot=1;
	scanf("%d %d %d",&x,&y,&o);
	getchar();
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			scanf("%c",&arr[i][j]);
		}
		getchar();
	}
	x1=0;y1=o-1;
	
	while(1)
	{
		if(arr[x1][y1]=='W')
		{
			arr[x1][y1]='*';
			y1--;
			if(y1>=0)
			{
				foot++;
			}
			else
			{
				printf("out %d",foot);
				break;
			}			
		}
		else if(arr[x1][y1]=='E')
		{
			arr[x1][y1]='*';
			y1++;
			if(y1<y)
			{
				foot++;
			}
			else
			{
				printf("out %d",foot);
				break;
			}			
		}
		else if(arr[x1][y1]=='N')
		{
			arr[x1][y1]='*';
			x1--;
			if(x1>=0)
			{
				foot++;
			}
			else
			{
				printf("out %d",foot);
				break;
			}			
		}
		else if(arr[x1][y1]=='S')
		{
			arr[x1][y1]='*';
			x1++;
			if(x1<x)
			{
				foot++;
			}
			else
			{
				printf("out %d",foot);
				break;
			}			
		}
		else if(arr[x1][y1]=='*')
		{
			printf("loop %d",foot-1);
			break;
		}
	}
	//printf("½áÊøÀ²"); 
	return 0;
	
	
	
	
	
 } 
