#include "stdio.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TFile.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TLegend.h"
#include "TLine.h"
#include "TList.h"
#include "TLorentzVector.h"
#include "TSystem.h"
#include "TTree.h"

#include "style.h"
#include "AnaFunctions.h"
#include "AnaIO.h"
#include "AnaUtils.h"
#include "AnaCut.h"

#include <algorithm>    // std::sort
#include <vector>       // std::vector

//if true, use MC signal and bypass all cuts; otherwise full data set will go through cuts
const bool gkOnlySignal = false;

//if true, observables will be filled before cuts; otherwise after. "false" if gkOnlySignal "true": only fill after all cuts
const bool gkFillBefore = false;//(gkOnlySignal?false:true);//

//1 is mc, 2 is data, 3 is both
const int gkDataBit = (gkOnlySignal?1:3);//1;//

//gkFast=true: only png will be save; otherwise eps, pdf, png all saved
const bool gkFast = true;//false;

int anaRec(TString finName, TList *lout, const TString tag, const int nEntryToStop = -999)
{
  //_____________________________________________________ basic settings _____________________________________________________ 
  cout<<"Input file:"<<endl;
  gSystem->Exec(Form("readlink -f %s", finName.Data()));
  cout<<endl;
  
  bool kMC = true;
  if(!finName.Contains("_mc_")){
    kMC = false;
  }

  TFile * fin = new TFile(finName);
  if(!fin->IsOpen()){
    cout<<"fin not open!"<<endl;
    exit(1);
  }

  const bool kPiZero = tag.Contains("MPiZero");
  const bool kTrackingProton = !tag.Contains("TrackingPiPlus");

  cout<<"\n\n                       Running anaRec kMC "<<kMC<<" kPiZero "<<kPiZero<<" TrackingProton "<<kTrackingProton<<endl<<endl;

  //initialise input and output
  TTree * tree = AnaIO::GetInputTree(fin, "pionana/beamana");
  TTree * tout = AnaIO::GetOutputTree(lout, tag);  
  AnaIO::IniRecHist(lout, tag);

  //_____________________________________________________ event loop with cuts _____________________________________________________

  int ientry = 0;
  int selBeamCount = 0;
  while(tree->GetEntry(ientry)){
    if(ientry%100000==0){
      printf("myEntries %d\n", ientry);
    }
    
    if(nEntryToStop>0){
      if(ientry>=nEntryToStop){
        printf("\n\n\n************************  Breaking after %d entries ***********************************************\n\n", nEntryToStop);
        break;
      }
    }

    //do it before the loop continues for any reason
    ientry++;
   
    //====================== Extract truth information ======================

    //calculate before any cuts! Only filled after ALL cuts!
    int TruthBeamType = -999;
    if(kMC){
      TruthBeamType = AnaUtils::GetParticleType(AnaIO::true_beam_PDG);
      AnaUtils::SetFullSignal(kPiZero);
    }
    else{
      AnaIO::kSignal = false;
    }

    //====================== Do cuts ======================
    //just do the plotting to test
    AnaUtils::FillBeamdEdx(true);

    //gkOnlySignal=true: use MC signal and no cuts
    if(gkOnlySignal){
      if(!AnaIO::kSignal){
        continue;
      }
    }
    else{
      if(!AnaCut::CutBeamAllInOne(kMC)){
        continue;
      }
    }
    //count beam after beam cut before other cuts
    selBeamCount++;

    //just do the plotting to test
    AnaUtils::FillBeamdEdx(false);

    //---------- fill beam kinematics ----------
    if(gkFillBefore){
      AnaUtils::FillBeamKinematics(kMC);
    }
    
    //---------- continue cut flow ----------
    if(!gkOnlySignal){  
      if(!AnaCut::CutTopology(kMC, kPiZero, gkFillBefore)){
        continue;
      }   
    }

    //====================== No cuts any more ======================

    //---------- fill beam kinematics ----------
    if(!gkFillBefore){
      AnaUtils::FillBeamKinematics(kMC);
    }
    
    if(kMC){
      AnaIO::hTruthBeamType->Fill(TruthBeamType);
      AnaIO::hTruthSignal->Fill(AnaIO::kSignal);
    }

    //Filling after-selection distributions
    TLorentzVector *dummypi0 = 0x0;
    int dummycounter = -999;
    const bool kprint = false;
    const bool kfill = !gkFillBefore;
    AnaCut::CountPFP(kMC, kPiZero, dummycounter, dummycounter, dummycounter, dummycounter, dummypi0, kprint, kfill);
    
    //--- to test
     /*   
    //x. Beam dEdx cut shadowed by beam filtering
    AnaIO::hBeamLen->Fill(AnaIO::reco_beam_len);
    AnaIO::hSignalVsLen->Fill(AnaIO::reco_beam_len, AnaIO::kSignal);
    if(!cutBeamdEdx(AnaIO::kSignal)){
      continue;
    }

    //Fill kSignal vs variable; the reason for kSignal but not kBeam is the signal is interacting pion, not all pions. Directly choose matrix to optimize for it
    //AnaIO::hSigAfterVsLen->Fill(AnaIO::reco_beam_len, AnaIO::kSignal);
    */

    //====================== end of loop ======================
    
    tout->Fill();
  }

  cout<<"All entries "<<ientry<<endl;

  //_____________________________________________________ Automatically handling histograms and reporting  _____________________________________________________ 
  style::Process2DHist(lout);

  //print cut flow statistics:
  int icut = 0;
  double nsel = -999;
  if(!gkOnlySignal){
    nsel = style::PrintStat(tag+Form(" %d. Beam ID",  icut++), AnaIO::hCutBeamID, 1, 1, ientry);
  }
  nsel = style::PrintStat(tag+Form(" %d. Pandora beam type",  icut++), AnaIO::hCutBeamType, 13, 13, nsel);
  nsel = style::PrintStat(tag+Form(" %d. Beam Pos",  icut++), AnaIO::hCutBeamPosPass, 1, 1, nsel);
  nsel = style::PrintStat(tag+Form(" %d. APA3",  icut++), AnaIO::hCutBeamEndZPass, 1, 1, nsel);
  nsel = style::PrintStat(tag+Form(" %d. Nproton", icut++), AnaIO::hCutnproton, 1, 1, nsel);
  nsel = style::PrintStat(tag+Form(" %d. Nshower",  icut++), AnaIO::hCutnshower, kPiZero?2:0, kPiZero?100000:0, nsel);
  nsel = style::PrintStat(tag+Form(" %d. Npiplus",  icut++), AnaIO::hCutnpiplus, kPiZero?0:1, kPiZero?0:1, nsel);
  nsel = style::PrintStat(tag+Form(" %d. Nmichel",  icut++), AnaIO::hCutnmichel, kPiZero?0:1, kPiZero?0:100, nsel);
  printf("End of %d cuts: %.1f selected\n", icut, nsel);

  if(kMC){
    /*
    //from pionana_mc_1GeV_6_15_20.root
    seeana010.log:kPiZero 0 signal 224.0 all 224.0 purity 100.0%
    seeana110.log:kPiZero 1 signal 246.0 all 246.0 purity 100.0%
    */
    //only valid for pionana_mc_1GeV_6_15_20.root
    //const double nfullsig = kPiZero? 246.0 : 224.0;
    //only valid for pionana_Prod3_mc_1GeV_9_15_20.root
    const double nfullsig = kPiZero? 1594.0 : 1829.0;
    printf("anaData hardcoded number of signal in pionana_Prod3_mc_1GeV_9_15_20.root kPiZero %d %f\n", kPiZero, nfullsig); 

    const double nsig = AnaIO::hTruthSignal->GetBinContent(2);
    const double nbk = AnaIO::hTruthSignal->GetBinContent(1);
    const double nall = nsig+nbk;
    const double purity = nsig/nall;
    const double eff = nsig/nfullsig;
    const double ep = eff*purity;
    printf("kPiZero %d fullsig %.1f signal %.1f all %.1f purity %.1f%% eff %.1f%% ep %.1f%%\n", kPiZero, nfullsig, nsig, nall, purity*100, eff*100, ep*100);
  }

  return selBeamCount; 
}

void anaTruth(TString finName, TList *lout, const TString tag, const int nEntryToStop = -999)
{
  //_____________________________________________________ basic settings _____________________________________________________ 

  if(!finName.Contains("_mc_")){
    printf("anaTruth _mc_ not found in file name! %s\n", finName.Data()); exit(1);
  }

  TFile * fin = new TFile(finName);
  if(!fin->IsOpen()){
    cout<<"fin not open!"<<endl;
    exit(1);
  }

  const bool kPiZero = tag.Contains("MPiZero");
  const bool kTrackingProton = !tag.Contains("TrackingPiPlus");

  cout<<"\n\n                       Running anaTruth kPiZero "<<kPiZero<<" TrackingProton "<<kTrackingProton<<endl<<endl;

  TTree * tree = AnaIO::GetInputTree(fin, "pionana/beamana");
  TTree * tout = AnaIO::GetOutputTree(lout, tag);
  AnaIO::IniTruthHist(lout, tag);

  //_____________________________________________________ loop  _____________________________________________________

  int ientry = 0;
  while(tree->GetEntry(ientry)){
    if(ientry%100000==0){
      printf("myEntries %d\n", ientry);
    }
    
    if(nEntryToStop>0){
      if(ientry>=nEntryToStop){
        printf("\n\n\n************************  Breaking after %d entries ***********************************************\n\n", nEntryToStop);
        break;
      }
    }

    //do it before the loop continues for any reason
    ientry++;
   
    //====================== get signal and save variables  ====================== 

    //---------- beam cut ---------- 
    const int beamtype = AnaUtils::GetParticleType(AnaIO::true_beam_PDG);
    AnaIO::hbeamType->Fill(beamtype);

    if(beamtype!=AnaUtils::gkPiPlus){
      continue;
    }

    const int nd = AnaIO::true_beam_daughter_PDG->size();
    AnaIO::hndaughter->Fill(nd);
    if(nd==0){
      continue;
    }

    //---------- get beam ---------- 
    const TLorentzVector beamFullP(AnaIO::true_beam_endPx, AnaIO::true_beam_endPy, AnaIO::true_beam_endPz, AnaFunctions::PionMass());

    AnaIO::iniPimomentum = beamFullP.P();
    AnaIO::iniPitheta = beamFullP.Theta()*TMath::RadToDeg();

    //---------- get final state ----------
    int  protonIdx = -999, piplusIdx = -999;
    AnaIO::kSignal = false;
    //return piplus, proton, proton
    vector<TLorentzVector> vecPiP = AnaUtils::GetFSTruth(kPiZero, protonIdx, piplusIdx, AnaIO::kSignal);
    AnaIO::hnexcl->Fill(AnaIO::kSignal);

    AnaIO::finPimomentum = vecPiP[0].P();
    AnaIO::finProtonmomentum = vecPiP[1].P();
    AnaIO::fin2Pmom = vecPiP[2].P();

    //---------- calculate TKI only for signal ----------
    if(AnaIO::kSignal){
      AnaIO::hnproton->Fill(AnaIO::nproton);
      AnaIO::hnneutron->Fill(AnaIO::nneutron);
      AnaIO::hnPiZero->Fill(AnaIO::nPiZero);
      
      //re-calculate final pi p theta w.r.t. iniPi
      const int targetA = 40;
      const int targetZ = 18;
      AnaFunctions::getCommonTKI(targetA, targetZ, &beamFullP, &(vecPiP[0]), &(vecPiP[1]), AnaIO::dalphat, AnaIO::dphit, AnaIO::dpt, AnaIO::pn, AnaIO::finPitheta, AnaIO::finProtontheta);
      
      AnaIO::hmomIniPi->Fill(AnaIO::iniPimomentum);
      AnaIO::hmomFinPi->Fill(AnaIO::finPimomentum);
      AnaIO::hmomFinProton->Fill(AnaIO::finProtonmomentum);
      AnaIO::hdalphat->Fill(AnaIO::dalphat);
      AnaIO::hdphit->Fill(AnaIO::dphit);
      AnaIO::hdpt->Fill(AnaIO::dpt);
      AnaIO::hpn->Fill(AnaIO::pn);
    }

    //---------- get truth-matched reconstructed momentum ---------- 
    vector<double>* mombyrange = 0x0;
    double * recmomentum = 0x0;
    int recidx = -999;
    if(kTrackingProton){
      recidx = protonIdx;
      mombyrange = AnaIO::reco_daughter_allTrack_momByRange_proton;
      recmomentum = &AnaIO::recProtonmomentum;
    }
    else{
      recidx = piplusIdx;
      mombyrange = AnaIO::reco_daughter_allTrack_momByRange_muon;
      recmomentum = &AnaIO::recPiPlusmomentum;
    }

    const bool kDoTracking = (recidx>=0);
    AnaIO::hksignp->Fill(kDoTracking, AnaIO::kSignal);
 
    //has true proton
    if(kDoTracking){
      (*recmomentum) = AnaUtils::GetRecFromTruth(recidx, mombyrange);
      tout->Fill();
    }

    //====================== end of loop ======================
  }

  cout<<"All entries "<<ientry<<endl;

}

int main(int argc, char * argv[])
{
  if(argc!=4){
    cout<<"argc!=4 !"<<argc<<endl;
    cout<<"Print legend instead!"<<endl;
    AnaUtils::PrintLegend();
    return 0;
  }

  //_____________________________________________________ basic settings _____________________________________________________ 

  gSystem->Load("libTree");

  style::SetGlobalStyle();

  const bool kPiZero = atoi(argv[1]);
  const bool kProton = atoi(argv[2]);
  if(kPiZero&&!kProton){
    return 0;
  }
  const bool kTruth = atoi(argv[3]);
  if(!kTruth&&!kProton){
    return 0;
  }

  TString tag = (kPiZero?"MPiZero":"1PiPlus");
  tag+=(kProton?"_TrackingProton":"_TrackingPiPlus");
  tag+=(kTruth?"_anaTruth":"_anaRec");

  TList * mclout = 0x0;
  TList * datalout = 0x0;

  if(gkDataBit & 1){
    mclout = new TList;
  }
  if(gkDataBit & 2){
    datalout = new TList;
  }

  double mcBeamCount = -999;
  double dataBeamCount = -999;

  //_____________________________________________________ Run truth only study or MC/data selection  _____________________________________________________

  const TString mcfinName = "input/protoDUNE_mc_reco_flattree.root";

  if(kTruth){
    anaTruth(mcfinName, mclout, tag);
  }
  else{
    if(mclout){
      mcBeamCount = anaRec(mcfinName, mclout, tag);
    }

    if(datalout){
      const TString datafinName = "input/protoDUNE_data_reco_flattree.root";
      dataBeamCount = anaRec(datafinName, datalout, tag);
    }
  }

  //_____________________________________________________ Draw and save  _____________________________________________________

  //normalise MC plots to Data by beam count ratio
  const double plotscale = dataBeamCount/mcBeamCount;

  printf("anaRec beamcount data: %.0f mc: %.0f plotscale %f\n", dataBeamCount, mcBeamCount, plotscale);

  if(mclout){
    if(datalout){
      //overlay MC and data
      style::DrawHist(mclout, plotscale, datalout, "output", tag, gkFast);
    }
    else{
      //MC plots only
      style::DrawHist(mclout, 1, 0x0, "output", tag, gkFast);
    }
  }
  else if(datalout){
    //data plots only
    style::DrawHist(datalout, 1, 0x0, "output", tag, gkFast);
  }

  TFile * fout = new TFile(Form("output/outanaData_%s.root", tag.Data()),"recreate");
  if(mclout){
    TDirectory * ld = gDirectory->mkdir("mc");
    ld->cd();
    mclout->Write();
    gDirectory->cd("../");
  }
  if(datalout){
    TDirectory * ld = gDirectory->mkdir("data");
    ld->cd();
    datalout->Write();
  }

  fout->Save();
  fout->Close();

  return 0;
}
