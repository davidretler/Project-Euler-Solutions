%%Project Euler Problem Number One
%%Find the sum of all the multiples of 3 or 5 below 1000.
%%David Etler, 29 June 2012

function total = main(n)
    array = [];                                 %Initialize an empty array
    count = 0;                                  %Ticker
    for i = 1:999
        if mod(i,3) == 0 || mod(i,5) == 0       %If the number is divisible by 3 and/or 5
            count += 1;                         %Add to the ticker
            array(count) = i;                   %Append the array with the number
        end
    end
    total = sum(array)                          %Sum the array
    return
end
