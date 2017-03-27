import csv
from matplotlib import pyplot as plt
from matplotlib import patches as mp

fileName = 'result.csv'
colors = ['', '', 'c', 'm', 'y', 'k']

ax1, ax2, ay11, ay12, ay21, ay22 = [], [], [], [], [], []
with open(fileName) as f:
    reader = csv.DictReader(f)
    form = 1
    for r in reader:
        print(r['Meow'], r['Correct'], r['Jizz'])
        if r['Meow'] == "":
            form = 2
        else:
            if form == 1:
                ax1.append(int(r['Meow']))
                ay11.append(float(r['Correct']))
                ay12.append(float(r['Jizz']))
            elif form == 2:
                ax2.append(int(r['Meow']))
                ay21.append(float(r['Correct']))
                ay22.append(float(r['Jizz']))
    plt.plot(ax1, ay11, colors[2])
    plt.plot(ax1, ay12, colors[3])
    plt.xlim([0, 30000])
    plt.ylim([0., 0.92])
    plt.legend(handles=[mp.Patch(color = colors[2], label='error = 0'), mp.Patch(color = colors[3], label='error <= 1')])
    plt.show()



'''
ax, ay = [], []
for line in f:
    a, b = line.split()
    ax.append(int(a))
    ay.append(float(b))
plt.plot(ax, ay, colors[i])

plt.xlim([-3, 103])
plt.ylim([0.65, 1.05])
plt.show()
'''
