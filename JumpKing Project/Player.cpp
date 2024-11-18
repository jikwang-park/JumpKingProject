#include "stdafx.h"
#include "Player.h"
#include "Animator.h"

Player::Player(const std::string& name)
	:GameObject(name)
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 2;
	SetScale({ 2.f,2.f });
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Player::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Player::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Player::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(body, originPreset);
	}
}


void Player::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = Utils::SetOrigin(body, originPreset);
}

void Player::Init()
{

}

void Player::Release()
{
}

void Player::Reset()
{
	animator.SetTarget(&body);

	body.setTexture(TEXTURE_MGR.Get(texureId));
	{
		sf::IntRect coord(0, 0, 32, 32);
		stay.id = "stay";
		stay.fps = 10;
		stay.loopType = AnimationLoopTypes::Loop;
		stay.frames.push_back(AnimationFrame(texureId, coord));
	}
	//달리기
	{
		sf::IntRect coord(0, 0, 32, 32);
		run.id = "run";
		run.fps = 10;
		run.loopType = AnimationLoopTypes::Loop;
		for (int i = 0; i < 4; ++i)
		{
			coord.left = i * 33;
			run.frames.push_back(AnimationFrame(texureId, coord));
		}
	}
	//점프
	{
		sf::IntRect coord(0, 43, 36, 36);
		jump.id = "jump";
		jump.fps = 10;
		jump.loopType = AnimationLoopTypes::Loop;
		for (int i = 0; i < 3; ++i)
		{
			coord.left = i * 36;
			jump.frames.push_back(AnimationFrame(texureId, coord));
		}
	}


	animator.Play(&stay);
	SetPosition({ 1920.f / 2,980.f}); //처음 태어나는위치
	SetOrigin(Origins::BC);
}

void Player::Update(float dt)
{	
	animator.Update(dt);
	//좌우이동
	if (Utils::Magnitude(diretcion)>1.f)
	{
		Utils::Normailize(diretcion);
	}

	if (isGrounded)
	{
		diretcion.x = InputMgr::GetAxis(Axis::Horizontal);
		velocity.x = diretcion.x * speed;
	}

	//점프
	if (isGrounded && InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		isGrounded = false;
		velocity.y = -1600.f;
		animator.Play(&jump);
		SetOrigin(Origins::BC);
	}
	if (!isGrounded)
	{
		velocity += grav * dt;
	}
	position += velocity * dt;

	//점프후 떨어지는 위치
	if (position.y > 980.f) 
	{
		velocity.y = 0.f;
		position.y = 980.f;
		isGrounded = true;
	}
	SetPosition(position);

	
	
	//방향전환할때 스케일 전환
	if (diretcion.x != 0.f)
	{
		origin = Utils::SetOrigin(body, Origins::BC);
		SetScale(diretcion.x > 0.f ? sf::Vector2f(2.f, 2.f) : sf::Vector2f(-2.f, 2.f));
		
	}
	


	if (animator.GetCurrentClipId() == "stay")
	{
		if (diretcion.x != 0.f)
		{
			animator.Play(&run);
			SetOrigin(Origins::BC);
		}
	}
	else if (animator.GetCurrentClipId() == "run")
	{
		if (diretcion.x == 0.f)
		{
			animator.Play(&stay);
			SetOrigin(Origins::BC);
		}

	}
	else if (animator.GetCurrentClipId() == "jump")
	{
		if (isGrounded)
		{
			if (diretcion.x == 0.f)
			{
				animator.Play(&stay);
				SetOrigin(Origins::BC);
			}
			else
			{
				animator.Play(&run);
				SetOrigin(Origins::BC);
			}
		}
		else
		{
			animator.Play(&jump);
		}
		
	}

	
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
