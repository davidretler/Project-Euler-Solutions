%%Project Euler Problem Number Two
%%By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
%%David Etler, 29 June 2012

function total = main()
    seed1 = 0;                                  %First Fibonacci value is 0
    seed2 = 1;                                  %Second Fibonacci value is 1
    nums = [];                                  %Empty array of numbers
    while seed2 + seed1 <= 4000000              %While the number doesn't exceed four million
        nums(length(nums)+1) = seed2 + seed1;   %The number is equal to the previous two seeds
        seed1 = seed2;                          %The first seed gets pushed back to the previous
        seed2 = nums(length(nums));             %The second seed is equal to the last number
    end
    nums(mod(nums,2) ~= 0) = [];                %If the value is not even, remove it
    total = sum(nums);                          %Get the sum of the Fibonacci numbers
    return
end