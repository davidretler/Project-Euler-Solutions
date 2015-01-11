%%Project Euler Problem Number Twenty-One
%%Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
%%If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
%%Evaluate the sum of all the amicable numbers under 10000.
%%David Etler, 29 June 2012


function d = divisor(n)
    if ~isscalar(n)
        error('divisor:NonScalarInput','Input must be a scalar.');
    end
    if (n < 1) || (floor(n) ~= n)
      error('divisor:PositiveIntegerOnly', 'Input must be a positive integer.'); 
    end
    pf = factor(n); 
    upf = unique(pf); 
    d = upf(1).^(0:1:sum(pf == upf(1)))';
    for f = upf(2:end)
        d = d*(f.^(0:1:sum(pf == f)));
        d = d(:);
    end
    d = sort(d)';
end 

function out = sumdivisiors(n)
    divisors = divisor(n);
    out = sum(divisors)-n;
    return
end

function out = checkamicalnumber(n)
    sum1 = sumdivisiors(n);
    sum2 = sumdivisiors(sum1);
    if n ~= sum1 && n == sum2
        out = true;
    else
        out = false;
    end
    return
end

function sum = main()
    numbers = [];
    count = 0;
    for n = 1:10000
        if checkamicalnumber(n)
            count += 1;
            numbers(count) = n;
        end
    end
    sum = sum(numbers)
    return
end
