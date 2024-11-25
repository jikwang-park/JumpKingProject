#pragma once
#include "GameObject.h"


class Player : public GameObject
{
protected:
	sf::Sprite body;
	Animator animator;

	HitBox hitbox;

	AnimationClip stay;
	AnimationClip run;
	AnimationClip jumpstart;
	AnimationClip jumpping;
	AnimationClip jumpend;
	AnimationClip jumphigh;

	enum class JumpState
	{
		None,
		Start,
		MidAir,
		End,
	};

	struct CollisionState
	{
		bool Up = false;
		bool Down = false;
		bool Left = false;
		bool Right = false;
	};

	JumpState jumpState = JumpState::None;

	std::string texureId = "grahpics/playerimage/player.png";

	sf::Vector2f diretcion;
	sf::Vector2f velocity = { 0.f,0.f };
	sf::Vector2f grav = { 0.f, 300.f };

	//점프관련 멤버변수
	float jumpHoldTime = 0.f; //스페이스바 누르고 있는 시간
	float maxJumpHoldTime = 0.5f; //최대 점프 유지 시간
	float minJumpForce = -10.f; //최소 점프힘
	float maxJumpForce = -300.f; //최대 점프힘

	bool isJumping = false;
	bool isGrounded = true;

	const float speed = 100.f;

public:
	Player(const std::string& name = "");
	~Player() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	void SetOrigin(Origins preset) override;
	sf::Vector2f GetPosition() const { return position; }
	void SetOrigin(const sf::Vector2f& newOrigin) override;
	HitBox GetPlayerHitBox() const { return hitbox; }

	Player::CollisionState GetCollsionState(const sf::FloatRect& player, const sf::FloatRect& stage);

	bool IsGrounded() const { return isGrounded; }

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

