#include "myhead.h"

iusr *iusr_init(void)
{
	iusr *p = (iusr *)malloc(sizeof(iusr));
	if (p == NULL)
	{
		perror("malloc p error\n");
		return NULL;
	}
	memset(p->id, 0, sizeof(p->id));
	memset(p->passwd, 0, sizeof(p->passwd));
	p->purse = 0;
	p->add = 0;
	for (int i = 0; i < UBOOK_MAX; i++)
	{
		p->arr[i].num = 0;
		memset(p->arr[i].name, 0, sizeof(p->arr[i].name));
	}
	p->next = NULL;
}
void usr_registry(void)
{
	char tmp_id[100];
	memset(tmp_id, 0, sizeof(tmp_id));
	char passwd1[100];
	memset(passwd1, 0, sizeof(passwd1));
	char passwd2[100];
	memset(passwd2, 0, sizeof(passwd2));
	while (1)
	{
		// 对比帐号名是否重复
		printf("请输入新的帐号名\n");
		scanf("%s", tmp_id);
		while (getchar() != '\n')
			;
		int ret = id_contrast(iusr_head, tmp_id);
		if (ret == 1)
		{
			printf("该帐号已被注册\n");
		}
		else if (ret == 0)
		{
			break;
		}
	}

	while (1)
	{
		system("clear");
		printf("请输入新的密码\n");
		scanf("%s", passwd1);
		printf("请再次输入密码\n");
		scanf("%s", passwd2);
		if (strcmp(passwd1, passwd2) == 0)
		{
			break;
		}
		printf("密码不一致，请重新设置密码\n");
	}
	add_usr(iusr_head, tmp_id, passwd1);
	show_usr(iusr_head);
}
int id_contrast(iusr *head, char *tmp_id)
{
	if (head->next == NULL)
	{
		//	暂无帐号
		return 0;
	}
	iusr *pos = head->next;
	for (; pos != NULL; pos = pos->next)
	{
		if (strcmp(tmp_id, pos->id) == 0)
		{
			printf("该帐号已被注册\n");
			return 1;
		}
	}
	if (pos == NULL)
	{
		return 0;
	}
}

void add_usr(iusr *head, char *id, char *passwd) // 添加用户
{
	iusr *new = iusr_init();
	if (new == NULL)
	{
		perror("malloc new failed\n");
		return;
	}
	strcpy(new->id, id);
	strcpy(new->passwd, passwd);
	new->next = head->next;
	head->next = new;
}

void show_usr(iusr *head) // 用户信息展示
{
	printf("帐号\t\t密码\t\t钱包\n");
	if (head->next == NULL)
	{
		printf("没有用户\n");
		return;
	}
	iusr *pos = head->next;
	for (; pos != NULL; pos = pos->next)
	{
		printf("%s\t\t%s\t\t%.1f\n", pos->id, pos->passwd, pos->purse);
	}
}
void usr_login(iusr *head)
{
	char tmp_id[100];
	char tmp_passwd[100];
	iusr *pos = NULL;
	while (1)
	{
		system("clear");
		printf("==========用户登录界面==========\n");
		printf("请输入帐号和密码\n");
		printf("帐号：\n");
		scanf("%s", tmp_id);
		printf("密码：\n");
		scanf("%s", tmp_passwd);
		for (pos = head->next; pos != NULL; pos = pos->next)
		{
			if (strcmp(pos->id, tmp_id) == 0 && strcmp(pos->passwd, tmp_passwd) == 0)
			{
				system("clear");
				printf("登录成功\n");
				sleep(2);
				while (1)
				{
					system("clear");
					printf("============用户界面1============\n");
					printf("1:查看或修改账户余额\n");
					printf("2:订购图书\n");
					printf("3:查看已购买的图书\n");
					printf("4:退出\n");
					scanf("%d", &n);
					while (getchar() != '\n')
						;
					switch (n)
					{
					case 1:
						usr_purse(pos);
						break;
					case 2:
						buy_book(pos, book_head);
						break;
					case 3:
						show_hand_book(pos);
						break;
					case 4:
						return;
						break;
					default:
						break;
					}
				}
			}
		}
		printf("帐号或密码有误，请重新登录\n");
		sleep(1);
		break;
	}
}
void show_hand_book(iusr *pos)
{
	int n = 1;
	printf("书名\t\t\t\t数量\n");
	int i;
	for (i = 0; i < pos->add; i++)
		printf("%s\t\t\t\t%d\n", pos->arr[i].name, pos->arr[i].num);
	// sleep(5);
	printf("退出请按0\n");

	scanf("%d", &n);
	while (getchar() != '\n')
		;
	if (n == 0)
	{
		return;
	}
	else
	{
		sleep(10);
	}
}
void buy_book(iusr *iusr_pos, book *book_head)
{
	int tmp_id;
	int tmp_num;
	float allprice;
	while (1)
	{
		book *book_pos = NULL;
		// bbb:
		printf("============图书信息大全============\n");
		show_all_book(book_head); // 遍历所有图书

		printf("请输入您想购买的书名的编号\n");
		printf("输入0退出\n");

		scanf("%d", &tmp_id);
		while (getchar() != '\n')
			;
		if (tmp_id == 0)
		{
			return;
		}
		//	printf("序号\t\t书名\t\t\t\t\t\t数量\t\t价格\n");
		if (book_head->next == NULL)
		{
			printf("暂无图书\n");
			//			return ;
		}
		else
		{
			for (book_pos = book_head->next; book_pos != NULL; book_pos = book_pos->next)
			{
				if (tmp_id == book_pos->id)
				{
					// aaa:
					printf("请输入想要购买的数量：\n");
					scanf("%d", &tmp_num);
					while (getchar() != '\n')
						;
					if (tmp_num > book_pos->num)
					{
						printf("购买失败，没有这么多的书\n");
						// goto aaa;
						sleep(3);
						break;
					}
					allprice = tmp_num * book_pos->price;
					if (iusr_pos->purse < allprice)
					{
						printf("购买失败，你没有足够的dollar\n");
						// goto bbb;
						sleep(3);
						return;
					}
					iusr_pos->add %= UBOOK_MAX;
					int i = iusr_pos->add;
					strcpy(iusr_pos->arr[i].name, book_pos->name);
					iusr_pos->arr[i].num = tmp_num;
					printf("书名%s\t,数目%d\n", iusr_pos->arr[i].name, iusr_pos->arr[i].num);
					sleep(1);
					iusr_pos->add++;
					book_pos->num -= tmp_num;
					iusr_pos->purse -= allprice;
					show_all_book(book_head); // 遍历所有图书
					return;
				}
			}
		}
	}
}
void usr_purse(iusr *pos) // 查看或修改余额
{
	system("clear");
	unsigned int sum;
	printf("当前余额为%.1f\n", pos->purse);
	printf("是否充值：\n1:  yes\n2:  no\n");
	while (1)
	{
		scanf("%d", &n);
		if (n == 1)
		{
			printf("请输入充值的金额：\n");
			scanf("%d", &sum);
			pos->purse += sum;
			printf("当前余额为%.1f\n", pos->purse);
			break;
		}
		else if (n == 2)
		{
			break;
		}
	}
}
void root_show_usr()
{
	if (iusr_head->next == NULL)
	{
		system("clear");
		printf("当前没有用户\n");
		return;
	}
	int i, j;
	iusr *pos = iusr_head->next;
	// printf("%d\n",__LINE__);

	for (; pos != NULL; pos = pos->next)
	{
		// printf("%d\n",__LINE__);
		//  帐号密码余额书籍数量
		printf("帐号：%s,密码：%s,余额：%.1f\n", pos->id, pos->passwd, pos->purse);
		for (i = 0; i < pos->add; i++)
		{
			printf("书名%d:%s,已购数:%d\n", i, pos->arr[i].name, pos->arr[i].num);
			// printf("%d\n",__LINE__);
		}

		// printf("%d\n",__LINE__);
	}
	printf("如需退出请输入0\n");
	scanf("%d", &j);
	while (getchar() != '\n')
		;
	if (j != 0)
		sleep(3);

	// printf("%d\n",__LINE__);
}
void del_usr(void)
{

	char tmp_id[100];
	memset(tmp_id, 0, sizeof(tmp_id));
	iusr *pos = iusr_head->next;
	iusr *pos_prev = iusr_head;
	if (iusr_head->next == NULL)
	{
		system("clear");
		printf("没有用户\n");
		return;
	}
	printf("请输入你想删除的用户名\n");
	scanf("%s", tmp_id);
	for (; pos != NULL; pos = pos->next)
	{
		if (strcmp(pos->id, tmp_id) == 0)
		{
			iusr *tmp = pos;
			pos = pos->next;
			pos_prev->next = pos;
			free(tmp);
			break;
		}
		pos_prev = pos;
	}
	if (pos == NULL)
	{
		printf("没找到您想删除的书\n");
	}
	show_usr(iusr_head); // 用户信息展示
}
