"""
Selectionsort
We search for the minimum element and place at the beginning of the unsorted part of the list.
Worst case runtime O(n^2)
"""


def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(min_idx + 1, len(arr)):  # remaining unsorted list
            if arr[min_idx] > arr[j]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]  # swap found minimal with the first element
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

    print(selection_sort(test_arr))
    import benchmark
    benchmark.benchmark(selection_sort)
