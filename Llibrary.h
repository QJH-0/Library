#ifndef _Llibrary_h_
#define _Llibrary_h_
#include "menu.h"
#include "conio.h"//从控制台读取一个字符 
#include "file.h"
#include <string.h>
	void readlink(book*);
	void writelink(book*);
void tsmainlink()//图书功能系统 ，插入等 
{
	/*函数声明*/ 
	void scts();
	void xgts();
	void pxts();
	void llts();
	void cxts();
	void crts();
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
				scts();// 删除 
				continue;
			case'3':
				cxts();//查询 
				continue;
			case'6':
				llts();//浏览 计数 
				continue;
			case'5':
				crts();//插入 
				continue;
			case'7':
				xgts();//修改 
				continue;
			case'4':
				pxts();//排序 
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

int tjts()//统计图书种数 
{
FILE *fp;
int txcl=0,n;
float tprice=0;
char ttitlee[20]={'\0'},tauthor[20]={'\0'},tshuhao[20]={'\0'};
fp=fopen("library.txt","r");//打开文件
for (n=0;!feof(fp);n++)//逐个读文件
fscanf(fp,"%s%s%s%d%f",tshuhao,ttitlee,tauthor,&txcl,&tprice);
n--;//当文件内部的位置指针指向文件结束时，并不会立即设置FILE结构中的文件结束标识，
//只有再执行一次读文件操作，才会设置结束标志，此后调用feof()才会返回为真。
fclose(fp);//关闭文件
return (n);//返回个数
}
void llts()//浏览图书
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
	printf("书号\t\t书名\t\t作者\t\t库存量 \t单价\n");
		for(;p!=NULL;p=p->next)
	   {	  
			printf("%-16s%-16s%-16s%-8d%-8.2f\n",p->ISBN,p->title,p->author,p->count,p->price); 
			num+=p->count;       
       }
       	printf("\n");
	  printf("\t\t\t共%d种%d本书",n,num);	
	         	printf("\n");
    	system("pause");
		system("cls"); 
}

void crts()//插入 
{
	int insert(book *,int ,book* ); 
    book head;//先分配内存再传 
        readlink(&head);//book* head=NULL;readlink(&head);传地址内存问题（动态分配） 
    if(head.next==NULL)
    {
    	return;
	}

    book *p,*p1,*p2;
	int j=tjts();//统计长度 
	int position = 0;
        system ("cls");
		printf("请输入插入的位置；");
		scanf("%d",&position);
	if(position<1||position>j+1)
	{
		printf("插入位置不合理");
			system("pause");
			system("cls");
		return;
	}
   	printf("\n请按以下格式输入图书信息:\n书号 书名 作者 进库量 单价");

		printf("请输入:\n");
		p==(book*)malloc(LEN);
		scanf("%s%s%s%d%f",p->ISBN,p->title,p->author,&(p->count),&(p->price));
 
		int tag=insert(&head,position,p);
		if(tag)
		printf("插入成功");
		else
		printf("插入失败"); 
    
writelink(&head);
		system("pause");
		system("cls"); 
}

int insert(book *head,int i,book* s)//插入实现 
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
		printf("插入位置不合理！");
		return 0;
	}
	q=(book*)malloc(LEN);
	q=s;
	q->next=p->next;
	p->next=q;
	return 1;	
 } 
 
 void cxts()//查询图书
{ 
//    *hea=(book*)malloc(sizeof(LEN));//带头结点单链表 
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
       printf("请输入书号,书名或作者查询：\n");
       scanf("%s",chazhao);
       system ("cls");
       m=tjts();
	   for(;p!=NULL;p=p->next)
	   {
	   		
        if(!strcmp(chazhao,p->ISBN)||!strcmp(chazhao,p->title)||!strcmp(chazhao,p->author))
        {
        	if(k==0)
			{
				  printf("查询结果:\n\n");
			  printf("书号\t书名\t\t作者\t\t现存量\t单价\n");
			}	
			k++; 
			printf("%-8s%-16s%-16s%-7d%-8.2f\n",p->ISBN,p->title,p->author,p->count,p->price);
        }
        
       }
		writelink(&head);
        if (k==0)//文件夹为空则输出无记录并返回上一层
        { 
        printf("\n无符合记录!\n");
		}	

		system("pause");
		system("cls"); 
}
 
 void scts()//删除图书
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
	      printf("\n请输入你要删除的书名或者书号:");//输入删除图书书名
	      fflush(stdin);
          scanf("%s",shanchu);

		while(p->next!=NULL)
		{
			if (!strcmp(shanchu,p->next->title) || !strcmp(shanchu,p->next->ISBN))//比较书号，书命
			 {

			 			  printf("查询结果:\n\n");
			  printf("书号\t\t书名\t\t作者\t\t现存量 \t单价\n");
				 printf("%-16s%-16s%-16s%-8d%-8.2f\n",p->next->ISBN,p->next->title,p->next->author,p->next->count,p->next->price);
				           printf("\n确认删除请回车，取消请按Esc\n");
		          i=getch();
		          for(;i!=13&&i!=27;)
		          i=getch();
		          if (i==13)
		          {
		          		p->next=p->next->next;
			 			k++;
			 			printf("\n删除成功 \n按任意键继续\n");
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
			printf("无符合项按，任意键返回上一层");
		}
  
		 getch();//返回上一层
   system ("cls");
   writelink(&head);
}
 
 
 void xgts()//修改图书 
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
	      printf("\n请输入你要修改的书名，作者或者书号:");//输入修改图书书名
	      fflush(stdin);
          scanf("%s",xiugai);

        p=p->next;
        int count=0;
       float price=0;
       char  title[20]={'\0'},author[20]={'\0'},ISBN[20]={'\0'};
		for(;p!=NULL;p=p->next)
		{
			if (!strcmp(xiugai,p->title) || !strcmp(xiugai,p->ISBN)|| !strcmp(xiugai,p->author))//比较书号，书命
			 {

				 					  printf("查询结果:\n\n");
			  printf("书号\t书名\t\t作者\t\t现存量\t单价\n");
				 printf("%-8s%-16s%-16s%-7d%-8.2f\n",p->ISBN,p->title,p->author,p->count,p->price);
				           printf("\n确认修改请回车，取消请按Esc\n");
		          i=getch();
		          for(;i!=13&&i!=27;)
		          i=getch();
		          if (i==13)
		          {

				 	printf("\n请按以下格式输入图书信息:\n书号 书名 作者 进库量 单价");
					printf("请输入:\n");
					scanf("%s%s%s%d%f",ISBN,title,author,&count,&price);
								 	strcpy(p->ISBN,ISBN);//复制书号
	                strcpy(p->title,title);//复制书名
	                strcpy(p->author,author);//复制作者名字
	                p->count=count;//复制个数
	                p->price=price;//复制单价
				 	k++;
				 		printf("\n修改成功 \n按任意键继续\n");
				 		getch();
				  }
			   				

			}	
		}
		if(k==0)
		{
			printf("无符合项按，任意键返回上一层");
		}
   
		 getch();//返回上一层
 	   system ("cls");
   writelink(&head);
 }
 
void pxts()//冒泡排序 
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
				shuhao();// 书号 
				continue;
			case'3':
				shuming();//书名 
				continue;
			case'4':
				kucun();//库存
				continue;
			case'5':
				jiage();//价格 
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

void print(book* head)//输出链表 
{
	book *p=head;
	p=p->next;
				  printf("排序结果:\n\n");
			  printf("书号\t\t书名\t\t作者\t\t现存量 \t单价\n");
	for(;p!=NULL;p=p->next)
	printf("%-16s%-16s%-16s%-8d%-8.2f\n",p->ISBN,p->title,p->author,p->count,p->price);
}

void shuhao()
{
	
	    book head;//先分配内存再传 
        readlink(&head);//book* head=NULL;readlink(&head);传地址内存问题（动态分配） 
    if(head.next==NULL)
    {
    	return;
	}
	
		book *pre,*cur,*nex,*temp;
	book *p;//pre前一项 cur当前项 next后一项 end控制循环次数(优化冒泡)
	book *end=NULL;
	int flag=1; 
	while(head.next!=end && flag==1)
	{
		flag=0;
		//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
		for(pre=&head,cur=pre->next,nex=cur->next;  nex!=end;  pre=pre->next,cur=cur->next,nex=nex->next)
		{
			if(strcmp(cur->ISBN,nex->ISBN)>0) //从小到大
			{
				flag=1;//flag置为1说明本次发生交换 
				pre->next=nex;
				cur->next=nex->next;
				nex->next=cur;

				//此时next变前一项，cur变后一项  交换next cur
				temp=cur; cur=nex; nex=temp;
			}
		}

		//一轮循环结束 最后一项已经排好 end提前一项 (冒泡原理)
		end = cur;
	}
	
	system("cls");
	print(&head); 
	printf("\n按任意键返回上一层\n");
	getch();
return;
}


void shuming()
{
	/*
	常用汉字 的unicode 码范围是：u4e00-u9fa5
	汉字：[0x4e00,0x9fa5]（或十进制[19968,40869]）
	数字：[0x30,0x39]（或十进制[48, 57]）
	小写字母：[0x61,0x7a]（或十进制[97, 122]）
	大写字母：[0x41,0x5a]（或十进制[65, 90]）
	*/
		book head;//先分配内存再传 
        readlink(&head);//book* head=NULL;readlink(&head);传地址内存问题（动态分配） 
    if(head.next==NULL)
    {
    	return;
	}
	
		book *pre,*cur,*nex,*temp;
	book *p;//pre前一项 cur当前项 next后一项 end控制循环次数(优化冒泡)
	book *end=NULL;
	int flag=1; 
	while(head.next!=end && flag==1)
	{
		flag=0;
		//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
		for(pre=&head,cur=pre->next,nex=cur->next;  nex!=end;  pre=pre->next,cur=cur->next,nex=nex->next)
		{
			if(strcmp(cur->title,nex->title)>0) //从小到大
			{
				flag=1;//flag置为1说明本次发生交换 
				pre->next=nex;
				cur->next=nex->next;
				nex->next=cur;

				//此时next变前一项，cur变后一项  交换next cur
				temp=cur; cur=nex; nex=temp;
			}
		}

		//一轮循环结束 最后一项已经排好 end提前一项 (冒泡原理)
		end = cur;
	}
	
		system("cls");
	print(&head); 
	printf("\n按任意键返回上一层\n");
	getch();
return;
}

void kucun()
{
			book head;//先分配内存再传 
        readlink(&head);//book* head=NULL;readlink(&head);传地址内存问题（动态分配） 
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

				//此时nex变前一项，cur变后一项  交换nex cur
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
	printf("\n按任意键返回上一层\n");
	getch();
return;
 } 
 
 
void jiage()
{
		book head;//先分配内存再传 
        readlink(&head);//book* head=NULL;readlink(&head);传地址内存问题（动态分配） 
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

				//此时nex变前一项，cur变后一项  交换nex cur
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
	printf("\n按任意键返回上一层\n");
	getch();
return;
}
 

#endif
