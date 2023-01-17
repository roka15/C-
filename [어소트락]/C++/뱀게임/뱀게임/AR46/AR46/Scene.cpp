#include "Scene.h"

void Scene::Initialize()
{
	int size = 0;
	//�� �ʱ�ȭ
	for (size_t i = 0; i < MapY; i++)
	{

		mMap[i][0] = L'��';
		mMap[i][MapX - 1] = L'��';
	}
	for (size_t i = 0; i < MapY; i++)
	{
		mMap[0][i] = L'��';
		mMap[MapY - 1][i] = L'��';
	}
	
	//������Ʈ �ʱ�ȭ
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
	

	//�� �׸���
	for (size_t i = 0; i < MapY; i++)
	{
		for (size_t j = 0; j < MapX; j++)
		{
			SET_COLOR((int)COLOR::WHITE);
			GOTO_XY((j * 2 + offsetX), i);
			std::wcout << mMap[i][j];
		}
	}
	//������Ʈ �׸���
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

void Scene::AddGameObject(Vector2 _pos)
{
	GameObject* obj = new GameObject();
	obj->SetPos(_pos);
	mGameObjects[mgobj_index++] = obj;
}

Scene::Scene()
{
}

Scene::~Scene()
{
}
