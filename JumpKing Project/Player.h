#pragma once
#include "GameObject.h"
class Player : public GameObject
{
protected:
	sf::Sprite body;
	Animator animator;

	AnimationClip stay;
	AnimationClip run;
	AnimationClip jump;


	std::string texureId = "grahpics/playerimage/player.png";

	sf::Vector2f diretcion;
	sf::Vector2f velocity = { 0.f,0.f };
	sf::Vector2f grav = { 0.f, 300.f };

	bool isGrounded = true;
	const float speed = 300.f;
	
public:
	Player(const std::string& name = "");
	~Player() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	void SetOrigin(Origins preset) override;
	sf::Vector2f GetPosition() const { return position; } 
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

