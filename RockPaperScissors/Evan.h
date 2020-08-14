#include <windows.h>
#include <stdio.h>


//ȭ���� ����� �Լ�
void Clear(void)
{
	system("cls");
}

// Ŀ���� ��ġ�� �ٲ��ִ� �Լ�(�ش� ��ġ���� ���ϴ� ��� ���� ������ ������ �� �ִ�.
void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// �ܼ� â�� ������ �����ϴ� �Լ�
void SetTitle(const char* _szConsoleName)
{
	SetConsoleTitle(_szConsoleName);
}

// ���ڻ�, ������ �������ִ� �Լ�
//���� 0 ~ 15, ���ڻ� 0 ~ 15���� 16�� ����ؼ� �����ϴ� �Լ�
void SetColor(unsigned char _BgColor, unsigned char _TextColor)
{
	if (_BgColor > 15 || _TextColor > 15) return;

	//������ ���ڻ��� ���ÿ� �����ϴ� �Լ� - high 4bit:����, Low 4 bit : ���ڻ�
	//0x00f0 �̸� f�� ��� ��� 0�� ���� �۾�
	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

//Ŀ���� �Ⱥ��̰� �ϴ� �Լ�
void SetCursor(BOOL _bShow)
{
	CONSOLE_CURSOR_INFO curInfor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
	curInfor.bVisible = _bShow;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
}

void SetConsoleSize(int _col, int _lines)
{
	char setText[100];
	sprintf_s(setText, "mode con cols=%d lines=%d", _col, _lines);
	system(setText);
}
