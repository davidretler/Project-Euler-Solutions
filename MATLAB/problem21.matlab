function d = divisor(n)
    %% Input error check :
    %   Check whether input is positive integer and scalar.
    if ~isscalar(n)
        error('divisor:NonScalarInput','Input must be a scalar.');
    end
    if (n < 1) || (floor(n) ~= n)
      error('divisor:PositiveIntegerOnly', 'Input must be a positive integer.'); 
    end

    %% Find prime factors of number :
    pf = factor(n);         % Prime factors of n
    upf = unique(pf);       % Unique

    %% Calculate the divisors
    d = upf(1).^(0:1:sum(pf == upf(1)))';
    for f = upf(2:end)
        d = d*(f.^(0:1:sum(pf == f)));
        d = d(:);
    end
    d = sort(d)';   % To further improve the speed one may remove this sort command
                    %   Just remember to take the transpose of "d" to get a result
                    %   as a row vector instead of a column vector.
end 

function out = sumdivisiors(n)
    divisors = divisor(n);
    out = sum(divisors)-n;
    return
end

function out = checkamicalnumber(n)
    sum1 = sumdivisiors(n);
    sum2 = sumdivisiors(sum1);
    if n != sum1 && n == sum2
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
