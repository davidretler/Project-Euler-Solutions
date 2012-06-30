function total = main(n)
    array = []; 
    count = 0;
    for i = 1:999
        if mod(i,3) == 0 || mod(i,5) == 0
            count += 1;
            array(count) = i;
        end
    end
    total = sum(array)
    return
end
