#include <iostream>
#include <conio.h>
#include "Player.h"
#include "Util.h"
#include "Math.h"

void Player::Clear()
{
	Util::Gotoxy(Math::FloorToInt(position.GetX() + screen->GetLeft()), Math::FloorToInt(position.GetY() + screen->GetTop()));

	std::cout << " ";
}

void Player::DrawPosition()
{
	Util::Gotoxy(0, 0);
	Util::SetColor(Util::Color::White);

	String positionStr = String("Position : [").Append(Math::FloorToInt(position.GetX())).Append(", ").Append(Math::FloorToInt(position.GetY())).Append("]");

	for (int i = 0; i < positionStr.GetLength() + 1; i++)
	{
		std::cout << " ";
	}

	Util::Gotoxy(0, 0);

	std::cout << positionStr.GetData();
}

void Player::DrawStatus()
{
	// Draw level state
	Util::Gotoxy(0, 1);
	Util::SetColor(Util::Color::Green);

	String str = String("Level : [").Append(currentLevel).Append("/").Append(maxLevel).Append("]");

	for (int i = 0; i < str.GetLength() + 3; i++)
	{
		std::cout << " ";
	}

	Util::Gotoxy(0, 1);

	std::cout << str.GetData();

	// Draw health state
	Util::Gotoxy(32, 0);
	Util::SetColor(Util::Color::Red);

	str.Set("Health : [").Append(currentHealth).Append("/").Append(maxHealth).Append("]");

	for (int i = 0; i < str.GetLength() + 3; i++)
	{
		std::cout << " ";
	}

	Util::Gotoxy(32, 0);

	std::cout << str.GetData();

	// Draw hungry state
	Util::Gotoxy(32, 1);
	Util::SetColor(Util::Color::DarkYellow);

	str.Set("Hungry : [").Append(currentHungry).Append("/").Append(maxHungry).Append("]");

	for (int i = 0; i < str.GetLength() + 3; i++)
	{
		std::cout << " ";
	}

	Util::Gotoxy(32, 1);

	std::cout << str.GetData();

	// Draw thirst state
	Util::Gotoxy(32, 2);
	Util::SetColor(Util::Color::Blue);

	str.Set("Thirst : [").Append(currentThirst).Append("/").Append(maxThirst).Append("]");

	for (int i = 0; i < str.GetLength() + 3; i++)
	{
		std::cout << " ";
	}

	Util::Gotoxy(32, 2);

	std::cout << str.GetData();
}

void Player::DrawName()
{
	Util::Gotoxy(0, 2);
	Util::SetColor(Util::Color::White);

	std::cout << String("Name : ").Append(name).GetData();
}

Player::Player(Application* application, Screen* screen, unsigned int maxLevel, unsigned int maxHealth, unsigned int maxHungry, unsigned int maxThirst, float walkSpeed, float runSpeed) : application(application), screen(screen), WorldObject(Vector2::zero), currentLevel(1), maxLevel(maxLevel), currentHealth(maxHealth), maxHealth(maxHealth), currentHungry(maxHungry), maxHungry(maxHungry), currentThirst(maxThirst), maxThirst(maxThirst), name(String::empty), walkSpeed(walkSpeed), runSpeed(runSpeed), applySpeed(walkSpeed)
{
	DrawStatus();
}

Player::Player(Application* application, Screen* screen, Vector2 position, unsigned int maxLevel, unsigned int maxHealth, unsigned int maxHungry, unsigned int maxThirst, float walkSpeed, float runSpeed) : application(application), screen(screen), WorldObject(position), currentLevel(1), maxLevel(maxLevel), currentHealth(maxHealth), maxHealth(maxHealth), currentHungry(maxHungry), maxHungry(maxHungry), currentThirst(maxThirst), maxThirst(maxThirst), name(String::empty), walkSpeed(walkSpeed), runSpeed(runSpeed), applySpeed(walkSpeed)
{
	DrawStatus();
}

Player::Player(Application* application, Screen* screen, Vector2 position, unsigned int currentLevel, unsigned int maxLevel, unsigned int currentHealth, unsigned int maxHealth, unsigned int currentHungry, unsigned int maxHungry, unsigned int currentThirst, unsigned int maxThirst, float walkSpeed, float runSpeed) : application(application), screen(screen), WorldObject(position), currentLevel(currentLevel), maxLevel(maxLevel), currentHealth(currentHealth), maxHealth(maxHealth), currentHungry(currentHungry), maxHungry(maxHungry), currentThirst(currentThirst), maxThirst(maxThirst), name(String::empty), walkSpeed(walkSpeed), runSpeed(runSpeed), applySpeed(walkSpeed)
{
	DrawStatus();
}

Player::~Player()
{

}

Player& Player::SetCurrentLevel(unsigned int currentLevel, bool check)
{
	if (!check || currentLevel <= maxLevel)
	{
		this->currentLevel = currentLevel;
	}

	DrawStatus();

	return *this;
}

Player& Player::SetMaxLevel(unsigned int maxLevel, bool check)
{
	if (!check || maxLevel - 1 <= maxLevel)
	{
		this->maxLevel = maxLevel;
	}
	if (check && maxLevel < currentLevel)
	{
		currentLevel = maxLevel;
	}

	DrawStatus();

	return *this;
}

Player& Player::SetCurrentHealth(unsigned int currentHealth, bool check)
{
	if (!check || currentHealth <= maxHealth)
	{
		this->currentHealth = currentHealth;
	}

	DrawStatus();

	return *this;
}

Player& Player::SetMaxHealth(unsigned int maxHealth, bool check)
{
	if (!check || maxHealth - 1 <= maxHealth)
	{
		this->maxHealth = maxHealth;
	}
	if (check && maxHealth < currentHealth)
	{
		currentHealth = maxHealth;
	}

	DrawStatus();

	return *this;
}

Player& Player::SetCurrentHungry(unsigned int currentHungry, bool check)
{
	if (!check || currentHungry <= maxHungry)
	{
		this->currentHungry = currentHungry;
	}

	DrawStatus();

	return *this;
}

Player& Player::SetMaxHungry(unsigned int maxHungry, bool check)
{
	if (!check || maxHungry - 1 <= maxHungry)
	{
		this->maxHungry = maxHungry;
	}
	if (check && maxHungry < currentHungry)
	{
		currentHungry = maxHungry;
	}

	DrawStatus();

	return *this;
}

Player& Player::SetCurrentThirst(unsigned int currentThirst, bool check)
{
	if (!check || currentThirst <= maxThirst)
	{
		this->currentThirst = currentThirst;
	}

	DrawStatus();

	return *this;
}

Player& Player::SetMaxThirst(unsigned int maxThirst, bool check)
{
	if (!check || maxThirst - 1 <= maxThirst)
	{
		this->maxThirst = maxThirst;
	}
	if (check && maxThirst < currentThirst)
	{
		currentThirst = maxThirst;
	}

	DrawStatus();

	return *this;
}

Player& Player::SetName(const String& name)
{
	this->name = name;

	DrawName();

	return *this;
}

Player& Player::SetWalkSpeed(float walkSpeed)
{
	this->walkSpeed = walkSpeed;

	return *this;
}

Player& Player::SetRunSpeed(float runSpeed)
{
	this->runSpeed = runSpeed;

	return *this;
}

void Player::Draw()
{
	Util::Gotoxy(Math::FloorToInt(position.GetX() + screen->GetLeft()), Math::FloorToInt(position.GetY() + screen->GetTop()));
	Util::SetColor(Util::Color::DarkPurple);

	std::cout << "@";

	DrawPosition();
}

void Player::Movement(float deltaTIme)
{
	applySpeed = Util::GetKeyDown(Util::KeyCode::Z) || Util::GetKeyDown(Util::KeyCode::z) ? runSpeed : walkSpeed;

	if (Util::GetKeyDown(Util::KeyCode::LeftArrow) && position.GetX() - applySpeed * deltaTIme >= 0)
	{
		Clear();

		position.SetX(position.GetX() - applySpeed * deltaTIme);

		Draw();
	}
	if (Util::GetKeyDown(Util::KeyCode::UpArrow) && position.GetY() - applySpeed * deltaTIme >= 0)
	{
		Clear();

		position.SetY(position.GetY() - applySpeed * deltaTIme);

		Draw();
	}
	if (Util::GetKeyDown(Util::KeyCode::RightArrow) && position.GetX() + applySpeed * deltaTIme < screen->GetRight() - screen->GetLeft())
	{
		Clear();

		position.SetX(position.GetX() + applySpeed * deltaTIme);

		Draw();
	}
	if (Util::GetKeyDown(Util::KeyCode::DownArrow) && position.GetY() + applySpeed * deltaTIme < screen->GetBottom() - screen->GetTop())
	{
		Clear();

		position.SetY(position.GetY() + applySpeed * deltaTIme);

		Draw();
	}
}

void Player::UpdateStatus(float deltaTime)
{
	static float thirstTimer = 0.0f;
	static float hungryTimer = 0.0f;

	thirstTimer += deltaTime;
	hungryTimer += deltaTime;

	// Thirst : 1 Day (24 Hour)
	if (thirstTimer > 86400.0f)
	{
		thirstTimer -= 1.0f;

		SetCurrentThirst(currentThirst - 1, true);
	}

	// Hungry : 5 Day (120 Hour)
	if (hungryTimer > 432000.0f)
	{
		hungryTimer -= 60.0f;

		SetCurrentHungry(currentHungry - 1, true);
	}
}