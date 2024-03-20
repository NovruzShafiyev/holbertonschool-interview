#!/usr/bin/python3
"""
Module to calculate the minimum number of operations required to achieve
a specific number of characters in a file using the Copy All and Paste operations.
"""


def minOperations(n):

    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations


