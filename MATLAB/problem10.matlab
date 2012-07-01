%%Project Euler Problem Number Ten
%%Find the sum of all the primes below two million.
%%David Etler, 01 July 2012

format long;                      %Output full number
function out = main()
    out = (sum(primes(2e6)));     %Find the sum of all primes under 2,000,000
end