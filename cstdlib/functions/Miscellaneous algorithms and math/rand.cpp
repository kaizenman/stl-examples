// std::rand

// Returns a pseudo-random integral value between 0 and RAND_MAX
// (0 and RAND_MAX included)

// std::srand() seeds the pseudo-random number generator used by rand(). If rand()
// is used before any calls to srand(), rand() behaves as if it was seeded with
// srand(1)
// Each time rand() is seeded with srand(), it must produce the same sequence
// of values on successive calls. Other functions in the standard library may call rand,
// it is implementation-defined which functions do so.

// It is implementation defined whether rand() is thread-safe

// There are no guarantees as to the quality of the random sequence produced.
// In the past, some implementations of rand() have had serous shortcomings
// in the randomness, distribution and period of the sequence produced
// (in one well-known example, the low-order bit simply alternated between 1 and 0 between
// calls).

// rand() is not recommended for serious random-number generation needs

#include <cstdlib>
#include <iostream>
#include <ctime>

int main()
{
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	int random_variable = std::rand();
	std::cout << "Random value on[0 " << RAND_MAX << "]: " << random_variable << '\n';

	for (int n = 0; n != 20; ++n) {
		int x = 7;
		while(x > 6)
			x = 1 + std::rand() / ((RAND_MAX + 1u)/6); // Note: 1+rand()%6 is biased
		std::cout  << x << ' ';
	}
}