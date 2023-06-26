import numpy as np
import matplotlib.pyplot as plt

# example data
gamma_energy = [1,   2.2, 4,    6,    8,   10,   15,   20,   25,   30,   35,   40,   45,   50]
Total_nHit_8   = [24370,75858,81872,79523,77420,75939,73378,72851,72316,71021,71087,70653,70840,70683]
Escape_NHit_8  = [75630,24142,18128,20477,22580,24061,26622,27149,27684,28979,28913,29347,29160,29317]
Total_nHit_15   = [1176,2500,2486,2405,2321,2278,2264,2110,2205,2113,2110,2125,2093,2161]
Escape_NHit_15  = [1824, 500, 514, 595, 679, 722, 736, 890, 795, 887, 890, 875, 907, 839]
Total_nHit_30   = [1581,2569,2528,2394,2396,2284,2228,2209,2207,2123,2129,2181,2124,2114]
Escape_NHit_30  = [1419, 431, 472, 606, 604, 716, 772, 791, 793, 877, 871, 819, 876, 886]
Total_nHit_60   = [1974,2582,2468,2376,2319,2327,2208,2211,2167,2141,2136,2064,2144,2108]
Escape_NHit_60  = [1026, 418, 532, 624, 681, 673, 792, 789, 833, 859, 864, 936, 856, 892]
Total_nHit_78   = [2076,2594,2456,2360,2359,2292,2203,2156,2200,2184,2151,2097,2102,2160]
Escape_NHit_78  = [ 924, 406, 544, 640, 641, 708, 797, 844, 800, 839, 849, 903, 898, 840]


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

fig, ax0 = plt.subplots(nrows=1, ncols=1, figsize=(4, 6))
ax0.plot(gamma_energy, Total_nHit_8[:]/100000, marker='o',label = "nPMT hit")
ax0.plot(gamma_energy, Total_nHit_15[:]/3000, marker='o', label = "nPMT hit")
ax0.plot(gamma_energy, Total_nHit_30[:]/3000, marker='o',label = "nPMT hit")
ax0.plot(gamma_energy, Total_nHit_60[:]/3000, marker='o',label = "nPMT hit")
ax0.plot(gamma_energy, Total_nHit_78[:]/3000, marker='o', label = "nPMT hit")

fig3, ax3 = plt.subplots(nrows=1, ncols=1, figsize=(6, 4))
ax3.grid(True)
ax3.plot(gamma_energy, Escape_NHit_8[:]/100000, marker='o',label = "pc 8")
ax3.plot(gamma_energy, Escape_NHit_15[:]/3000, marker='o',label = "pc 15")
ax3.plot(gamma_energy, Escape_NHit_30[:]/3000, marker='o',label = "pc 30")
ax3.plot(gamma_energy, Escape_NHit_60[:]/3000, marker='o', label = "pc 60")
ax3.plot(gamma_energy, Escape_NHit_78[:]/3000, marker='o',label = "pc 78")
ax3.set_xlabel(r'$\gamma$ Energy (MeV)')
ax3.set_ylabel('Ratio (%)')
ax3.set_title('Escape hit')
ax3.legend()
fig3.suptitle('3m radius 2m hight cylinder')

plt.show()

