#pragma once
#include "Scene.h"

class Application
{
public:
	void Initialize();
	void Run();
	void Update();
	void Render();
	void Release();
public:
	Application();
	~Application();
private:
	bool bEnable;
	Scene m_Scene[(UINT)eSceneType::Max];
	Scene* mPlayScene;
};