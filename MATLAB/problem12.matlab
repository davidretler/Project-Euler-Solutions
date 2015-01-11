%%Project Euler Problem Number Twelve
%%What is the value of the first triangle number to have over five hundred divisors?
%%David Etler, 01 July 2012

function d = divisor(n)                                     %Find all divisors of a number
    pf = factor(n); 
    upf = unique(pf); 
    d = upf(1).^(0:1:sum(pf == upf(1)))';
    for f = upf(2:end)
        d = d*(f.^(0:1:sum(pf == f)));
        d = d(:);
    end
    d = sort(d)';
end 

function number = trianglenumber(n)                         %Calculate the nth triangle number
    number = sum(1:n);                                      %Sum of the first n natural numbers
    return
end

function out = main()
    n = 1;
    while true                                      
        if length(divisor(trianglenumber(n))) > 500         %If the triangle number has more than five-hundred divisors
            out = trianglenumber(n);
            break
        else
            n += 1;
        end
    end
    return
end