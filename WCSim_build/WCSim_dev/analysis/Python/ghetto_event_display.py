#!/usr/bin/python

import matplotlib.pyplot as plt 
import numpy as np
import math

import sys
import re
import stat
import time
import os
from os import chmod, remove
from os.path import expandvars, join
import subprocess
from subprocess import call

def read_hitlist( fname ): 
      
   hit_list = {}

   line_number = 0 
   with open( fname ) as f:
     for line in f :
       items = line.strip().split()

       if not 'Event' in items[0] : continue
       event = int( items[1] )
       #print("In the read_hitlist")
       #print("EVENT= ", event)       
       # items[2] is the word "nHit" 
       nmax = int( items[3] )
       #print("NMAX= ", nmax)
       hit_list[event] = [] 
       for i in range( 0, nmax):
         # now with charge reading
         hit_list[event] += [ (int(items[4+i*2]), float(items[5+i*2]) )  ]
         #hit_list[event] += [ int(items[4+i])  ]
       #print(hit_list)
   return hit_list

def read_maxhit( fname ):
   maxhit = []
   with open( fname ) as f:
     for line in f :
       items = line.strip().split()
       maxhit.append(int(items[3]))
   return maxhit
          

def read_geofile( fname ):

   pmt_list = {}
   maxZ = -10000
   minZ =  10000
   radius = 0 
   height = 0 
#l1 100.56  201.12      7248    2.50
#l2   0.00    0.00    0.00
#l3+  1 100.530741285 2.527145223 -92.500000000 -0.999684189 -0.025130095 0.000000000   1

   line_number = 0 
   with open( fname ) as f:
     for line in f :
       items = line.strip().split()
      
       if line_number == 0 : 
         radius = float( items[0] ) 
         height = float( items[1] ) 
         line_number += 1 
         continue 

       if line_number == 1 : 
         line_number += 1 
         continue 

       cable = int( items[0] )
       X     = float( items[1] )
       Y     = float( items[2] )
       Z     = float( items[3] )
       TBW   = float( items[7] )  # 1=bottom , 0 = wall , 2=top

       if Z < minZ : minZ = Z       
       if Z > maxZ : maxZ = Z       

       pmt_list[cable] = [ X , Y, Z, TBW ]
        
   return minZ, maxZ, radius, height, pmt_list 


def ConvertToWC( pmt_list , minZ, maxZ, det_r, h ): 

  WCPMTs = {}
  rotate_angle = 0 
  for cable, pos in pmt_list.items():
     x = pos[0]
     y = pos[1] 
     z = pos[2] 
     twb = int( pos[3] )
 
     xpos_wc = 0
     ypos_wc = 0


     # bottom tubes
     if z < minZ + 1.0e-3 :
       xpos_wc = -(y * math.cos(rotate_angle) + x * math.sin(rotate_angle))
       ypos_wc = minZ - det_r - y * math.sin(rotate_angle) + x * math.cos(rotate_angle)

     # top tubes
     elif  z > maxZ -1.0e-3:
       xpos_wc = -(y * math.cos(rotate_angle) + x * math.sin(rotate_angle))
       ypos_wc = maxZ + det_r + y * math.sin(rotate_angle) - x * math.cos(rotate_angle)

     # barrel tubes
     else :
       ypos_wc = z;
       theta = math.atan2(y, x)
       xpos_wc = -(theta + rotate_angle)

       if xpos_wc > 3.1415926  : 
         xpos_wc = -3.1415926*2 + xpos_wc
       elif xpos_wc < -3.1415926 :
         xpos_wc = 3.1415926*2 + xpos_wc
       else:
         xpos_wc = xpos_wc 
       xpos_wc *= det_r 

       # print (cable, x,y,z, "WC: " , xpos_wc , ypos_wc , theta)

     WCPMTs[ cable ] = [ xpos_wc , ypos_wc ]

  return WCPMTs




if __name__ == "__main__":
   import sys

   if len(sys.argv) < 2 :
     print( sys.argv[0] , ' [geofile.txt] [evlist] [event]\n' )
     sys.exit()
   #print("==START DEFINE INPUT==") 
   geofile = sys.argv[1]
   #print("==GEOFILE = ", geofile)
   evlist  = sys.argv[2]
   #print("==EVENTFILE ==", evlist)
   event   = int( sys.argv[3] )
   #print("==EVENT NUMBER ==", event)
   
   
   #print("==START READ GEOFILE==")
   minZ, maxZ, r, h, pmt_list = read_geofile( geofile ) 
   #print("==READ GEOFILE DONE==")
   #print()
   #print("==START HitFILE==")
   hit_list = read_hitlist( evlist ) 
   print( minZ, maxZ )
   #print("==HitLIST DONE==")

   drawList = ConvertToWC( pmt_list, minZ, maxZ, r, h )
   X = []
   Y = []
   S = []
   for cable in drawList.keys() :
     X += [ drawList[cable][0] ]
     Y += [ drawList[cable][1] ]
     S += [7] # list of sizes
   hitX = []
   hitY = []
   hitS = []
   hitQ = []
   
   #print(hit_list[0])
   for word in hit_list[event]:
     cable = word[0]
     q     = word[1]
     print(cable, q)
     hitX += [ drawList[cable][0] ]
     hitY += [ drawList[cable][1] ]
     hitS += [7] # list of sizes
     hitQ += [q] # list of sizes
   
   maxhit = read_maxhit(evlist)
   # First plot
   #fig1, axs1 = plt.subplots()
   #axs1.hist(maxhit, bins=20 )
   #axs1.set_xlabel('Value')
   #axs1.set_ylabel('Frequency')
   #axs1.set_title('Histogram of maxhit')
   
   # Second plot
   fig2, axs2 = plt.subplots()
   axs2.scatter(X, Y, S, color='#88c999')
   axs2.scatter(hitX, hitY, hitS, hitQ, cmap='plasma')
   
   # Set figure numbers
   #fig1.number = 1
   fig2.number = 2
   #  fig.suptitle('')

   plt.show()   




