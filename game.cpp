#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define L 30  // ��Ϸ����ߴ�
#define W 60


// ȫ�ֱ���
int cells[L][W]; // ����λ��ϸ����1����0


void gotoxy(int x,int y)//��������������
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void startup() // ���ݳ�ʼ��
{
	int i,j;
	for (i=0;i<L;i++) // ��ʼ��
		for (j=0;j<W;j++)
		{
			cells[i][j] = 1;
		}
}

void show()  // ��ʾ����
{
	gotoxy(0,0);  // ����
	int i,j;
	for (i=1;i<=L-1;i++)
	{
		for (j=1;j<=W-1;j++)
		{
			if (cells[i][j]==1)
				printf("��");  //   ������ϸ��
			else
				printf("��");  //   ����ո�			
		}
		printf("\n");
	}
	Sleep(500);
}

void updateWithoutInput()  // ���û������޹صĸ���
{	
	int NewCells[L][W]; // ��һ֡��ϸ�����
	int NeibourNumber; //ͳ���ھӵĸ���
	int i,j;
	for (i=1;i<=L-1;i++)
	{
		for (j=1;j<=W-1;j++)
		{
			NeibourNumber = cells[i-1][j-1] + cells[i-1][j] + cells[i-1][j+1]
				+ cells[i][j-1] + cells[i][j+1] + cells[i+1][j-1] + cells[i+1][j] + cells[i+1][j+1];
			if (NeibourNumber==3)
				NewCells[i][j] = 1;  
			else if (NeibourNumber==2)
				NewCells[i][j] = cells[i][j];
			else
				NewCells[i][j] = 0; 
		}
	}
	
	for (i=1;i<=L-1;i++)
		for (j=1;j<=W-1;j++)
			cells[i][j] = NewCells[i][j];
		
}

void updateWithInput()  // ���û������йصĸ���
{
	
}

void main()
{
	startup();  // ���ݳ�ʼ��	
	while (1) //  ��Ϸѭ��ִ��
	{
		show();  // ��ʾ����
		updateWithoutInput();  // ���û������޹صĸ���
		updateWithInput();  // ���û������йصĸ���
	}
}	