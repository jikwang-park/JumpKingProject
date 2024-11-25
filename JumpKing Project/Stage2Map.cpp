#include "stdafx.h"
#include "Stage2Map.h"



Stage2Map::Stage2Map(const std::string& texId, const std::string& name)
	:SpriteGo(texId, name)
{
	sortingLayer = SortingLayers::Background;
	sortingOrder = 0;
}

void Stage2Map::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(sprite, originPreset);
	}
}

void Stage2Map::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);
}

void Stage2Map::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	sprite.setPosition(position);
}

void Stage2Map::SetRotation(float angle)
{
	rotation = angle;
	sprite.setRotation(angle);
}

void Stage2Map::SetScale(const sf::Vector2f& s)
{
	scale = s;
	sprite.setScale(scale);
}

void Stage2Map::Init()
{
	sprite.setTexture(TEXTURE_MGR.Get("grahpics/midground/2.png"));
	for (int i = 0; i < hitboxcount; ++i)
	{
		hitboxs.push_back(hit);
	}
	SetPosition({ 0.f,-360.f });
	SetOrigin(Origins::BC);
	hitboxs[0].SetRect(sprite, sf::FloatRect(0, 0, 5, 360));
	hitboxs[1].SetRect(sprite, sf::FloatRect(5, 80, 75, 85));
	hitboxs[2].SetRect(sprite, sf::FloatRect(120, 105, 70, 60));
	hitboxs[3].SetRect(sprite, sf::FloatRect(255, 200, 75, 30));
	hitboxs[4].SetRect(sprite, sf::FloatRect(410, 200, 65, 30));
	hitboxs[5].SetRect(sprite, sf::FloatRect(295, 295, 95, 30));
	hitboxs[6].SetRect(sprite, sf::FloatRect(475, 0, 5, 360));
	hitboxs[0].SetColor(sf::Color::Red);
	hitboxs[1].SetColor(sf::Color::Green);
	hitboxs[2].SetColor(sf::Color::Blue);
	hitboxs[3].SetColor(sf::Color::Magenta);
	hitboxs[4].SetColor(sf::Color::Yellow); 
	hitboxs[5].SetColor(sf::Color::Black);
	hitboxs[6].SetColor(sf::Color::Yellow);
	
	SpriteGo::Init();
}

void Stage2Map::Release()
{
	SpriteGo::Release();
}

void Stage2Map::Reset()
{
	SpriteGo::Reset();
}

void Stage2Map::Update(float dt)
{
	SpriteGo::Update(dt);

}

void Stage2Map::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	for (int i = 0; i < hitboxcount; ++i)
	{
		hitboxs[i].Draw(window);
		hit.Draw(window);
	}
}
