input = {}
horizontal = 0
depth = 0
aim = 0
with open("Day_2/input.txt", "r") as file:
    for line in file:
        line = line.strip().split(" ")
        match line[0]:
            case "forward":
                horizontal += int(line[1])
                depth += int(line[1]) * aim
            case "down":
                aim += int(line[1])
            case "up":
                aim -= int(line[1])
    print(f"{horizontal*depth}")
