
#include "Contact.h"
#pragma warning (disable:4996)
//1. �����ϵ����Ϣ
//2. ɾ��ָ����ϵ����Ϣ
//3. ����ָ����ϵ����Ϣ
//4. �޸�ָ����ϵ����Ϣ
//5. ��ʾ������ϵ����Ϣ
//6. ���������ϵ��
//7. ����������������ϵ��
//8. ������ϵ�˵��ļ�
//9. ������ϵ��
//����
void menu()
{
	printf("######��ӭʹ��XXXͨѶ¼############\n");
	printf("#####0.exit######1.add#############\n");
	printf("#####2.del#######3.search############\n");
	printf("#####4.show######5.clear#############\n");
	printf("#####6.sort######7.destory#############\n");
	printf("####################################\n");
}
int main()
{
	int input = 0;
	Contact con;
	initContact(&con);
	do{
		menu();
		printf("��������Ĳ�����");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			break;
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case CLEAR:
			ClearContact(&con);
			break;
		case SORT:
			break;
		case DESTORY:
			DestoryContact(&con);
			break;
		default:
			break;
		}
	} while (input);
	system("pause");
	return 0;
}