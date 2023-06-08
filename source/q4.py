# def significant (n , k):
#     """ Return the K most significant digits of N.
#     >>> significant (12345 , 3)
#     123
#     >>> significant (12345 , 7)
#     12345
#     """
#     if :
#         return n
#     return significant (n // 10 , k - 1)


def significant(n, k):
    """Return the K most significant digits of N.
    >>> significant (12345 , 3)
    123
    >>> significant (12345 , 7)
    12345
    """
    # n < pow(10, k)
    # n // pow(10, k) == 0
    if n < pow(10, k):
        return n
    return significant(n // 10, k)


print(significant(12345, 3))
print(significant(12345, 7))
