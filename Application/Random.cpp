#include <random>
#include "Random.h"

int Random::Range(int minInclusive, int maxInclusive)
{
	std::random_device randomDevice;
	std::mt19937 randomEngine(randomDevice());
	std::uniform_int_distribution<> value(minInclusive, maxInclusive);

	return value(randomEngine);
}