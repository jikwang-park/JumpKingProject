#include "stdafx.h"
#include "Player.h"
#include "Animator.h"
#include "SceneDev1.h"
#include "Stage1Map.h"

Player::Player(const std::string& name)
	:GameObject(name)
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 2;
	SetScale({ 1.f, 1.25f });

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
	//�޸���
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
	//���� Ű�Է��߿� ���;��ϴ°�
	{
		sf::IntRect coord(0, 43, 36, 36);
		jumpstart.id = "jumpstart";
		jumpstart.fps = 10;
		jumpstart.loopType = AnimationLoopTypes::Loop;
		jumpstart.frames.push_back(AnimationFrame(texureId, coord));
	}
	//���� Ű�Է³����ڸ��� ���;��ϴ°�
	{
		sf::IntRect coord(36, 43, 36, 36);
		jumpping.id = "jumpping";
		jumpping.fps = 10;
		jumpping.loopType = AnimationLoopTypes::Loop;
		jumpping.frames.push_back(AnimationFrame(texureId, coord));
	}
	//�ְ���̵����ϰ� y�� �����ɶ� ���;��ϴ°�
	{
		sf::IntRect coord(69, 43, 36, 36);
		jumpend.id = "jumpend";
		jumpend.fps = 10;
		jumpend.loopType = AnimationLoopTypes::Loop;
		jumpend.frames.push_back(AnimationFrame(texureId, coord));
	}
	//�ʹ� ���������� �������鳪�;��ϴ°�
	{
		sf::IntRect coord(105, 43, 36, 36);
		jumphigh.id = "jumphigh";
		jumphigh.fps = 10;
		jumphigh.loopType = AnimationLoopTypes::Loop;
		jumphigh.frames.push_back(AnimationFrame(texureId, coord));
	}
	



	animator.Play(&stay);
	SetPosition({ 0, -32 }); //ó�� �¾����ġ
	SetOrigin(Origins::BC);
}

void Player::Update(float dt)
{
animator.Update(dt);

	float horizontalInput = InputMgr::GetAxisRaw(Axis::Horizontal);

	// �¿� �̵�
	if (Utils::Magnitude(diretcion) > 1.f)
	{
		Utils::Normailize(diretcion);
	}

	if (isGrounded && !isJumping)  // ���� ���� �ƴϰ�, �ٴڿ� ���� ��
	{

		if (InputMgr::GetKeyDown(sf::Keyboard::Space))  // �����̽��� ������ ��
		{
			isJumping = true;  // ���� ����
			jumpHoldTime = 0.f;  // ���� ���� �ð� �ʱ�ȭ
			velocity.x = 0;
		}
		else
		{
			// �����̽��ٰ� ������ �ʾҴٸ� �¿� �̵� ó��
			diretcion.x = horizontalInput;
			if (!InputMgr::GetKey(sf::Keyboard::Space))  // �����̽��� ������ ��
			{
				velocity.x = diretcion.x * speed;
			}

		}
	}

	if (isJumping)
	{


		if (InputMgr::GetKey(sf::Keyboard::Space))
		{
			jumpHoldTime += dt;
			jumpHoldTime = std::min(jumpHoldTime, maxJumpHoldTime);

			if (jumpState != JumpState::Start)
			{
				jumpState = JumpState::Start; // ���� ���� ���·� ��ȯ
				animator.Play(&jumpstart);
				SetOrigin(Origins::BC);
			}
		}

		if (InputMgr::GetKeyUp(sf::Keyboard::Space))
		{
			isGrounded = false;
			isJumping = false;

			float jumpForce = minJumpForce +
				(maxJumpForce - minJumpForce) * (jumpHoldTime / maxJumpHoldTime);
			velocity.x = horizontalInput * speed;
			velocity.y = jumpForce; 


			jumpState = JumpState::MidAir;
			animator.Play(&jumpping);  
			SetOrigin(Origins::BC);  
		}

	}
	else if (isGrounded)
	{
		jumpState = JumpState::None;
		isJumping = false;
	}


	// �߷� ����
	if (!isGrounded)
	{
		velocity += grav * dt;

		if (jumpState == JumpState::MidAir && velocity.y > 0.f)
		{
			jumpState = JumpState::End;
			animator.Play(&jumpend);
			SetOrigin(Origins::BC);
		}
	}

	// �ٴڿ� ���� �� ó��
	sf::Vector2f nextPosition = position + velocity * dt;

	if (nextPosition.y > -32.f)
	{
		nextPosition.y = -32.f;
		velocity.y = 0.f;
		isGrounded = true;

		if (jumpState == JumpState::End)
		{
			jumpState = JumpState::None;
			animator.Play(&stay);  
			SetOrigin(Origins::BC);
		}
	}

	position = nextPosition;
	SetPosition(position);
	if (diretcion.x != 0.f)
	{
		origin = Utils::SetOrigin(body, Origins::BC);
		SetScale(diretcion.x > 0.f ? sf::Vector2f(1.f, 1.25f) : sf::Vector2f(-1.f, 1.25f));
	}

	if (jumpState == JumpState::Start)
	{
		if (animator.GetCurrentClipId() != "jumpstart")
		{
			animator.Play(&jumpstart);
			SetOrigin(Origins::BC);
		}
	}
	else if (jumpState == JumpState::MidAir)
	{
		if (animator.GetCurrentClipId() != "jumpping")
		{
			animator.Play(&jumpping);
			SetOrigin(Origins::BC);
		}
	}
	else if (jumpState == JumpState::End)
	{
		if (animator.GetCurrentClipId() != "jumpend")
		{
			animator.Play(&jumpend);
			SetOrigin(Origins::BC);
		}
	}
	else
	{
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
	}




	hitbox.UpdateTr(body, body.getGlobalBounds());
	hitbox.SetColor(sf::Color::White);

	/*auto stage1HitBoxBounds =dynamic_cast<Stage1Map*>(SCENE_MGR.GetCurrentScene()->FindGo("stage1"))->GetHitBoxs();*/
	



}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	hitbox.Draw(window);
}
