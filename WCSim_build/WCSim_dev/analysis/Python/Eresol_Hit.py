import numpy as np
import matplotlib.pyplot as plt

# example data
gamma_energy =   [1,   2.2,   4,    6,    8,    10,   15,   20,   25,   30,   35,   40,   45,   50]
Gamma_energy =   [2.2,   4,    6,    8,    10,   15,   20,   25,   30,   35,   40,   45,   50]
Total_nHit_8   = [10.5, 10.5, 12.5, 16.5, 21.5, 29.5, 43.5, 50.5,56.5,60.5,70.5,68.5,77.5]
Escape_NHit_8  = [0.98, 1.9,  3.2,  4.5,  5.7,  8.7, 11.6, 14.8,17.1,19.8,22.0,24.3, 26.1]
Total_nHit_15  = [10.5, 16.5, 22.5, 34.5, 41.5, 63.5,131.5,105.5,128.5,131.5,158.5,166.5,111.5]
Escape_NHit_15 = [1.9,  4.5,  7.0,  9.2, 11.4, 18.1, 41.1, 31.5, 35.8, 41.1, 46.9, 51.7, 54.5]
Total_nHit_30  = [10.5, 14.5, 30.5, 50.5, 66.5, 91.5,128.5,167.5,185.5,216.5,193.5,201.5,209.5,203.5]
Escape_NHit_30 = [ 1.3,  4.6,  9.2, 13.9, 20.1, 24.3, 37.6, 51.5, 61.2, 63.6, 64.4, 62.8, 68.2, 68.9]
Total_nHit_60  = [11.0, 31.0, 65.5,  95.5,129.5,175.5,259.5,261.5,285.3,349.0,388.5,310.5,365.0,252]
Escape_NHit_60 = [ 3.7,  9.6, 18.3,  28.0, 39.0, 50.2, 72.9, 85.3, 86.8, 98.1, 96.8, 97.2,99.0,99]
Total_nHit_78  = [15.5, 35.5, 77.5,125.5,175.5,209.5,312.0,371.5,388.5,359.5,359.5,355.5,347.5,361.5]
Escape_NHit_78 = [ 4.4, 11.5, 22.3, 27.5, 41.6, 52.1, 85.9, 96.9, 101.7, 99.1,96.6, 99.0,103.5,101.9]


Total_nHit_8 = np.array(Total_nHit_8)
Escape_NHit_8 = np.array(Escape_NHit_8)
Total_nHit_15 = np.array(Total_nHit_15)
Escape_NHit_15 = np.array(Escape_NHit_15)
Total_nHit_30 = np.array(Total_nHit_30)
Escape_NHit_30 = np.array(Escape_NHit_30)
Total_nHit_60 = np.array(Total_nHit_60)
Escape_NHit_60 = np.array(Escape_NHit_60)
Total_nHit_78 = np.array(Total_nHit_78)
Escape_NHit_78 = np.array(Escape_NHit_78)

fig, ax0 = plt.subplots(nrows=1, ncols=1, figsize=(6, 4))
ax0.plot(Gamma_energy, Escape_NHit_8/Total_nHit_8, marker='o',  label = "pc 8")
ax0.plot(Gamma_energy, Escape_NHit_15/Total_nHit_15, marker='o',label = "pc 15" )
ax0.plot(gamma_energy, Escape_NHit_30/Total_nHit_30, marker='o',label = "pc 30")
ax0.plot(gamma_energy, Escape_NHit_60/Total_nHit_60, marker='o',label = "pc 60")
ax0.plot(gamma_energy, Escape_NHit_78/Total_nHit_78, marker='o',label = "pc 78")
ax0.set_xlabel(r'$\gamma$ Energy (MeV)')
ax0.set_ylabel('RMS/Max_peak')
ax0.set_title('E_resolution')
ax0.legend()
ax0.set_ylim(-0.05, 0.55)
fig.suptitle('3m radius 2m hight cylinder')


plt.show()

