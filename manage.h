#ifndef _manage_h_
#define _manage_h_
#define LEN2 sizeof(struct land)//�йص�¼ϵͳ�Ľṹ��
#include "conio.h"//�ӿ���̨��ȡһ���ַ� 
#include "Llibrary.h"
#include "Seqlibrary.h"
#include "menu.h"
struct land//����Ա�ṹ�� 
{
	int zhanghao;
	char password[20];
	struct land*next;
};

void xzLSmain()//ͼ����⡢����˳��� 
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
		switch(choose)//���ܺ���
		  {
			  case'1':
			  	system("cls");
			    zjts();//����ͼ��ruku
			    continue;
			  case'2':
			  	tsmainlink();//���� 
			  	continue;
			  case'3': 
			  	tsmainseq();//˳��� 
		        continue;
			  case'0'://������һ��  
			  	system("cls");
			  	return;
		    	break;
		      default:
		      	printf("error");
		      	continue;
		    		
		  }
	}

}


int tjzhs()//ͳ���˺������ı�����
{
FILE *fp;
int zhang=0,n;
char mm[20]={'\0'};
fp=fopen("land.txt","r");//���ļ�
for (n=0;!feof(fp);n++)//������ļ�
fscanf(fp,"%d %s",&zhang,mm);
n--;
fclose(fp);//�ر��ļ�
return (n);//���ظ���
}

void xinjian()//�½��˻�����
{
	FILE *fp;
	int zhanghao;
	char password[20],password1[20];
	char hit=0;
	if ((fp=fopen("land.txt","r"))==NULL)//if��䣺��ͼ����ļ��������ڴ��ļ����½�
	{
      fp=fopen("land.txt","w");
      fclose(fp);
    }
    system("cls");
	fp=fopen("land.txt","a");
	for(;;)//������������ȷ�ϣ�������ͬ����ȷ��
	{
	   printf("\n�밴���¸�ʽ�����˻�:\nѧ�� ����\n");
	   printf("������:");
	   scanf("%d %s",&zhanghao,password);
       printf("�ٴ���������:\n");
	   scanf("%s",password1);
	   if(strcmp(password,password1)==0)
	   {
	       fprintf(fp,"%d %s\n",zhanghao,password);
		   break;
       }
       else
	   {
	       printf("�����������벻һ�£������������س����˳���ESC");
	       hit=getch();
		   if(hit=27)
		   system("cls");
	   }
   }
   fclose(fp);
   printf("�����ɹ��������������");
   getch();
   system("cls");
}

void xgmm()//�޸�����
{
void xg(int z,char m[20]);
	   FILE *fp;
       int zh=0,k=0,count=0,m=0,n=0;
       int chazhao,hit;
       char mima[20]={'\0'},password1[20]={'\0'};
       char  mm[20]={'\0'};
       char i;

       if ((fp=fopen("land.txt","r"))==NULL)//���ļ�
       {
	       system ("cls");
           printf("\n��¼�ļ�������!�����������");
  		   getch();
  		   system("cls");
		   return;
       }
	   system("cls");
       printf("����������ʺź;����룺\n");
       scanf("%d %s",&chazhao,mima);
	   m =tjzhs();
	   for (n=0;n<=m;n++)
	   {
	    	fscanf(fp,"%d %s",&zh,mm);
          if(zh==chazhao)//�Ƚ��˺� 
          {
        	 if(!strcmp(mm,mima))//�Ƚ����� 
        	 {
        		printf("�������µ�����");
        		scanf("%s",mima);
       		    printf("�ٴ���������:\n");
	            scanf("%s",password1);
	             if(strcmp(mima,password1)==0)
	   			 {
		            xg(chazhao,mima);
		            fclose(fp);
		            printf("�޸ĳɹ��Σ�����˳�");
		            getch();
	                system("cls");
	                return;
   			     }
       			  else
	   			  {
	       		   	  printf("�����������벻һ��,��������˳�");
	       		   	  fclose(fp);
	       			  getch();
	       			  system("cls");
						return;
   				  }
		   	  } 
			else
			{
				printf("��������󣬰���������أ�");
				fclose(fp);
				getch();
				system("cls");
				return;   
			}
          }
       }
	   printf("�����ڴ��˺ţ������������");
		fclose(fp);//�޸Ľ���
		getch();
		system("cls");
}

void xg(int z,char m[20])//�޸����뺯��
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
           if (z!=zhanghao1)//�Ƚ����֣�����ͬ���ֵ���Ϣ���Ƶ�����
          {
	            n++;//��ͬ����ֵΪ0��ִ��if������ѭ������ͬ��ִ��ֱ�������в�ͬ����������������
	            if (n==1)//��������
                {
		          p1=p2=(struct land*)malloc(LEN2);
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct land*)malloc(LEN2);//�½�����
                }
 				p1->zhanghao=zhanghao1;
                strcpy(p1->password,mima1);//�����˺�����
          }
       }
        if (n==0)
		 {
			head=NULL;
		 }
		else//������������ʣ��һ������ռ䣬���Է��
		{
			p2->next=p1;
			p1->next=NULL;
			fclose(fp);
		}
			  fp=fopen("land.txt","w");//����ļ���ֻд�򿪣�Ȼ��ر�
              fclose(fp);
              fp=fopen("land.txt","a");//׷���ļ�
              p=head;
            for (;p!=NULL;)//���������ݸ��ǵ��ļ�
   			{
   	   		 	fprintf(fp,"%d %s%\n",p->zhanghao,p->password);
   	   			p=p->next;
	        }
	        fprintf(fp,"%d %s\n",z,m);
            fclose(fp);
             system ("cls");

}


void land()//�����˻�����ĵ�¼����
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
	   printf("\n�������˺�:\n");
       scanf("%d",&zhanghao);
       printf("ȷ�������밲�س������������밴ECS");
       fflush(stdin);
       hit=getch();//��ͣ����i���պ������һ��ָ��
       for (;hit!=13&&hit!=27;)//��ֻ֤����CR��ESC�����˳�ѭ��,���������ַ����ã���ͣ���򣬰�'CR'������
       {
	        hit=getch();
	   }
    }while(hit==27);
    
	 printf("\n����������:\n");
	 scanf("%s",password);
     i=match(zhanghao,password);
     if(i==1)
	 {
       printf("��½�ɹ�!�����������");
	   getch();
	   xzLSmain();
	 }
	 else
	 {
	 	if(i==-1)
		 {
			 printf("�������!");
		 }
		 if(i==0)
		    printf("�����ڴ��û�");
		 getch();
		 system("cls");
	 }
}
int match(int m,char a[20])//ƥ�����ݿ��е��˺�����
{
	FILE*fp;
	int n=0,i=0;
	int zhanghao;
	char password[20];

	if ((fp=fopen("land.txt","r"))==NULL)//�����ڶ����ļ�
	  {
         system ("cls");
		 printf("\n ��δ�����û�!���½��˻�");
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
 



void zjts()//����ͼ����� 
{
	FILE*fp;
	char i;
	int count=0;
    float price=0;
    char  title[20]={'\0'},author[20]={'\0'},ISBN[20]={'\0'};
    system ("cls");

    if ((fp=fopen("library.txt","r"))==NULL)//if��䣺��ͼ����ļ��������ڴ��ļ����½�
	{
      fp=fopen("library.txt","w");
      fclose(fp);
    }
	fp=fopen("library.txt","a");
	
	printf("\n�밴���¸�ʽ����ͼ����Ϣ:\n��� ���� ���� ������ �۸�");
	
	for(;i!=13;)//Ϊ��ʵ������һ�κ�h�س��˳�
	{
		printf("������:\n");
		scanf("%s%s%s%d%f",ISBN,title,author,&count,&price);
		fprintf(fp,"%-8s%-9s%-14s%-7d%-8.2f\n",ISBN,title,author,count,price);
	    printf("���������밴Esc�����������밴�س�\n");
        i=getch();//��ͣ����i���պ������һ��ָ��
        for (;i!=13&&i!=27;)//��ֻ֤����CR��ESC�����˳�ѭ��,���������ַ����ã���ͣ���򣬰�'CR'������
        i=getch();
     }

	fclose(fp);
    printf("\n����ɹ����������������һ��!");
    getch();
}
#endif
