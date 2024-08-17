#include "myhead.h"

int n;		 // 选项的数字
int book_id; // 书的编号
book *book_head = NULL;
iusr *iusr_head = NULL;

int main(int argc, char const *argv[])
{
	book_head = book_init(); // 图书信息初始化
	iusr_head = iusr_init(); // 用户信息初始化
	system("clear");
	while (1)
	{
		system("clear");
		printf("============图书管理系统============\n");
		printf("1:管理员\n");
		printf("2:用户\n");

		printf("请选择您的身份：\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			//				printf("管理员界面\n");
			manage();
			break;
		case 2:
			printf("用户界面\n");
			usr();
			break;
		}
	}

	return 0;
}
