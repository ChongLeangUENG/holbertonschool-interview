#!/usr/bin/python3

def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding
    """
    # Counter to keep track of the bytes to be processed for a character
    n_bytes = 0

    # Mask to check if the most significant bit is 1 or 0
    mask1 = 1 << 7
    # Mask to check if the second most significant bit is 1 or 0
    mask2 = 1 << 6

    for num in data:
        # Keep only the 8 least significant bits
        mask = 1 << 7
        if n_bytes == 0:
            while mask & num:
                n_bytes += 1
                mask >>= 1

            # 1-byte character
            if n_bytes == 0:
                continue

            # Invalid scenarios: Either we have only one '1' (which would indicate a continuation byte)
            # or more than 4 '1's (indicating a character more than 4 bytes long which is invalid in UTF-8)
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            # For continuation bytes, the most significant bit should be 1 and second most significant bit should be 0
            if not (num & mask1 and not (num & mask2)):
                return False

        # Decrement the byte counter for next iteration
        n_bytes -= 1

    # Return True if no pending bytes are left, else False
    return n_bytes == 0
