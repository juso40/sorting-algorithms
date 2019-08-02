"""
Quicksort
We divide our unsorted list in 2 smaller unsorted lists using a pivot-element.
On each of these smaller lists we call again the quicksort algorithm.
Repeat until the lists are of the length 1 or 0.
Worst case runtime O(n^2)
"""


def quick_sort(arr):

    def _partition(array, begin, end):
        pivot = begin
        for i in range(begin + 1, end + 1):
            if array[i] <= array[begin]:  # We increment i until we locate a value that is smaller than the pivot value
                pivot += 1
                array[i], array[pivot] = array[pivot], array[i]  # then we swap the smaller value with our pivot value
        array[pivot], array[begin] = array[begin], array[pivot]
        return pivot  # return the index of our pivot-element

    def _sort(_arr, start, end):
        if start >= end:
            return
        pivot = _partition(_arr, start, end)
        _sort(_arr, start, pivot - 1)
        _sort(_arr, pivot + 1, end)
    _sort(arr, 0, len(arr) - 1)  # our pivot is the first element
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
    print(quick_sort(test_arr))
