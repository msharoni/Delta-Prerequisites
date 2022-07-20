'''
problem:
This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
'''


def func(List, k):
    nums = []
    for num in List:
        if k-num in nums:
            return True
        else:
            nums.append(num)
    return False
print(func([1,2,3,4,5], 5))
