"""
Insertionsort
We iterate over all elements and place them in the correct new order.
We create the gaps for the insertions by shifting the elements one to the right.
Worst case runtime O(n^2)
"""


def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        elem = arr[i]  # remember our current element
        j = i  # we guess that our element is already in the correct place
        while j > 0 and arr[j - 1] > elem:  # Move greater elements than our current value one position ahead
            arr[j] = arr[j - 1]
            j -= 1
        arr[j] = elem
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

    print(insertion_sort(test_arr))
    import benchmark
    benchmark.benchmark(insertion_sort)
