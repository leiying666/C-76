#include"contact.h"
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满,无法创建。\n");
	}
	else
	{
		printf("输入名字：");
		scanf("%s", ps->data[ps->size].name);
		printf("输入年龄：");
		scanf("%d", &(ps->data[ps->size].age));
		printf("输入性别：");
		scanf("%s", ps->data[ps->size].sex);
		printf("输入电话：");
		scanf("%s", ps->data[ps->size].tele);
		printf("输入地址：");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
	}
}
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DelContact(struct Contact* ps)
{
	//查找
	char name[MAX_NAME];
	printf("请输入要删除人的名字：");//因为输出为删除，所以不能封装
	scanf("%s", name);
	/*int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			break;
		}
	}*/
	int pos=FindByName(ps, name);//这段代码要多次使用，用函数封装，以后使用会很方便
	//用pos来表示下标，没找到返回-1
	//删除
	if (pos == -1)
	{
		printf("要删除的人不存在。\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字：");
	int pos=FindByName(ps, name);
	if (pos == -1)
	{
		printf("找不到该联系人。\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字：");
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("找不到该联系人。\n");
	}
	else
	{
		printf("输入名字：");
		scanf("%s", ps->data[pos].name);
		printf("输入年龄：");
		scanf("%d", &(ps->data[pos].age));
		printf("输入性别：");
		scanf("%s", ps->data[pos].sex);
		printf("输入电话：");
		scanf("%s", ps->data[pos].tele);
		printf("输入地址：");
		scanf("%s", ps->data[pos].addr);
		printf("修改成功\n");
	}
}
