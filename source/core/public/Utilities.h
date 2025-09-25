#include <random>

/**
 * @brief Utility class for generating random integer values within a specified range.
 */
class RandomNumberGenerator
{
  public:
    /**
     * @brief Constructs a random number generator with the given range.
     * @param Min The minimum value (inclusive) that can be generated.
     * @param Max The maximum value (inclusive) that can be generated.
     */
    RandomNumberGenerator(int Min, int Max);

    /**
     * @brief Generates a random integer value within the specified range.
     * @return A random integer between Min and Max (inclusive).
     */
    int GetRandomValue();

  private:
    std::mt19937 gen;                        ///< Mersenne Twister random number engine.
    std::uniform_int_distribution<int> dist; ///< Uniform integer distribution for the specified range.
};
