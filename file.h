#ifndef _file_h_
#define _file_h_
#include "LSstruc.h"
#include "Llibrary.h"
#include "Seqlibrary.h" 
#include "conio.h"
int tjts();
void readlink(book* head)//读到链表 
{	

	head->next=NULL;
    book *p,*p1,*p2;
    int tcount=0;
    float tprice=0;
    char  ttitle[20]={'\0'},tauthor[20]={'\0'},tISBN[20]={'\0'};
    FILE *fp;

	   if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
	       system ("cls");
           printf("\n记录文件不存在!按任意键返回");
		   getch();//返回
			return;
	   }
       
    else
    {
		 int j=tjts();//统计长度 
		 if(j==0)
		 {
		   printf("\n无数据按任意键返回");
		   fclose(fp);
		   getch();//返回
			return;
		 }
		 else
		 {
				int n=0;
			   for (int k=0;k<j;k++)
		       {
			       fscanf(fp,"%s%s%s%d%f",tISBN,ttitle,tauthor,&tcount,&tprice);
			          n++;
			            if (n==1)//建立链表
		                {
				          p1=p2=(book*)malloc(LEN);
		                  head->next=p1;
						}
		                else
					    {
					      p2->next=p1;
						  p2=p1;
		                  p1=(book*)malloc(LEN);//新建链表
		                }
		
		                strcpy(p1->ISBN,tISBN);//复制书号
		                strcpy(p1->title,ttitle);//复制书名
		                strcpy(p1->author,tauthor);//复制作者名字
		                p1->count=tcount;//复制个数
		                p1->price=tprice;//复制单价
		           
		       }
			       if(j==1)
			       {
			       	p1->next=NULL;
				   }
				   else
				   {
				   		 p2->next=p1;
						 p1->next=NULL;
			       }
			fclose(fp);
		   } 
	}
}

void writelink(book* head)//链表写道文件 
{
	book * p=NULL;
	FILE *fp;
	  fp=fopen("library.txt","w");//清空文件，只写打开，
   p=head->next;
   for (;p!=NULL;)//把链表内容覆盖到文件
   {
   	   fprintf(fp,"%-8s%-9s%-14s%-7d%-8.2f\n",p->ISBN,p->title,p->author,p->count,p->price);
   	   p=p->next;
   }
   fclose(fp);
}


void readseq(books head[MAX],int *length)//读到顺序表 
{
		
	    FILE *fp;
	                     int tcount=0;
       float tprice=0;
       char  ttitle[20]={'\0'},tauthor[20]={'\0'},tISBN[20]={'\0'};
          if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
	       system ("cls");
           printf("\n记录文件不存在!按任意键返回");
            fclose(fp);
           getch();
       }

    else
    {
		 int j=tjts();//统计长度 
		 *length=j;
		 if(j==0)
		 {
		   printf("\n无数据按任意键返回");
		   fclose(fp);
		   getch();//返回
			return;
		 }
		 else
		 {
		    for (int k=0;k<j;k++)
	       {
		       fscanf(fp,"%s%s%s%d%f",tISBN,ttitle,tauthor,&tcount,&tprice);
	
	                strcpy(head[k].ISBN,tISBN);//复制书号
	                strcpy(head[k].title,ttitle);//复制书名
	                strcpy(head[k].author,tauthor);//复制作者名字
	                head[k].count=tcount;//复制个数
	                head[k].price=tprice;//复制单价      
	       }
		 }
			 fclose(fp);
	}
}
void writeseq(books head[MAX],int length)//顺序表写道文件 
{
	books *p=NULL;
	p=head;
	FILE *fp;
	  fp=fopen("library.txt","w");//清空文件，只写打开，
   for (int k=0;k<length;k++)//把链表内容覆盖到文件
   {
   	   fprintf(fp,"%-8s%-9s%-14s%-7d%-8.2f\n",head[k].ISBN,head[k].title,head[k].author,head[k].count,head[k].price);
   }
   fclose(fp);
}

#endif
