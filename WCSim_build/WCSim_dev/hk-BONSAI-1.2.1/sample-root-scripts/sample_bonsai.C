//C++
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//ROOT
#include <TH1F.h>
#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TSystem.h>
#include <TMath.h>
#include <TStyle.h>

#if !defined(__CINT__) || defined(__MAKECINT__)
//WCSim
#include "WCSimRootEvent.hh"
#include "WCSimRootGeom.hh"
//BONSAI
#include "WCSimBonsai.hh"
#endif

// Simple example of reading a generated Root file
int sample_bonsai(TString filename="../wcsim.root", bool verbose=false)
{
  // Clear global scope
  //gROOT->Reset();
  /*
    gStyle->SetOptStat(0);
    gStyle->SetCanvasColor(0);
    gStyle->SetTitleColor(1);
    gStyle->SetStatColor(0);
    gStyle->SetFrameFillColor(0);
    gStyle->SetPadColor(0);
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetTitleSize(0.04);
    gStyle->SetCanvasBorderMode(0);
    gStyle->SetFrameBorderMode(0);
    gStyle->SetFrameLineWidth(2);
    gStyle->SetPadBorderMode(0);
    gStyle->SetPalette(1);
    gStyle->SetTitleAlign(23);
    gStyle->SetTitleX(.5);
    gStyle->SetTitleY(0.99);
    gStyle->SetTitleBorderSize(0);
    gStyle->SetTitleFillColor(0);
    gStyle->SetHatchesLineWidth(2);
    gStyle->SetLineWidth(1.5);
    gStyle->SetTitleFontSize(0.07);
    gStyle->SetLabelSize(0.05,"X");
    gStyle->SetLabelSize(0.05,"Y");
    gStyle->SetTitleSize(0.04,"X");
    gStyle->SetTitleSize(0.04,"Y");
    gStyle->SetTitleBorderSize(0);
    gStyle->SetCanvasBorderMode(0);
  */
  gStyle->SetOptStat(1);
  
#if !defined(__MAKECINT__)
  // Load the library with class dictionary info
  // (create with "gmake shared")
  char* wcsimdirenv;
  wcsimdirenv = getenv ("WCSIMDIR");
  if(wcsimdirenv !=  NULL){
    gSystem->Load("${WCSIMDIR}/libWCSimRoot.so");
  }else{
    gSystem->Load("../libWCSimRoot.so");
  }
  char* bonsaidirenv;
  bonsaidirenv = getenv ("BONSAIDIR");
  if(bonsaidirenv !=  NULL){
    gSystem->Load("${BONSAIDIR}/libWCSimBonsai.so");
  }else{
    gSystem->Load("../libWCSimBonsai.so");
  }
#endif

  WCSimBonsai* bonsai = new WCSimBonsai();
  
  // Open the file
  TFile *file = new TFile(filename.Data(),"read");
  if (!file->IsOpen()){
    std::cout << "Error, could not open input file: " << filename << std::endl;
    return -1;
  }

  // Get a pointer to the tree from the file
  TTree *tree = (TTree*)file->Get("wcsimT");

  // Get the number of events
  int nevent = tree->GetEntries();
  if(verbose) printf("nevent %d\n",nevent);
  
  // Create a WCSimRootEvent to put stuff from the tree in
  WCSimRootEvent* wcsimrootsuperevent = new WCSimRootEvent();

  // Set the branch address for reading from the tree
  TBranch *branch = tree->GetBranch("wcsimrootevent");
  branch->SetAddress(&wcsimrootsuperevent);
  
  // Force deletion to prevent memory leak 
  tree->GetBranch("wcsimrootevent")->SetAutoDelete(kTRUE);
  
  
  // Geometry tree - only need 1 "event"
  TTree *geotree = (TTree*)file->Get("wcsimGeoT");
  WCSimRootGeom *geo = 0; 
  geotree->SetBranchAddress("wcsimrootgeom", &geo);
  if(verbose) std::cout << "Geotree has " << geotree->GetEntries() << " entries" << std::endl;
  if (geotree->GetEntries() == 0) {
    exit(9);
  }
  geotree->GetEntry(0);
  bonsai->Init(geo);

  // start with the main "subevent", as it contains most of the info
  // and always exists.
  WCSimRootTrigger* wcsimrootevent;

  TH1F *h1 = new TH1F("hPMTHits", "PMT Hits;N PMT hits;Number in bin", 200, 0, 200);
  //true
  TH1F *hTrueX = new TH1F("hTrueX", "True X;True X (cm);Number in bin", 200, -4000, 4000);
  TH1F *hTrueY = new TH1F("hTrueY", "True Y;True Y (cm);Number in bin", 200, -4000, 4000);
  TH1F *hTrueZ = new TH1F("hTrueZ", "True Z;True Z (cm);Number in bin", 200, -3000, 3000);
  TH1F *hTrueT = new TH1F("hTrueT", "True T;True T (ns);Number in bin", 200, -1500, 1500);
  TH1F *hTrueR = new TH1F("hTrueR", "True R;True R = X^{2} + Y^{2} (cm);Number in bin", 100, 0, 4000);
  //recon
  TH1F *hRecoX = new TH1F("hRecoX", "Reconstructed X;Reconstructed X (cm);Number in bin", 200, -4000, 4000);
  TH1F *hRecoY = new TH1F("hRecoY", "Reconstructed Y;Reconstructed Y (cm);Number in bin", 200, -4000, 4000);
  TH1F *hRecoZ = new TH1F("hRecoZ", "Reconstructed Z;Reconstructed Z (cm);Number in bin", 200, -3000, 3000);
  TH1F *hRecoT = new TH1F("hRecoT", "Reconstructed T;Reconstructed T (ns);Number in bin", 200, -1500, 1500);
  TH1F *hRecoR = new TH1F("hRecoR", "Reconstructed R;Reconstructed R = X^{2} + Y^{2} (cm);Number in bin", 100, 0, 4000);
  //resolution
  TH1F *hResoX = new TH1F("hResoX", "Resolution X;(True - Reconstructed) X (cm);Number in bin", 50, -1000, 1000);
  TH1F *hResoY = new TH1F("hResoY", "Resolution Y;(True - Reconstructed) Y (cm);Number in bin", 50, -1000, 1000);
  TH1F *hResoZ = new TH1F("hResoZ", "Resolution Z;(True - Reconstructed) Z (cm);Number in bin", 50, -1000, 1000);
  TH1F *hResoT = new TH1F("hResoT", "Resolution T;(True - Reconstructed) T (ns);Number in bin", 200, -1500, 1500);
  TH1F *hResoR = new TH1F("hResoR", "Resolution R;(True - Reconstructed) R = X^{2} + Y^{2} (cm);Number in bin", 25, 0, 1000);
  //goodness
  TH1F *bsgy = new TH1F("Bonsai Goodness", "Bonsai Goodness", 200, -1500, 1500);

  // Now loop over events
  for (int ev=0; ev<nevent; ev++)
    {
      // Read the event from the tree into the WCSimRootEvent instance
      tree->GetEntry(ev);      
      wcsimrootevent = wcsimrootsuperevent->GetTrigger(0);
      if(verbose){
	printf("********************************************************");
	printf("Evt, date %d %ld\n", wcsimrootevent->GetHeader()->GetEvtNum(),
	       wcsimrootevent->GetHeader()->GetDate());
	printf("Mode %d\n", wcsimrootevent->GetMode());
	printf("Number of subevents %d\n",
	       wcsimrootsuperevent->GetNumberOfSubEvents());
	
	printf("Vtxvol %d\n", wcsimrootevent->GetVtxvol());
	printf("Vtx %f %f %f\n", wcsimrootevent->GetVtx(0),
	       wcsimrootevent->GetVtx(1),wcsimrootevent->GetVtx(2));
      }
      double trueX = wcsimrootevent->GetVtx(0);
      double trueY = wcsimrootevent->GetVtx(1);
      double trueZ = wcsimrootevent->GetVtx(2);
      double trueT = wcsimrootevent->GetHeader()->GetDate();
      double trueR = TMath::Sqrt(trueX * trueX + trueY * trueY);
      hTrueX->Fill(trueX);
      hTrueY->Fill(trueY);
      hTrueZ->Fill(trueZ);
      hTrueT->Fill(trueT);
      hTrueR->Fill(trueR);
      
      if(verbose){
	printf("Jmu %d\n", wcsimrootevent->GetJmu());
	printf("Npar %d\n", wcsimrootevent->GetNpar());
	printf("Ntrack %d\n", wcsimrootevent->GetNtrack());
      }
      // Now read the tracks in the event
      
      // Get the number of tracks
      int ntrack = wcsimrootevent->GetNtrack();
      if(verbose) printf("ntracks=%d\n",ntrack);
      
      int i;
      // Loop through elements in the TClonesArray of WCSimTracks
      for (i=0; i<ntrack; i++)
	{
	  TObject *element = (wcsimrootevent->GetTracks())->At(i);
	  
	  WCSimRootTrack *wcsimroottrack = dynamic_cast<WCSimRootTrack*>(element);
	  
	  if(verbose){
	    printf("Track ipnu: %d\n",wcsimroottrack->GetIpnu());
	    printf("Track parent ID: %d\n",wcsimroottrack->GetParenttype());
	    
	    for (int j=0; j<3; j++)
	      printf("Track dir: %d %f\n",j, wcsimroottrack->GetDir(j));
	  }
	  
	  
	}  // End of loop over tracks
      
      // Now look at the Cherenkov hits

      // Get the number of Cherenkov hits.
      // Note... this is *NOT* the number of photons that hit tubes.
      // It is the number of tubes hit with Cherenkov photons.
      // The number of digitized tubes will be smaller because of the threshold.
      // Each hit "raw" tube has several photon hits.  The times are recorded.
      // See chapter 5 of doc/DetectorDocumentation.pdf in the WCSim repository
      // for more information on the structure of the root file.
      //  
      // The following code prints out the hit times for the first 10 tubes and also
      // adds up the total pe.
      // 
      // For digitized info (one time/charge tube after a trigger) use
      // the digitized information.
      //
      
      int ncherenkovhits     = wcsimrootevent->GetNcherenkovhits();
      int ncherenkovdigihits = wcsimrootevent->GetNcherenkovdigihits(); 
      
      h1->Fill(ncherenkovdigihits);
      if(verbose){
	printf("node id: %i\n", ev);
	printf("Ncherenkovhits %d\n",     ncherenkovhits);
	printf("Ncherenkovdigihits %d\n", ncherenkovdigihits);
	std::cout << "RAW HITS:" << std::endl;
      }

      // Grab the big arrays of times and parent IDs
      TClonesArray *timeArray = wcsimrootevent->GetCherenkovHitTimes();
      
      int totalPe = 0;
      // Loop through elements in the TClonesArray of WCSimRootCherenkovHits
      for (i=0; i< ncherenkovhits; i++)
	{
	  TObject *Hit = (wcsimrootevent->GetCherenkovHits())->At(i);
	  WCSimRootCherenkovHit *wcsimrootcherenkovhit = 
	    dynamic_cast<WCSimRootCherenkovHit*>(Hit);
	  
	  int tubeNumber     = wcsimrootcherenkovhit->GetTubeID();
	  int timeArrayIndex = wcsimrootcherenkovhit->GetTotalPe(0);
	  int peForTube      = wcsimrootcherenkovhit->GetTotalPe(1);
	  WCSimRootPMT pmt   = geo->GetPMT(tubeNumber-1);
	  totalPe += peForTube;
	  
	  
	  if ( i < 10 ) // Only print first XX=10 tubes
	    {
	      if(verbose) printf("Total pe: %d times( ",peForTube);
	      for (int j = timeArrayIndex; j < timeArrayIndex + peForTube; j++)
		{
		  WCSimRootCherenkovHitTime * HitTime = 
		    dynamic_cast<WCSimRootCherenkovHitTime*>(timeArray->At(j));
		  
		  if(verbose) printf("%6.2f ", HitTime->GetTruetime() );	     
		}
	      if(verbose) std::cout << ")" << std::endl;
	    }
	  
	} // End of loop over Cherenkov hits
      if(verbose) std::cout << "Total Pe : " << totalPe << std::endl;
      
      // Look at digitized hit info
      
      // Get the number of digitized hits
      // Loop over sub events
      float bsT[500],bsQ[500];
      float bsvertex[4],bsresult[6];
      float bsgood[3];
      int bsCAB[500];
      int bsnhit[1]; //nsel (SLE)
      int bsnsel[2]; //nsel (SLE)
      if(verbose) std::cout << "DIGITIZED HITS:" << std::endl;
      for (int index = 0 ; index < wcsimrootsuperevent->GetNumberOfEvents(); index++) 
	{
	  wcsimrootevent = wcsimrootsuperevent->GetTrigger(index);
	  if(verbose) std::cout << "Sub event number = " << index << "\n";
	  
	  int ncherenkovdigihits = wcsimrootevent->GetNcherenkovdigihits();
	  if(verbose) printf("Ncherenkovdigihits %d\n", ncherenkovdigihits);
	  
	  //for (i=0;i<(ncherenkovdigihits>4 ? 4 : ncherenkovdigihits);i++){
	  bsnhit[0] = ncherenkovdigihits;
	  for (i=0;i<ncherenkovdigihits;i++) // this will crash for high-E events, where ncherenkovdigihits > 500
	    {
	      // Loop through elements in the TClonesArray of WCSimRootCherenkovDigHits
	      
	      TObject *element = (wcsimrootevent->GetCherenkovDigiHits())->At(i);
	      
	      WCSimRootCherenkovDigiHit *wcsimrootcherenkovdigihit = 
		dynamic_cast<WCSimRootCherenkovDigiHit*>(element);
	      
	      bsT[i]=wcsimrootcherenkovdigihit->GetT();
	      bsQ[i]=wcsimrootcherenkovdigihit->GetQ();
	      bsCAB[i]=wcsimrootcherenkovdigihit->GetTubeId();
	      
	      if(verbose){
		if ( i < 10 ) // Only print first XX=10 tubes
		  printf("q, t, tubeid: %f %f %d \n",wcsimrootcherenkovdigihit->GetQ(),
			 wcsimrootcherenkovdigihit->GetT(),wcsimrootcherenkovdigihit->GetTubeId());
	      }
	    } // End of loop over Cherenkov digihits

	  //Fit the trigger using BONSAI
	  if (bonsai->BonsaiFit( bsvertex, bsresult, bsgood, bsnsel, bsnhit, bsCAB, bsT, bsQ) != 0) {
	  
	    //only fill these histograms if BONSAI succeeded
	    double recoX = bsvertex[0];
	    double recoY = bsvertex[1];
	    double recoZ = bsvertex[2];
	    double recoT = bsvertex[3];
	    double recoR = TMath::Sqrt(recoX * recoX + recoY * recoY);

	    //fill reco
	    hRecoX->Fill(recoX);
	    hRecoY->Fill(recoY);
	    hRecoZ->Fill(recoZ);
	    hRecoT->Fill(recoT);
	    hRecoR->Fill(recoR);

	    //fill resolution
	    hResoX->Fill(trueX - recoX);
	    hResoY->Fill(trueY - recoY);
	    hResoZ->Fill(trueZ - recoZ);
	    hResoT->Fill(trueT - recoT);
	    hResoR->Fill(TMath::Sqrt(TMath::Power(trueX - recoX, 2) + TMath::Power(trueY - recoY, 2)));

	    bsgy->Fill(bsgood[2]);
	  }
	} // End of loop over trigger
      
      // reinitialize super event between loops.
      wcsimrootsuperevent->ReInitialize();
      
    } // End of loop over events
  //  TCanvas c1("c1"); 
  float win_scale = 0.75;
  int n_wide(2);
  int n_high(2);
  TCanvas* canv = new TCanvas("c1", "True", 500*n_wide*win_scale, 500*n_high*win_scale);
  filename.ReplaceAll(".root", ".pdf");
  canv->SaveAs(TString::Format("%s[", filename.Data()));
  canv->Draw();
  canv->Divide(2,2);
  canv->cd(1); hTrueX->Draw();
  canv->cd(2); hTrueY->Draw();
  canv->cd(3); hTrueZ->Draw();
  canv->cd(4); hTrueR->Draw();
  canv->SaveAs(filename.Data());
  canv = new TCanvas("c2", "Reconstructed", 500*n_wide*win_scale, 500*n_high*win_scale);
  canv->Divide(2,2);
  canv->cd(1); hRecoX->Draw();
  canv->cd(2); hRecoY->Draw();
  canv->cd(3); hRecoZ->Draw();
  canv->cd(4); hRecoR->Draw();
  canv->SaveAs(filename.Data());
  canv = new TCanvas("c3", "Resolution", 500*n_wide*win_scale, 500*n_high*win_scale);
  canv->Divide(2,2);
  canv->cd(1); hResoX->Draw();
  canv->cd(2); hResoY->Draw();
  canv->cd(3); hResoZ->Draw();
  canv->cd(4); hResoR->Draw();
  canv->SaveAs(filename.Data());
  canv->SaveAs(TString::Format("%s]", filename.Data()));

  return 0;
}
