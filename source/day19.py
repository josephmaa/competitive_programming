from functools import lru_cache


def main():
    total_quality = 0

    with open("source/day19test.txt") as f:
        lines = f.readlines()
        for i, line in enumerate(lines):
            blueprint_idx = i + 1
            words = line.split(" ")
            ore, clay, obsidian, geode = (
                int(words[6]),
                int(words[12]),
                (int(words[18]), int(words[21])),
                (int(words[27]), int(words[30])),
            )

            @lru_cache
            def helper(
                day,
                raw_ore,
                raw_clay,
                raw_obsidian,
                raw_geode,
                ore_robot,
                clay_robot,
                obsidian_robot,
                geode_robot,
            ):
                for k, v in locals().items():
                    print(blueprint_idx, k, v)
                print()
                print()

                if day == 25:
                    return raw_geode

                if raw_ore >= geode[0] and raw_obsidian >= geode[1]:
                    # Add a geode robot
                    return helper(
                        day + 1,
                        raw_ore + ore_robot - geode[0],
                        raw_clay + clay_robot,
                        raw_obsidian + obsidian_robot - geode[1],
                        raw_geode + geode_robot,
                        ore_robot,
                        clay_robot,
                        obsidian_robot,
                        geode_robot + 1,
                    )

                elif raw_ore >= obsidian[0] and raw_clay >= obsidian[1]:
                    # Add an obsidian robot
                    return helper(
                        day + 1,
                        raw_ore + ore_robot - obsidian[0],
                        raw_clay + clay_robot - obsidian[1],
                        raw_obsidian + obsidian_robot,
                        raw_geode + geode_robot,
                        ore_robot,
                        clay_robot,
                        obsidian_robot + 1,
                        geode_robot,
                    )

                elif raw_ore >= clay:
                    # Add a clay robot
                    return helper(
                        day + 1,
                        raw_ore + ore_robot - clay,
                        raw_clay + clay_robot,
                        raw_obsidian + obsidian_robot,
                        raw_geode + geode_robot,
                        ore_robot,
                        clay_robot + 1,
                        obsidian_robot,
                        geode_robot,
                    )

                # clay_robot and ore_robot/clay_robot < obsidian[0]/obsidian[1] and
                # elif raw_ore >= ore:
                #     # Add a ore robot
                #     return helper(
                #         day + 1,
                #         raw_ore + ore_robot - ore,
                #         raw_clay + clay_robot,
                #         raw_obsidian + obsidian_robot,
                #         raw_geode + geode_robot,
                #         ore_robot + 1,
                #         clay_robot,
                #         obsidian_robot,
                #         geode_robot,
                #     )

                else:
                    return helper(
                        day + 1,
                        raw_ore + ore_robot,
                        raw_clay + clay_robot,
                        raw_obsidian + obsidian_robot,
                        raw_geode + geode_robot,
                        ore_robot,
                        clay_robot,
                        obsidian_robot,
                        geode_robot,
                    )

            res = helper(0, 0, 0, 0, 0, 1, 0, 0, 0)
            print(blueprint_idx, res)

            total_quality += blueprint_idx * res

    print(total_quality)


if __name__ == "__main__":
    main()
