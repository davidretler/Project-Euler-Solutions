#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#ifndef PRIME_2_H
#define PRIME_2_H

#ifndef N_PRIMES
#define N_PRIMES 100000
#endif
#ifndef P_LIMIT
#define P_LIMIT 1000000
#endif

//#define DEBUG_PRIME

extern bool is_prime(long long num);
extern int n_digits(long n);
extern long next_prime(long p);
extern void initialize_primes(void);
extern void prime_factors(long num, int *factors);
extern long prime(int n);

#endif
