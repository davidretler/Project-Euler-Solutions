%%Project Euler Problem Number Four
%%Find the largest palindrome made from the product of two 3-digit numbers.
%%David Etler, 30 June 2012
 
function out = checkpalindrome(num)                                                       %Checks if the imputed number is palindromic 
    out = (num2str(num,1000) == (num2str(num,1000))(length(num2str(num,1000)):-1:1));     %Reverse the string and check equality
    return
end

function out = main()
    products = [];
    out = [];                                                                              %Initialize empty products array
    for i = 999:-1:100                                                                     %For all three-digit numbers, twice
        for j = 999:-1:100                                                           
            if checkpalindrome(i*j)                                                        %If it is a palidrome
                out = i*j;
                break                                  
            end
        end
        if ~isempty(out)
            break
        end
    end
    return
end
