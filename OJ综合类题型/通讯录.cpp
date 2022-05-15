#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Address
{
	char name[10];
	char number[11];
	struct Address *next;
	
}; 

void release(struct Address *person)
{
	struct Address *a;
	while(person!=NULL)
	{
		a = person;
		free(person);
		person = a->next;
	}

}

void displayperson(struct Address *person)
{
	while(person!=NULL)
	{
		printf("联系人姓名:%s\n",person->name);
		printf("联系人电话:%s\n",person->number);
		printf("-------------------------\n");
		person = person->next;
	}
	
}



void findperson(struct Address *person,char input[])
{
	int count=0;
	while(!strcmp(person->name,input)||!strcmp(person->number,input))
	{
		printf("联系人姓名：%s\n",person->name);
		printf("联系人电话：%s\n",person->number);
		printf("--------------------------\n");
		person = person->next;
		count++;
	}
	if(input[0]>='0'&&input[0]<='9')
	{
		if(count==0)
		{
			printf("通讯录中不存在此号码"); 
		}
	}
	else
	{
		if(count==0)
		{
			printf("通讯录中不存在此人"); 
		}
	}
	
	
}


struct Address * changeperson(struct Address **person,char input[])
{
	int count=0;
	struct Address *current,*previous;
	current = *person;
	while(!strcmp(current->name ,input))
	{
		printf("请输入更改后的新手机号码；");
		scanf("%s",current->number); 
		current = current->next;  
		count++;
		
	}
	
		if(count==0)
	{
			printf("通讯录中不存在此人"); 
	}
	return *person;
	
	
}


struct Address *deleperson(struct Address **person,char input1[])
{
	struct Address *previous,*current;
	current = *person;                  //首先起个头 
	previous = NULL;
	while(current!=NULL&&(strcmp(current->name,input1)!=0))          //开始寻找符合条件的联系人 
	{
		
		previous = current;
		current = current->next;
		
	}
	if(current==NULL)                //这里有两种情况，第一种是通讯录本来就是空的，第二种是通讯录中不存在此人； 
	{
		printf("sorry,未搜索到此人"); 
		return *person; 
	}
	else              //这一步，我们可以得知，通讯录肯定不是空的，且已经找到了符合的人 
	{
		if(previous == NULL)              //这里有两种情况，符合的人就是第一个人是特殊情况，第二种情况就是普通的情况 
		{
			*person = current->next;
		}
		else
		{
			previous->next = current->next ;
		}
		return *person;
		
	 } 
	
	

}


void input(struct Address *person1)
{
	printf("请输入联系人姓名：");
	scanf("%s",person1->name);
    printf("请输入电话：");
    scanf("%s",person1->number);
	 
	
}
void addperson(struct Address **person)
{
	struct Address *new1 = (struct Address *)malloc(sizeof(struct Address));
	static struct Address *tail;
	if(new1 == NULL)
	{
		printf("内存分配失败");
		exit(1);

	}
	input(new1);
	if(*person==NULL)
	{
		*person = new1;
		new1->next = NULL;
		
	}
	else
	{
		tail->next = new1;              //因为改变的是尾部后面的值，所以尽管尾部变了也不要紧，尾部后面的始终是NULL 
		new1->next = NULL;
	
	}
	tail = new1;

}
int main()
{
	struct Address *person=NULL;
	int b; 
	char input[11];
	char input1[11];
	char input2[11];
	while(1)
	{
		printf("选择通讯录操作\n");
		printf("1为加入联系人\n") ;
		printf("2为查找联系人\n") ;
		printf("3为更改已有联系人\n") ;
		printf("4为删除已有联系人\n") ;
		printf("5为显示当前通讯录\n");
		printf("6为退出通讯录\n") ;
		scanf("%d",&b);
		if(b==1)
		{
			addperson(&person);
		 } 
		if(b==2)
		{
			printf("请输入联系人姓名或电话号码：");
			
			scanf("%s",input);
			
			findperson(person,input); 
			  

		}
		if(b==3)
		{
			printf("请输入需要更改的联系人：");
			
			scanf("%s",input1);
			
			changeperson(&person,input1);
			
		 } 
		if(b==4)
		{
			printf("请输入需要删除的联系人姓名：");
			
			scanf("%s",input2);
			
			deleperson(&person,input2);
			

			
		 } 
		if(b==5)
		{
			displayperson(person);
		 } 
		if(b==6)
		{
			release(person);
			break;
		}
		printf("\n"); 

		 
	}
	return 0;
	
}
