#include <random>

class RandomNumberGenerator
{
public:
    RandomNumberGenerator(int Min, int Max);
    int GetRandomValue();

private:
    std::mt19937 gen;  // Engine persists between calls
    std::uniform_int_distribution<int> dist;
};

