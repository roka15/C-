#include "Scene.h"

void Scene::Initialize()
{
	for (auto Obj : mGameObjects)
	{
		if (Obj == nullptr)
			continue;

		Obj->Initialize();
	}
}

void Scene::Update()
{
	for (auto Obj : mGameObjects)
	{
		if (Obj == nullptr)
			continue;

		Obj->Update();
	}
}

void Scene::Render()
{
	for (auto Obj : mGameObjects)
	{
		if (Obj == nullptr)
			continue;

		Obj->Render();
	}
}

void Scene::Release()
{
	for (auto Obj : mGameObjects)
	{
		if (Obj == nullptr)
			continue;

		Obj->Release();
	}
}

void Scene::AddGameObject(wchar_t _ch,Vector2 _pos)
{
	GameObject* obj = new GameObject();
	obj->SetWChar(_ch);
	obj->SetPos(_pos);
	mGameObjects[mgobj_index++] = obj;
}

Scene::Scene()
{
}

Scene::~Scene()
{
}
