#ifndef _Seqlibrary_h_
#define _Seqlibrary_h_
#include "menu.h"
#include "conio.h"//从控制台读取一个字符 
#include "file.h"
#include <string.h>
#define MAX 50
void readseq(books head[MAX],int *length);
void writeseq(books head[MAX],int length);
int tjts();


void tsmainseq()//图书功能系统 ，插入等 
{
	/*函数声明*/ 
	void scts1();
	void xgts1();
	void pxts1();
	void llts1();
	void cxts1();
	void crts1();
	void tsczmenu(); //图书操作菜单
	char choose;
	while(1)
	{
		system("cls");
			tsczmenu();
		scanf("%c",&choose);
			switch(choose)
			{
			case'2':
				scts1();// 删除 
				continue;
			case'3':
				cxts1();//查询 
				continue;
			case'6':
				llts1();//浏览 
				continue;
			case'5':
				crts1();//插入 
				continue;
			case'7':
				xgts1();//修改 
				continue;
			case'4':
				pxts1();//排序 
				continue;
			case'0':
				return;//返回上一层 
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
	printf("书号\t\t书名\t\t作者\t\t库存量 \t单价\n");
	for(int k=0;k<length;k++)
	{
			
			printf("%-16s%-16s%-16s%-8d%-8.2f\n",head[k].ISBN,head[k].title,head[k].author,head[k].count,head[k].price); 
			num+=head[k].count;		
	};
	printf("\n");
	  printf("\t\t\t共%d种%d本书",length,num);	
	 	printf("\n"); 
	    system("pause");
		system("cls"); 
}


void pxts1()//排序选择  折半插入排序 
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
				shuhao1();// 书号 
				continue;
			case'3':
				shuming1();//书名 
				continue;
			case'4':
				kucun1();//库存
				continue;
			case'5':
				jiage1();//价格 
				continue;
			case'0':
				return;//返回图书系统 
			default:
				printf("error");
				system("cls");
				continue;
			}
	}
	
}

void print1(books *head,int length)//输出顺序表图书信息 
{
	printf("书号\t\t书名\t\t作者\t\t库存量 \t单价\n");
	for(int k=0;k<length;k++)
	{
			
			printf("%-16s%-16s%-16s%-8d%-8.2f\n",head[k].ISBN,head[k].title,head[k].author,head[k].count,head[k].price); 		
	};
	
	return;
}

void shuhao1() //书号排序     
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
         books temp = head[i];//哨兵 
 
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

void shuming1()//书名排序 
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

void kucun1()//库存排序 
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

void jiage1()//价格排序 
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


void scts1()//删除 
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
	      printf("\n请输入你要删除的书名或者书号:");//输入删除图书书名
	      fflush(stdin);
          scanf("%s",shanchu);

          	
        for(int n=0;n<length;n++)
		{
			if (!strcmp(shanchu,head[n].ISBN) || !strcmp(shanchu,head[n].title))//比较书号，书命
			 {
//			 	if(k==0)
//			 	{
			 		printf("\n查询结果:\n\n");
				  printf("书号\t\t书名\t\t作者\t\t库存量 \t单价\n");
				 	printf("%-16s%-16s%-16s%-8d%-8.2f\n",head[n].ISBN,head[n].title,head[n].author,head[n].count,head[n].price);
						           printf("\n确认删除请回车，取消请按Esc\n");
		          i=getch();
		          for(;i!=13&&i!=27;)
		          i=getch();
		          if (i==13)
		          {
				          	for(int m=n;m<length;m++)
					 		head[m]=head[m+1];
					 	k++;
					 	length=length-1;
					 		printf("\n删除成功 \n按任意键继续\n");
					 		getch();
				  }
//		          	return;	
//				 }

			 }	
		}
		
			if(k==0)
		{
			printf("无符合项按，任意键返回上一层");
		}
//		else
//		{
//			printf("\n删除成功 \n按任意键返回上一层\n");
//		 }    
		 getch();//返回上一层
   system ("cls");
	writeseq(head,length);
}

void cxts1()//查询 
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
       printf("请输入书号,书名或作者查询：\n");
       scanf("%s",chazhao);
       system ("cls");
       
       	   for(int k=0;k<length;k++)
	   {
	   		
	        if(!strcmp(chazhao,head[k].author)||!strcmp(chazhao,head[k].ISBN)||!strcmp(chazhao,head[k].title))
	        {
	        	if(n==0)
				{
					  printf("查询结果:\n\n");
				  printf("书号\t\t书名\t\t作者\t\t库存量 \t单价\n");
				}	
				n++; 
				printf("%-16s%-16s%-16s%-8d%-8.2f\n",head[k].ISBN,head[k].title,head[k].author,head[k].count,head[k].price);
	        }
        
       }
	
	        if (n==0)//文件夹为空则输出无记录并返回上一层
        { 
        printf("\n无符合记录!\n");
		}	

		system("pause");
		system("cls");
		writeseq(head,length);
}

void xgts1()//修改 
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
	      printf("\n请输入你要修改的书名,作者或者书号:");//输入修改图书书名
	      fflush(stdin);
          scanf("%s",xiugai);

          	
        	for(int k=0;k<length;k++)
		{
			if (!strcmp(xiugai,head[k].author)||!strcmp(xiugai,head[k].ISBN)||!strcmp(xiugai,head[k].title))//比较书号，书命.zuozhe
			 {
				 						  printf("查询结果:\n\n");
				  printf("书号\t\t书名\t\t作者\t\t库存量 \t单价\n");
				 	printf("%-16s%-16s%-16s%-8d%-8.2f\n",head[k].ISBN,head[k].title,head[k].author,head[k].count,head[k].price);
				 	
				 	          printf("\n确认修改请回车，取消请按Esc\n");
			          i=getch();
			          for(;i!=13&&i!=27;)
			          i=getch();
			          if (i==13)
			          {
				          	//			          	return;
					 	printf("\n请按以下格式输入图书信息:\n书号 书名 作者 进库量 单价");
						printf("请输入:\n");
						scanf("%s%s%s%d%f",ISBN,title,author,&count,&price);
										
					 	strcpy(head[k].ISBN,ISBN);//复制书号
		                strcpy(head[k].title,title);//复制书名
		                strcpy(head[k].author,author);//复制作者名字
		                head[k].count=count;//复制个数
		                head[k].price=price;;//复制单价
					 	n++;
					 		printf("\n修改成功 \n按任意键继续\n");
					 		getch();

				  } 
			   	

			 }	
		}
	
		if (n==0)//文件夹为空则输出无记录并返回上一层
        { 
        printf("\n无符合记录!\n");
		}
 
		 getch();//返回上一层	

		system("cls");
		writeseq(head,length);
}

void crts1()//插入 
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
			printf("请输入插入的位置；");
		scanf("%d",&position);
		
	if(position<1||position>length+1)
	{
		printf("插入位置不合理");
			system("pause");
			system("cls");
		return;
	}
	else if(length==MAX)
	{
		printf("位置已满");
			system("pause");
			system("cls");
		return; 
	 } 		
   	printf("\n请按以下格式输入图书信息:\n书号 书名 作者 进库量 单价");

		printf("请输入:\n");
		scanf("%s%s%s%d%f",charu.ISBN,charu.title,charu.author,&(charu.count),&(charu.price));
		
		int k=0;
		for( k=length;k>=position;k--)
		{
			head[k]=head[k-1];
		}
		head[k]=charu;
					printf("插入成功");
				writeseq(head,length+1);
		
	system("pause");
			system("cls");
	
}

int insert1(books *head,int i,books s,int length)//插入实现 
{
	if(i<1&&i>length+1)
	{
		printf("插入位置不合理");
		return 0;
	}
	else if(length==MAX)
	{
		printf("位置已满");
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
