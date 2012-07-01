%%Project Euler Problem Number Five
%%What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
%%David Etler, 30 June 2012

function out = main()
    for i = 11:11:prod(11:20)
        if rem(1,11:20) == [0 0 0 0 0 0 0 0 0 0]
            out = i;
            break
        end
    end
    return
end