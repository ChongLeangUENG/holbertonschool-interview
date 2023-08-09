#!/usr/bin/python3
"""
method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    # Set to keep track of visited boxes
    visited = set()
    visited.add(0)  # Start with the first box (0th index)

    # Queue to keep track of boxes to be explored
    queue = [0]

    while queue:
        current_box = queue.pop(0)
        for key in boxes[current_box]:
            if key < len(boxes) and key not in visited:
                visited.add(key)
                queue.append(key)

    # Check if all boxes have been visited
    return len(visited) == len(boxes)
