#include "stdafx.h"
#include "Stage1Map.h"



Stage1Map::Stage1Map(const std::string& texId, const std::string& name)
	:SpriteGo(texId,name)
{
	sortingLayer = SortingLayers::Background;
	sortingOrder = 1;
	
}

void Stage1Map::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(sprite, originPreset);
	}
}

void Stage1Map::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);
}

void Stage1Map::SetPosition(const sf::Vector2f& pos)
{
	SetOrigin(originPreset);
}

void Stage1Map::SetRotation(float angle)
{
	rotation = angle;
	sprite.setRotation(angle);
}

void Stage1Map::SetScale(const sf::Vector2f& s)
{
	scale = s;
	sprite.setScale(scale);

}

void Stage1Map::Init()
{
	
	sprite.setTexture(TEXTURE_MGR.Get("grahpics/midground/1.png"));
	for (int i = 0; i < 5; ++i)
	{ 
		
		hitboxs.push_back(hit);
		
	}
	sprite.setPosition({ 0.f,0.f });

	SetOrigin(Origins::BC);
	hitboxs[0].SetRect(sprite, sf::FloatRect(0, 0, 7, 180));
	hitboxs[1].SetRect(sprite, sf::FloatRect(0, 180, 127, 180));
	hitboxs[2].SetRect(sprite, sf::FloatRect(127, 327, 226, 33));
	hitboxs[3].SetRect(sprite, sf::FloatRect(353, 180, 127, 180));
	hitboxs[4].SetRect(sprite, sf::FloatRect(473, 0, 7, 180));
	hitboxs[0].SetColor(sf::Color::Red);
	hitboxs[1].SetColor(sf::Color::Green);
	hitboxs[2].SetColor(sf::Color::Blue);
	hitboxs[3].SetColor(sf::Color::Magenta);
	hitboxs[4].SetColor(sf::Color::Yellow);
	hit.UpdateTr(sprite, sprite.getLocalBounds());

	
	
	SpriteGo::Init();
	
}

void Stage1Map::Release()
{
	SpriteGo::Release();
}

void Stage1Map::Reset()
{
	/*sprite.setTexture(TEXTURE_MGR.Get(textureId));*/
	
	SpriteGo::Reset();
}

void Stage1Map::Update(float dt)
{

	SpriteGo::Update(dt);


	

}

void Stage1Map::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	for (int i = 0; i < 5; ++i)
	{
		hitboxs[i].Draw(window);
		hit.Draw(window);
	}
}
