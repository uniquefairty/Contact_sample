#include "Contact.h"
#pragma warning (disable:4996)
//���أ����ļ�
void LoadContact(Contact *pcon)
{
	FILE *pf = fopen("Contact.bat", "rb");
	Personinfo tmp = { 0 };
	//fread�����ķ���ֵ�ǣ���ȡ���ֽ���
	if (pf == NULL)
	{
		return;
	}//��һ�μ���ʲô��������
	while (fread(&tmp, sizeof(Personinfo), 1, pf) > 0)
	{
		CheckFullAndRe(pcon);//�����ж��Ƿ�Ϊ���������������
		pcon->per[pcon->usedSize] = tmp;
		pcon->usedSize++;
	}
	fclose(pf);
	pf = NULL;
}
void initContact(Contact *pcon)
{
	/*pcon->usedSize = 0;
	memset(pcon->per, 0, sizeof(pcon->per));*///��ͨ�汾
	pcon->usedSize = 0;
	pcon->cpaticty = DEFAULT_SIZE;
	pcon->per = (Personinfo *)malloc(sizeof(Personinfo)*pcon->cpaticty);
	assert(pcon->per != NULL);
	LoadContact(pcon);
}
//����ֵ���������Ƿ�ɹ�
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
			printf("���ݳɹ�\n");
			return 1;
		}
		else{
			return 0;//����ʧ��
		}
	}
	return 1;//�ڴ�û����û�н���if����Ҫ����ֵ
}
void AddContact(Contact *pcon)
{
	/*if (pcon->usedSize == MAX_NUMBER)
	{
		printf("������˼������\n");
		return;
	}*/
	if (CheckFullAndRe(pcon) != 1)
	{
		printf("����ʧ�ܣ�\n");
		return;
	}
	printf("������������");
	scanf("%s", pcon->per[pcon->usedSize].name);
	printf("���������䣺");
	scanf("%d", &(pcon->per[pcon->usedSize].age));
	printf("�������Ա�");
	scanf("%d", pcon->per[pcon->usedSize].sex);
	printf("������绰��");
	scanf("%d", pcon->per[pcon->usedSize].tele);
	printf("������סַ��");
	scanf("%d", pcon->per[pcon->usedSize].addr);
	pcon->usedSize++;
	printf("��ӳɹ�!\n");
}
void ShowContact(Contact *pcon)
{
	int i = 0;
	printf("%-10s %-5s %-5s %-11s %-20s\n", "����" ,"����",
		"�Ա�", "�绰", "��ַ");
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
		printf("ͨѶ¼Ϊ��\n");
		return -1;
	}
	printf("��������Ҫ���ҵ�������");
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
		printf("���޴���\n");
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
		printf("���޴���\n");
		return;
	}
	for (i = index; i < pcon->usedSize - 1; i++)
	{
		pcon->per[i] = pcon->per[i + 1];
	}
		pcon->usedSize--;
		printf("ɾ���ɹ�\n");
}
void ClearContact(Contact *pcon)
{
	pcon->usedSize = 0;
}
//�洢
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
	pcon->per = NULL;//Ԥ��Ұָ��
	pcon->cpaticty = 0;
	pcon->usedSize = 0;
}
