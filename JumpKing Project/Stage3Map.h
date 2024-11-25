#pragma once
#include "SpriteGo.h"
class Stage3Map : public SpriteGo
{
protected:
	std::vector<HitBox> hitboxs;
	HitBox hit;

	int hitboxcount = 9;
public:
	Stage3Map(const std::string& texId = "", const std::string& name = "");
	~Stage3Map() = default;

	void SetTextureId(const std::string& id) { textureId = id; }

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& pos) override;

	const std::vector<HitBox> GetHitBoxs() const { return hitboxs; }
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

