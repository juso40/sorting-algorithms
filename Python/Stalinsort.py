"""
Stalinsort
The fastest sorting algorithm known to mankind.
Constant runtime of O(n)
Iterates once over the unsorted list and deletes all unsorted elements.
Done
"""


def stalin_sort(arr):
    if len(arr) <= 1:
        return arr
    max = arr[0]

    def new_max(val):
        nonlocal max
        max = val
        return max

    return [new_max(x) for x in arr if x >= max]


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

    print(stalin_sort(test_arr))
    import benchmark
    benchmark.benchmark(stalin_sort)
