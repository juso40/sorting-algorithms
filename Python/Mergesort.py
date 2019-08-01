"""
Mergesort -> divide and conquer!
We divide our list in multiple smaller lists.
Each of those smaller lists will then be sorted.
At the end we merge the smaller, sorted lists to one big sorted list.
Worst case runtime O(n*log(n))
"""


def merge_sort(arr):
    # recursive implementation
    def merge(l, r):
        l_index, r_index = 0, 0
        result = []
        while l_index < len(l) and r_index < len(r):
            # compare the left and right elements
            # append the smaller one first to the new list
            if l[l_index] < r[r_index]:
                result.append(l[l_index])
                l_index += 1
            else:
                result.append(r[r_index])
                r_index += 1
        # either left or right has been used up, add the remaining elements of the other
        result += l[l_index:]
        result += right[r_index:]
        return result

    if len(arr) <= 1:
        return arr
    else:
        # split the array in 2 arrays recursively
        right = merge_sort(arr[len(arr)//2:])
        left = merge_sort(arr[:len(arr)//2])
        return merge(left, right)


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

    print(merge_sort(test_arr))
