#include<stdio.h>
int main()
{
	typedef struct stu
	{
		int num;
		int min1;
		int s1;
		int min2;
		int s2;
		int sum1;
		
	}STU;
	STU hb[100],ui,op[100];
	int m,category=0,l;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d:%d %d:%d",&hb[i].num,&hb[i].min1,&hb[i].s1,&hb[i].min2,&hb[i].s2);
		hb[i].sum1=hb[i].min2*60+hb[i].s2-hb[i].min1*60-hb[i].s1;
		
	}
	/*for(int j=0;j<m;j++)
	{
		hb[j].sum2=0;
	}*/
	for(int k=0;k<m;k++)
	{
		for(l=0;l<k;l++)
		{
			if(hb[k].num==hb[l].num)
			{
				break;
			}
		}
		if(l==k)
		{
			op[category].num=hb[k].num;
			category++;
			
		}
	}
	for(int j=0;j<m;j++)
	{
		op[j].sum1=0;
	}
	for(int q=0;q<category;q++)
	{
		for(int w=0;w<m;w++)
		{
			if(op[q].num==hb[w].num)
			{
				op[q].sum1+=hb[w].sum1;
			}
		}
	}
	for(int e=0;e<category-1;e++)
	{
		for(int t=0;t<category-1;t++)
		{
			if(op[t].sum1<op[t+1].sum1)
			{
				ui=op[t+1];
				op[t+1]=op[t];
				op[t]=ui;	
			}
			else if(op[t].sum1==op[t+1].sum1)
			{
				if(op[t].num>op[t+1].num)
				{
					ui=op[t+1];
			    	op[t+1]=op[t];
				    op[t]=ui;		
				}
			}	
				
		}
	}
	for(int r=0;r<category;r++)
	{
		printf("%d %d\n",op[r].num,op[r].sum1);
	}
	return 0;

}
