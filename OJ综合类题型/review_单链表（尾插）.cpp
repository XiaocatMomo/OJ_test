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
	printf("请输入书名："); 
	scanf("%s",book->title);
	printf("请输入作者名：");
	scanf("%s",book->writer);
	
}
void printlibrary(struct Book *library)
{
	while(library !=NULL)
	{
		printf("书名：%s\n",library->title);
		printf("作者名：%s\n",library->writer);
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
    static struct Book *tail;//static是静态变量的标志，使用静态变量就是为了避免每次调用该函数时需初始化数据，这样其数据保留 ，tail指的是单链表的尾部 
	if(book ==NULL)
	{
		printf("内存分配失败"); 
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
		tail->next = book;//上次调用后单链表的尾部为新插入的数据
		book->next = NULL;
		
	}
	tail = book;//新单链表的尾部为新插入的数据
}
int main()
{
	struct Book *library = NULL;
	
	char ch,sh;
	
	while(1)
	{
	  
	     printf("是否输入书籍（t/f)");
	
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
	printf("是否打印书籍（t/f)");
	
	sh = getchar();
	
	if(sh == 't')
	{
		printlibrary(library);
	}
	releasebook(library);
	return 0;
}
