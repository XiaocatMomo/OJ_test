#include<stdio.h>
#include<stdlib.h>
struct WOOB
{
	int num;
	struct WOOB *next;
	
};
void insertwoob(struct WOOB **head,int value);

struct WOOB *removenum(struct WOOB **head,int value);

void insertwoob(struct WOOB **head,int value)
{
	struct WOOB *previous,*current,*new1;
	current = *head;
	previous = NULL;
	while(current != NULL&&current->num<value)
	{
		previous = current;
		current = current->next; 
		
	}
	new1 = (struct WOOB*)malloc(sizeof(struct WOOB)); 
	if(new1 == NULL)
	{
		printf("内存分配失败");
		exit(1); 
	}
	new1->num = value;
	new1->next = current;
	if(previous == NULL)
	{
		*head = new1;
	}
	else
	{
		previous->next = new1;
		
	}

	
}

void printwoob(struct WOOB *head)
{
	while(head != NULL)
	{
		printf("%d ",head->num);
		head = head->next;
	}
	printf("\n");
		
}
void release(struct WOOB *wb)
{
	struct WOOB *a;
	while(wb!=NULL)
	{
		a = wb;
		free(wb);
		wb = a->next;

	}
}
struct WOOB*removenum(struct WOOB **head,int value)
{
	struct WOOB *previous,*current,*new2;
	current = *head;
	previous = NULL;
	while(current != NULL&&current->num != value)
	{
		 previous = current;
		 current = current->next;
	}
	if(current == NULL)
	{
		printf("sorry，未找到相应匹配数字\n");
		return *head;
	}
	else
	{
		if(previous == NULL)
		{
			*head = current->next;
		}
		else {
			
			previous->next = current->next;
		}
		return *head;
		
	}
	
	
	
	
	
	
	
	
 } 
int main()
{
	struct WOOB *head = NULL;
	int input,identify,dele;
	while(1)
	{
		printf("请输入整数（输入-1为结束） ：");
		scanf("%d",&input);
		if(input == -1)
		{
			break;
		}
		insertwoob(&head,input);		
		printwoob(head);	
	}
	while(1)
	{
		printf("是否想删除某值(是输入1，否输入0)   ");
		scanf("%d",&identify);
		if(identify == 0)
		{
			break;
		}
		 if(identify == 1)
		{
			printf("请输入想要删去的值： ");
			scanf("%d",&dele);
			head = removenum(&head,dele);
			printwoob(head);
		}
		
		
		
	 } 
	 
	
	return 0;
	
	
	
	
	
	
	
}

