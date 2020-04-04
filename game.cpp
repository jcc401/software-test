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

void updateWithoutInput()  // 与用户输入无关的更新
{	
	int NewCells[L][W]; // 下一帧的细胞情况
	int NeibourNumber; //统计邻居的个数
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

void updateWithInput()  // 与用户输入有关的更新
{
	
}

void main()
{
	startup();  // 数据初始化	
	while (1) //  游戏循环执行
	{
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();  // 与用户输入有关的更新
	}
}	