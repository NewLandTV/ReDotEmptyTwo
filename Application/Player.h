#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Application.h"
#include "Screen.h"
#include "WorldObject.h"

class Player : public WorldObject
{
private:
	Application* application;
	Screen* screen;

	// Status
	unsigned int currentLevel;
	unsigned int maxLevel;
	unsigned int currentHealth;
	unsigned int maxHealth;
	unsigned int currentHungry;
	unsigned int maxHungry;
	unsigned int currentThirst;
	unsigned int maxThirst;

	// Personal informations
	String name;

	// Movement speeds
	float walkSpeed;
	float runSpeed;
	float applySpeed;

	void Clear();
	void DrawPosition();
	void DrawStatus();
	void DrawName();

public:
	Player(Application* application, Screen* screen, unsigned int maxLevel, unsigned int maxHealth, unsigned int maxHungry, unsigned int maxThirst, float walkSpeed, float runSpeed);
	Player(Application* application, Screen* screen, Vector2 position, unsigned int maxLevel, unsigned int maxHealth, unsigned int maxHungry, unsigned int maxThirst, float walkSpeed, float runSpeed);
	Player(Application* application, Screen* screen, Vector2 position, unsigned int currentLevel, unsigned int maxLevel, unsigned int currentHealth, unsigned int maxHealth, unsigned int currentHungry, unsigned int maxHungry, unsigned int currentThirst, unsigned int maxThirst, float walkSpeed, float runSpeed);
	~Player();

	// Getters
	unsigned int GetCurrentLevel() const { return currentLevel; }
	unsigned int GetMaxLevel() const { return maxLevel; }
	unsigned int GetCurrentHealth() const { return currentHealth; };
	unsigned int GetMaxHealth() const { return maxHealth; };
	unsigned int GetCurrentHungry() const { return currentHungry; };
	unsigned int GetMaxHungry() const { return maxHungry; };
	unsigned int GetCurrentThirst() const { return currentThirst; };
	unsigned int GetMaxThirst() const { return maxThirst; };
	const String& GetName() const { return name; }
	float GetWalkSpeed() const { return walkSpeed; }
	float GetRunSpeed() const { return runSpeed; }
	float GetApplySpeed() const { return applySpeed; }

	// Setters
	Player& SetCurrentLevel(unsigned int currentLevel, bool check);
	Player& SetMaxLevel(unsigned int maxLevel, bool check);
	Player& SetCurrentHealth(unsigned int currentHealth, bool check);
	Player& SetMaxHealth(unsigned int maxHealth, bool check);
	Player& SetCurrentHungry(unsigned int currentHungry, bool check);
	Player& SetMaxHungry(unsigned int maxHungry, bool check);
	Player& SetCurrentThirst(unsigned int currentThirst, bool check);
	Player& SetMaxThirst(unsigned int maxThirst, bool check);
	Player& SetName(const String& name);
	Player& SetWalkSpeed(float walkSpeed);
	Player& SetRunSpeed(float runSpeed);

	// Render
	void Draw();

	// Logics
	void Movement(float deltaTIme);
	void UpdateStatus(float deltaTime);
};

#endif