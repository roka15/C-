#include "GameObject.h"


void GameObject::Initialize()
{
	//mCh = L'¡Ü';
	mDir = E_Direction::Right;
	mBody = new Node();
	mBody->prev = nullptr;
	mBody->next = nullptr;
	mBody->ch = L'¡Ý';
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
				mDir = E_Direction::Left;
				break;
			case  EnumToInt(KeyDir::RIGHT):
				mDir = E_Direction::Right;
				break;
			case  EnumToInt(KeyDir::UP):
				mDir = E_Direction::Up;
				break;
			case  EnumToInt(KeyDir::DOWN):
				mDir = E_Direction::Down;
				break;
			}
		}
	}

	if (mDir == E_Direction::Right)
	{
		RenderClear();
		std::wcout << '\0';
		mPos.x++;
	}
	else if (mDir == E_Direction::Left)
	{
		RenderClear();
		std::wcout << '\0';
		mPos.x--;
	}
	else if (mDir == E_Direction::Up)
	{
		RenderClear();
		std::wcout << '\0';
		mPos.y--;
	}
	else if (mDir == E_Direction::Down)
	{
		RenderClear();
		std::wcout << '\0';
		mPos.y++;
	}
}
void GameObject::Render()
{
	int randColor = (rand() % 13) + 1;
	SET_COLOR(randColor);
	GOTO_XY((mPos.x * 2 + offsetX), (mPos.y + offsetY));
	std::wcout << mBody->ch;
}

void GameObject::Release()
{
	delete mBody;
	mBody = nullptr;
}

void GameObject::SetPos(Vector2 _pos)
{
	mPos = _pos;
}

void GameObject::RenderClear()
{
	GOTO_XY((mPos.x * 2 + offsetX), (mPos.y + offsetY));
	std::wcout << '\0';
}
