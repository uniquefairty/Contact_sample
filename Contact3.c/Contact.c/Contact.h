#ifndef _CONTACT_H_
#define _CONTACT_H_
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<vld.h>
enum Oper
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	SHOW,
	CLEAR,
	SORT,
	DESTORY
};
#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TELE 11
#define MAX_ADDR 20
#define MAX_NUMBER 1000
#define DEFAULT_SIZE 2
typedef struct Personinfo
{
	char name[MAX_NAME];
	short age;
	char sex[MAX_SEX];//�Ա�
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}Personinfo;//ÿ���˵���Ϣ
typedef struct Contact
{
	//Personinfo per[MAX_NUMBER];//��ͨ�汾
	Personinfo *per;
	int usedSize;
	int cpaticty;//����
}Contact;//ͨѶ¼
void initContact(Contact *pcon);
void AddContact(Contact *pcon);
void ShowContact(Contact *pcon);
void DelContact(Contact *pcon);
void ClearContact(Contact *pcon);
void SearchContact(Contact *pcon);
void DestoryContact(Contact *pcon);
int CheckFullAndRe(Contact *pcon);
void LoadContact(Contact *pcon);

#endif