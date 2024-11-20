#pragma once

class HitBox
{
public:
	HitBox();

	sf::RectangleShape rect;

	void UpdateTr(const sf::Transformable& tr, const sf::FloatRect& localBound);
	void SetRect(const sf::Transformable& tr, const sf::FloatRect& irect);
	void SetColor(const sf::Color& color) { rect.setOutlineColor(color); }
	void Draw(sf::RenderWindow& window);
};