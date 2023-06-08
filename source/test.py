SIGNS = ["+", "-", "*", "//"]
for x in SIGNS:
    for y in SIGNS:
        for z in SIGNS:
            print(x, y, z)
            print(x == "//", y == "//", z == "//")
            # x = x if x != "//" else "/"
            # y = y if y != '//' else '/'
            # z = z if z != '//' else '/'
            print(x, y, z)
            print("----------")
