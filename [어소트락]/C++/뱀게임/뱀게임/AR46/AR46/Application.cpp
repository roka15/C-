#include "Application.h"

void Application::Initialize()
{
	bEnable = true;
	m_Scene[(UINT)eSceneType::Play].AddGameObject(L'¡Ý', Vector2{ 5,5 });
	mPlayScene = &m_Scene[(UINT)eSceneType::Play];
}

void Application::Run()
{
	while (bEnable)
	{
		mPlayScene->Update();
		mPlayScene->Render();
	}
}

void Application::Update()
{
	//GOTO_XY(5, 5);
	//SET_COLOR(RED);
	cout << "hello" << endl;
}

void Application::Render()
{
}

void Application::Release()
{
	for (auto Scene : m_Scene)
	{
		Scene.Release();
	}
}

Application::Application()
{
}

Application::~Application()
{
}
