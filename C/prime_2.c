//Fills the factors array with the prime factors of the number
 
void prime_factors(long num, int *factors)
{
    bool first_check = true;
    int curr_prime_index = 0;
    while(num > 1)
    {
	if(first_check)
	{
	    factors[curr_prime_index] = 0;
	    first_check = false;
	}

	if(num % prime(curr_prime_index) == 0)
	{
	    num = num / prime(curr_prime_index);
	    factors[curr_prime_index] = factors[curr_prime_index] + 1;
	}
	else
	{
	    curr_prime_index++;
	    first_check = true;
	}
    }
    if(num == 0)
    {
	printf("Error! Result is 0 in prime_factors()\n");
    }
    return;
}

//Returns true if a number is prime, O(sqrt(n))
//This naive algorithm works by trial division rather than anything fancy.
bool is_prime(long long num)
{
    if(initialized && num < P_LIMIT)
    {
#ifdef DEBUG_PRIME
	printf("Cached!\n");
#endif
	return primes[num];
    }
    
    if(num == 1 || num <= 0) return false;

    long max = ceil(sqrt(num));
    long n = 2;
    bool prime = true;

    while(n <= max)
    {
	if(num % n == 0 && num != n)
	{
	    prime = false;
	    break;
	}
	n++;
    }
     
    return prime;
}

//Returns the nth prime number
long prime(int n)
{
    if(initialized && n < N_PRIMES)
    {
	return nth_prime[n];
    }
    else
    {
	printf("Error!\n");
	return -1;
    }
}


void initialize_primes(void)
{
    int i = 0;
    long n = 2; 
    while(n < P_LIMIT)
    {
	bool curr_b = is_prime(n);
	primes[n] = curr_b;
	if(curr_b)
	{
	    nth_prime[i] = n;
	    i++;
	}
	n++;
    }
    initialized = true;
}


//Returns the number of digits in the number
int n_digits(long n)
{
    return ceil(log(n)/log(10));
}


//Returns the first prime after p
long next_prime(long p)
{
    //if p is even, add one. if p is odd, add two.
    p += (p % 2 == 0) ? 1 : 2;
    while(!is_prime(p))
    {
	p += 2;
    }
    return p;
}