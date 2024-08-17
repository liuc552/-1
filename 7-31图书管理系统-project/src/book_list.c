#include "myhead.h"

book *book_init(void)
{
	book *p = (book *)malloc(sizeof(book));
	if (p == NULL)
	{
		perror("malloc p failed!");
		return NULL;
	}
	p->id = book_id;
	memset(p->name, 0, sizeof(p->name));
	p->num = 0;
	p->price = 0;
	p->next = NULL;
	return p;
}
void add_book(book *head)
{
	system("clear");
	book *pos_tail = head;
	while (pos_tail->next != NULL)
		pos_tail = pos_tail->next;
	book *new = book_init();

	new->id = ++book_id;
	printf("请输入书名:\n");
	scanf("%s", new->name);
	printf("请添加书的数量:\n");
	scanf("%d", &new->num);
	printf("请设置书的单价：\n");
	scanf("%f", &new->price);
	new->next = pos_tail->next;
	pos_tail->next = new;
	show_all_book(book_head);
}
void find_show_book(book *head)
{

	while (1)
	{

		printf("请输入你想要查询的方式:\n");
		printf("1:编号查询\n");
		printf("2:书名查询\n");
		printf("3:退出\n");
		scanf("%d", &n);
		while (getchar() != '\n')
			;
		switch (n)
		{
		case 1:
			system("clear");
			// printf("id find\n");
			book_id_find(head);
			break;
		case 2:
			system("clear");
			// printf("name find\n");
			book_name_find(head);
			break;
		case 3:
			return;
			break;
		default:
			printf("错误的输入,退出\n");

			break;
		}
	}
}
void show_all_book(book *head)
{
	system("clear");
	printf("序号\t\t书名\t\t\t\t数量\t\t价格\n");
	if (head->next == NULL)
	{
		printf("暂无图书\n");
		return;
	}
	book *pos = head->next;
	for (; pos != NULL; pos = pos->next)
	{
		printf("%d\t\t%s\t\t\t\t%d\t\t%.1f\n", pos->id, pos->name, pos->num, pos->price);
	}
}

void book_id_find(book *head)
{
	int tmp_id;
	while (1)
	{
		printf("请输入书的id号:\n");
		scanf("%d", &tmp_id);
		while (getchar() != '\n')
			;
		book *pos = head->next;
		for (; pos != NULL; pos = pos->next)
		{
			if (pos->id == tmp_id)
			{
				system("clear");
				printf("序号\t\t书名\t\t\t\t\t\t数量\t\t价格\n");
				printf("%d\t\t%s\t\t\t\t%d\t\t%.1f\n", pos->id, pos->name, pos->num, pos->price);
				return;
			}
		}
		if (pos == NULL)
		{
			printf("没找到您想查询的书\n");
			void show_all_book(book * head);
			printf("==三秒后退出==\n");
			sleep(3);
			system("clear");
			return;
		}
	}
}
void book_name_find(book *head)
{
	char tmp_name[100];
	memset(tmp_name, 0, sizeof(tmp_name));
	while (1)
	{
		printf("请输入书的书名:\n");
		scanf("%s", tmp_name);
		book *pos = head->next;
		for (; pos != NULL; pos = pos->next)
		{
			if (strcmp(tmp_name, pos->name) == 0)
			{
				system("clear");
				printf("序号\t\t书名\t\t\t\t\t数量\t\t价格\n");
				printf("%d\t\t%s\t\t\t\t%d\t\t%.1f\n", pos->id, pos->name, pos->num, pos->price);
				return;
				system("clear");
			}
		}
		if (pos == NULL)
		{
			printf("没找到您想查询的书\n");
			void show_all_book(book * head);
			printf("==三秒后退出==\n");
			sleep(3);
			system("clear");
			return;
		}
	}
}
void revise_book(book *head)
{
	int tmp_id;
	int tmp_num;
	float tmp_price;
	while (1)
	{
		printf("请输入书的编号：");
		scanf("%d", &tmp_id);
		book *pos = head->next;
		for (; pos != NULL; pos = pos->next)
		{
			if (pos->id == tmp_id)
			{
				system("clear");
				printf("修改数量请按1：\n");
				printf("修改单价请按2：\n");
				printf("修改数量和单价请按3：\n");
				printf("退出请按其它数\n");
				printf("您输入的命令：");
				scanf("%d", &n);
				if (n == 1)
				{
					printf("请输入调整后的书的数量:\n");
					scanf("%d", &tmp_num);
					pos->num = tmp_num;
				}
				else if (n == 2)
				{
					printf("请输入调整后的书的价格:\n");
					scanf("%f", &tmp_price);
					pos->price = tmp_price;
				}
				else if (n == 3)
				{
					printf("请输入调整后的书的数量:\n");
					scanf("%d", &tmp_num);
					pos->num = tmp_num;
					printf("请输入调整后的书的价格:\n");
					scanf("%f", &tmp_price);
					pos->price = tmp_price;
				}
				else
				{
					return;
				}
				printf("序号\t\t书名\t\t\t\t数量\t\t价格\n");
				printf("%d\t\t%s\t\t\t\t%d\t\t%.1f\n", pos->id, pos->name, pos->num, pos->price);
				return;
			}
		}
		if (pos == NULL)
		{
			printf("没找到您想查询的书,请输入正确的编号\n");
			sleep(1);
		}
	}
}
void del_book(book *head)
{
	system("clear");
	show_all_book(book_head);
	int tmp_id;
	char tmp_name[100];
	book *tmp = NULL;
	memset(tmp_name, 0, sizeof(tmp_name));
	printf("1请输入您想删除的id:\n");
	printf("2请输入您想删除的书名\n");
	printf("请输入命令:\n");
	scanf("%d", &n);
	while (getchar() != '\n')
		;
	if (n == 1)
	{
		printf("请输入书的id:\n");
		scanf("%d", &tmp_id);
		book *pos_prev = head;
		book *pos = head->next;
		for (; pos != NULL; pos = pos->next)
		{
			if (pos->id == tmp_id)
			{
				tmp = pos;
				pos_prev->next = pos->next;
				pos = pos->next;
				free(tmp);
				for (; pos != NULL; pos = pos->next)
				{
					pos->id--;
				}
				show_all_book(book_head);
				return;
			}
			pos_prev = pos;
		}
		if (pos == NULL)
		{
			printf("没有找到你想删除的书");
			return;
		}
	}
	if (n == 2)
	{
		printf("请输入书名:\n");
		scanf("%s", tmp_name);
		book *pos = head->next;
		book *pos_prev = head;
		for (; pos != NULL; pos = pos->next)
		{
			if (strcmp(pos->name, tmp_name) == 0)
			{
				tmp = pos;
				pos_prev->next = pos->next;
				pos = pos->next;
				free(tmp);
				for (; pos != NULL; pos = pos->next)
				{
					pos->id--;
				}
				show_all_book(book_head);
				return;
			}
			pos_prev = pos;
		}
		if (pos == NULL)
		{
			printf("没有找到你想删除的书");
			return;
		}
	}
}
