#pragma once

#include "GameObject.h"

#define GAMEOBJECT_MAX 256
#define MapY 20
#define MapX 20


class Scene
{
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	void AddGameObject(Vector2 _pos);
public:
	Scene();
	~Scene();
private:
	GameObject* mGameObjects[GAMEOBJECT_MAX];
	UINT mgobj_index;
	wchar_t mMap[MapY][MapX];
};

