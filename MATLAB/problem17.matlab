%%Project Euler Problem Number Seventeen
%%How many letters would be needed to write all the numbers in words from 1 to 1000?
%%David Etler, 18 July 2012

function word = num2word(number)
    simple = {'one' 'two' 'three' 'four' 'five' 'six' 'seven' 'eight' 'nine' 'ten' 'eleven' 'twelve' 'thirteen' 'fourteen' 'fifteen' 'sixteen' 'seventeen' 'eighteen' 'nineteen'};
    tens = {'twenty' 'thirty' 'forty' 'fifty' 'sixty' 'seventy' 'eighty' 'ninety'};
    if (~isscalar(number)) || (floor(number) ~= number) || (number < 0) || (number == 0)
        error('Please input a positive integer as a scalar argument.')
    end
    if number < 20
        word = cell2mat(simple(number));
    elseif (number < 100) && (mod(number,10) == 0)
        word = cell2mat(tens(round(number/10 - 1)));
    elseif (number < 100)
        word = [cell2mat(tens(floor(number/10) - 1)) '-' cell2mat(simple(mod(number,10)))];
    elseif (number < 1000) && (mod(number,100) == 0)
        word = [cell2mat(simple(floor(number/100))) ' hundred'];
    elseif (number < 1000)
        word = [cell2mat(simple(floor(number/100))) ' hundred and ' num2word(mod(number,100))];
    elseif (number == 1000)
        word = 'one thousand';
    end
    return
end

words = [];
for i = 1:1000
    words = [words num2word(i)];
end
words(words == ' ') = [];
words(words == '-') = [];
length(words)