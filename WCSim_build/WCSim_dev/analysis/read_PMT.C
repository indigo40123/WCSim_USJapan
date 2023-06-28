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

using namespace std;
int read_PMT(const char *filename, int dumpHitTubes);

int main( int argc , const char * argv[] )
{
  if( argc < 2 ) 
  {
     cout << argv[0] << "[wcsim.root]" << endl;
  }
  int dumpHitTubes = 0; 
  if (argc > 2 )  dumpHitTubes = 1; 
 
  read_PMT( argv[1], dumpHitTubes );
  return 0;
}

int read_PMT(const char *filename="../wcsim.root", int dumpHitTubes = 1) {
  /* A simple script to plot aspects of phototube hits 
   * This code is rather cavalier; I should be checking return values, etc.
   * First revision 6-24-10 David Webber
   * 
   * I like to run this macro as 
   * $ root -l -x 'read_PMT.C("../wcsim.root")'
   */
  ofstream outFile("../Uni_evtlist/Test.txt");
  gROOT->Reset();
  gStyle->SetOptStat(1);

  std::cout<<"Input file: "<<filename<<std::endl;
  TFile *f = new TFile(filename);
  if (!f->IsOpen()){
    cout << "Error, could not open input file: " << filename << endl;
    return -1;
  }

  TTree  *wcsimT = 0;
  f->GetObject("wcsimT", wcsimT);

  WCSimRootEvent *wcsimrootsuperevent = new WCSimRootEvent();
  wcsimT->SetBranchAddress("wcsimrootevent",&wcsimrootsuperevent);

  // Force deletion to prevent memory leak when issuing multiple
  // calls to GetEvent()
  wcsimT->GetBranch("wcsimrootevent")->SetAutoDelete(kTRUE);
  wcsimT->GetEvent(0); 

  // Currently only looks at one subevent.  I suspect you could loop over more subevents, if they existed.
  WCSimRootTrigger *wcsimrootevent = wcsimrootsuperevent->GetTrigger(0);

  //--------------------------
  // As you can see, there are lots of ways to get the number of hits.
  cout << "Number of tube hits " << wcsimrootevent->GetNumTubesHit() << endl;
  cout << "Number of Cherenkov tube hits " << wcsimrootevent->GetNcherenkovhits() << endl;
  cout << "Number of Cherenkov tube hits " << wcsimrootevent->GetCherenkovHits()->GetEntries() << endl;

  cout << "Number of digitized tube hits " << wcsimrootevent->GetNumDigiTubesHit() << endl;
  cout << "Number of digitized Cherenkov tube hits " << wcsimrootevent->GetNcherenkovdigihits() << endl;
  cout << "Number of digitized Cherenkov tube hits " << wcsimrootevent->GetCherenkovDigiHits()->GetEntries() << endl;
  cout << "Number of photoelectron hit times " << wcsimrootevent->GetCherenkovHitTimes()->GetEntries() << endl;

  //-----------------------

  TH1D *PE = new TH1D("PEmult","Photoelectron multiplicty", 16,-0.5,15.5);
  PE->SetXTitle("Photoelectrons");

  TH1D *PMT_hits = new TH1D("PMT_hits","Hits vs PMT detector number", 120000,-0.5,120000-0.5);
  TH1D *nHits = new TH1D("nHits","hit PMTs per trigger", 298, 0, 300 );
  TH1D *nHits_no0 = new TH1D("nHits_no0","hit PMTs per trigger", 298, 2, 300 );
  TH2D *QvsT = new TH2D("QvsT","charge vs. time", 40, 900, 1400, 40, -0.5, 15.5);
  QvsT->SetXTitle("time");
  QvsT->SetYTitle("charge");

  int hit_false = 0;
  int hit_true = 0;
  for( unsigned k = 0  ; k < wcsimT->GetEntries() ; k++ )
  {
     wcsimT->GetEntry(k);
     wcsimrootevent = wcsimrootsuperevent->GetTrigger(0);
     int max = wcsimrootevent->GetNcherenkovhits();
     nHits->Fill( max );
     // outFile << max << endl;
     if (max != 0) nHits_no0->Fill( max );
     if (max != 0) hit_true++;
     if (max == 0) hit_false++;

     if ( dumpHitTubes == 1 ) outFile << "Event " << k << " nHit " << max ;

     for (int i = 0; i<max; i++)
     {
       TObject * element = wcsimrootevent->GetCherenkovHits()->At(i);
       if(!element)  continue;
        WCSimRootCherenkovHit *chit = dynamic_cast<WCSimRootCherenkovHit*>(element);
        PMT_hits->Fill(chit->GetTubeID());
        //WCSimRootCherenkovHit has methods GetTubeId(), GetTotalPe(int)
        PE->Fill(chit->GetTotalPe(1));
        if (dumpHitTubes == 1) outFile << " " << chit->GetTubeID() << " " << chit->GetTotalPe(1) ;
     }
     if (dumpHitTubes == 1) outFile << endl;

  //----------------------------

  max = wcsimrootevent->GetNcherenkovdigihits_slots();
  for (int i = 0; i<max; i++)
  {
    TObject* element = wcsimrootevent->GetCherenkovDigiHits()->At(i);
    if(!element)  continue;
    WCSimRootCherenkovDigiHit *cDigiHit = dynamic_cast<WCSimRootCherenkovDigiHit*>(element);
    if(!cDigiHit) continue;
    //WCSimRootChernkovDigiHit has methods GetTubeId(), GetT(), GetQ()
    QvsT->Fill(cDigiHit->GetT(), cDigiHit->GetQ());
    //WCSimRootCherenkovHitTime *cHitTime = wcsimrootevent->GetCherenkovHitTimes()->At(i); // this should loop over wcsimrootevent->GetCherenkovHitTimes()!
    //WCSimRootCherenkovHitTime has methods GetTubeId(), GetTruetime()
  }
 }// end loop on entries

  cout<<"Hit: "<< hit_true <<endl;
  cout<<"NoHit: "<< hit_false <<endl;
  TF1 *gaussian = new TF1("gaussian", "gaus");

  double fitRangeMin = 70.;
  double fitRangeMax = 200.;
  gaussian->SetParLimits(1, fitRangeMin, fitRangeMax);  // Constrain mean parameter within the fit range

  Int_t maxBin = nHits_no0->GetMaximumBin();
  Double_t maxPeak = nHits_no0->GetBinCenter(maxBin);
  Double_t rms = nHits_no0->GetRMS();
  std::cout<<"===== MaxPeak: "<<maxPeak<<std::endl;
  std::cout<<"===== RMS: "<<rms<<std::endl;
  outFile.close();
   
  TH1 *temp;
  TProfile * temp_profile;
  float win_scale=0.75;
  int n_wide=3;
  int n_high=2;
  TCanvas *c1 = new TCanvas("c1","c1",700*n_wide*win_scale,500*n_high*win_scale);
  c1->Divide(n_wide,n_high);
  c1->cd(1);
  QvsT->Draw("colz");

  c1->cd(2);
  temp=QvsT->ProjectionY();
  temp->SetTitle("charge");
  temp->Draw();
  c1->GetPad(2)->SetLogy();

  c1->cd(3);
  temp=QvsT->ProjectionX();
  temp->SetTitle("hits vs time");
  temp->Draw();
  c1->GetPad(3)->SetLogy();

  c1->cd(4);
  temp_profile=QvsT->ProfileX();
  temp_profile->SetTitle("average charge vs time");
  temp_profile->Draw();

  c1->cd(5);
  temp=PE;
  temp->Draw();
  c1->GetPad(5)->SetLogy();

  c1->cd(6);
  nHits_no0->GetYaxis()->SetRangeUser(1e-1, 1e2);
  nHits_no0->Fit(gaussian);
  nHits->SetLineColor(kBlue);
  nHits->SetStats(kFALSE);
  nHits->Draw("same");
  c1->GetPad(6)->SetLogy();
  
  c1->SaveAs("test_canvas.pdf");
  
  return 0;

}
