#ifndef _LSstruc_h_
#define _LSstruc_h_
#define LEN sizeof(book)//�й�ͼ����Ϣ�Ľṹ��
typedef struct node//ͼ����Ϣ
{
	char ISBN[20],title[20],author[20];//��� ���� ���� 
	int  count;//��� 
	float price;//�۸� 
	struct node*next;
}book;

typedef struct//ͼ����Ϣ
{
	char ISBN[20],title[20],author[20];
	int  count;
	float price;
}books;
#endif
