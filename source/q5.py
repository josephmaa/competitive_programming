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


print(repeat_sum(lambda x: x * x, 3, 0))
print(repeat_sum(lambda x: x * x, 3, 1))
print(repeat_sum(lambda x: x + 2, 3, 4))
