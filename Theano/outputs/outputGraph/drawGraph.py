from matplotlib import pyplot as plt


fileName = 'output_'
colors = ['', '', 'c', 'm', 'y', 'k']

for i in range(2,6,1):
    f = open(fileName + str(i), 'r')
    ax, ay = [], []
    for line in f:
        a, b = line.split()
        ax.append(int(a))
        ay.append(float(b))
    plt.plot(ax, ay, colors[i])
plt.xlim([-3, 103])
plt.ylim([0.65, 1.05])
plt.show()
