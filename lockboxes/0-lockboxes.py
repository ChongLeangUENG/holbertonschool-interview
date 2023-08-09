#!/usr/bin/python3
"""
method that determines if all the boxes can be opened.
"""

def canUnlockAll(boxes):
    """ Initialize a list to keep track of the visited boxes """
    visited = [False] * len(boxes)
    
    """ The first box (box 0) is unlocked initially """
    visited[0] = True
    
    """ Initialize a stack for DFS """
    stack = [0]
    
    """ Perform DFS """
    while stack:
        current_box = stack.pop()
        for key in boxes[current_box]:
            if not visited[key]:
                visited[key] = True
                stack.append(key)
    
    """ Check if all boxes have been visited """
    return all(visited)
