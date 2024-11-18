#pragma once
#include "Scene.h"

class Stage1Map;
class Stage2Map;
class Stage3Map;
class Player;

class SceneDev1 : public Scene
{
protected:
	Player* player;
	Stage1Map* stage1map;
	Stage2Map* stage2map;
	Stage3Map* stage3map;

	std::vector<sf::FloatRect> mapRectList;
	
	float centerMovepos = -1080.f;
	int mapCount = 3;

public:
	SceneDev1();
	~SceneDev1() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};
