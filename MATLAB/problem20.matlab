%%Project Euler Problem Number Twenty
%%What is the sum of digits in the number 100!
%%David Etler, 01 July 2012

function out = main()
    out = sum(str2num(num2str(factorial(100),1000)(:))')
return