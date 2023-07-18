import numpy as np
import matplotlib.pyplot as plt

New_E = [1,2,3,4,5,6,7,8,9,10,15,20,25,30,35,40,45,50]

PC8_std = [252.581,96.9863,93.7479,81.1028,71.4301,62.1482,54.5366,46.9477,40.8791,34.3123,27.9806,26.1034,27.2506,25.805,27.5239,28.7992,29.4441,30.2283]
PC15_std = [144.994,89.4499,71.6496,49.8058,36.0917,35.8828,30.7226,26.7498,25.4554,25.7663,23.3285,23.2986,24.5434,26.7288,27.8256,30.5911,30.2004,32.412]
PC30_std = [93.8892,62.2485,38.225,27.5778,25.7683,22.6886,22.3218,20.7698,20.4112,19.748,21.0581,22.9338,25.1402,30.119,30.9779,32.8644,33.7309,33.608]
PC60_std = [82.7422,34.1656,23.937,20.6084,18.6487,17.9327,17.5181,16.975,16.5526,16.5691,20.6306,18.7144,21.4798,23.035,27.0707]
PC78_std = [77.6265,29.2385,21.5901,19.1439,17.6805,16.7454,16.0655,16.2175,17.6599,18.9355,15.486,16.6427,20.8914]

RMS_8 = np.array(PC8_std)
RMS_15 = np.array(PC15_std)
RMS_30 = np.array(PC30_std)
RMS_60 = np.array(PC60_std)
RMS_78 = np.array(PC78_std)

pc60_E = [1,2,3,4,5,6,7,8,9,10,15,20,25,30,35]
pc78_E = [1,2,3,4,5,6,7,8,9,10,15,20,25]
fig, ax0 = plt.subplots(nrows=1, ncols=1, figsize=(6, 4))
ax0.plot(New_E, RMS_8 , marker='o', alpha=0.7,label = "pc 8")
ax0.plot(New_E, RMS_15, marker='o',alpha=0.7,label = "pc 15" )
ax0.plot(New_E, RMS_30, marker='o',alpha=0.7,label = "pc 30")
ax0.plot(pc60_E, RMS_60, marker='o',alpha=0.7,label = "pc 60")
ax0.plot(pc78_E, RMS_78, marker='o',alpha=0.7,label = "pc 78")
ax0.grid(True)
ax0.set_xlabel(r'$\gamma$ Energy (MeV)')
ax0.set_ylabel('Stdev from Gaussian Fit (cm)')
ax0.set_title('vertex resolution')
ax0.legend()
ax0.set_xlim(0., 10.)
fig.suptitle('3m radius 2m hight cylinder')

plt.show()

