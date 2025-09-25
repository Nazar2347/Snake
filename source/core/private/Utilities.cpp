#include "Utilities.h"

RandomNumberGenerator::RandomNumberGenerator(int Min, int Max) : 
    gen(std::random_device{}()), dist(Min, Max)
{
}

int RandomNumberGenerator::GetRandomValue()
{
    return dist(gen);
}