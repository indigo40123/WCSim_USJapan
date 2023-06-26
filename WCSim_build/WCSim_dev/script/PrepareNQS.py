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
pc_range = [1,2,3,4,5,6,7,8,9,10,15,20,25,30,35,40,45,50]
for mode in ["fhc"]:
    subfile = "nqs_list_"
    fsub = open(subfile, 'w')
    #change channel name from 1) numu_x_numu, 2) numu_x_nue, 
    #3) numubar_x_numubar, 4) numubar_x_nuebar, 5) nue_x_nue, 6) nuebar_x_nuebar
    for n in pc_range:
       num = "{0:02d}".format(n)
       scriptdir = expandvars("/disk02/usr7/licheng/smsimulator5.5/work/sim_tm1510/script/nqs")
       scriptname = "_".join(["nqs_MeV", num]) + ".sh"
       scriptname = join(scriptdir, scriptname)
       fscript = open(scriptname, 'w')
       fscript.write("#!/bin/bash\n")
       fscript.write("#\n")
       fscript.write("# Batch mode using NQS\n")
       fscript.write("#\n")
       fscript.write("\n")
       fscript.write("cd /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/setup\n")
       fscript.write("source env_sukap.sh\n")
       fscript.write("#cd /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev\n")
       fscript.write("#cp SNS_Example.mac script/MacFiles/SNS_" + num + "_MeV.mac\n")
       fscript.write("#sed -i 's@/gps/energy 10 MeV@/gps/energy " +num+ " MeV@' script/MacFiles/SNS_"+ num +"_MeV.mac\n")

       fscript.write("bin/WCSim script/MacFiles/SNS_" + num + "_MeV.mac\n")
       #fscript.write("cd /disk02/usr7/licheng/smsimulator5.5/work/sim_tm1510/script/output\n")
       #fscript.write("../../root/Analysis/CANATA_ANALYSIS Test"+ num +"_0000.root Test"+ num +"_0000_secinfo.root\n")
       fscript.write("\n")
       fscript.close()
       os.chmod(scriptname, permission)
       log = expandvars("/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/script/log" + "/SNS_") + num + "_MeV.log"
       fsub.write("pjsub -X -L rscgrp=lowe -o " + log + " " + scriptname + "\n")
    fsub.close()
cmd = "chmod 751 %s" % (subfile)
os.system(cmd)
print("Finish......")

