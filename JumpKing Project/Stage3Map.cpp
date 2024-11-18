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
	SetOrigin(originPreset);
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
	SpriteGo::Init();

}

void Stage3Map::Release()
{
	SpriteGo::Release();
}

void Stage3Map::Reset()
{
	/*sprite.setTexture(TEXTURE_MGR.Get(textureId));*/
	sprite.setScale(4.f, 3.f);
	sprite.setPosition({ 1920.f / 2  , -1620.f });
	SetOrigin(Origins::MC);
	SpriteGo::Reset();
}

void Stage3Map::Update(float dt)
{
	SpriteGo::Update(dt);

}

void Stage3Map::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
