#!/usr/bin/python3

import sys
import signal

# Dictionary to store status code counts
status_counts = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0
}

total_file_size = 0
line_count = 0

def print_statistics():
    """Prints the computed statistics."""
    global total_file_size, line_count
    print("File size: {}".format(total_file_size))
    for status_code, count in sorted(status_counts.items()):
        if count > 0:
            print("{}: {}".format(status_code, count))
    sys.stdout.flush()

def signal_handler(sig, frame):
    """Handles keyboard interrupt signal and prints statistics."""
    print_statistics()
    sys.exit(0)

# Registering signal handler for keyboard interrupt
signal.signal(signal.SIGINT, signal_handler)

for line in sys.stdin:
    try:
        # Splitting the line by space
        parts = line.strip().split()
        
        # Extracting relevant information
        status_code = int(parts[-2])
        file_size = int(parts[-1])

        # Updating statistics
        status_counts[status_code] += 1
        total_file_size += file_size
        line_count += 1

        # Printing statistics every 10 lines
        if line_count % 10 == 0:
            print_statistics()

    except Exception as e:
        # Skip the line if it doesn't match the specified format
        continue

# Printing final statistics
print_statistics()
