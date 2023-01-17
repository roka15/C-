#pragma once
#include "Scene.h"

class Application
{
public:
	void Initialize()
	{
		bEnable = true;
		mScenes[(UINT)eSceneType::Play].AddGameObject(L'¡Ý', Vector2{ 5, 5 });
		mPlayScene = &mScenes[(UINT)eSceneType::Play];
	}
	void Run()
	{
		while (bEnable)
		{
			mPlayScene->Update();
			mPlayScene->Render();
		}
	}
	void Update()
	{
		
	}
	void Render()
	{

	}
	void Release()
	{
		for (Scene scene : mScenes)
		{
			scene.Release();
		}
	}

private:
	bool bEnable;
	Scene mScenes[(UINT)eSceneType::Max];
	Scene* mPlayScene;
};