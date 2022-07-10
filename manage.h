#ifndef _manage_h_
#define _manage_h_
#define LEN2 sizeof(struct land)//有关登录系统的结构体
#include "conio.h"//从控制台读取一个字符 
#include "Llibrary.h"
#include "Seqlibrary.h"
#include "menu.h"
struct land//管理员结构体 
{
	int zhanghao;
	char password[20];
	struct land*next;
};

void xzLSmain()//图书入库、链表，顺序表 
{
	void xzLSmenu();
	void zjts();
	void tsmainlink();
	void tsmainseq();
	char choose;
	
	while(1)
	{
		xzLSmenu();
			scanf("%c",&choose);
		switch(choose)//功能函数
		  {
			  case'1':
			  	system("cls");
			    zjts();//增加图书ruku
			    continue;
			  case'2':
			  	tsmainlink();//链表 
			  	continue;
			  case'3': 
			  	tsmainseq();//顺序表 
		        continue;
			  case'0'://返回上一层  
			  	system("cls");
			  	return;
		    	break;
		      default:
		      	printf("error");
		      	continue;
		    		
		  }
	}

}


int tjzhs()//统计账号密码文本个数
{
FILE *fp;
int zhang=0,n;
char mm[20]={'\0'};
fp=fopen("land.txt","r");//打开文件
for (n=0;!feof(fp);n++)//逐个读文件
fscanf(fp,"%d %s",&zhang,mm);
n--;
fclose(fp);//关闭文件
return (n);//返回个数
}

void xinjian()//新建账户密码
{
	FILE *fp;
	int zhanghao;
	char password[20],password1[20];
	char hit=0;
	if ((fp=fopen("land.txt","r"))==NULL)//if语句：打开图书馆文件，不存在此文件则新建
	{
      fp=fopen("land.txt","w");
      fclose(fp);
    }
    system("cls");
	fp=fopen("land.txt","a");
	for(;;)//输入两次密码确认，两次相同才能确认
	{
	   printf("\n请按以下格式输入账户:\n学号 密码\n");
	   printf("请输入:");
	   scanf("%d %s",&zhanghao,password);
       printf("再次输入密码:\n");
	   scanf("%s",password1);
	   if(strcmp(password,password1)==0)
	   {
	       fprintf(fp,"%d %s\n",zhanghao,password);
		   break;
       }
       else
	   {
	       printf("两次输入密码不一致，继续创建按回车，退出按ESC");
	       hit=getch();
		   if(hit=27)
		   system("cls");
	   }
   }
   fclose(fp);
   printf("创建成功，按任意键返回");
   getch();
   system("cls");
}

void xgmm()//修改密码
{
void xg(int z,char m[20]);
	   FILE *fp;
       int zh=0,k=0,count=0,m=0,n=0;
       int chazhao,hit;
       char mima[20]={'\0'},password1[20]={'\0'};
       char  mm[20]={'\0'};
       char i;

       if ((fp=fopen("land.txt","r"))==NULL)//打开文件
       {
	       system ("cls");
           printf("\n记录文件不存在!按任意键返回");
  		   getch();
  		   system("cls");
		   return;
       }
	   system("cls");
       printf("请输入你的帐号和旧密码：\n");
       scanf("%d %s",&chazhao,mima);
	   m =tjzhs();
	   for (n=0;n<=m;n++)
	   {
	    	fscanf(fp,"%d %s",&zh,mm);
          if(zh==chazhao)//比较账号 
          {
        	 if(!strcmp(mm,mima))//比较密码 
        	 {
        		printf("请输入新的密码");
        		scanf("%s",mima);
       		    printf("再次输入密码:\n");
	            scanf("%s",password1);
	             if(strcmp(mima,password1)==0)
	   			 {
		            xg(chazhao,mima);
		            fclose(fp);
		            printf("修改成功任，意键退出");
		            getch();
	                system("cls");
	                return;
   			     }
       			  else
	   			  {
	       		   	  printf("两次输入密码不一致,按任意键退出");
	       		   	  fclose(fp);
	       			  getch();
	       			  system("cls");
						return;
   				  }
		   	  } 
			else
			{
				printf("旧密码错误，按任意键返回！");
				fclose(fp);
				getch();
				system("cls");
				return;   
			}
          }
       }
	   printf("不存在此账号，按任意键返回");
		fclose(fp);//修改结束
		getch();
		system("cls");
}

void xg(int z,char m[20])//修改密码函数
{
	FILE *fp;
	int zhanghao1,n,j,k;
	char mima1[20];
	struct land *head,*p,*p1,*p2;

	 fp=fopen("land.txt","r");
	   j =tjzhs();

	   for (k=0;k<=j;k++)
       {
	       fscanf(fp,"%d %s",&zhanghao1,mima1);
           if (z!=zhanghao1)//比较名字，将不同名字的信息复制到链表
          {
	            n++;//相同返回值为0不执行if语句继续循环，不同则执行直到将所有不同的书名建立成链表
	            if (n==1)//建立链表
                {
		          p1=p2=(struct land*)malloc(LEN2);
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct land*)malloc(LEN2);//新建链表
                }
 				p1->zhanghao=zhanghao1;
                strcpy(p1->password,mima1);//复制账号密码
          }
       }
        if (n==0)
		 {
			head=NULL;
		 }
		else//建立链表的最后剩余一个储存空间，所以封底
		{
			p2->next=p1;
			p1->next=NULL;
			fclose(fp);
		}
			  fp=fopen("land.txt","w");//清空文件，只写打开，然后关闭
              fclose(fp);
              fp=fopen("land.txt","a");//追加文件
              p=head;
            for (;p!=NULL;)//把链表内容覆盖到文件
   			{
   	   		 	fprintf(fp,"%d %s%\n",p->zhanghao,p->password);
   	   			p=p->next;
	        }
	        fprintf(fp,"%d %s\n",z,m);
            fclose(fp);
             system ("cls");

}


void land()//输入账户密码的登录函数
{
	int match(int m,char a[20]);
	void xzLSmain();
	int zhanghao;
	char password[20];
	int i=2,j,k,n;
	char hit=0;
	system("cls");
	do
	{
	   printf("\n请输入账号:\n");
       scanf("%d",&zhanghao);
       printf("确认输入请安回车，重新输入请按ECS");
       fflush(stdin);
       hit=getch();//暂停程序当i接收后继续下一条指令
       for (;hit!=13&&hit!=27;)//保证只能是CR和ESC才能退出循环,输入其他字符无用，暂停程序，按'CR'继续。
       {
	        hit=getch();
	   }
    }while(hit==27);
    
	 printf("\n请输入密码:\n");
	 scanf("%s",password);
     i=match(zhanghao,password);
     if(i==1)
	 {
       printf("登陆成功!按任意键继续");
	   getch();
	   xzLSmain();
	 }
	 else
	 {
	 	if(i==-1)
		 {
			 printf("密码错误!");
		 }
		 if(i==0)
		    printf("不存在此用户");
		 getch();
		 system("cls");
	 }
}
int match(int m,char a[20])//匹配数据库中的账号密码
{
	FILE*fp;
	int n=0,i=0;
	int zhanghao;
	char password[20];

	if ((fp=fopen("land.txt","r"))==NULL)//不存在读者文件
	  {
         system ("cls");
		 printf("\n 还未存在用户!请新建账户");
	 	return 3;
      }
      
      for(;!feof(fp);)
      {
        fscanf(fp,"%d%s",&zhanghao,password);
        if(m==zhanghao)
        {
        	if(strcmp(a,password)==0)
			return 1;
			else
			{
			return -1;
		}
	    }
	  }
	return 0;
 }
 



void zjts()//增加图书入库 
{
	FILE*fp;
	char i;
	int count=0;
    float price=0;
    char  title[20]={'\0'},author[20]={'\0'},ISBN[20]={'\0'};
    system ("cls");

    if ((fp=fopen("library.txt","r"))==NULL)//if语句：打开图书馆文件，不存在此文件则新建
	{
      fp=fopen("library.txt","w");
      fclose(fp);
    }
	fp=fopen("library.txt","a");
	
	printf("\n请按以下格式输入图书信息:\n书号 书名 作者 进库量 价格");
	
	for(;i!=13;)//为了实现输入一次后按h回车退出
	{
		printf("请输入:\n");
		scanf("%s%s%s%d%f",ISBN,title,author,&count,&price);
		fprintf(fp,"%-8s%-9s%-14s%-7d%-8.2f\n",ISBN,title,author,count,price);
	    printf("继续输入请按Esc，结束输入请按回车\n");
        i=getch();//暂停程序当i接收后继续下一条指令
        for (;i!=13&&i!=27;)//保证只能是CR和ESC才能退出循环,输入其他字符无用，暂停程序，按'CR'继续。
        i=getch();
     }

	fclose(fp);
    printf("\n保存成功，按任意键返回上一层!");
    getch();
}
#endif
