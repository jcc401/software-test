#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define L 30  // 游戏画面尺寸
#define W 60


// 全局变量
int cells[L][W]; // 所有位置细胞生1或死0


void gotoxy(int x,int y)//类似于清屏函数
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void startup() // 数据初始化
{
	int i,j;
	for (i=0;i<L;i++) // 初始化
		for (j=0;j<W;j++)
		{
			cells[i][j] = 1;
		}
}

void show()  // 显示画面
{
	gotoxy(0,0);  // 清屏
	int i,j;
	for (i=1;i<=L-1;i++)
	{
		for (j=1;j<=W-1;j++)
		{
			if (cells[i][j]==1)
				printf("●");  //   输出活的细胞
			else
				printf("○");  //   输出空格			
		}
		printf("\n");
	}
	Sleep(500);
}	