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
	SetOrigin(originPreset);
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
	SpriteGo::Init();
}

void Stage2Map::Release()
{
	SpriteGo::Release();
}

void Stage2Map::Reset()
{
	/*sprite.setTexture(TEXTURE_MGR.Get(textureId));*/
	sprite.setPosition({0,-360});
	SetOrigin(Origins::BC);
	SpriteGo::Reset();
}

void Stage2Map::Update(float dt)
{
	SpriteGo::Update(dt);

}

void Stage2Map::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
