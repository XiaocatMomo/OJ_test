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
		printf("��ϵ������:%s\n",person->name);
		printf("��ϵ�˵绰:%s\n",person->number);
		printf("-------------------------\n");
		person = person->next;
	}
	
}



void findperson(struct Address *person,char input[])
{
	int count=0;
	while(!strcmp(person->name,input)||!strcmp(person->number,input))
	{
		printf("��ϵ��������%s\n",person->name);
		printf("��ϵ�˵绰��%s\n",person->number);
		printf("--------------------------\n");
		person = person->next;
		count++;
	}
	if(input[0]>='0'&&input[0]<='9')
	{
		if(count==0)
		{
			printf("ͨѶ¼�в����ڴ˺���"); 
		}
	}
	else
	{
		if(count==0)
		{
			printf("ͨѶ¼�в����ڴ���"); 
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
		printf("��������ĺ�����ֻ����룻");
		scanf("%s",current->number); 
		current = current->next;  
		count++;
		
	}
	
		if(count==0)
	{
			printf("ͨѶ¼�в����ڴ���"); 
	}
	return *person;
	
	
}


struct Address *deleperson(struct Address **person,char input1[])
{
	struct Address *previous,*current;
	current = *person;                  //�������ͷ 
	previous = NULL;
	while(current!=NULL&&(strcmp(current->name,input1)!=0))          //��ʼѰ�ҷ�����������ϵ�� 
	{
		
		previous = current;
		current = current->next;
		
	}
	if(current==NULL)                //�����������������һ����ͨѶ¼�������ǿյģ��ڶ�����ͨѶ¼�в����ڴ��ˣ� 
	{
		printf("sorry,δ����������"); 
		return *person; 
	}
	else              //��һ�������ǿ��Ե�֪��ͨѶ¼�϶����ǿյģ����Ѿ��ҵ��˷��ϵ��� 
	{
		if(previous == NULL)              //������������������ϵ��˾��ǵ�һ����������������ڶ������������ͨ����� 
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
	printf("��������ϵ��������");
	scanf("%s",person1->name);
    printf("������绰��");
    scanf("%s",person1->number);
	 
	
}
void addperson(struct Address **person)
{
	struct Address *new1 = (struct Address *)malloc(sizeof(struct Address));
	static struct Address *tail;
	if(new1 == NULL)
	{
		printf("�ڴ����ʧ��");
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
		tail->next = new1;              //��Ϊ�ı����β�������ֵ�����Ծ���β������Ҳ��Ҫ����β�������ʼ����NULL 
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
		printf("ѡ��ͨѶ¼����\n");
		printf("1Ϊ������ϵ��\n") ;
		printf("2Ϊ������ϵ��\n") ;
		printf("3Ϊ����������ϵ��\n") ;
		printf("4Ϊɾ��������ϵ��\n") ;
		printf("5Ϊ��ʾ��ǰͨѶ¼\n");
		printf("6Ϊ�˳�ͨѶ¼\n") ;
		scanf("%d",&b);
		if(b==1)
		{
			addperson(&person);
		 } 
		if(b==2)
		{
			printf("��������ϵ��������绰���룺");
			
			scanf("%s",input);
			
			findperson(person,input); 
			  

		}
		if(b==3)
		{
			printf("��������Ҫ���ĵ���ϵ�ˣ�");
			
			scanf("%s",input1);
			
			changeperson(&person,input1);
			
		 } 
		if(b==4)
		{
			printf("��������Ҫɾ������ϵ��������");
			
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
