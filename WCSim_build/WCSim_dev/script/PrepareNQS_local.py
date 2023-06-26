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

for mode in ["fhc"]:
    subfile = "nqs_list_local"
    fsub = open(subfile, 'w')
    #change channel name from 1) numu_x_numu, 2) numu_x_nue, 
    #3) numubar_x_numubar, 4) numubar_x_nuebar, 5) nue_x_nue, 6) nuebar_x_nuebar
    for n in range(200):
       num = "{0:03d}".format(n)
       fsub.write("../../root/Analysis/CANATA_ANALYSIS Test"+ num +"_0000.root Test"+ num +"_0000_secinfo.root\n")
    fsub.close()
cmd = "chmod 751 %s" % (subfile)
os.system(cmd)
print("Finish......")

