#include "stdafx.h"
#include "Stage1Map.h"



Stage1Map::Stage1Map(const std::string& texId, const std::string& name)
	:SpriteGo(texId,name)
{
	sortingLayer = SortingLayers::Background;
	sortingOrder = 0;
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
	SpriteGo::Init();
	
}

void Stage1Map::Release()
{
	SpriteGo::Release();
}

void Stage1Map::Reset()
{
	/*sprite.setTexture(TEXTURE_MGR.Get(textureId));*/
	sprite.setScale(4.f, 3.f);
	sprite.setPosition({ 1920.f / 2 , 1080.f / 2 });
	SetOrigin(Origins::MC);
	SpriteGo::Reset();
}

void Stage1Map::Update(float dt)
{
	SpriteGo::Update(dt);
	

}

void Stage1Map::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
