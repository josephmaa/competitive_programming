def main():
    surface, satellite = None, None
    surface_coords, satellite_coords = [], []
    while 1:

        # print("i" + i)
        # print(surface, satellite, surface_coords, satellite_coords)
        if not surface and not satellite and surface_coords:
            # print("t")
            res = 0

            # print("hello")
            # print(surface_coords, satellite_coords)
            for surface_x, surface_y, surface_z in surface_coords:
                for satellite_x, satellite_y, satellite_z in satellite_coords:
                    v1 = [surface_x, surface_y, surface_z]
                    v2 = [
                        satellite_x - surface_x,
                        satellite_y - surface_y,
                        satellite_z - surface_z,
                    ]

                    tmp = 0
                    for coord1, coord2 in zip(v1, v2):
                        tmp += coord1 * coord2

                    if tmp <= 0:
                        res += 1
                        break
            print(res)

            surface_coords, satellite_coords = [], []

        i = input()
        if i == "0 0":
            break

        vars = [float(i) for i in i.split()]
        if len(vars) == 2:
            satellite, surface = int(vars[0]), int(vars[1])
        elif satellite:
            satellite_coords.append(vars)
            satellite -= 1
        else:
            surface_coords.append(vars)
            surface -= 1


if __name__ == "__main__":
    main()
