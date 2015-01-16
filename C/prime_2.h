

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define N_PRIMES 100000
#define P_LIMIT 1000000

bool is_prime(long long num);
int n_digits(long n);
long next_prime(long p);
void initialize_primes(void);
void prime_factors(long num, int *factors);
long prime(int n);

static bool primes[P_LIMIT];
static long nth_prime[N_PRIMES];
static bool initialized = false;

//#define DEBUG_PRIME


