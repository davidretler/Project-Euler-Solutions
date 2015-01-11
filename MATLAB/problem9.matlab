%%Project Euler Problem Number Nine
%%There exists exactly one Pythagorean triplet for which a + b + c = 1000.
%%Find the product abc.
%%David Etler, 01 July 2012 

function triplets = gettriplets()                               %Populates a matrix of Pythagorean triplets
    triplets = [];                                              %Initialize empty matrix
    for i = 1:500
        for j = 1:500
            if floor(sqrt(i^2 + j^2)) == sqrt(i^2 + j^2)        %If the third number is a integer
               triplets = [triplets; i j sqrt(i^2 + j^2)];      %Put all three numbers on a new row
            end
        end
    end
end

function row = findrow(triplets)                                %Finds the row whose sum is 1000
    for i = 1:rows(triplets)
        if sum(triplets(i,:)) == 1000
            row = i;
            break;
        end
    end
end

function out = main()
    triplets = gettriplets;
    row = findrow(triplets);
    out = prod(triplets(row,:));                                %Calculate the product of the row
end
