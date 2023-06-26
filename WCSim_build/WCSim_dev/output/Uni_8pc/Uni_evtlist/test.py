import numpy as np
import matplotlib.pyplot as plt

# Load the data from the .txt files
d1 = np.loadtxt('evtlist_8pc_1MeV_nHit.txt', max_rows=1000)
d2 = np.loadtxt('evtlist_8pc_2.2MeV_nHit.txt', max_rows=1000)
d3 = np.loadtxt('evtlist_8pc_4MeV_nHit.txt', max_rows=1000)
d4 = np.loadtxt('evtlist_8pc_6MeV_nHit.txt', max_rows=1000)
d5 = np.loadtxt('evtlist_8pc_8MeV_nHit.txt', max_rows=1000)
d6 = np.loadtxt('evtlist_8pc_10MeV_nHit.txt', max_rows=1000)
d7 = np.loadtxt('evtlist_8pc_15MeV_nHit.txt', max_rows=1000)
d8 = np.loadtxt('evtlist_8pc_20MeV_nHit.txt', max_rows=1000)
d9 = np.loadtxt('evtlist_8pc_25MeV_nHit.txt', max_rows=1000)
d10 = np.loadtxt('evtlist_8pc_30MeV_nHit.txt', max_rows=1000)
d11 = np.loadtxt('evtlist_8pc_35MeV_nHit.txt', max_rows=1000)
d12 = np.loadtxt('evtlist_8pc_40MeV_nHit.txt', max_rows=1000)
d13 = np.loadtxt('evtlist_8pc_45MeV_nHit.txt', max_rows=1000)
d14 = np.loadtxt('evtlist_8pc_50MeV_nHit.txt', max_rows=1000)
Bins = 30

# Create histograms for each dataset
h1, b2 = np.histogram(d1, bins=Bins, range=(0, Bins))
h2, b2 = np.histogram(d2, bins=Bins, range=(0, Bins))
h3, b2 = np.histogram(d3, bins=Bins, range=(0, Bins))
h4, b2 = np.histogram(d4, bins=Bins, range=(0, Bins))
h5, b2 = np.histogram(d5, bins=Bins, range=(0, Bins))
h6, b2 = np.histogram(d6, bins=Bins, range=(0, Bins))
h7, b2 = np.histogram(d7, bins=Bins, range=(0, Bins))
h8, b2 = np.histogram(d8, bins=Bins, range=(0, Bins))
h9, b2 = np.histogram(d9, bins=Bins, range=(0, Bins))
h10, b2 = np.histogram(d10, bins=Bins, range=(0, Bins))
h11, b2 = np.histogram(d11, bins=Bins, range=(0, Bins))
h12, b2 = np.histogram(d12, bins=Bins, range=(0, Bins))
h13, b2 = np.histogram(d13, bins=Bins, range=(0, Bins))
h14, b2 = np.histogram(d14, bins=Bins, range=(0, Bins))

hist_matrix = np.vstack((h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,h12,h13,h14))
print(np.rot90(hist_matrix))
hist_matrix = hist_matrix.T

y = np.linspace(0, Bins/0.5, Bins)  # Modify the range of x values
x = np.array([1,2,4,6,8,10,15,20,25,30,35,40,45,50])  # Define a single value for y
xx, yy = np.meshgrid(x, y)
#z = hist.reshape(1, 100)  # Reshape the z array to (1, 100)

# Set the range for the color bar
vmin = 0
vmax = 300

plt.figure(figsize=(6, 6))
plt.imshow(hist_matrix, origin='lower', interpolation='none', extent=[x[0], x[-1], y[0], y[-1]])
plt.gca().set_aspect((x[-1] - x[0]) / (y[-1] - y[0]) * 1.0)
plt.clim(vmin, vmax)  # Set the range of the color bar
plt.colorbar(label='nHit')
plt.xlabel('Energy (MeV)')
plt.ylabel('nHit per trigger')
plt.show()
