#include <stdio.h>     
#include <stdlib.h>    
#include <iostream>

#include "TSystem.h"
#include "TFile.h"
#include "TTree.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TF1.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TProfile.h"
#include "TCanvas.h"
#include <TMath.h>

#include "WCSimRootEvent.hh"
#include <fstream>
#include <string>

using namespace std;

struct Result{
      double Peak[18] = {0.};
      double RMS[18] = {0.};
      double Escape[18] = {0.};
  };

Result nHit_PMT(const char *filename, int num = 0);

int main( int argc , const char * argv[] )
{
  if( argc < 2 ) 
  {
     cout << argv[0] << "[wcsim.root]" << endl;
  }
  int dumpHitTubes = 0; 
  if (argc > 2 )  dumpHitTubes = 0; 
  
  Result result_out;
  Result result_tmp;
  for (int i = 1; i<argc; i++) 
  {
     result_tmp = nHit_PMT( argv[i], i );
     result_out.Peak[i] =  result_tmp.Peak[i];
     result_out.RMS[i]  =  result_tmp.RMS[i];
     result_out.Escape[i] = result_tmp.Escape[i];
     cout<<"=====Processing "<<i<<" th input file"<<endl;
  }

  cout<<"RMS: [";
  for (int i = 1; i<argc; i++)
  {
      cout<<result_out.RMS[i];
      if (i < argc - 1) {
          std::cout << ",";	      
      }
  }
  std::cout << "]" << std::endl;

  cout<<"Peak: [";
  for (int i = 1; i<argc; i++)
  {
      cout<<result_out.Peak[i];
      if (i < argc - 1) {
          std::cout << ",";
      }
  }
  std::cout << "]" << std::endl;

  cout<<"Escape: [";
  for (int i = 1; i<argc; i++)
  {
      cout<<result_out.Escape[i];
      if (i < argc - 1) {
          std::cout << ",";
      }
  }
  std::cout << "]" << std::endl;

  return 0;
}



Result nHit_PMT(const char *filename="../wcsim.root", int num) {
  Result result;  
  gROOT->Reset();
  gStyle->SetOptStat(1);

  TFile *f = new TFile(filename);
  if (!f->IsOpen()){
    cout << "Error, could not open input file: " << filename << endl;
    return result;
  }

  TTree  *wcsimT = 0;
  f->GetObject("wcsimT", wcsimT);
  WCSimRootEvent *wcsimrootsuperevent = new WCSimRootEvent();
  wcsimT->SetBranchAddress("wcsimrootevent",&wcsimrootsuperevent);
  wcsimT->GetBranch("wcsimrootevent")->SetAutoDelete(kTRUE);
  wcsimT->GetEvent(0); 

  WCSimRootTrigger *wcsimrootevent = wcsimrootsuperevent->GetTrigger(0);

  TH1D *nHits = new TH1D("nHits","hit PMTs per trigger", 400, 0, 400 );
  TH1D *nHits_no0 = new TH1D("nHits_no0","hit PMTs per trigger", 999, 1, 1000 );

  double hit_false = 0.;
  double hit_true = 0.;
  for( unsigned k = 0  ; k < wcsimT->GetEntries() ; k++ )
  {
     wcsimT->GetEntry(k);
     wcsimrootevent = wcsimrootsuperevent->GetTrigger(0);
     int max = wcsimrootevent->GetNcherenkovhits();
     nHits->Fill( max );
     if (max != 0) nHits_no0->Fill( max );
     if (max != 0) hit_true++;
     if (max == 0) hit_false++;

  }// end loop on entries

  Int_t maxBin = nHits_no0->GetMaximumBin();
  Double_t maxPeak = nHits_no0->GetBinCenter(maxBin);
  Double_t rms = nHits_no0->GetRMS();
  
  result.Escape[num] = hit_false;
  result.Peak[num] = maxPeak;
  result.RMS[num]  = rms;
  
  return result;

}
