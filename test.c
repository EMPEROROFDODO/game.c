
#include"game.h"

void game()
{
	//��������
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//��ʼ������
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');

	//����Ƿ�ɹ���ʼ��
	//DisplayBoard(mine, ROW, COL);
	//DisplayBoard(show, ROW, COL);

	//���õ���
	SetMine(mine, ROW, COL);
	
	//����Ƿ�ɹ����õ���
	//DisplayBoard(mine, ROW, COL);

	//���ҵ���
	FindMine(mine, show, ROW, COL);

}
int main()
{
	int input = 0;
	do{
		menu();
		printf("���������ѡ��:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ!\n");
			break;
		default:
			printf("ѡ�����������ѡ��!\n");
			break;
		}
	} while (input);
	return 0;
}