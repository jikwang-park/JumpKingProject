#include "stdafx.h"
#include "SceneDev1.h"
#include "AniPlayer2.h"
#include "Player.h"
#include "Stage1Map.h"
#include "Stage2Map.h"
#include "Stage3Map.h"
SceneDev1::SceneDev1() : Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{
	player = AddGo(new Player("player"));
	stage1map = AddGo(new Stage1Map("grahpics/midground/1.png"));
	stage2map = AddGo(new Stage2Map("grahpics/midground/2.png"));
	stage3map = AddGo(new Stage3Map("grahpics/midground/3.png"));

	//for (int i = 0; i < mapCount ; ++i)
	//{
	//	sf::FloatRect temp;
	//	temp.
	//}
	
	Scene::Init();


	
}

void SceneDev1::Enter()
{
	Scene::Enter();
	worldView.setSize(FRAMEWORK.GetWindowSizeF());
	worldView.setCenter(FRAMEWORK.GetWindowSizeF().x/2, FRAMEWORK.GetWindowSizeF().y / 2);
	
	
}

void SceneDev1::Exit()
{
	Scene::Exit();
}

void SceneDev1::Update(float dt)
{ 
	Scene::Update(dt);
	//1Ãþ->2Ãþ
	
	/*float Ypos[3];w
	for (int i = -1080; i < 3; ++i)
	{
		Ypos[i] += 1080;
	}*/

	if ( player->GetPosition().y < 0.f && player->GetPosition().y >-1080.f)
	{
		worldView.setCenter(FRAMEWORK.GetWindowSizeF().x / 2, -540.f );
	}
	else if (player->GetPosition().y > 0.f && player->GetPosition().y < 1080.f)
	{
		worldView.setCenter(FRAMEWORK.GetWindowSizeF().x / 2, 540.f);
	}
	else if (player->GetPosition().y < -1080.f && player->GetPosition().y >-2060.f)
	{
		worldView.setCenter(FRAMEWORK.GetWindowSizeF().x / 2, -1620.f );
	}
	else if (player->GetPosition().y < 0.f && player->GetPosition().y > -1080.f)
	{
		worldView.setCenter(FRAMEWORK.GetWindowSizeF().x / 2, -540.f);
	}

}

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
