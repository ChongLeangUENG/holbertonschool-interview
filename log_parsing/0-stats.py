#!/usr/bin/python3
import sys
import datetime

# Initialize variables to store metrics
total_file_size = 0
status_code_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

try:
    for line in sys.stdin:
        # Parse the input line
        parts = line.split()
        if len(parts) != 7:
            # Skip lines with incorrect format
            continue

        ip_address, _, _, _, status_code_str, file_size_str = parts
        try:
            status_code = int(status_code_str)
            file_size = int(file_size_str)
        except ValueError:
            # Skip lines with non-integer status code or file size
            continue

        # Update metrics
        total_file_size += file_size
        status_code_counts[status_code] += 1
        line_count += 1

        # Print statistics every 10 lines
        if line_count % 10 == 0:
            print(status_code_counts":" total_file_size)
            for code in sorted(status_code_counts.keys()):
                if status_code_counts[code] > 0:
                    print(code, ":", status_code_counts[code])

except KeyboardInterrupt:
    # Handle keyboard interruption
    pass

# Print final statistics
print("Total file size:", total_file_size)
for code in sorted(status_code_counts.keys()):
    if status_code_counts[code] > 0:
        print(code, ":", status_code_counts[code])
