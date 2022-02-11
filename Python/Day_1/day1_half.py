input = []

with open("input.txt", "r") as file:
    for line in file:
        input.append(int(line))

counter = 0
for i, num in enumerate(input):
    if num > input[i-1]:
        counter+=1
print(counter)