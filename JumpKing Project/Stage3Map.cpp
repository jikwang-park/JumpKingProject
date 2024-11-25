#include "stdafx.h"
#include "Stage3Map.h"



Stage3Map::Stage3Map(const std::string& texId, const std::string& name)
	:SpriteGo(texId, name)
{
	sortingLayer = SortingLayers::Background;
	sortingOrder = 0;
}

void Stage3Map::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(sprite, originPreset);
	}
}

void Stage3Map::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);
}

void Stage3Map::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	sprite.setPosition(position);
}

void Stage3Map::SetRotation(float angle)
{
	rotation = angle;
	sprite.setRotation(angle);
}

void Stage3Map::SetScale(const sf::Vector2f& s)
{
	scale = s;
	sprite.setScale(scale);
}

void Stage3Map::Init()
{

	sprite.setTexture(TEXTURE_MGR.Get("grahpics/midground/3.png"));
	for (int i = 0; i < hitboxcount; ++i)
	{

		hitboxs.push_back(hit);

	}
	SetPosition({ 0.f,-720.f });
	SetOrigin(Origins::BC);
	hitboxs[0].SetRect(sprite, sf::FloatRect(7, 95, 57, 17));
	hitboxs[1].SetRect(sprite, sf::FloatRect(135, 0, 73, 15));
	hitboxs[2].SetRect(sprite, sf::FloatRect(160, 120, 60, 47));
	hitboxs[3].SetRect(sprite, sf::FloatRect(190, 220, 150, 35));
	hitboxs[4].SetRect(sprite, sf::FloatRect(285, 205, 50, 20));
	hitboxs[5].SetRect(sprite, sf::FloatRect(207, 303, 50, 15));
	hitboxs[6].SetRect(sprite, sf::FloatRect(320, 305, 58, 13));
	hitboxs[7].SetRect(sprite, sf::FloatRect(425, 255, 48, 15));
	hitboxs[8].SetRect(sprite, sf::FloatRect(473, 0, 7, 360));
	
	
	
	
	
	
	
	
	
	SpriteGo::Init();

}

void Stage3Map::Release()
{
	SpriteGo::Release();
}

void Stage3Map::Reset()
{
	SpriteGo::Reset();
}

void Stage3Map::Update(float dt)
{
	SpriteGo::Update(dt);

}

void Stage3Map::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	for (int i = 0; i < hitboxcount; ++i)
	{
		hitboxs[i].Draw(window);
		hit.Draw(window);
	}
}
