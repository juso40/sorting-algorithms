import random
from timeit import default_timer as timer


def benchmark(func):
    n = [10, 50, 200, 1000, 20000]
    for i in n:
        unsorted = random.sample(range(0, i), i)
        start = timer()
        func(unsorted)
        end = timer()
        print("Sorting algorithm:", func.__name__,
              "\nList length:", i,
              " \nExecution time:",
              (end - start) * 1000, "ms\n")
