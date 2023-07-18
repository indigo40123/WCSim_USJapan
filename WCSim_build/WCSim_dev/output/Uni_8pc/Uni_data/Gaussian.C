#include <iostream>
#include <string>
#include "TFile.h"
#include "TH1.h"
#include "TF1.h"

int Gaussian() {

  std::string filenames[] = {
    "sns_8pc_gamma_1MeV_ISO_analyzed.root",
    "sns_8pc_gamma_2MeV_ISO_analyzed.root",
    "sns_8pc_gamma_3MeV_ISO_analyzed.root",
    "sns_8pc_gamma_4MeV_ISO_analyzed.root",
    "sns_8pc_gamma_5MeV_ISO_analyzed.root",
    "sns_8pc_gamma_6MeV_ISO_analyzed.root",
    "sns_8pc_gamma_7MeV_ISO_analyzed.root",
    "sns_8pc_gamma_8MeV_ISO_analyzed.root",
    "sns_8pc_gamma_9MeV_ISO_analyzed.root",
    "sns_8pc_gamma_10MeV_ISO_analyzed.root",
    "sns_8pc_gamma_15MeV_ISO_analyzed.root",
    "sns_8pc_gamma_20MeV_ISO_analyzed.root",
    "sns_8pc_gamma_25MeV_ISO_analyzed.root",
    "sns_8pc_gamma_30MeV_ISO_analyzed.root",
    "sns_8pc_gamma_35MeV_ISO_analyzed.root",
    "sns_8pc_gamma_40MeV_ISO_analyzed.root",
    "sns_8pc_gamma_45MeV_ISO_analyzed.root",
    "sns_8pc_gamma_50MeV_ISO_analyzed.root"
  };

  const int numFiles = sizeof(filenames) / sizeof(filenames[0]);  

  double stdev[20] = {};
  // Create a Gaussian function
  TF1* gaussian = new TF1("gaussian", "gaus");


  for (int i = 0; i < numFiles; i++) {
    // Open the ROOT file
    TFile* file = TFile::Open(filenames[i].c_str());
    // Get the histograms
    TH1F* hResoX = (TH1F*)file->Get("hResoX");
    TH1F* hResoY = (TH1F*)file->Get("hResoY");
    TH1F* hResoZ = (TH1F*)file->Get("hResoZ");

    // Fit hResoX
    hResoX->Fit(gaussian, "Q"); // "Q" option for quiet mode
    double meanX = gaussian->GetParameter(1);
    double sigmaX = gaussian->GetParameter(2);

    // Fit hResoY
    hResoY->Fit(gaussian, "Q");
    double meanY = gaussian->GetParameter(1);
    double sigmaY = gaussian->GetParameter(2);

    // Fit hResoZ
    hResoZ->Fit(gaussian, "Q");
    double meanZ = gaussian->GetParameter(1);
    double sigmaZ = gaussian->GetParameter(2);

    // Calculate the average of the fitted parameters
    double avgMean = sqrt(meanX*meanX + meanY*meanY + meanZ*meanZ);
    double avgSigma = (sigmaX + sigmaY + sigmaZ) / 3.0;

    // Print the results
    std::cout << "Mean: " << meanX <<" "<< meanY <<" " <<meanZ <<" "<< avgMean << std::endl;
    std::cout << "Sigma: " << sigmaX<< " "<< sigmaY<< " "<< sigmaZ<< " "<<avgSigma << std::endl;
    stdev[i] = avgSigma;
 }

 std::cout<<"PC8_std = [";
 for (int i = 0; i < numFiles; i++) {
    std::cout<<stdev[i];
    if (i != numFiles-1) std::cout<<",";
 }
 std::cout<<"]"<<std::endl;

 return 0;
}

int main() {
  Gaussian();
  return 0;
}

