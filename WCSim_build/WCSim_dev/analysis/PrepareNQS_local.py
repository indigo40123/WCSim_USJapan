#!/usr/bin/env python3.6
# use ProcessNCEL_mc.sh

import os
import sys
import stat
from os.path import expandvars, join
from glob import glob
from collections import defaultdict
from optparse import OptionParser

permission = stat.S_IRWXU | stat.S_IRGRP | stat.S_IXGRP
pc = ['60']
E_ga = ['01', '2_2', '04', '06', '08', '10', '15', '20', '25', '30', '35', '40', '45','50']
#pc = ['8', '15', '30', '60', '78']
#E_ga = ['01', '2_2', '4', '6', '8', '10', '15', '20', '25', '30', '35', '40', '45','50']

subfile = "nqs_list_local"
fsub = open(subfile, 'w')
for Pc in pc:
    fsub.write("echo 'Strat" + Pc + " pc' \n")
    for n in E_ga:
       #num = "{0:03d}".format(n)
       fsub.write("./nHit_PMT ../Uni_"+ Pc +"pc/Uni_data/sns_"+Pc+"pc_gamma_"+ n +"MeV_Uni.root\n")
fsub.close()
cmd = "chmod 751 %s" % (subfile)
os.system(cmd)
print("Finish......")

