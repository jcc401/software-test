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
