def func(List):
    smallest = 0
    for num in List:
        if num > 0:
            smallest = num
            break
    for num in List:
        if num > 0 and num < smallest:
            smallest = num
    if smallest != 1:
        return smallest-1
    else:
        while(True):
            smallest += 1
            if smallest not in List:
                return smallest
def func2(List):
    i=1
    while i in List:
        i += 1
    return i
print(func2([3, 4, -1, 1]))
