#pragma once
#define SLOT_SIZE 130
#define GAP 10

#include <SFML/Graphics.hpp>

#include "Model.hpp"
#include "View.hpp"
#include "Delivery.hpp"

class ItemSlot;
class Delivery;

class Inventory : public Updateable, public Renderable
{
public:
	Inventory();
	~Inventory();
	void update(Model*, sf::Time deltaTime);
	void render(View*);
	void open() { isOpen = isOpen ? false : true; }
	void addToInventory(Delivery*);
	void shiftItemsLeft();
private:
	std::vector<std::string> itemImageNames;
	sf::RectangleShape background;
	std::vector<ItemSlot*> items;
	int numSlots, numItems, numPages;
	bool isOpen;
};

class ItemSlot
{
	friend class Inventory;
public:
	ItemSlot() {
		slot.setSize(sf::Vector2f(SLOT_SIZE, SLOT_SIZE));
		slot.setFillColor(sf::Color::Cyan);
		slot.setOutlineColor(sf::Color::Black);
		slot.setOutlineThickness(3.f);
		delivery = 0;
	}
	~ItemSlot() {}

private:
	void fillSlot() {
		texture.loadFromFile(delivery->getImageFile());
		texture.setSmooth(true);
		item.setTexture(texture);
		item.setColor(sf::Color(50, 50, 50));
		item.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
		item.setPosition(slot.getPosition() + sf::Vector2f(slot.getSize().x / 2, slot.getSize().y / 2));
	}
	void render(sf::RenderWindow& window) { 
		window.draw(slot); 
		window.draw(item);
	}

	Delivery* delivery;
	sf::RectangleShape slot;
	sf::Texture texture;
	sf::Sprite item;
};