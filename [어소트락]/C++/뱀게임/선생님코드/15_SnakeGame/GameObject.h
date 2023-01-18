#pragma once
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

class GameObject
{
public:
	void Initialize()
	{
		//mCh = L'��';
	}
	void Update()
	{
		char c;
		if (_kbhit()) //Ű���� �Է� Ȯ�� (true / false)
		{        
			c = _getch();   // ����Ű �Է½� 224 00�� ������ �Ǳ⿡ �տ� �ִ� �� 224�� ����
			if (c == -32)	// -32�� �ԷµǸ�
			{    
				c = _getch();  // ���� �Է°��� �Ǻ��Ͽ� �����¿� ���
				if (LEFT == c)
				{
					mPos.x--;
				}
				else if (RIGHT == c)
				{
					mPos.x++;
				}
				else if (UP == c)
				{
					mPos.y--;
				}
				else if (DOWN == c)
				{
					mPos.y++;
				}
			}
		}
	}
	void Render()
	{
		GOTO_XY((mPos.x * 2), mPos.y);
		std::wcout << mCh;
	}
	void Release()
	{

	}

	void SetWChar(wchar_t ch) { mCh = ch; }
	void SetPos(Vector2 pos) { mPos = pos; }


private:
	wchar_t mCh;
	Vector2 mPos;
};