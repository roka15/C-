#pragma once
#include "Commoninclude.h"

class GameObject
{
public:
	enum class E_Direction
	{
		Right,
		Left,
		Up,
		Down,
	};
	void Initialize();
	void Update();
	void Render();
	void Release();
	void SetPos(Vector2 _pos);
	void RenderClear();
public:

private:
	Vector2 mPos;
	E_Direction mDir;

	Node* mBody;
};

