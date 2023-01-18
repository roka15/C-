#pragma once
#include "CommonInclude.h"
#include "GameObject.h"

#define MAX_OJBECT 256

class Scene
{
public:
	void Initialize()
	{
		for (GameObject* obj : mGameObjects)
		{
			if (obj == nullptr)
				continue;

			obj->Initialize();
		}
	}
	void Update()
	{
		for (GameObject* obj : mGameObjects)
		{
			if (obj == nullptr)
				continue;

			obj->Update();
		}
	}
	void Render()
	{
		for (GameObject* obj : mGameObjects)
		{
			if (obj == nullptr)
				continue;

			obj->Render();
		}
	}
	void Release()
	{
		for (GameObject* obj : mGameObjects)
		{
			if (obj == nullptr)
				continue;

			obj->Release();
		}
	}

	void AddGameObject(wchar_t ch, Vector2 pos)
	{
		GameObject* obj = new GameObject();
		obj->SetPos(pos);
		obj->SetWChar(ch);

		mGameObjects[0] = obj;
	}

private:
	GameObject* mGameObjects[MAX_OJBECT];
};

