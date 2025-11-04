'''Good morning! Here's your coding interview problem for today.

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
'''


def multiply_div(_input_arr):
    """complete with divison"""
    total = 1
    ans = []
    for i in _input_arr:
        total *= i
    for i in _input_arr:
        ans += [total / i]
    print(ans)

def multiply(_input_arr):
    """complete without divison"""
    total = 1
    arr = []
    for i in _input_arr:
        arr += [total]
        total *= i
    total = 1
    for i in range(len(arr) - 1 , -1 , -1):
        arr[i] *= total
        total *= _input_arr[i]
    print(arr)

input_arr = [1,2,3,4,5]

multiply(input_arr)
