#!/usr/bin/python3
"""
Module to calculate the minimum number of operations required to achieve
a specific number of characters in a file using the Copy All and Paste operations.
"""


def min_operations(n):
    """
    Calculate the minimum number of operations required.

    Args:
        n (int): The desired number of characters.

    Returns:
        int: The minimum number of operations required.
             Returns 0 if it's impossible to achieve the desired number.
    """
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


if __name__ == "__main__":
    # Test cases
    n = 4
    print("Min # of operations to reach {} char: {}".format(n, min_operations(n)))

    n = 12
    print("Min # of operations to reach {} char: {}".format(n, min_operations(n)))

    n = 9
    print("Min # of operations to reach {} char: {}".format(n, min_operations(n)))
