"""
Bubblesort is the easiest sorting algorithm.
We iterate over our list and compare each element with its next one,
if our element is bigger than the next, we swap them.
Worst case runtime O(n^2)
"""


def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr


if __name__ == "__main__":
    test_arr = [
        3,
        1,
        7,
        4,
        12,
        9,
        11,
        102
    ]

    print(bubble_sort(test_arr))
