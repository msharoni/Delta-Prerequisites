def func(List):
    ans = []
    for i in range(len(List)):
        sum = 1
        for j in range(len(List)):
            if i != j:
                sum *= List[j]
        ans.append(sum)
    return ans
print(func([3,2,1]))