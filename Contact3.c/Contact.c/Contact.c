#include "Contact.h"
#pragma warning (disable:4996)
//加载，读文件
void LoadContact(Contact *pcon)
{
	FILE *pf = fopen("Contact.bat", "rb");
	Personinfo tmp = { 0 };
	//fread函数的返回值是：读取的字节数
	if (pf == NULL)
	{
		return;
	}//第一次加载什么都不用做
	while (fread(&tmp, sizeof(Personinfo), 1, pf) > 0)
	{
		CheckFullAndRe(pcon);//必须判断是否为满，如果满了扩容
		pcon->per[pcon->usedSize] = tmp;
		pcon->usedSize++;
	}
	fclose(pf);
	pf = NULL;
}
void initContact(Contact *pcon)
{
	/*pcon->usedSize = 0;
	memset(pcon->per, 0, sizeof(pcon->per));*///普通版本
	pcon->usedSize = 0;
	pcon->cpaticty = DEFAULT_SIZE;
	pcon->per = (Personinfo *)malloc(sizeof(Personinfo)*pcon->cpaticty);
	assert(pcon->per != NULL);
	LoadContact(pcon);
}
//返回值代表扩容是否成功
static int CheckFullAndRe(Contact *pcon)
{
	if (pcon->usedSize == pcon->cpaticty)
	{
		Personinfo *ptr = NULL;
		ptr=(Personinfo *)realloc(pcon->per, sizeof(Personinfo)*pcon->cpaticty * 2);
		if (ptr != NULL)
		{
			pcon->per = ptr;
			pcon->cpaticty *= 2;
			printf("扩容成功\n");
			return 1;
		}
		else{
			return 0;//扩容失败
		}
	}
	return 1;//内存没满，没有进入if，需要返回值
}
void AddContact(Contact *pcon)
{
	/*if (pcon->usedSize == MAX_NUMBER)
	{
		printf("不好意思，满了\n");
		return;
	}*/
	if (CheckFullAndRe(pcon) != 1)
	{
		printf("扩容失败！\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s", pcon->per[pcon->usedSize].name);
	printf("请输入年龄：");
	scanf("%d", &(pcon->per[pcon->usedSize].age));
	printf("请输入性别：");
	scanf("%d", pcon->per[pcon->usedSize].sex);
	printf("请输入电话：");
	scanf("%d", pcon->per[pcon->usedSize].tele);
	printf("请输入住址：");
	scanf("%d", pcon->per[pcon->usedSize].addr);
	pcon->usedSize++;
	printf("添加成功!\n");
}
void ShowContact(Contact *pcon)
{
	int i = 0;
	printf("%-10s %-5s %-5s %-11s %-20s\n", "姓名" ,"年龄",
		"性别", "电话", "地址");
	for (i = 0; i < pcon->usedSize; i++)
	{
		printf("%-10s %-5d %-5s %-11s %-20s\n",
			pcon->per[i].name,pcon->per[i].age,
			pcon->per[i].sex, pcon->per[i].tele,
			pcon->per[i].addr);
	}
}
int FindContact(Contact *pcon)
{
	int i = 0;
	char name[MAX_NAME] = { 0 };
	if (pcon->usedSize == 0)
	{
		printf("通讯录为空\n");
		return -1;
	}
	printf("请输入你要查找的姓名：");
	scanf("%s", name);
	for (i = 0; i < pcon->usedSize; i++)
	{
		if (strcmp(pcon->per[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void SearchContact(Contact *pcon)
{
	int index = FindContact(pcon);
	if (index == -1)
	{
		printf("查无此人\n");
		return;
	}
	else{
		int i = index;
		printf("%-10s %-5d %-5s %-11s %-20s\n",
			pcon->per[i].name, pcon->per[i].age,
			pcon->per[i].sex, pcon->per[i].tele,
			pcon->per[i].addr);
	}
}
void DelContact(Contact *pcon)
{
	int index = FindContact(pcon);
	int i = 0;
	if (index == -1)
	{
		printf("查无此人\n");
		return;
	}
	for (i = index; i < pcon->usedSize - 1; i++)
	{
		pcon->per[i] = pcon->per[i + 1];
	}
		pcon->usedSize--;
		printf("删除成功\n");
}
void ClearContact(Contact *pcon)
{
	pcon->usedSize = 0;
}
//存储
void SaveContact(Contact *pcon)
{
	int i = 0;
	FILE *pf = fopen("Contact.bat","wb");
	assert(pf != NULL);
	for (i = 0; i < pcon->usedSize; i++)
	{
		fwrite(pcon->per + i,sizeof(Personinfo),1,pf);
	}
	fclose(pf);
	pf = NULL;
}
void DestoryContact(Contact *pcon)
{
	SaveContact(pcon);
	free(pcon->per);
	pcon->per = NULL;//预防野指针
	pcon->cpaticty = 0;
	pcon->usedSize = 0;
}
