inp = []

with open("example.txt", "r") as text:
    for line in text:
        inp.append([int(i) for i in line.split()])

res = 0

for i in range(20):
    for j in range(20):
        if i + 3 < 20 and j + 3 < 20:
            res = max(
                res,
                inp[i][j] * inp[i + 1][j + 1] * inp[i + 2][j + 2] * inp[i + 3][j + 3],
            )
        if i - 3 >= 0 and j + 3 < 20:
            res = max(
                res,
                inp[i][j] * inp[i - 1][j + 1] * inp[i - 2][j + 2] * inp[i - 3][j + 3],
            )
        if i + 3 < 20:
            res = max(res, inp[i][j] * inp[i + 1][j] * inp[i + 2][j] * inp[i + 3][j])
        if j + 3 < 20:
            res = max(res, inp[i][j] * inp[i][j + 1] * inp[i][j + 2] * inp[i][j + 3])


print(res)
