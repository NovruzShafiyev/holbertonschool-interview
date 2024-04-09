#!/usr/bin/python3
import sys
"""Reads stdin line by line and computes metrics
If count of lines is evenly divided by 10 and/or
keyboardinterrupt
all info will be printed"""

def print_statistics(total_size, status_counts):
    print(f"File size: {total_size}")
    for status_code, count in sorted(status_counts.items()):
        print(f"{status_code}: {count}")

def parse_line(line):
    parts = line.split()
    if len(parts) != 7:
        return None
    ip, _, _, status_code, file_size = parts[:5]
    if not ip.replace('.', '').isdigit():
        return None
    try:
        status_code = int(status_code)
        file_size = int(file_size)
        return (status_code, file_size)
    except ValueError:
        return None

def main():
    total_size = 0
    status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        for line in sys.stdin:
            line = line.strip()
            parsed = parse_line(line)
            if parsed:
                status_code, file_size = parsed
                total_size += file_size
                status_counts[status_code] += 1
                line_count += 1
                if line_count % 10 == 0:
                    print_statistics(total_size, status_counts)
    except KeyboardInterrupt:
        print_statistics(total_size, status_counts)

if __name__ == "__main__":
    main()
