#include "Inventory.hpp"
#include <iostream>
Inventory::Inventory()
{
	background.setSize(sf::Vector2f(850, 570));
	background.setOrigin(850 / 2, 600 / 2);
	background.setPosition(1300 / 2 - 100, 780 / 2);
	background.setFillColor(sf::Color::Blue);

	numSlots = 24; numItems = 0;
	sf::Vector2f slotStartPoint(background.getPosition() - background.getOrigin());
	items.resize(numSlots);
	int k, l;
	k = l = 0;
	for (int i = 0; i < numSlots; i++) {
		items[i] = new ItemSlot();
		items[i]->slot.setPosition(sf::Vector2f(slotStartPoint.x + GAP + l * (SLOT_SIZE + GAP), slotStartPoint.y + GAP + k * (SLOT_SIZE + GAP)));
		l++;
		if (l + 1 > background.getSize().x / (SLOT_SIZE + GAP)) { l = 0; k++; }
	}
	isOpen = false;
}

Inventory::~Inventory()
{}

void Inventory::update(Model* model, sf::Time deltaTime)
{
	for (int i = 0; i < numItems; i++)
		if (items[i]->delivery != 0) {
			if (items[i]->delivery->isPickedUp())
				items[i]->item.setColor(sf::Color(255, 255, 255));
			if (items[i]->delivery->isDroppedOff()) {
				shiftItemsLeft();
				numItems--;
			}
		}
}

void Inventory::render(View* view)
{
	if (isOpen) {
		view->window.draw(background);
		for (int i = 0; i < numSlots; i++)
			items[i]->render(view->window);
	}
}

void Inventory::addToInventory(Delivery* newDelivery)
{
	if (numItems < numSlots) {
		items[numItems]->delivery = newDelivery;
		items[numItems]->fillSlot();
		numItems++;
	}
}

void Inventory::shiftItemsLeft()
{
	numItems--;
	for (int i = 0; i < numItems; i++)
	{
		items[i]->delivery = items[i + 1]->delivery;
		items[i]->texture = items[i + 1]->texture;
		items[i]->item = items[i + 1]->item;
	}
	items[numItems]->delivery = 0;
	items[numItems]->texture = sf::Texture::Texture();
	items[numItems]->item = sf::Sprite::Sprite();
}