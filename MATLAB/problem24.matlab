%%Project Euler Problem Number Twenty-Four
%%What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
%%David Etler, 19 July 2012

permutations = perms([0:9]);                    %Find all permutations of digits 0:9
multiply = zeros(length(permutations),10);      %Create a matrix to multiply the permutations by
for j = 1:10
        multiply(:,j) = 1*10^(10-j);            %The columns are the decimal place of the corresponding digit
end
nums(:,:) = sum((permutations.*multiply)');     %By multiplying and summing the matrix, the digits become concatenated
sprintf('%u',sort(nums)(1e6))                   %Sort them lexicographically and print the 1,000,000th