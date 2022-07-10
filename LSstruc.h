#ifndef _LSstruc_h_
#define _LSstruc_h_
#define LEN sizeof(book)//有关图书信息的结构体
typedef struct node//图书信息
{
	char ISBN[20],title[20],author[20];//书号 书名 作者 
	int  count;//库存 
	float price;//价格 
	struct node*next;
}book;

typedef struct//图书信息
{
	char ISBN[20],title[20],author[20];
	int  count;
	float price;
}books;
#endif
