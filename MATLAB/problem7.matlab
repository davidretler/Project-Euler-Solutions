%%Project Euler Problem Number Seven
%%What is the 10,001st prime number?
%%David Etler, 01 July 2012

function out = main()
    out = primes(1e6)(10001);       %Take the 10,001st prime from a list of primes under 1,000,000
    return
end