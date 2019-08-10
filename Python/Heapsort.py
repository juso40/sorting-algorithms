"""
Heapsort
| Build binary maxheap
|-> first element is max
|--> swap first element in heap with last element of unsorted array
|---> heapify
|----> repeat until heap size is 1
Done
Worst case runtime O(n*log(n))
"""


def heapify(heap, n, i):
    """
    :param heap: Our list on that we operate
    :param n: Our current heap size
    :param i: The index of our currently added element
    :return:
    """
    max = i
    l = 2 * i + 1
    r = 2 * i + 2

    # See if left child of root exists and is
    # greater than root
    if l < n and heap[i] < heap[l]:
        max = l

    # See if right child of root exists and is
    # greater than root
    if r < n and heap[max] < heap[r]:
        max = r

    # Change root, if needed
    if max != i:
        heap[i], heap[max] = heap[max], heap[i]  # swap

        # Heapify the root.
        heapify(heap, n, max)


def heap_sort(arr):
    n = len(arr)

    # Build a maxheap.
    for i in reversed(range(n)):
        heapify(arr, n, i)

    # At this point our array is already sorted, but in declining order!
    # Now we swap the order of the Elements and re-heapify the other elements.
    for i in reversed(range(n)):
        arr[i], arr[0] = arr[0], arr[i]  # swap
        heapify(arr, i, 0)

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
        102,
        2,
        3,
        3,
        2,
        2,
        121,
        132,
        3423,
        234,
        199
    ]

    print(heap_sort(test_arr))
