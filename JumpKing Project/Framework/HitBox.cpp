#include "stdafx.h"
#include "HitBox.h"

HitBox::HitBox()
{
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color::Green);
	rect.setOutlineThickness(1.f);
}

void HitBox::UpdateTr(const sf::Transformable& tr, const sf::FloatRect& irect)
{
	rect.setOutlineColor(sf::Color::Green);
	rect.setOrigin(tr.getOrigin());
	rect.setSize(irect.getSize());
	rect.setPosition(tr.getPosition());
	rect.setScale(tr.getScale());
	rect.setRotation(tr.getRotation());
}

void HitBox::SetRect(const sf::Transformable& tr, const sf::FloatRect& irect)
{
	rect.setOrigin(tr.getOrigin() - irect.getPosition());
	rect.setSize(irect.getSize());
	rect.setPosition(tr.getPosition());
	rect.setScale(tr.getScale());
	rect.setRotation(tr.getRotation());
}


void HitBox::Draw(sf::RenderWindow& window)
{
	if (Variables::isDrawHitBox)
		window.draw(rect);
}
