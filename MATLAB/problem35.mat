function out = checkpalindrome(num)
    str = num2str(num,1000);
    bak = str(length(str):-1:1);
    if str == bak
        out = true;
    else
        out = false;
    end
    return
end

function out = checkbases(num)
    num10 = num;
    num2 = str2num(dec2base(num,2));
    if checkpalindrome(num10) && checkpalindrome(num2)
        out = true;
    else
        out = false;
    end
    return
end

function out = main()
    count = 0;
    global answers = [];
    for number = 1:1000000
        if checkbases(number)
            count += 1;
            answers(count) = number;
        end
    end
    disp(count);
end