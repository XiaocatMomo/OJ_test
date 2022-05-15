#include<stdio.h>
#include<stdlib.h>
struct Book
{
	char title[40];
	char writer[10];
	struct Book *next;
};
void input(struct Book *book)
{
	printf("������������"); 
	scanf("%s",book->title);
	printf("��������������");
	scanf("%s",book->writer);
	
}
void printlibrary(struct Book *library)
{
	while(library !=NULL)
	{
		printf("������%s\n",library->title);
		printf("��������%s\n",library->writer);
		printf("------------\n");
		library = library->next;
	}
	
}
void releasebook(struct Book *library)
{
	struct Book *a;
	while(library != NULL)
	{
		a = library;
		free(library);
		library = a->next;
	}

}
void addbook(struct Book **library)
{
	struct Book *book = (struct Book *)malloc(sizeof(struct Book));
	struct Book *temp;
	if(book ==NULL)
	{
		printf("�ڴ����ʧ��"); 
		exit(1);
	}
	input(book);
	if(*library ==NULL)
	{
		*library = book;
		book->next = NULL;
	}
	else
	{
		temp = *library;
		*library = book;
		book->next = temp;
		
	}
	
}
int main()
{
	struct Book *library = NULL;
	
	char ch,sh;
	
	while(1)
	{
	  
	     printf("�Ƿ������鼮��t/f)");
	
	     ch = getchar();
	
	     if(ch=='t')
	    {
		   addbook(&library);
		   getchar();
	    }
	    if(ch=='f')
	    {
	    	getchar();
	    	break;
		}
	    
   }
	printf("�Ƿ��ӡ�鼮��t/f)");
	
	sh = getchar();
	
	if(sh == 't')
	{
		printlibrary(library);
	}
	releasebook(library);
	return 0;
}
