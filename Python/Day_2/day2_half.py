input = {}
horizontal = 0
depth = 0
with open("Day_2/input.txt", "r") as file:
    for line in file:
        line = line.strip().split(" ")
        match line[0]:
            case "forward":
                horizontal += int(line[1])
            case "down":
                depth += int(line[1])
            case "up":
                depth -= int(line[1])
    print(f"{horizontal*depth}")
