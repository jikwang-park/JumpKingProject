#include "stdafx.h"
#include "SceneDev2.h"
#include "AniPlayer.h"
#include "Stage2Map.h"
SceneDev2::SceneDev2() : Scene(SceneIds::Dev2)
{
	
}

void SceneDev2::Init()
{
	
	Scene::Init();
}

void SceneDev2::Enter()
{
	Scene::Enter();
	worldView.setSize(FRAMEWORK.GetWindowSizeF());
	worldView.setCenter(FRAMEWORK.GetWindowSizeF().x / 2, FRAMEWORK.GetWindowSizeF().y / 2);
	
}

void SceneDev2::Exit()
{
	Scene::Exit();
}

void SceneDev2::Update(float dt)
{
	Scene::Update(dt);
}

void SceneDev2::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
