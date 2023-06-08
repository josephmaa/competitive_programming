# def counter(d: int):
#     """Return a function of N that returns the number of times D appears in N.
#     >>> counter(8)(8018) # d = 8, n = 8018
#     2
#     >>> counter(0)(2016)
#     1
#     >>> counter(0)(0)
#     0
#     """

#     def count(n: int):
#         k = 0
#         while n:
#             n, last = n // 10, n % 10
#             if last == d:
#                 k += 1
#         return k  # some integer

#     return count


def counter(d: int):
    str_d = str(d)

    def count(n: int):
        str_n = str(n)
        k = 0
        for char in str_n:
            # print(char)
            if str_d == char:
                k += 1
        return k

    return count


def main():
    print(counter(8)(8018))
    print(counter(0)(2016))
    print(counter(0)(0))


if __name__ == "__main__":
    main()
