import numpy as np
import matplotlib.pyplot as plt

New_E = [1,2,3,4,5,6,7,8,9,10,15,20,25,30,35,40,45,50]

Peak_8 = [2.5,3.5,5.5,8.5,10.5,12.5,15.5,16.5,19.5,23.5,34.5,42.5,53.5,58.5,61.5,66.5,82.5,87.5]
RMS_8 =[1.23911,1.89799,2.68492,3.29827,3.85881,4.49343,4.99016,5.68081,6.29934,6.92039,9.93312,13.3084,16.4469,18.9608,21.3564,23.3459,25.8418,27.6932]
Escape_8 = [7171,1793,790,746,828,965,1055,1177,1212,1275,1544,1693,1708,1784,1856,1807,1868,0]

Peak_15 = [3.5,6.5,10.5,17.5,22.5,24.5,29.5,35.5,42.5,42.5,67.5,87.5,100.5,113.5,125.5,128.5,125.5,147.5]
RMS_15 = [1.72535,2.93755,4.18482,5.18101,6.28346,7.47232,8.51845,9.56158,10.8768,12.269,17.9065,24.8031,30.8484,35.6133,39.9637,43.8882,48.4196,52.1546]
Escape_15 = [5745,846,644,706,784,931,1048,1114,1238,1203,1552,1718,1651,1840,1862,1844,1842,0]

Peak_30 = [6.5,12.5,19.5,30.5,40.5,53.5,61.5,70.5,79.5,86.5,131.5,166.5,204.5,234.5,244.5,309.5,238.5,324.5]
RMS_30 = [2.52081,4.91672,7.23185,9.17401,11.4437,13.5219,15.6943,18.3248,20.6864,22.7698,35.5097,49.2371,60.7103,70.1654,80.7645,88.1548,94.732,103.411]
Escape_30 = [4145,491,512,650,796,940,1003,1096,1183,1279,1472,1626,1711,1870,1850,1889,1860,0]

Peak_60 =  [11.5,22.5,44.5,60.5,81.5,96.5,116.5,134.5,144.5,166.5,254.5,352.5,395.5,437.5,518.5,527.5,507.5,586.5]
RMS_60 = [3.82982,8.41507,12.8163,16.5503,20.9581,25.5125,30.1991,34.9869,39.6573,44.1099,70.3089,95.8133,120.025,140.473,157.44,173.323,191.539,206.199]
Escape_60 = [2934,407,508,634,789,944,1034,1125,1183,1266,1520,1661,1716,1868,1813,1807,1866,0]

Peak_78 = [15.5,31.5,53.5,83.5,99.5,117.5,142.5,160.5,188.5,216.5,321.5,422.5,531.5,530.5,547.5,708.5,810.5,695.5]
RMS_78 = [4.45393,10.2209,15.751,20.9083,26.6452,32.417,37.8526,45.1785,50.5726,57.5364,88.7404,122.931,154.061,178.435,203.81,223.564,237.143,248.363]
Escape_78 = [2560,371,484,706,782,899,991,1156,1207,1227,1549,1607,1726,1835,1790,1806,1847,0]


Peak_8 = np.array(Peak_8)
Peak_15 = np.array(Peak_15)
Peak_30 = np.array(Peak_30)
Peak_60 = np.array(Peak_60)
Peak_78 = np.array(Peak_78)

RMS_8 = np.array(RMS_8)
RMS_15 = np.array(RMS_15)
RMS_30 = np.array(RMS_30)
RMS_60 = np.array(RMS_60)
RMS_78 = np.array(RMS_78)

Escape_8 = np.array(Escape_8)
Escape_15 = np.array(Escape_15)
Escape_30 = np.array(Escape_30)
Escape_60 = np.array(Escape_60)
Escape_78 = np.array(Escape_78)

N = 10000
#New_E = [1,2,3,4,5,6,7,8,9,10,15,20]
fig, ax0 = plt.subplots(nrows=1, ncols=1, figsize=(6, 4))
ax0.plot(New_E, RMS_8/Peak_8, marker='o', alpha=0.7, label = "pc 8")
ax0.plot(New_E, RMS_15/Peak_15, marker='o',alpha=0.7,label = "pc 15" )
ax0.plot(New_E, RMS_30/Peak_30, marker='o',alpha=0.7,label = "pc 30")
ax0.plot(New_E, RMS_60/Peak_60, marker='o',alpha=0.7,label = "pc 60")
ax0.plot(New_E, RMS_78/Peak_78, marker='o',alpha=0.7,label = "pc 78")
ax0.grid(True)
ax0.set_xlabel(r'$\gamma$ Energy (MeV)')
ax0.set_ylabel('RMS/Max_peak')
ax0.set_title('E_resolution')
ax0.legend()
ax0.set_xlim(0., 15.)
fig.suptitle('3m radius 2m hight cylinder')

fig2, ax2 = plt.subplots(nrows=1, ncols=1, figsize=(6, 4))
ax2.plot(New_E, Escape_8/N , marker='o', alpha=0.7, label = "pc 8")
ax2.plot(New_E, Escape_15/N, marker='o',alpha=0.7,label = "pc 15" )
ax2.plot(New_E, Escape_30/N, marker='o',alpha=0.7,label = "pc 30")
ax2.plot(New_E, Escape_60/N, marker='o',alpha=0.7,label = "pc 60")
ax2.plot(New_E, Escape_78/N, marker='o',alpha=0.7,label = "pc 78")
ax2.grid(True)
ax2.set_xlabel(r'$\gamma$ Energy (MeV)')
ax2.set_ylabel('Ratio (%)')
ax2.set_title('Escape hit')
ax2.legend()
ax2.set_xlim(0., 40.)
fig2.suptitle('3m radius 2m hight cylinder')

plt.show()

