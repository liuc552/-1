#ifndef _MYHEAD_H_
#define _MYHEAD_H_
// 头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// 宏定义
#define UBOOK_MAX 20

// 结构体声明
// 1.书的信息结构体
typedef struct book_information
{
	int id;			// 序号
	char name[100]; // 书名
	int num;		// 数量
	float price;	// 价格
	struct book_information *next;
} book;
// 1.5用户已购买书的数量，以及书名的小结构体
typedef struct book_usr
{
	char name[100]; //
	int num;
} ubook;
// 2.用户的信息结构体
typedef struct usr_information
{
	char id[100];
	char passwd[100];
	float purse;
	ubook arr[UBOOK_MAX];
	int add;
	struct usr_information *next;
} iusr;

// 全局变量声明
extern int n;
extern book *book_head;
extern int book_id; // 书的编号
extern iusr *iusr_head;

// 函数声明
void manage(void);								  // 管理员界面
void usr(void);									  // 用户界面
void book_manage(void);							  // 图书信息管界面
void usr_manage(void);							  // 用户信息管理界面
book *book_init();								  // 图书信息初始化
void add_book(book *head);						  // 添加图书
void show_all_book(book *head);					  // 遍历所有图书
void find_show_book(book *head);				  // 查找图书
void book_id_find(book *head);					  // 通过id查找图书
void book_name_find(book *head);				  // 通过书名查找图书
void revise_book(book *head);					  // 修改图书信息
void del_book(book *head);						  // 删除图书
void usr_login(iusr *head);						  // 用户登录
void usr_registry(void);						  // 用户注册
iusr *iusr_init(void);							  // 用户信息初始化
int id_contrast(iusr *head, char *tmp_id);		  // 帐号名比对
void add_usr(iusr *head, char *id, char *passwd); // 添加用户
void show_usr(iusr *head);						  // 用户基本信息展示
void usr_purse(iusr *pos);						  // 查看或修改余额
void buy_book(iusr *iusr_pos, book *book_head);	  // 书籍购买
void show_hand_book(iusr *pos);					  // 用户已购书籍
void root_show_usr();							  // 用户详细信息展示
void del_usr(void);								  // 删除用户
#endif
