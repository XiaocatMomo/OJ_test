#include<stdio.h>
int n,sum=0,j,k,value1,value2,sumA;//value1为拿去宝藏后你的价值，value2为你不拿宝藏后的价值 
	int a[201][20001]={0};
	int baozang[201];
int main(void)
{
		
	
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&baozang[i]);
		sum+=baozang[i];
	}
	for(j=1;j<=n;j++)
	{
		if(baozang[j]>sum/2)
		{
			a[n][sum/2]=sum-baozang[j];
			break;
		}
		
			for(k=1;k<=sum/2;k++)
			{
				if(baozang[j]>k)
				{
					a[j][k]=a[j-1][k];
				}
				else
				{
					value1=a[j-1][k-baozang[j]]+baozang[j];
					value2=a[j-1][k];
					if(value1>value2)
					{
						a[j][k]=value1;
					 } 
					 else
					 {
					 	a[j][k]=value2;
					 }
					
				}
				
			}
			
	
	}
	sumA=a[n][sum/2];
	printf("%d",sum-2*sumA);
	return 0;
	
}
