#!/usr/bin/python3
"""
Determines if a given data set represents a valid UTF-8 encoding.
"""

def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.
    """
    bytes_to_follow = 0

    for byte in data:
        if bytes_to_follow == 0:
            if byte >> 7 == 0:
                bytes_to_follow = 0
            elif byte >> 5 == 0b110:
                bytes_to_follow = 1
            elif byte >> 4 == 0b1110:
                bytes_to_follow = 2
            elif byte >> 3 == 0b11110:
                bytes_to_follow = 3
            else:
                return False
        else:
            if byte >> 6 != 0b10:
                return False
            bytes_to_follow -= 1
            if bytes_to_follow < 0:
                return False

    return bytes_to_follow == 0

if __name__ == "__main__":
    data1 = [65]
    print(validUTF8(data1))

    data2 = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
    print(validUTF8(data2))

    data3 = [229, 65, 127, 256]
    print(validUTF8(data3))
