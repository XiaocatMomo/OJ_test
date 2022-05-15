#include<stdio.h>
#include<string.h>
char str[9];
int  dex;
int count;
int n;
void yunsuan();
int op();
void pailie(int);
int main()
{
	scanf("%d",&n);
	pailie(0);
	printf("%d",count);
	return 0;
}


void pailie(int pos)
{
	if(pos==n-1)
	{
		yunsuan();
	}
	else
	{
		str[pos]=' ';
		pailie(pos+1);
		str[pos]='+';
		pailie(pos+1);
		str[pos]='-';
		pailie(pos+1);
			
   }
		
}




int get_sum()
{
	
	int num=dex+1;
	
	while(str[dex]==' '&&dex<n-1)
	{
		num=num*10+dex+2;
		dex++;
	}
	return num;
}




void yunsuan()
{
     int fuhao;
	 int sum=0;
	 dex=0;
	 sum=get_sum();
	 
	 while(1)
	 {
	 	fuhao=op();
	 	if(fuhao==0)
	 	{
	 		break;
		 }
	 	else
	 	{
	 		sum+=fuhao*get_sum();
		 }
	}	
	if(sum==0)
	{
		count++;
	}
	
	
}




int op()
{
	int ope;
	if(dex>=n-1)
	{
		return 0;
	}
	if(str[dex]=='+')
	{
		dex++;
		return 1;
	}
	if(str[dex]=='-')
	{
		dex++;
		return -1;
	}
	return 0;
		
}

