%%Project Euler Problem Number Six
%%Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
%%David Etler, 01 July 2012

function difference = main()
    difference = sum(1:100)^2 - sum((1:100).^2)
    return
end