#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Llibrary.h"
#include "manage.h"
#include "menu.h" 
#include "file.h"
#include "LSstruc.h" 
#include "Seqlibrary.h"
#include "conio.h"//从控制台读取一个字符 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char choose;//管理员菜单 
	
	while(1)
	{
	    landmenu();
			scanf(" %c",&choose);
		switch(choose)
		  {
			  case'1':
			    land();//登录 
			   continue;
			  case'2':
			  	xinjian();//新建账号 
			  	continue; 
			  	case'3':
			  	xgmm();//修改密码 
			  	continue;
			  case'0':
		        exit(0);//退出 
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
