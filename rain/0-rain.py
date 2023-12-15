#!/usr/bin/python3
""" Module Rain """


def rain(walls=[]):
    """
    Calculate the total amount of rainwater retained after it rains.

    Args:
        walls (list): A list of non-negative integers 
        representing the heights of walls.

    Returns:
        int: Total amount of water retained.
    """
    n = len(walls)
    total_water = 0

    for i in range(1, n - 1):
        # Find the maximum height to the left of the current wall
        left_max = max(walls[:i])

        # Find the maximum height to the right of the current wall
        right_max = max(walls[i + 1:])

        # Calculate water retained at the current wall
        water_at_wall = min(left_max, right_max) - walls[i]

        # Add positive values only
        if water_at_wall > 0:
            total_water += water_at_wall

    return total_water
