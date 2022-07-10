#ifndef _menu_h_
#define _menu_h_
void landmenu()//显示登录菜单
{
printf("\n\n\t    欢迎使用\n\n");
printf("**********************************************");
printf("\n\n\t\t1.登录系统\n\n");

printf("\n\n\t\t2.创建账号\n\n");

printf("\n\n\t\t3.修改密码\n\n");

printf("\n\n\t\t0.退出系统\n\n");

printf("\n\n\t    请按键选择，回车确定\n");
printf("**********************************************\n");
return ;
}


void xzLSmenu()//选择操作 
{
system ("cls");

printf("**************************************************");

printf("\n\n 1.图书入库\n\n");

printf("\n\n 2.链表\n\n");

printf("\n\n 3.顺序表\n\n");

printf("\n\n 0.退出系统\n\n");

printf("\n\n 请按键选择，回车确定\n");

printf("*************************************************\n");

return ;
}


void tsczmenu() //图书操作菜单
{
system ("cls");

printf("****************************************************");


printf("\n 2.删除图书\n\n");

printf("\n 3.查询图书\n\n");

printf("\n 4.图书排序\n\n"); 

printf("\n 5.插入图书\n\n");

printf("\n 6.库存统计浏览\n\n");

printf("\n 7.图书信息修改\n\n");

printf("\n 0.返回上一层\n\n");

printf("\n 请按键选择，回车确定\n");

printf("***************************************************\n");

return ;
}

void tspxmenu() //图书排序菜单
{
system ("cls");

printf("****************************************************");

printf("\n 2.书号\n\n");

printf("\n 3.书名\n\n");

printf("\n 4.库存\n\n"); 

printf("\n 5.价格\n\n");

printf("\n 0.返回上一层\n\n");

printf("\n 请按键选择，回车确定\n");

printf("***************************************************\n");

return ;
}

#endif
