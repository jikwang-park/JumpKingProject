#pragma once
#include "Scene.h"
class MainTitleScene : public Scene
{


	protected:

	public:
		MainTitleScene();
		~MainTitleScene() = default;

		void Init() override;
		void Enter() override;
		void Exit() override;

		void Update(float dt) override;
		void Draw(sf::RenderWindow& window) override;
	};

