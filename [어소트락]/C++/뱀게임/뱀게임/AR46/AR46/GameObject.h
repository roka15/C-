#pragma once
#include "Commoninclude.h"

class GameObject
{
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	void SetWChar(wchar_t _ch);
	void SetPos(Vector2 _pos);
public:

private:
	wchar_t mCh;
	Vector2 mPos;
};

