%%Project Euler Problem Number Sixteen
%%What is the sum of digits in the number 2^1000
%%David Etler, 01 July 2012

function out = main()
    out = sum(str2num(num2str(2^1000,1000)(:))')
return