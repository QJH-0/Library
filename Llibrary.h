#ifndef _Llibrary_h_
#define _Llibrary_h_
#include "menu.h"
#include "conio.h"//�ӿ���̨��ȡһ���ַ� 
#include "file.h"
#include <string.h>
	void readlink(book*);
	void writelink(book*);
void tsmainlink()//ͼ�鹦��ϵͳ ������� 
{
	/*��������*/ 
	void scts();
	void xgts();
	void pxts();
	void llts();
	void cxts();
	void crts();
	void tsczmenu(); //ͼ������˵�
	char choose;
	while(1)
	{
		system("cls");
			tsczmenu();
		scanf("%c",&choose);
			switch(choose)
			{
			case'2':
				scts();// ɾ�� 
				continue;
			case'3':
				cxts();//��ѯ 
				continue;
			case'6':
				llts();//��� ���� 
				continue;
			case'5':
				crts();//���� 
				continue;
			case'7':
				xgts();//�޸� 
				continue;
			case'4':
				pxts();//���� 
				continue;
			case'0':
				return;//������һ��  
			default:
				printf("error");
				system("cls");
				continue;
			}
	}

}

int tjts()//ͳ��ͼ������ 
{
FILE *fp;
int txcl=0,n;
float tprice=0;
char ttitlee[20]={'\0'},tauthor[20]={'\0'},tshuhao[20]={'\0'};
fp=fopen("library.txt","r");//���ļ�
for (n=0;!feof(fp);n++)//������ļ�
fscanf(fp,"%s%s%s%d%f",tshuhao,ttitlee,tauthor,&txcl,&tprice);
n--;//���ļ��ڲ���λ��ָ��ָ���ļ�����ʱ����������������FILE�ṹ�е��ļ�������ʶ��
//ֻ����ִ��һ�ζ��ļ��������Ż����ý�����־���˺����feof()�Ż᷵��Ϊ�档
fclose(fp);//�ر��ļ�
return (n);//���ظ���
}
void llts()//���ͼ��
{
	book head;
    readlink(&head);
    book *p=head.next;
    if(p==NULL)
    {
    	return;
	}
	int n=tjts();
	int num=0;
	system("cls");
	printf("���\t\t����\t\t����\t\t����� \t����\n");
		for(;p!=NULL;p=p->next)
	   {	  
			printf("%-16s%-16s%-16s%-8d%-8.2f\n",p->ISBN,p->title,p->author,p->count,p->price); 
			num+=p->count;       
       }
       	printf("\n");
	  printf("\t\t\t��%d��%d����",n,num);	
	         	printf("\n");
    	system("pause");
		system("cls"); 
}

void crts()//���� 
{
	int insert(book *,int ,book* ); 
    book head;//�ȷ����ڴ��ٴ� 
        readlink(&head);//book* head=NULL;readlink(&head);����ַ�ڴ����⣨��̬���䣩 
    if(head.next==NULL)
    {
    	return;
	}

    book *p,*p1,*p2;
	int j=tjts();//ͳ�Ƴ��� 
	int position = 0;
        system ("cls");
		printf("����������λ�ã�");
		scanf("%d",&position);
	if(position<1||position>j+1)
	{
		printf("����λ�ò�����");
			system("pause");
			system("cls");
		return;
	}
   	printf("\n�밴���¸�ʽ����ͼ����Ϣ:\n��� ���� ���� ������ ����");

		printf("������:\n");
		p==(book*)malloc(LEN);
		scanf("%s%s%s%d%f",p->ISBN,p->title,p->author,&(p->count),&(p->price));
 
		int tag=insert(&head,position,p);
		if(tag)
		printf("����ɹ�");
		else
		printf("����ʧ��"); 
    
writelink(&head);
		system("pause");
		system("cls"); 
}

int insert(book *head,int i,book* s)//����ʵ�� 
{
	book *p,*q;
	int j;
//		p=(book*)malloc(sizeof(LEN));
	p= head;
	j=0;
	while(p->next!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(j!=i-1)
	{
		printf("����λ�ò�����");
		return 0;
	}
	q=(book*)malloc(LEN);
	q=s;
	q->next=p->next;
	p->next=q;
	return 1;	
 } 
 
 void cxts()//��ѯͼ��
{ 
//    *hea=(book*)malloc(sizeof(LEN));//��ͷ��㵥���� 
//    book* head=*hea;
	book head;
    readlink(&head);
    book *p=head.next;
    if(p==NULL)
    {
    	return;
	}
       int count=0,m=0,k=0;
	   float price=0;
       char  title[20]={'\0'},author[20]={'\0'},ISBN[20]={'\0'};
       char chazhao[20]={'\0'};
	   system("cls");
       printf("���������,���������߲�ѯ��\n");
       scanf("%s",chazhao);
       system ("cls");
       m=tjts();
	   for(;p!=NULL;p=p->next)
	   {
	   		
        if(!strcmp(chazhao,p->ISBN)||!strcmp(chazhao,p->title)||!strcmp(chazhao,p->author))
        {
        	if(k==0)
			{
				  printf("��ѯ���:\n\n");
			  printf("���\t����\t\t����\t\t�ִ���\t����\n");
			}	
			k++; 
			printf("%-8s%-16s%-16s%-7d%-8.2f\n",p->ISBN,p->title,p->author,p->count,p->price);
        }
        
       }
		writelink(&head);
        if (k==0)//�ļ���Ϊ��������޼�¼��������һ��
        { 
        printf("\n�޷��ϼ�¼!\n");
		}	

		system("pause");
		system("cls"); 
}
 
 void scts()//ɾ��ͼ��
{
	book head;
    readlink(&head);
    book *p=&head;
    if(p->next==NULL)
    {
    	return;
	}

       int j,k=0;
	   char i;
	   char shanchu[20]={'\0'};
	      system ("cls");
	      printf("\n��������Ҫɾ���������������:");//����ɾ��ͼ������
	      fflush(stdin);
          scanf("%s",shanchu);

		while(p->next!=NULL)
		{
			if (!strcmp(shanchu,p->next->title) || !strcmp(shanchu,p->next->ISBN))//�Ƚ���ţ�����
			 {

			 			  printf("��ѯ���:\n\n");
			  printf("���\t\t����\t\t����\t\t�ִ��� \t����\n");
				 printf("%-16s%-16s%-16s%-8d%-8.2f\n",p->next->ISBN,p->next->title,p->next->author,p->next->count,p->next->price);
				           printf("\nȷ��ɾ����س���ȡ���밴Esc\n");
		          i=getch();
		          for(;i!=13&&i!=27;)
		          i=getch();
		          if (i==13)
		          {
		          		p->next=p->next->next;
			 			k++;
			 			printf("\nɾ���ɹ� \n�����������\n");
			 			getch();
				  }


				   else
				   {
				   		p=p->next;
				   }

			 }	
				 
			 else
			 	p=p->next;
		}
		if(k==0)
		{
			printf("�޷�����������������һ��");
		}
  
		 getch();//������һ��
   system ("cls");
   writelink(&head);
}
 
 
 void xgts()//�޸�ͼ�� 
 {
 	book head;
    readlink(&head);
    book *p=&head;
    if(p->next==NULL)
    {
    	return;
	}
	   int j,k=0;
	   char i;
	   char xiugai[20]={'\0'};
	      system ("cls");
	      printf("\n��������Ҫ�޸ĵ����������߻������:");//�����޸�ͼ������
	      fflush(stdin);
          scanf("%s",xiugai);

        p=p->next;
        int count=0;
       float price=0;
       char  title[20]={'\0'},author[20]={'\0'},ISBN[20]={'\0'};
		for(;p!=NULL;p=p->next)
		{
			if (!strcmp(xiugai,p->title) || !strcmp(xiugai,p->ISBN)|| !strcmp(xiugai,p->author))//�Ƚ���ţ�����
			 {

				 					  printf("��ѯ���:\n\n");
			  printf("���\t����\t\t����\t\t�ִ���\t����\n");
				 printf("%-8s%-16s%-16s%-7d%-8.2f\n",p->ISBN,p->title,p->author,p->count,p->price);
				           printf("\nȷ���޸���س���ȡ���밴Esc\n");
		          i=getch();
		          for(;i!=13&&i!=27;)
		          i=getch();
		          if (i==13)
		          {

				 	printf("\n�밴���¸�ʽ����ͼ����Ϣ:\n��� ���� ���� ������ ����");
					printf("������:\n");
					scanf("%s%s%s%d%f",ISBN,title,author,&count,&price);
								 	strcpy(p->ISBN,ISBN);//�������
	                strcpy(p->title,title);//��������
	                strcpy(p->author,author);//������������
	                p->count=count;//���Ƹ���
	                p->price=price;//���Ƶ���
				 	k++;
				 		printf("\n�޸ĳɹ� \n�����������\n");
				 		getch();
				  }
			   				

			}	
		}
		if(k==0)
		{
			printf("�޷�����������������һ��");
		}
   
		 getch();//������һ��
 	   system ("cls");
   writelink(&head);
 }
 
void pxts()//ð������ 
{ 
void shuhao();
void shuming();
void kucun();
void jiage(); 
	char choose;
	while(1)
	{
		system("cls");
			tspxmenu();
		scanf("%c",&choose);
			switch(choose)
			{
			case'2':
				shuhao();// ��� 
				continue;
			case'3':
				shuming();//���� 
				continue;
			case'4':
				kucun();//���
				continue;
			case'5':
				jiage();//�۸� 
				continue;
			case'0':
				return;//������һ�� 
			default:
				printf("error");
				system("cls");
				continue;
			}
	}
	
}

void print(book* head)//������� 
{
	book *p=head;
	p=p->next;
				  printf("������:\n\n");
			  printf("���\t\t����\t\t����\t\t�ִ��� \t����\n");
	for(;p!=NULL;p=p->next)
	printf("%-16s%-16s%-16s%-8d%-8.2f\n",p->ISBN,p->title,p->author,p->count,p->price);
}

void shuhao()
{
	
	    book head;//�ȷ����ڴ��ٴ� 
        readlink(&head);//book* head=NULL;readlink(&head);����ַ�ڴ����⣨��̬���䣩 
    if(head.next==NULL)
    {
    	return;
	}
	
		book *pre,*cur,*nex,*temp;
	book *p;//preǰһ�� cur��ǰ�� next��һ�� end����ѭ������(�Ż�ð��)
	book *end=NULL;
	int flag=1; 
	while(head.next!=end && flag==1)
	{
		flag=0;
		//��ʼ������ָ�� ; �ж��Ƿ񵽴����λ�� ; ����ָ�뼯�����
		for(pre=&head,cur=pre->next,nex=cur->next;  nex!=end;  pre=pre->next,cur=cur->next,nex=nex->next)
		{
			if(strcmp(cur->ISBN,nex->ISBN)>0) //��С����
			{
				flag=1;//flag��Ϊ1˵�����η������� 
				pre->next=nex;
				cur->next=nex->next;
				nex->next=cur;

				//��ʱnext��ǰһ�cur���һ��  ����next cur
				temp=cur; cur=nex; nex=temp;
			}
		}

		//һ��ѭ������ ���һ���Ѿ��ź� end��ǰһ�� (ð��ԭ��)
		end = cur;
	}
	
	system("cls");
	print(&head); 
	printf("\n�������������һ��\n");
	getch();
return;
}


void shuming()
{
	/*
	���ú��� ��unicode �뷶Χ�ǣ�u4e00-u9fa5
	���֣�[0x4e00,0x9fa5]����ʮ����[19968,40869]��
	���֣�[0x30,0x39]����ʮ����[48, 57]��
	Сд��ĸ��[0x61,0x7a]����ʮ����[97, 122]��
	��д��ĸ��[0x41,0x5a]����ʮ����[65, 90]��
	*/
		book head;//�ȷ����ڴ��ٴ� 
        readlink(&head);//book* head=NULL;readlink(&head);����ַ�ڴ����⣨��̬���䣩 
    if(head.next==NULL)
    {
    	return;
	}
	
		book *pre,*cur,*nex,*temp;
	book *p;//preǰһ�� cur��ǰ�� next��һ�� end����ѭ������(�Ż�ð��)
	book *end=NULL;
	int flag=1; 
	while(head.next!=end && flag==1)
	{
		flag=0;
		//��ʼ������ָ�� ; �ж��Ƿ񵽴����λ�� ; ����ָ�뼯�����
		for(pre=&head,cur=pre->next,nex=cur->next;  nex!=end;  pre=pre->next,cur=cur->next,nex=nex->next)
		{
			if(strcmp(cur->title,nex->title)>0) //��С����
			{
				flag=1;//flag��Ϊ1˵�����η������� 
				pre->next=nex;
				cur->next=nex->next;
				nex->next=cur;

				//��ʱnext��ǰһ�cur���һ��  ����next cur
				temp=cur; cur=nex; nex=temp;
			}
		}

		//һ��ѭ������ ���һ���Ѿ��ź� end��ǰһ�� (ð��ԭ��)
		end = cur;
	}
	
		system("cls");
	print(&head); 
	printf("\n�������������һ��\n");
	getch();
return;
}

void kucun()
{
			book head;//�ȷ����ڴ��ٴ� 
        readlink(&head);//book* head=NULL;readlink(&head);����ַ�ڴ����⣨��̬���䣩 
    if(head.next==NULL)
    {
    	return;
	}
	
	 	book *pre,*cur,*nex;
	book *p;
	pre=&head;
	cur=head.next;
	nex=cur->next;
	int flag=1; 
	int m=tjts();
	while((m>0)&&(flag==1))
	{
		pre=&head;
		cur=head.next;
		nex=cur->next;
		flag=0;
		for(int i=1;i<m;i++)
		{
			if(cur->count>nex->count)
			{
				pre->next=nex;
				cur->next=nex->next;
				nex->next=cur;

				//��ʱnex��ǰһ�cur���һ��  ����nex cur
			    p=cur; cur=nex; nex=p;
				flag=1;				
			}
			pre=pre->next;
			cur=cur->next;
			nex=nex->next;
		}

		m--;
	}
	
	system("cls");
		print(&head); 
	printf("\n�������������һ��\n");
	getch();
return;
 } 
 
 
void jiage()
{
		book head;//�ȷ����ڴ��ٴ� 
        readlink(&head);//book* head=NULL;readlink(&head);����ַ�ڴ����⣨��̬���䣩 
    if(head.next==NULL)
    {
    	return;
	}
	
	 	book *pre,*cur,*nex;
	book *p;
	pre=&head;
	cur=head.next;
	nex=cur->next;
	int flag=1;
	int m=tjts();
	while((m>0)&&(flag==1))
	{
			pre=&head;
	cur=head.next;
	nex=cur->next;
		flag=0;
		for(int i=1;i<m;i++)
		{
			if(cur->price>nex->price)
			{
				pre->next=nex;
				cur->next=nex->next;
				nex->next=cur;

				//��ʱnex��ǰһ�cur���һ��  ����nex cur
			    p=cur; cur=nex; nex=p;
				flag=1;				
			}
			pre=pre->next;
			cur=cur->next;
			nex=nex->next;
		}

		m--;
	}
	
	system("cls");
		print(&head); 
	printf("\n�������������һ��\n");
	getch();
return;
}
 

#endif
