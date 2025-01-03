#pragma once
#include "SpriteGo.h"
class Stage2Map : public SpriteGo
{
protected:
	std::vector<HitBox> hitboxs;
	HitBox hit;

	int hitboxcount = 7;
public:
	Stage2Map(const std::string& texId = "", const std::string& name = "");
	~Stage2Map() = default;

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

