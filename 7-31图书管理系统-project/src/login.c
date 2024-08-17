#include "myhead.h"

char gec[20];
void manage() // 管理员
{
	printf("请输入管理员密码:\n");
	scanf("%s", gec);
	if (strcmp(gec, "gec123456") != 0)
	{
		printf("密码错误\n");
		sleep(1);
		system("clear");
		return;
	}

	while (1)
	{
		system("clear");
		printf("======管理员界面======\n");
		printf("1:管理图书信息\n");
		printf("2:管理用户信息\n");
		printf("3:退出\n");
		printf("请输入您的选择：\n");
		scanf("%d", &n);
		while (getchar() != '\n')
			;
		switch (n)
		{
		case 1:
			// 图书信息管界面
			book_manage();
			break;
		case 2:
			usr_manage();
			break;
		case 3:
			return;
		default:
			printf("错误的命令\n");
			break;
		}
	}
}
void book_manage(void)
{

	while (1)
	{
		// system("clear");
		printf("============图书信息管理界面============\n");
		printf("1.增加一本书\n");
		printf("2.删除一本书\n");
		printf("3.查找一本书\n");
		printf("4.查看所有书\n");
		printf("5.修改一本书\n");
		printf("6.退出\n");

		printf("请输入命令：\n");
		scanf("%d", &n);
		while (getchar() != '\n')
			;
		switch (n)
		{
		case 1:
			//				printf("添加图书\n");
			add_book(book_head);
			break;
		case 2:
			//				printf("删除图书\n");
			del_book(book_head);
			break;
		case 3:
			//				printf("查找图书\n");
			find_show_book(book_head);
			break;
		case 4:
			//				printf("遍历图书\n");
			show_all_book(book_head);
			break;
		case 5:
			//				printf("修改图书信息\n");
			revise_book(book_head);
			break;
		case 6:
			printf("退出\n");
			return;
			break;
		default:
			printf("命令错误,请输入正确的命令\n");
			break;
		}
		//	break;
	}
}

void usr_manage(void)
{
	
	while(1)
	{
		printf("========用户信息管理界面========\n");
		printf("1:查看用户信息\n");
		printf("2:删除用户\n");
		printf("3:退出\n");
		printf("请输入命令：\n");
		scanf("%d",&n);
		if(n==1)
		{
			//查看用户信息
			root_show_usr();
		}
		else if(n==2)
		{
			//删除用户
			del_usr();
			
		
		}
		else if(n==3)
		{
			return ;	
		}
		else
		{
			return ;	
		}

	}
}
void usr() // 用户
{
	while (1)
	{
		system("clear");
		printf("============用户界面============\n");
		printf("1:登录\n");
		printf("2:注册\n");
		printf("3:退出\n");
		scanf("%d", &n);
		while (getchar() != '\n')
			;
		if (n == 1)
		{
			printf("用户登录\n");
			usr_login(iusr_head);
		}
		else if (n == 2)
		{
			printf("用户注册\n");
			usr_registry();
		}
		else if (n == 3)
		{
			return;
		}
	}
}
