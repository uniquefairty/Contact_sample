
#include "Contact.h"
#pragma warning (disable:4996)
//1. 添加联系人信息
//2. 删除指定联系人信息
//3. 查找指定联系人信息
//4. 修改指定联系人信息
//5. 显示所有联系人信息
//6. 清空所有联系人
//7. 以名字排序所有联系人
//8. 保存联系人到文件
//9. 加载联系人
//更新
void menu()
{
	printf("######欢迎使用XXX通讯录############\n");
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
		printf("请输入你的操作：");
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