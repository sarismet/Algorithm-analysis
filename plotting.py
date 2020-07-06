import matplotlib.pyplot as plt
import numpy as np
import math

ReadingInputFile = open("results.txt", "r")

Lines = ReadingInputFile.readlines()


bests = Lines[0].strip().split()
worsts = Lines[1].strip().split()
averages = Lines[2].strip().split()

bests = [int(i)*1000 for i in bests]

worsts = [int(i)*1000 for i in worsts]
averages = [int(i)*1000 for i in averages]

print(bests)


x = np.array(range(2, 1000))
b = [math.log(i, 2) for i in x]
y = x
axis = list(range(0, 1000, 50))


plt.plot(axis, bests, 'bs')
plt.plot(x, y, 'r')

plt.show()
