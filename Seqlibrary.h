#ifndef _Seqlibrary_h_
#define _Seqlibrary_h_
#include "menu.h"
#include "conio.h"//�ӿ���̨��ȡһ���ַ� 
#include "file.h"
#include <string.h>
#define MAX 50
void readseq(books head[MAX],int *length);
void writeseq(books head[MAX],int length);
int tjts();


void tsmainseq()//ͼ�鹦��ϵͳ ������� 
{
	/*��������*/ 
	void scts1();
	void xgts1();
	void pxts1();
	void llts1();
	void cxts1();
	void crts1();
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
				scts1();// ɾ�� 
				continue;
			case'3':
				cxts1();//��ѯ 
				continue;
			case'6':
				llts1();//��� 
				continue;
			case'5':
				crts1();//���� 
				continue;
			case'7':
				xgts1();//�޸� 
				continue;
			case'4':
				pxts1();//���� 
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


void llts1()
{
	books head[MAX];
	int length=0;
	readseq(head,&length);
	if(length==0)
	{
		return;
	}
	int num=0;
	system("cls");
	printf("���\t\t����\t\t����\t\t����� \t����\n");
	for(int k=0;k<length;k++)
	{
			
			printf("%-16s%-16s%-16s%-8d%-8.2f\n",head[k].ISBN,head[k].title,head[k].author,head[k].count,head[k].price); 
			num+=head[k].count;		
	};
	printf("\n");
	  printf("\t\t\t��%d��%d����",length,num);	
	 	printf("\n"); 
	    system("pause");
		system("cls"); 
}


void pxts1()//����ѡ��  �۰�������� 
{
void shuhao1();
void shuming1();
void kucun1();
void jiage1(); 
	char choose;
	while(1)
	{
		system("cls");
			tspxmenu();
		scanf("%c",&choose);
			switch(choose)
			{
			case'2':
				shuhao1();// ��� 
				continue;
			case'3':
				shuming1();//���� 
				continue;
			case'4':
				kucun1();//���
				continue;
			case'5':
				jiage1();//�۸� 
				continue;
			case'0':
				return;//����ͼ��ϵͳ 
			default:
				printf("error");
				system("cls");
				continue;
			}
	}
	
}

void print1(books *head,int length)//���˳���ͼ����Ϣ 
{
	printf("���\t\t����\t\t����\t\t����� \t����\n");
	for(int k=0;k<length;k++)
	{
			
			printf("%-16s%-16s%-16s%-8d%-8.2f\n",head[k].ISBN,head[k].title,head[k].author,head[k].count,head[k].price); 		
	};
	
	return;
}

void shuhao1() //�������     
{
	
		books head[MAX];
	int length=0;
	readseq(head,&length);
	if(length==0)
	{
		return;
	}
	system("cls");
	
    for(int i = 1; i < length; i++){
         int low = 0;
         int hight = i-1;
         books temp = head[i];//�ڱ� 
 
         while(hight>=low){
             int mid = ( low + hight ) / 2;
             if (strcmp(head[mid].ISBN,temp.ISBN)>0)
			 {
                    hight = mid - 1;
             }
			 else
			 {
                 low = mid + 1;
              }
          }
 
          for (int j = i-1; j > hight; j--) {
              head[j+1] = head[j];
          }
 
          head[hight+1] = temp;
	}
	print1(head,length);
		    system("pause");
		system("cls"); 
}

void shuming1()//�������� 
{
	
		books head[MAX];
	int length=0;
	readseq(head,&length);
	if(length==0)
	{
		return;
	}
	system("cls");
	
    for(int i = 1; i < length; i++){
         int low = 0;
         int hight = i-1;
         books temp = head[i];
 
         while(hight>=low){
             int mid = ( low + hight ) / 2;
             if (strcmp(head[mid].title,temp.title)>0)
			 {
                    hight = mid - 1;
             }
			 else
			 {
                 low = mid + 1;
              }
          }
 
          for (int j = i-1; j > hight; j--) {
              head[j+1] = head[j];
          }
 
          head[hight+1] = temp;
	}
	print1(head,length);
		    system("pause");
		system("cls"); 
}

void kucun1()//������� 
{
	
		books head[MAX];
	int length=0;
	readseq(head,&length);
	if(length==0)
	{
		return;
	}
	system("cls");
	
    for(int i = 1; i < length; i++){
         int low = 0;
         int hight = i-1;
         books temp = head[i];
 
         while(hight>=low){
             int mid = ( low + hight ) / 2;
             if (head[mid].count>temp.count)
			 {
                    hight = mid - 1;
             }
			 else
			 {
                 low = mid + 1;
              }
          }
 
          for (int j = i-1; j > hight; j--) {
              head[j+1] = head[j];
          }
 
          head[hight+1] = temp;
	}
	print1(head,length);
		    system("pause");
		system("cls"); 
}

void jiage1()//�۸����� 
{
	
		books head[MAX];
	int length=0;
	readseq(head,&length);
	if(length==0)
	{
		return;
	}
	system("cls");
	
    for(int i = 1; i < length; i++){
         int low = 0;
         int hight = i-1;
         books temp = head[i];
 
         while(hight>=low){
             int mid = ( low + hight ) / 2;
             if (head[mid].price>temp.price)
			 {
                    hight = mid - 1;
             }
			 else
			 {
                 low = mid + 1;
              }
          }
 
          for (int j = i-1; j > hight; j--) {
              head[j+1] = head[j];
          }
 
          head[hight+1] = temp;
	}
	print1(head,length);
		    system("pause");
		system("cls"); 
}


void scts1()//ɾ�� 
{
		books head[MAX];
	int length=0;
	readseq(head,&length);
	if(length==0)
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

          	
        for(int n=0;n<length;n++)
		{
			if (!strcmp(shanchu,head[n].ISBN) || !strcmp(shanchu,head[n].title))//�Ƚ���ţ�����
			 {
//			 	if(k==0)
//			 	{
			 		printf("\n��ѯ���:\n\n");
				  printf("���\t\t����\t\t����\t\t����� \t����\n");
				 	printf("%-16s%-16s%-16s%-8d%-8.2f\n",head[n].ISBN,head[n].title,head[n].author,head[n].count,head[n].price);
						           printf("\nȷ��ɾ����س���ȡ���밴Esc\n");
		          i=getch();
		          for(;i!=13&&i!=27;)
		          i=getch();
		          if (i==13)
		          {
				          	for(int m=n;m<length;m++)
					 		head[m]=head[m+1];
					 	k++;
					 	length=length-1;
					 		printf("\nɾ���ɹ� \n�����������\n");
					 		getch();
				  }
//		          	return;	
//				 }

			 }	
		}
		
			if(k==0)
		{
			printf("�޷�����������������һ��");
		}
//		else
//		{
//			printf("\nɾ���ɹ� \n�������������һ��\n");
//		 }    
		 getch();//������һ��
   system ("cls");
	writeseq(head,length);
}

void cxts1()//��ѯ 
{
			books head[MAX];
	int length=0;
	readseq(head,&length);
	if(length==0)
	{
		return;
	}
	int n=0;
	       char  title[20]={'\0'},author[20]={'\0'},ISBN[20]={'\0'};
       char chazhao[20]={'\0'};
	   system("cls");
       printf("���������,���������߲�ѯ��\n");
       scanf("%s",chazhao);
       system ("cls");
       
       	   for(int k=0;k<length;k++)
	   {
	   		
	        if(!strcmp(chazhao,head[k].author)||!strcmp(chazhao,head[k].ISBN)||!strcmp(chazhao,head[k].title))
	        {
	        	if(n==0)
				{
					  printf("��ѯ���:\n\n");
				  printf("���\t\t����\t\t����\t\t����� \t����\n");
				}	
				n++; 
				printf("%-16s%-16s%-16s%-8d%-8.2f\n",head[k].ISBN,head[k].title,head[k].author,head[k].count,head[k].price);
	        }
        
       }
	
	        if (n==0)//�ļ���Ϊ��������޼�¼��������һ��
        { 
        printf("\n�޷��ϼ�¼!\n");
		}	

		system("pause");
		system("cls");
		writeseq(head,length);
}

void xgts1()//�޸� 
{
	books head[MAX];
	int length=0;
	readseq(head,&length);
	if(length==0)
	{
		return;
	}
		int n=0;
		int count=0;
		float price=0;
	       char  title[20]={'\0'},author[20]={'\0'},ISBN[20]={'\0'};
	       
	    	   char i;
	   char xiugai[20]={'\0'};
	      system ("cls");
	      printf("\n��������Ҫ�޸ĵ�����,���߻������:");//�����޸�ͼ������
	      fflush(stdin);
          scanf("%s",xiugai);

          	
        	for(int k=0;k<length;k++)
		{
			if (!strcmp(xiugai,head[k].author)||!strcmp(xiugai,head[k].ISBN)||!strcmp(xiugai,head[k].title))//�Ƚ���ţ�����.zuozhe
			 {
				 						  printf("��ѯ���:\n\n");
				  printf("���\t\t����\t\t����\t\t����� \t����\n");
				 	printf("%-16s%-16s%-16s%-8d%-8.2f\n",head[k].ISBN,head[k].title,head[k].author,head[k].count,head[k].price);
				 	
				 	          printf("\nȷ���޸���س���ȡ���밴Esc\n");
			          i=getch();
			          for(;i!=13&&i!=27;)
			          i=getch();
			          if (i==13)
			          {
				          	//			          	return;
					 	printf("\n�밴���¸�ʽ����ͼ����Ϣ:\n��� ���� ���� ������ ����");
						printf("������:\n");
						scanf("%s%s%s%d%f",ISBN,title,author,&count,&price);
										
					 	strcpy(head[k].ISBN,ISBN);//�������
		                strcpy(head[k].title,title);//��������
		                strcpy(head[k].author,author);//������������
		                head[k].count=count;//���Ƹ���
		                head[k].price=price;;//���Ƶ���
					 	n++;
					 		printf("\n�޸ĳɹ� \n�����������\n");
					 		getch();

				  } 
			   	

			 }	
		}
	
		if (n==0)//�ļ���Ϊ��������޼�¼��������һ��
        { 
        printf("\n�޷��ϼ�¼!\n");
		}
 
		 getch();//������һ��	

		system("cls");
		writeseq(head,length);
}

void crts1()//���� 
{
	int insert1(books *,int ,books ,int );
		books head[MAX];
	int length=0;
	readseq(head,&length);
	if(length==0)
	{
		return;
	}
	books charu;
		int position = 0;
        system ("cls");	
			printf("����������λ�ã�");
		scanf("%d",&position);
		
	if(position<1||position>length+1)
	{
		printf("����λ�ò�����");
			system("pause");
			system("cls");
		return;
	}
	else if(length==MAX)
	{
		printf("λ������");
			system("pause");
			system("cls");
		return; 
	 } 		
   	printf("\n�밴���¸�ʽ����ͼ����Ϣ:\n��� ���� ���� ������ ����");

		printf("������:\n");
		scanf("%s%s%s%d%f",charu.ISBN,charu.title,charu.author,&(charu.count),&(charu.price));
		
		int k=0;
		for( k=length;k>=position;k--)
		{
			head[k]=head[k-1];
		}
		head[k]=charu;
					printf("����ɹ�");
				writeseq(head,length+1);
		
	system("pause");
			system("cls");
	
}

int insert1(books *head,int i,books s,int length)//����ʵ�� 
{
	if(i<1&&i>length+1)
	{
		printf("����λ�ò�����");
		return 0;
	}
	else if(length==MAX)
	{
		printf("λ������");
		return 0; 
	 } 
	else
	{
		int k=0;
		for( k=length;k>=i;k--)
		{
			head[k]=head[k-1];
		}
		head[k]=s;
	}
	return 1;	
 }
#endif
