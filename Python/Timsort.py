"""
Timsort
If our list has less than 64 elements, run insertion sort!
This is a very dumped down version of the actual timsort.
Its way slower than the actual built in sort, but its good enough
for me to learn and understand how it works.

First we use insertionsort on Runs in our list.
Now we have multiple sorted runs.
Next we merge the runs and create bigger sorted runs.
Repeat until done.
Done
"""

"""
RUN is our size of sorted blocks (known as Run in timsort)
"""
RUN = 32


def insertion_sort(arr, start=0, end=None):
    if end is None:
        end = len(arr)
    for i in range(start, end):
        elem = arr[i]
        j = i
        while j > 0 and arr[j - 1] > elem:
            arr[j] = arr[j - 1]
            j -= 1
        arr[j] = elem
    return arr


def merge(arr, start, mid, end):
    # Slice our original array in 2 sorted subarrays
    len1, len2 = mid - start + 1, end - mid
    left, right = arr[start: mid + 1], arr[mid + 1: end + 1]

    i, j, k = 0, 0, start
    # Compare each element of the 2 sorted subarrays
    # and merge them back in the original array
    while i < len1 and j < len2:
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    while i < len1:
        arr[k] = left[i]
        k += 1
        i += 1

    while j < len2:
        arr[k] = right[j]
        k += 1
        j += 1


def timsort(arr):
    n = len(arr)
    if n <= 64:  # On small lists its best to use insertion_sort to minimize function calls
        return insertion_sort(arr)
    else:
        for i in range(0, n, RUN):
            insertion_sort(arr, i, min((i + RUN - 1), (n - 1)))
        # At this point we have one unsorted list
        # containing multiple sorted runs/ blocks

        # Now we need to take 2 runs/ blocks and merge them
        # After each merge we double our merge size
        # that we merge our old merged subarray with the new subarray
        block = RUN
        while block < n:
            for start in range(0, n, 2 * block):
                end = min((start + 2 * block - 1), (n - 1))
                mid = (start + end) // 2
                merge(arr, start, mid, end)

            block *= 2


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

    timsort(test_arr)
    print(test_arr)
    import benchmark
    benchmark.benchmark(timsort)
