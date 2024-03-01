#!/usr/bin/python3
'''
    Lockboxes
'''


def canUnlockAll(boxes):
    if not boxes:
        return False

    all_keys = set(range(1, len(boxes)))

    opened_boxes = set()
    stack = [0]

    while stack:
        current_box = stack.pop()
        opened_boxes.add(current_box)

        all_keys -= set(boxes[current_box])

        for key in boxes[current_box]:
            if key not in opened_boxes and key < len(boxes):
                stack.append(key)

    return len(all_keys) == 0

