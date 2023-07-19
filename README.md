=====This is detector simulation work for Spallation Neutron Source (SNS) US-Japan project=====  
Our target is to evaluate the detector performance with different photon coverage (pc), size, and materials.  
This code can be found at   
https://github.com/indigo40123/WCSim_USJapan  

=====This repository modified the "src/WCSimDetectorConfigs.cc" from the official WCSim code=====  
Official WCSim code can be found at  
https://github.com/WCSim/WCSim  

We set a diameter 3 meter x height 2-meter cylinder detector with 3-inch PMT, filled with pure water as a preliminary setting.  
The code is compiled at the WCSim_build/WCSim_dev as the main directory  
The SNS_Example.mac includes the input particle setting.  
Example Usage :  ./bin/WCSim SNS_Example.mac  
This would output wcsim.root (PMT output data) and geofile.txt (PMT distribution)  


=====The files are organized as follows=====  
output : These files include the different pc setting, which varies from 7.5, 15, 30, 60, 78.  
output/Uni_78pc/Uni_data : WCSim output data  
output/Uni_78pc/Uni_macfile : The mac files that produced WCSim output data.  
output/Uni_78pc/Uni_evtlist : PMT hit event list, PMT id, and hit numbers  

=====/analysis read_PMT.C : The code to read WCSim output file=====  
Usage:  
(1) source compile.sh (Compile the code or run it with ROOT execute mode)  
(2) ./read_PMT input_file (Run the code, I prefer to compile the code)                                  
e.g. ./read_PMT ../output/Uni_78pc/Uni_data/sns_78pc_gamma_10MeV_Uni.root  
(3) Output files include a .pdf and evtlist file, which record PMT info.  
e.g. output files are test_canvas.pdf and Test.txt  

=====/analysis/Python/Event_display.py : Plot out the PMT distribution=====  
require input file geofile.txt that generates from WCSim  
Usage:  
python Event_display.py geofile.txt  
e.g. python Event_display.py ../../geofile.txt  

=====/analysis/Python/ghetto_event_display.py : Plot the PMT distribution and PMT hits=====  
input (1) geofile.txt generates from WCSim  
input (2) Test.txt generates from read_PMT  
input (3) display event number  
e.g. python ghetto_event_display.py ../../geofile.txt Test.txt 10  

=====Vertex Resconstruction (WCSim-Bonsai)======  
/WCSim_build/WCSim_dev/hk-BONSAI-1.2.1.tar.gz : Original WCSim bonsai code
 source /WCSim_build/WCSim_dev/this_wcsim.sh : Please source your compiled WCSim 
 source /WCSim_build/WCSim_dev/hk-BONSAI-1.2.1env_sukap.sh : Define the path for WCSIMDIR and BONSAIDIR

./WCSim_build/WCSim_dev/hk-BONSAI-1.2.1/rootbonsai : load necessary library within ROOT
.x ../sample-root-scripts/sample_bonsai.C : execute the bonsai fitting sample code

WCSim_build/WCSim_dev/hk-BONSAI-1.2.1/data/likelihood_binary : Probability Density Functions for T-TOF.
To make WCSim bonsai load the designed PDF, Rename one of them as like.bin and place at WCSim_build/WCSim_dev/hk-BONSAI-1.2.1/data/ 


#Last Update 2023. July 18th by LiCheng FENG  
Please contact LiCheng if you have any further questions  
feng.licheng.67p@st.u-kyoto.ac.jp  
