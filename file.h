#ifndef _file_h_
#define _file_h_
#include "LSstruc.h"
#include "Llibrary.h"
#include "Seqlibrary.h" 
#include "conio.h"
int tjts();
void readlink(book* head)//�������� 
{	

	head->next=NULL;
    book *p,*p1,*p2;
    int tcount=0;
    float tprice=0;
    char  ttitle[20]={'\0'},tauthor[20]={'\0'},tISBN[20]={'\0'};
    FILE *fp;

	   if ((fp=fopen("library.txt","r"))==NULL)//���ļ�
       {
	       system ("cls");
           printf("\n��¼�ļ�������!�����������");
		   getch();//����
			return;
	   }
       
    else
    {
		 int j=tjts();//ͳ�Ƴ��� 
		 if(j==0)
		 {
		   printf("\n�����ݰ����������");
		   fclose(fp);
		   getch();//����
			return;
		 }
		 else
		 {
				int n=0;
			   for (int k=0;k<j;k++)
		       {
			       fscanf(fp,"%s%s%s%d%f",tISBN,ttitle,tauthor,&tcount,&tprice);
			          n++;
			            if (n==1)//��������
		                {
				          p1=p2=(book*)malloc(LEN);
		                  head->next=p1;
						}
		                else
					    {
					      p2->next=p1;
						  p2=p1;
		                  p1=(book*)malloc(LEN);//�½�����
		                }
		
		                strcpy(p1->ISBN,tISBN);//�������
		                strcpy(p1->title,ttitle);//��������
		                strcpy(p1->author,tauthor);//������������
		                p1->count=tcount;//���Ƹ���
		                p1->price=tprice;//���Ƶ���
		           
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

void writelink(book* head)//����д���ļ� 
{
	book * p=NULL;
	FILE *fp;
	  fp=fopen("library.txt","w");//����ļ���ֻд�򿪣�
   p=head->next;
   for (;p!=NULL;)//���������ݸ��ǵ��ļ�
   {
   	   fprintf(fp,"%-8s%-9s%-14s%-7d%-8.2f\n",p->ISBN,p->title,p->author,p->count,p->price);
   	   p=p->next;
   }
   fclose(fp);
}


void readseq(books head[MAX],int *length)//����˳��� 
{
		
	    FILE *fp;
	                     int tcount=0;
       float tprice=0;
       char  ttitle[20]={'\0'},tauthor[20]={'\0'},tISBN[20]={'\0'};
          if ((fp=fopen("library.txt","r"))==NULL)//���ļ�
       {
	       system ("cls");
           printf("\n��¼�ļ�������!�����������");
            fclose(fp);
           getch();
       }

    else
    {
		 int j=tjts();//ͳ�Ƴ��� 
		 *length=j;
		 if(j==0)
		 {
		   printf("\n�����ݰ����������");
		   fclose(fp);
		   getch();//����
			return;
		 }
		 else
		 {
		    for (int k=0;k<j;k++)
	       {
		       fscanf(fp,"%s%s%s%d%f",tISBN,ttitle,tauthor,&tcount,&tprice);
	
	                strcpy(head[k].ISBN,tISBN);//�������
	                strcpy(head[k].title,ttitle);//��������
	                strcpy(head[k].author,tauthor);//������������
	                head[k].count=tcount;//���Ƹ���
	                head[k].price=tprice;//���Ƶ���      
	       }
		 }
			 fclose(fp);
	}
}
void writeseq(books head[MAX],int length)//˳���д���ļ� 
{
	books *p=NULL;
	p=head;
	FILE *fp;
	  fp=fopen("library.txt","w");//����ļ���ֻд�򿪣�
   for (int k=0;k<length;k++)//���������ݸ��ǵ��ļ�
   {
   	   fprintf(fp,"%-8s%-9s%-14s%-7d%-8.2f\n",head[k].ISBN,head[k].title,head[k].author,head[k].count,head[k].price);
   }
   fclose(fp);
}

#endif
