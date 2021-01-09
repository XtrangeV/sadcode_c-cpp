import sys
import csv
import matplotlib.pylab as sadplt
from matplotlib.font_manager import FontProperties
# -*- coding: UTF-8 -*-

sadfile = open(sys.argv[1], encoding='utf-8')
csvsad = csv.reader(sadfile)
saddata = list(csvsad)
font = FontProperties(fname=r"c:\windows\fonts\simsun.ttc", size=15)

colors = ['#22EBCD',
          '#3300FF',
          '#8A2BE2',
          '#A52A2A',
          '#DEB887',
          '#5F9EA0',
          '#7FFF00',
          '#D2691E',
          '#FF7F50']

fig, axs = sadplt.subplots(3, 3, sharex=True, sharey=False, figsize=(20, 9))
_len = len(saddata)
x = [i for i in range(1, _len)]
y = list()

for line in range(9):
    y.append([])
    for i in range(1, _len):
        y[line].append(float(saddata[i][line]))

for i in range(0, 3):
    for j in range(0, 3):
        axs[i, j].plot(x, y[3*i+j], color=colors[3*i+j])
        axs[i, j].set_ylabel(saddata[0][3*i+j], fontproperties=font)

sadplt.savefig(sadfile.name.split('.')[0]+".png")
sadplt.show()
