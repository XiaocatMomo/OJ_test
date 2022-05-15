#include<stdio.h>
#include<math.h>
int main(){
	float x,m;
	scanf("%f",&x);
	if(x>=0){
		m=sqrt(x);
	}
	else{
		m=(x+1)*(x+1)+2.0*x+1.0/x;
			}
	printf("%.2f",m);
	return 0;
	
	
	
	
	
} 
