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
		//mCh = L'●';
	}
	void Update()
	{
		char c;
		if (_kbhit()) //키보드 입력 확인 (true / false)
		{        
			c = _getch();   // 방향키 입력시 224 00이 들어오게 되기에 앞에 있는 값 224를 없앰
			if (c == -32)	// -32로 입력되면
			{    
				c = _getch();  // 새로 입력값을 판별하여 상하좌우 출력
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