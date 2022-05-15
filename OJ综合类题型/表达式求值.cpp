#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,sum1,sum2,n,k;
	char a[100];
	gets(a);
	for(i=0,n=0,sum1=0,sum2=0;i<strlen(a);i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			n=n*10+(a[i]-48);
			if(sum1==0)
			{
			if(a[i+1]==' '){sum1=n;n=0;}
			else {continue;}
		    }
		    else
		    {
		    	if((a[i+1]==' ')||(i==strlen(a)-1)){sum2=n;}
		    	else{continue;}
			
			}
		}
	}
	for(j=0,k=0;j<strlen(a);j++)
	{
		if(a[j]=='+')k=sum1+sum2;
		if(a[j]=='-')k=sum1-sum2;
		if(a[j]=='*')k=sum1*sum2;
		if(a[j]=='%')k=sum1%sum2;
		if(a[j]=='/')k=sum1/sum2;	
	}	
	printf("%d",k);
	//printf("%d",sum2);	
	return 0;	
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

