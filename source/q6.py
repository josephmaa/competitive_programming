def repeat_sum(f, x, n):
    """Compute the following summation of N+1 terms , where the last term
    calls F N times : x + f(x) + f(f(x)) + f(f(f(x))) + ... + f(f (... f(x)))
    >>> repeat_sum ( lambda x: x*x, 3 , 0) # 3
    3
    >>> repeat_sum ( lambda x: x*x, 3 , 1) # 3 + 9
    12
    >>> repeat_sum ( lambda x: x+2 , 3 , 4) # 3 + 5 + 7 + 9 + 11
    35
    """
    total, k = 0, 0

    while k <= n:
        total = total + x
        x = f(x)
        k = k + 1

    return total


def sum_squares(n):
    """Return the sum of the first N perfect squares .
    >>> sum_squares (0)
    0
    >>> sum_squares (3) # 1**2 + 2**2 + 3**2
    14
    >>> sum_squares (5) # 1**2 + 2**2 + 3**2 + 4**2 + 5**2
    55
    """
    f = lambda x: (x + 1) ** 2
    return repeat_sum(f, 0, n)


print(sum_squares(0))
print(sum_squares(3))
print(sum_squares(5))
