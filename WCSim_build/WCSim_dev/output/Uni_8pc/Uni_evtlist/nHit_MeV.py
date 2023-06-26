import numpy as np
import matplotlib.pyplot as plt

# Load the data from the .txt files
data = np.loadtxt('evtlist_8pc_1MeV_nHit.txt')
Bins = 100

# Create histograms for each dataset
hist, bins = np.histogram(data, bins=Bins, range=(0, Bins))
print(hist)

# Create a meshgrid of x and y values
X, Y = np.meshgrid(np.arange(Bins), 1)

plt.imshow(hist, origin='lower', interpolation='none')
plt.show()
# Convert the histograms into a 2D array
#histograms = np.array([hist])

# Plot the 2D histograms using pcolormesh
#plt.pcolormesh(X, Y, histograms, cmap='jet')

# Add labels and title
#plt.xlabel('Dataset')
#plt.ylabel('Bins')
#plt.title('Histogram Distributions')

# Add a colorbar
#plt.colorbar(label='Counts')

# Show the plot
#plt.show()

