#include<stdio.h>
int main()
{
	typedef struct date
	{
		int xiang;
		int num; 
	}
	DATE;
	DATE str[100],t,y[100];
	int a1,a2,a3,ptr1[100],ptr2[100],gt1,gt2,ptr3[1000],category=1,hn=0,at,bt,wol,wel;
	scanf("%d %d %d",&a1,&a2,&a3);
	for(int i=0;i<2*a1;i++)
	{
		scanf("%d",&ptr1[i]);
	}
	for(int j=0;j<2*a2;j++)
	{
		scanf("%d",&ptr2[j]); 
	}
	if(a3==0)
	{
	     for(int w=0;w<2*a1;w++)
		 {
		 	ptr3[w]=ptr1[w];	
		}	
		for(int w1=0;w1<2*a2;w1++)
		{
			ptr3[w1+2*a1]=ptr2[w1];
		}
		str[0].xiang=ptr3[1];
		for(gt1=3;gt1<2*(a1+a2);gt1=gt1+2)
		{
			hn=0;
			for(gt2=1;gt2<gt1;gt2+=2)
			{
				if(ptr3[gt1]!=ptr3[gt2])
				{
					hn++;
				}
			}
			if(hn==(gt1-1)/2)
			{
				str[category].xiang=ptr3[gt1];
				category++;
			}
		}
		for(int rt=0;rt<category;rt++)
		{
			str[rt].num=0;
		}
		for( at=0;at<category;at++)
		{
			for(bt=1;bt<2*(a1+a2);bt+=2)
			{
				if(str[at].xiang==ptr3[bt])
				{
					str[at].num+=ptr3[bt-1];
				}
			}
		}
		for(int k=0;k<category-1;k++)
		{
			for(int l=0;l<category-1;l++)
			{
				if(str[l].xiang>str[l+1].xiang)
				{
					t=str[l+1];
					str[l+1]=str[l];
					str[l]=t;
				}
			}
		}
		for(wol=0,wel=0;wol<category;wol++)
		{
			if(str[wol].num==0)
			{
				continue;
			}
			y[wel]=str[wol];
				wel++;
			
		}
		
		
	for(int wn=0;wn<wel;wn++)
	{
		
          
		  if(y[wn].num>0)
		  {
		  	if(wn==0&&str[0].xiang==0)
		  	{
		  		printf("%d",y[0].num);
			  } 
		  	else if(wn==0&&y[0].xiang==1&&y[0].num!=1)
		  	{
		  		printf("%dx",y[0].num);
			  }
			else if(wn==0&&y[0].xiang!=1&&y[0].num!=1) 
			{
				printf("%dx^%d",y[wn].num,y[wn].xiang);
			 }
			else if(wn==0&&y[0].xiang==1&&y[0].num==1) 
			{
				printf("x");
			}
			else if(wn==0&&y[0].xiang!=1&&y[0].num==1)
			{
				printf("x^%d",y[wn].xiang);
			}
		  	else if(wn!=0&&y[wn].num==1&&y[wn].xiang==1)
		  	{
		  		printf("+x");
			  }
			 
			  else if(wn!=0&&y[wn].num!=1&&y[wn].xiang==1)
			  {
			  	printf("+%dx",y[wn].num);
			  }
			  
			  else if(wn!=0&&y[wn].num!=1&&y[wn].xiang!=1&&y[wn].xiang!=0)
			  {
			  	printf("+%dx^%d",y[wn].num,y[wn].xiang);
			  }
			  
		  	  else if(wn!=0&&y[wn].num==1&&y[wn].xiang!=1&&y[wn].xiang!=0)
		  	  {
		  	  	printf("+x^%d",y[wn].xiang);
				}
			  else if(wn!=0&&y[wn].num==1&&y[wn].xiang==0)
			  {
			  	printf("+1");
			  }
			  else if(wn!=0&&y[wn].num!=1&&y[wn].xiang==0)
			  {
			  	printf("+%d",y[wn].num);
			  }
		  	
		  }
		  else if(str[wn].num<0)
		  {
		  	if(wn==0&&y[0].xiang==0)
		  	{
		  		printf("%d",y[0].num);
			  } 
		  	else if(wn==0&&y[0].xiang==1&&y[0].num!=1)
		  	{
		  		printf("%dx",y[0].num);
			  }
			else if(wn==0&&y[0].xiang!=1&&y[0].num!=1) 
			{
				printf("%dx^%d",y[wn].num,y[wn].xiang);
			 }
			else if(wn==0&&y[0].xiang==1&&y[0].num==-1) 
			{
				printf("-x");
			}
			else if(wn==0&&y[0].xiang!=1&&y[0].num==-1)
			{
				printf("-x^%d",y[wn].xiang);
			}
		  	else if(wn!=0&&y[wn].num==-1&&y[wn].xiang==1)
		  	{
		  		printf("-x");
			  }
			  else if(wn!=0&&y[wn].num!=-1&&y[wn].xiang==1)
			  {
			  	printf("%dx",y[wn].num);
			  }
			  else if(wn!=0&&y[wn].num!=-1&&y[wn].xiang!=1)
			  {
			  	printf("%dx^%d",y[wn].num,y[wn].xiang);
			  }
		  	  else if(wn!=0&&y[wn].num==-1&&y[wn].xiang!=1)
		  	  {
		  	  	printf("-x^%d",y[wn].xiang);
				}
			  else if(wn!=0&&y[wn].num==-1&&y[wn].xiang==0)
		  	  {
		  	  	printf("-1");
				}
			  else if(wn!=0&&y[wn].num!=-1&&y[wn].xiang==0)
		  	  {
		  	  	printf("%d",y[wn].num);
				}			
		  	
		  }
 
		}
		 	

	
}
	if(a3==1)
	{
		for(int kc=0;kc<2*a2;kc+=2 )
		{
			ptr2[kc]=ptr2[kc]*(-1); 
		}
		for(int w=0;w<2*a1;w++)
		 {
		 	ptr3[w]=ptr1[w];	
		}	
		for(int w1=0;w1<2*a2;w1++)
		{
			ptr3[w1+2*a1]=ptr2[w1];
		}
		str[0].xiang=ptr3[1];
		for(gt1=3;gt1<2*(a1+a2);gt1=gt1+2)
		{
			hn=0;
			for(gt2=1;gt2<gt1;gt2+=2)
			{
				if(ptr3[gt1]!=ptr3[gt2])
				{
					hn++;
				}
			}
			if(hn==(gt1-1)/2)
			{
				str[category].xiang=ptr3[gt1];
				category++;
			}
		}
		
		for(int rt=0;rt<category;rt++)
		{
			str[rt].num=0;
		}
		for( at=0;at<category;at++)
		{
			for(bt=1;bt<2*(a1+a2);bt+=2)
			{
				if(str[at].xiang==ptr3[bt])
				{
					str[at].num+=ptr3[bt-1];
				}
			}
		}
		for(int k=0;k<category-1;k++)
		{
			for(int l=0;l<category-1;l++)
			{
				if(str[l].xiang>str[l+1].xiang)
				{
					t=str[l+1];
					str[l+1]=str[l];
					str[l]=t;
				}
			}
		}
	for(wol=0,wel=0;wol<category;wol++)
		{
			if(str[wol].num==0)
			{
				continue;
			}
			y[wel]=str[wol];
				wel++;
			
		}
		
		
	for(int wn=0;wn<wel;wn++)
	{
		
          
		  if(y[wn].num>0)
		  {
		  	if(wn==0&&str[0].xiang==0)
		  	{
		  		printf("%d",y[0].num);
			  } 
		  	else if(wn==0&&y[0].xiang==1&&y[0].num!=1)
		  	{
		  		printf("%dx",y[0].num);
			  }
			else if(wn==0&&y[0].xiang!=1&&y[0].num!=1) 
			{
				printf("%dx^%d",y[wn].num,y[wn].xiang);
			 }
			else if(wn==0&&y[0].xiang==1&&y[0].num==1) 
			{
				printf("x");
			}
			else if(wn==0&&y[0].xiang!=1&&y[0].num==1)
			{
				printf("x^%d",y[wn].xiang);
			}
		  	else if(wn!=0&&y[wn].num==1&&y[wn].xiang==1)
		  	{
		  		printf("+x");
			  }
			 
			  else if(wn!=0&&y[wn].num!=1&&y[wn].xiang==1)
			  {
			  	printf("+%dx",y[wn].num);
			  }
			  
			  else if(wn!=0&&y[wn].num!=1&&y[wn].xiang!=1&&y[wn].xiang!=0)
			  {
			  	printf("+%dx^%d",y[wn].num,y[wn].xiang);
			  }
			  
		  	  else if(wn!=0&&y[wn].num==1&&y[wn].xiang!=1&&y[wn].xiang!=0)
		  	  {
		  	  	printf("+x^%d",y[wn].xiang);
				}
			  else if(wn!=0&&y[wn].num==1&&y[wn].xiang==0)
			  {
			  	printf("+1");
			  }
			  else if(wn!=0&&y[wn].num!=1&&y[wn].xiang==0)
			  {
			  	printf("+%d",y[wn].num);
			  }
		  	
		  }
		  else if(str[wn].num<0)
		  {
		  	if(wn==0&&y[0].xiang==0)
		  	{
		  		printf("%d",y[0].num);
			  } 
		  	else if(wn==0&&y[0].xiang==1&&y[0].num!=1)
		  	{
		  		printf("%dx",y[0].num);
			  }
			else if(wn==0&&y[0].xiang!=1&&y[0].num!=1) 
			{
				printf("%dx^%d",y[wn].num,y[wn].xiang);
			 }
			else if(wn==0&&y[0].xiang==1&&y[0].num==-1) 
			{
				printf("-x");
			}
			else if(wn==0&&y[0].xiang!=1&&y[0].num==-1)
			{
				printf("-x^%d",y[wn].xiang);
			}
		  	else if(wn!=0&&y[wn].num==-1&&y[wn].xiang==1)
		  	{
		  		printf("-x");
			  }
			  else if(wn!=0&&y[wn].num!=-1&&y[wn].xiang==1)
			  {
			  	printf("%dx",y[wn].num);
			  }
			  else if(wn!=0&&y[wn].num!=-1&&y[wn].xiang!=1)
			  {
			  	printf("%dx^%d",y[wn].num,y[wn].xiang);
			  }
		  	  else if(wn!=0&&y[wn].num==-1&&y[wn].xiang!=1)
		  	  {
		  	  	printf("-x^%d",y[wn].xiang);
				}
			  else if(wn!=0&&y[wn].num==-1&&y[wn].xiang==0)
		  	  {
		  	  	printf("-1");
				}
			  else if(wn!=0&&y[wn].num!=-1&&y[wn].xiang==0)
		  	  {
		  	  	printf("%d",y[wn].num);
				}			
		  	
		  }
 
		}
		
	}
	
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
}
