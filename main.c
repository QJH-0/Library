#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Llibrary.h"
#include "manage.h"
#include "menu.h" 
#include "file.h"
#include "LSstruc.h" 
#include "Seqlibrary.h"
#include "conio.h"//�ӿ���̨��ȡһ���ַ� 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char choose;//����Ա�˵� 
	
	while(1)
	{
	    landmenu();
			scanf(" %c",&choose);
		switch(choose)
		  {
			  case'1':
			    land();//��¼ 
			   continue;
			  case'2':
			  	xinjian();//�½��˺� 
			  	continue; 
			  	case'3':
			  	xgmm();//�޸����� 
			  	continue;
			  case'0':
		        exit(0);//�˳� 
		  	    system ("cls");
			    break;
			  default:
			  	printf("error");
			  	system("cls");
			  	continue;
		  }	
	}
	return 0;
}
