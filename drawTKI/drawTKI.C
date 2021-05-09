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

TString setX(const TString var, const bool kPiZero, int &nbin, double &xmin, double &xmax, double &lxoff)
{
  //
  //define plotting elements
  //lxoff is legend x coordinate offset
  //

  TString vn;
  lxoff = 0;
  const double xr = 0.5;
  const TString sfinpi = Form("#pi^{%s}", kPiZero?"0":"+");
  const TString prefix = "p"+sfinpi+"-";

  if(var=="dalphat"){
    nbin = 18;
    xmin = 0;
    xmax = 180;
    vn="#delta#alpha_{T} (degree)";
  }
  else if(var=="dphit"){
    nbin = 18;
    xmin = 0; 
    xmax = 180;
    vn="#delta#phi_{T} (degree)";
    lxoff = xr;
  }
  else if(var=="dpt"){
    nbin = 30;
    xmin = 0;
    xmax = 1.2;
    vn="#delta#it{p}_{T} (GeV/#it{c})";
    lxoff = xr;
  }
  else if(var=="IApN"){
    nbin = 30;
    xmin = 0; 
    xmax = 1.2;
    vn="#it{p}_{N}^{IA} (GeV/#it{c})";
    lxoff = xr;
  }
  else if(var=="recoilP"){
    nbin = 30;
    xmin = 0; 
    xmax = 1.2;
    vn="#it{p}_{N}^{full} (GeV/#it{c})";
    lxoff = xr;
  }
  else if(var=="iniPimomentum"){
    nbin = 30;
    xmin = 0;
    xmax = 1.3;
    vn="#it{p}_{#pi^{+}}^{in} (GeV/#it{c})";
  }
  else if(var=="finPimomentum"){
    nbin = 20;
    xmin = 0;
    xmax = 1.1;
    vn="#it{p}_{"+sfinpi+"} (GeV/#it{c})";
    lxoff = xr;
  }
  else if(var=="finProtonmomentum"){
    nbin = 30;
    xmin = 0;
    xmax = 1.5;
    vn="#it{p}_{p} (GeV/#it{c})";
    lxoff = xr;
  }
  else if(var=="iniPitheta"){
    nbin = 30;
    xmin = 0;
    xmax = 30;
    vn="#theta_{#pi^{+}}^{in, lab} (degree)";
  }
  else if(var=="finPitheta"){
    nbin = 20;
    xmin = 0;
    xmax = 180;
    vn="#theta_{"+sfinpi+"} (degree)";
    lxoff = xr;
  }
  else if(var=="finProtontheta"){
    nbin = 20;
    xmin = 0;
    xmax = 180;
    vn="#theta_{p} (degree)";
    lxoff = xr;
  }
  else if(var=="fin2Pmom"){
    nbin = 30;
    xmin = 0;
    xmax = 1.5;
    vn="#it{p}_{p}^{subleading} (GeV/#it{c})";
    lxoff = xr;
  }
  else if(var=="deltaBeamP"){
    nbin = 30;
    xmin = -1;
    xmax = 0.2;
    vn="(Calc.- Meas.)_{#it{p}_{#pi^{+}}^{in}} (GeV/#it{c})";
  }
  else if(var=="recoilM"){
    nbin = 30;
    xmin = 36.2;
    xmax = 37.2;
    vn="M_{A'} (GeV)";
    lxoff = xr;
  }
  else{
    cout<<"setX unknown var! "<<var<<endl;
    exit(1);
  }

  return prefix+vn;
}

TString getUnit(const TString tit)
{
  const TString unit = tit(tit.First("(")+1,tit.Length());
  return unit(0, unit.First(")"));
}

void drawTKI(const TString var, TList *lout, const TString pretag, const bool kPScut, const bool kSLcut, const double ppthres, const bool kBeamPcut = false)
{
  //_____________________________________________________ basic settings _____________________________________________________ 

  const bool kPiZero = pretag.Contains("MPiZero");
  cout<<"\n\n                       Running kPiZero "<<kPiZero<<endl<<endl;
 
  TTree * tree = (TTree*)gDirectory->Get("mc/tree");
  if(!tree){
    cout<<"no tree!"<<endl;
    exit(1);
  }

  //_____________________________________________________ define plotting elements and cuts _____________________________________________________

  //====================== all plotting stuff ====================== 
  int nbin=-999;
  double xmin=-999, xmax=-999, lxoff=-999;
  const TString vn = setX(var, kPiZero, nbin, xmin, xmax, lxoff);
  const TString xunit = getUnit(vn);

  printf("var %s vn %s nbin %d xmin %f xmax %f\n", var.Data(), vn.Data(), nbin, xmin, xmax);

  THStack * stk = new THStack("s"+var,var); lout->Add(stk);
  TLegend * lg = new TLegend(lxoff+0.15, 0.5, lxoff+0.5, 0.88);
  style::ResetStyle(lg);

  //need system color
  //const int col[]={kGray, kRed, kBlue, kOrange, kGreen+3};
  const int col[]={kOrange,  1014, 1011, 1007,  kOrange, 1009, kOrange, 1003, 1008, 1002, kRed, kBlue, kGray, kOrange, kGreen+3, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009};
  const TString tag = Form("%s_%s_ppthres%.0fPScut%dSLcut%dbeamPcut%d", var.Data(), pretag.Data(), ppthres*1E3, kPScut, kSLcut, kBeamPcut);

  //====================== define cuts for topology decomposition to form a stack ======================

  vector<TString> cuts;//need to match cns
  cuts.push_back("1");
  cuts.push_back("nproton==1 && nneutron==0");
  cuts.push_back("nproton!=1 && nneutron==0");
  cuts.push_back("nproton==1 && nneutron!=0");
  cuts.push_back("nproton!=1 && nneutron!=0");

  const TString PScut = Form("&& (finProtonmomentum > %f && finProtonmomentum < 1)", ppthres);
  //no phase cut for pi+, need to investigate using Michel electron
  /*
  if(!kPiZero){
    PScut += "&& (finPimomentum > 0.15)";
  }
  */
  const TString SLcut = Form("&& (fin2Pmom < %f)", ppthres);
  vector<TString> cns;
  cns.push_back("all");
  cns.push_back("1p0n");
  cns.push_back("Np0n");
  cns.push_back("1pMn");
  cns.push_back("NpMn");

  const TString beamPcut = "&& deltaBeamP > -0.04";
  //_____________________________________________________ draw each cut and add non-all to stack  _____________________________________________________

  double ntotall = -999;
  for(unsigned int ii=0; ii<cuts.size(); ii++){
    const TString ntmp="h"+tag+cns[ii];
    TH1D * htmp = new TH1D(ntmp, ntmp, nbin, xmin, xmax); lout->Add(htmp);
    style::ResetStyle(htmp);
    htmp->SetXTitle(vn);
    htmp->SetYTitle("Events/"+xunit);
    htmp->SetTitle("");

    const TString darg = var+">>"+ntmp;
    TString dcut = "kSignal && "+cuts[ii];
    if(kPScut){
      dcut += PScut;
    }
    if(kSLcut){
      dcut += SLcut;
    }
    if(kBeamPcut){
      dcut += beamPcut;
    }

    const int nev = tree->Draw(darg, dcut);
    //print out drawing detail
    printf("ntmp %s ii %d darg %s cut: \"%s\" nev: %d underflow %f overflow %f integral %f\n", ntmp.Data(), ii, darg.Data(), dcut.Data(), nev, htmp->GetBinContent(0), htmp->GetBinContent(nbin+1), htmp->Integral(0, 1000));

    htmp->Scale(1,"width");
    if(cns[ii]!="all"){
      htmp->SetFillColor(style::GetColor(col[ii]));
      stk->Add(htmp);
      lg->AddEntry(htmp, cns[ii], "f");
    }
    else{
      ntotall = htmp->Integral(0,1000,"width");
    }
  }

  //_____________________________________________________ detailed drawing _____________________________________________________

  TCanvas * c1=new TCanvas("c1","", 600, 400);
  style::PadSetup(c1);
  gPad->SetTopMargin(0.07);
  gPad->SetRightMargin(0.03);
  gPad->SetBottomMargin(0.15);
  gStyle->SetOptTitle(1);

  style::ResetStyle(stk);
  stk->Draw();
  stk->GetXaxis()->SetTitle(vn);
  stk->GetYaxis()->SetTitle("Event/"+xunit);
  stk->SetTitle(Form("Total %.0f events", ntotall));
  stk->SetMinimum(0);
  stk->Draw("hist");

  TString lheader("full phase space");
  if(kPScut){
    lheader = Form("%.2f<#it{p}_{p}<1", ppthres);
    /*
    if(!kPiZero){
      lheader += ", #it{p}_{#pi^{+}}>0.15";
    }
    */
  }
  if(kSLcut){
    lheader += Form(", #it{p}_{p}^{s.l.}<%.2f", ppthres);
  }
  if(kBeamPcut){
    lheader.Prepend("#splitline{");
    lheader += "}{(calc.-meas.)_{P_{beam}}> #minus0.04}";
  }
  lg->SetHeader(lheader);
  lg->Draw();

  TString ptag = tag;
  ptag.ReplaceAll("_TrackingProton","");
  c1->Print("output/"+ptag+".png");
  c1->Print("output/"+ptag+".eps");
  c1->Print("output/"+ptag+".pdf");
}

int main(int argc, char* argv[])
{
  //_____________________________________________________ basic settings _____________________________________________________ 

  if(argc!=2){
    cout<<"argc!=2 !"<<argc<<endl;
    return 0;
  }

  gSystem->Load("libTree");

  style::SetGlobalStyle();

  const bool kPiZero = atoi(argv[1]);
  const TString tag = kPiZero?"MPiZero":"1PiPlus";

  TList * lout= new TList;

  //_____________________________________________________ draw MC signal distributions  _____________________________________________________

  TFile *fin = new TFile(Form("../anaData/output/outanaData_%s_TrackingProton_anaTruth.root", tag.Data()));
  if(!fin->IsOpen()){
    cout<<"fin not open!"<<endl;
    exit(1);
  }

  //draw different observables one by one
  const TString vars[]={"dalphat","dphit","dpt","IApN", "recoilP", "iniPimomentum", "finPimomentum", "finProtonmomentum", "iniPitheta", "finPitheta", "finProtontheta", "fin2Pmom", "deltaBeamP", "recoilM"};
  for(unsigned int ii=0; ii<sizeof(vars)/sizeof(TString); ii++){
    //void drawTKI(const TString var, TList *lout, const TString pretag, const bool kPScut, const bool kSLcut, const double ppthres)
    //draw different phase space cuts

    //0.45 -> 100 MeV K.E.
    drawTKI(vars[ii], lout, tag,  0, 0, 0.45);
    drawTKI(vars[ii], lout, tag,  0, 0, 0.45, 1);
    drawTKI(vars[ii], lout, tag,  1, 0, 0.45);
    drawTKI(vars[ii], lout, tag,  1, 1, 0.45);
    drawTKI(vars[ii], lout, tag,  1, 1, 0.45, 1);
    //0.25 -> 30 MeV K.E.
    drawTKI(vars[ii], lout, tag,  1, 0, 0.25);
    drawTKI(vars[ii], lout, tag,  1, 1, 0.25);
  }

  //_____________________________________________________ saving _____________________________________________________

  TFile * fout= new TFile(Form("output/outdrawTKI_%s.root", tag.Data()),"recreate");
  lout->Write();
  fout->Save();
  fout->Close();

  return 0;
}
