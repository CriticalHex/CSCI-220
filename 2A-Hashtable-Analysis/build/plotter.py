import matplotlib.pyplot as plt

hash0 = ([], [])
with open("hash0.txt", "r") as file:
    for line in file:
        x, y = map(float, line.split(","))
        hash0[0].append(x)
        hash0[1].append(y)

hash1 = ([], [])
with open("hash1.txt", "r") as file:
    for line in file:
        x, y = map(float, line.split(","))
        hash1[0].append(x)
        hash1[1].append(y)

hash2 = ([], [])
with open("hash2.txt", "r") as file:
    for line in file:
        x, y = map(float, line.split(","))
        hash2[0].append(x)
        hash2[1].append(y)

hash3 = ([], [])
with open("hash3.txt", "r") as file:
    for line in file:
        x, y = map(float, line.split(","))
        hash3[0].append(x)
        hash3[1].append(y)

hash4 = ([], [])
with open("hash4.txt", "r") as file:
    for line in file:
        x, y = map(float, line.split(","))
        hash4[0].append(x)
        hash4[1].append(y)

# print(max(max(hash0[1]), max(hash1[1]), max(hash2[1]), max(hash3[1]), max(hash4[1])))

plt.scatter(*hash0, c="b", label="hash0")
# plt.scatter(*hash1, c="r", label="hash1")
# plt.scatter(*hash2, c="g", label="hash2")
# plt.scatter(*hash3, c="y", label="hash3")
# plt.scatter(*hash4, c="m", label="hash4")
plt.grid(True)
plt.legend(loc="upper left")
plt.title("Average Comparisons Done vs. Size of Table")
plt.ylabel("Avg. Comparisons")
plt.xlabel("Table Size")
plt.show()
