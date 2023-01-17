#pragma once

#include "GameObject.h"

#define GAMEOBJECT_MAX 256
class Scene
{
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	void AddGameObject(wchar_t _ch, Vector2 _pos);
public:
	Scene();
	~Scene();
private:
	GameObject* mGameObjects[GAMEOBJECT_MAX];
	UINT mgobj_index;
};

