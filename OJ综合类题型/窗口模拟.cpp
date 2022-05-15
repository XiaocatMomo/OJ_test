#include<stdio.h>
int main()
{
	typedef struct stu
	{
		int x1,x2;
		int y1,y2;
		int bianhao;
		
	}
	FAN;
	typedef struct stu1
	{
		int x,y;
	}WAR;
	FAN str[10],t;
	WAR wtr[50];
	int n,m,i1,i2,j1,j2;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&str[i].x1,&str[i].y1,&str[i].x2,&str[i].y2);
		str[i].bianhao=i;
	}
	for(int j=0;j<m;j++)
	{
		scanf("%d %d",&wtr[j].x,&wtr[j].y);
	}
	for(i1=0;i1<m;i1++)
	{
		for(j1=n;j1>=1;j1--)
		{
			if(wtr[i1].x>=str[j1].x1&&wtr[i1].x<=str[j1].x2&&wtr[i1].y>=str[j1].y1&&wtr[i1].y<=str[j1].y2)
			{
				printf("%d\n",str[j1].bianhao);
				t=str[n];
				str[n]=str[j1];
				str[j1]=t;
				break;
			}
		}
		if(j1==0)
		{
			printf("IGNORED\n");
		}
	}
	return 0;
	
	
	
 } 
