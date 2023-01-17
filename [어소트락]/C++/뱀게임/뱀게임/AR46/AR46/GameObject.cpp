#include "GameObject.h"


void GameObject::Initialize()
{
	mCh = L'¡Ü';
}

void GameObject::Update()
{
	int c;
	if (_kbhit()) 
	{        
		c = _getch();      
		if (c == 224) 
		{    
			c = _getch();  

			switch (c)
			{
			case EnumToInt(KeyDir::LEFT):
				mPos.x--;
				break;
			case  EnumToInt(KeyDir::RIGHT):
				mPos.x++;
				break;
			case  EnumToInt(KeyDir::UP):
				mPos.y--;
				break;
			case  EnumToInt(KeyDir::DOWN):
				mPos.y++;
				break;
			}
		}
	}
}
void GameObject::Render()
{
	GOTO_XY((mPos.x * 2), mPos.y);
	std::wcout << mCh;
}

void GameObject::Release()
{
}

void GameObject::SetWChar(wchar_t _ch)
{
	mCh = _ch;
}

void GameObject::SetPos(Vector2 _pos)
{
	mPos = _pos;
}
