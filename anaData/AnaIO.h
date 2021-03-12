#ifndef _ANAIO_H_
#define _ANAIO_H_

namespace AnaIO
{
  //======================================= tree out =======================================
  double dalphat; 
  double  dphit;
  double  dpt; 
  double  pn; 
  double  iniPimomentum; 
  double  iniPitheta; 
  double  finPimomentum; 
  double  finPitheta; 
  double  finProtonmomentum; 
  double  finProtontheta; 
  double  fin2Pmom; 
  double  maxgammaEnergy;
  int nproton; 
  int nneutron; 
  int nPiZero; 
  int ngamma;
  bool kSignal;
  double recProtonmomentum;
  double recPiPlusmomentum;
  int ndEdxCls;
  double lastE0; 
  double lastE1; 
  double lastE2; 
  double lastE3; 
  double lastE4; 
  double lastE5;
  double startE0; 
  double startE1; 
  double startE2; 
  double startE3; 
  double startE4; 
  double startE5; 
  double startTruncatedMeanE10;
  double startTruncatedMeanE20;
  double startTruncatedMeanE30;
  double startTruncatedMeanE40;
  double startTruncatedMeanE50;
  double lastTruncatedMeanE;
  double chi2;
  double ndof;

  //Int_t           nTrack; 

  //not used, keep in case ->
  //--- beam related
  int beamNdEdx;
  double beamLastE0; 
  double beamLastE1; 
  double beamLastE2; 
  double beamLastE3; 
  double beamLastE4; 
  double beamLastE5;
  double beamStartE0; 
  double beamStartE1; 
  double beamStartE2; 
  double beamStartE3; 
  double beamStartE4; 
  double beamStartE5; 
  double beamLastTME;
  double beamStartTME;
  //<--

  //======================================= tree in =======================================
  //--------------------------------------- anaTruth ---------------------------------------
  vector<double> *true_beam_daughter_startPx=0x0;
  vector<double> *true_beam_daughter_startPy=0x0;
  vector<double> *true_beam_daughter_startPz=0x0;

  vector<int>* true_beam_daughter_PDG = 0x0;
  vector<int>* true_beam_Pi0_decay_PDG;
  vector<int>* true_beam_grand_daughter_PDG;

  vector<int>* true_beam_daughter_ID = 0x0;
  vector<int>* true_beam_Pi0_decay_ID;
  vector<int>* true_beam_grand_daughter_ID;
  vector<int>* reco_daughter_PFP_true_byHits_ID = 0x0;
  vector<int>* reco_daughter_PFP_true_byHits_PDG = 0x0;
  vector<int>* reco_daughter_allTrack_ID = 0x0;

  vector<vector<double> >* reco_daughter_allTrack_calibrated_dEdX_SCE = 0x0;

  vector<double>* reco_daughter_allTrack_Chi2_proton = 0x0;
  vector<int>*    reco_daughter_allTrack_Chi2_ndof = 0x0;

  double true_beam_endPx = -999;
  double true_beam_endPy = -999;
  double true_beam_endPz = -999;

  int true_beam_PDG   = -999;

  //--------------------------------------- anaRec ---------------------------------------

  vector<int>     *reco_daughter_PFP_ID =0x0;
  vector<int>     *reco_daughter_PFP_nHits =0x0;
  vector<double>  *reco_daughter_PFP_trackScore_collection =0x0;
  vector<double>  *reco_daughter_PFP_emScore_collection =0x0;
  vector<double>  *input_michelScore_array =0x0;
  vector<int>     *input_michelNhit_array =0x0;

  vector<int>     *reco_daughter_allShower_ID=0x0;
  vector<double>  *reco_daughter_allShower_dirX=0x0;
  vector<double>  *reco_daughter_allShower_dirY=0x0;
  vector<double>  *reco_daughter_allShower_dirZ=0x0;
  vector<double>  *reco_daughter_allShower_energy=0x0;
  vector<double>  *reco_daughter_allShower_startX = 0x0;
  vector<double>  *reco_daughter_allShower_startY = 0x0;
  vector<double>  *reco_daughter_allShower_startZ = 0x0;
    
  vector<double>* reco_daughter_allTrack_momByRange_proton = 0x0;
  vector<double>* reco_daughter_allTrack_momByRange_muon = 0x0;

  vector<double>* reco_daughter_allTrack_Theta = 0x0;
  vector<double>* reco_daughter_allTrack_Phi = 0x0;

  vector<int>     *data_BI_PDG_candidates=0x0;

  int reco_beam_type = -999;

  Double_t        reco_beam_startX;
  Double_t        reco_beam_startY;
  Double_t        reco_beam_startZ;
  Double_t        reco_beam_trackDirX;
  Double_t        reco_beam_trackDirY;
  Double_t        reco_beam_trackDirZ;
  Double_t        reco_beam_trackEndDirX;
  Double_t        reco_beam_trackEndDirY;
  Double_t        reco_beam_trackEndDirZ;
  //vector<double>  *reco_beam_calo_endDirX;
  //vector<double>  *reco_beam_calo_endDirY;
  //vector<double>  *reco_beam_calo_endDirZ;
  Double_t        true_beam_startX;
  Double_t        true_beam_startY;
  Double_t        true_beam_startZ;
  Double_t        true_beam_startDirX;
  Double_t        true_beam_startDirY;
  Double_t        true_beam_startDirZ;

  Double_t        reco_beam_endX;
  Double_t        reco_beam_endY;
  Double_t        reco_beam_endZ;
  Double_t        reco_beam_interactingEnergy;
  Double_t        true_beam_interactingEnergy;
  //Double_t        new_true_beam_interactingEnergy;

  Double_t        data_BI_X;
  Double_t        data_BI_Y;
  Double_t        data_BI_dirX;
  Double_t        data_BI_dirY;
  Double_t        data_BI_dirZ;
  Int_t           data_BI_nMomenta;
  Int_t           data_BI_nTracks;

  //not used, keep in case ->
  vector<double>  *reco_beam_calibrated_dEdX;
  Double_t        reco_beam_len;
  //<-

  //======================================= Truth Hist out =======================================
  TH1I * hbeamType = 0x0;
  TH1I * hndaughter = 0x0;
  TH1I * hnexcl = 0x0;
  TH2I * hksignp = 0x0;
  TH1I * hselectedDaughterType = 0x0;
  TH1I * hnproton = 0x0;
  TH1I * hnneutron = 0x0;
  TH1I * hnPiZero = 0x0;
  TH1D * hmomIniPi = 0x0;
  TH1D * hmomFinPi = 0x0;
  TH1D * hmomFinProton = 0x0;
  TH1D *hdalphat = 0x0;
  TH1D *hdphit = 0x0;
  TH1D *hdpt = 0x0;
  TH1D *hpn = 0x0;
  
  //======================================= Rec Hist out =======================================
  TH1I * hTruthBeamType = 0x0;
  TH1I * hTruthSignal = 0x0;

  TH1I * hCutBeamID = 0x0;
  TH2D * hCutBeamType = 0x0;
  TH2D * hCutBeamPosPass = 0x0;
  TH2D * hCutBeamEndZ = 0x0;
  TH2D * hCutBeamEndZPass = 0x0;

  TH2D * hBeamThetaRes = 0x0;
  TH2D * hBeamMomentumRes = 0x0;

  TH1I * hRecOtherPDG = 0x0;

  TH2D * hProtonThetaRes = 0x0;
  TH2D * hPiplusThetaRes = 0x0;

  TH2D * hProtonMomentumRes = 0x0;
  TH2D * hPiplusMomentumRes = 0x0;

  TH2D * hRecBeamTheta = 0x0;
  TH2D * hRecBeamMomentum = 0x0;

  TH2D * hRecProtonMomentum = 0x0;
  TH2D * hRecProtonTheta = 0x0;

  TH2D * hRecPiplusMomentum = 0x0;
  TH2D * hRecPiplusTheta = 0x0;

  TH2D * hRecProtonStartE2 = 0x0;
  TH2D * hRecProtonStartE3 = 0x0;
  TH2D * hRecPiplusStartE2 = 0x0;
  TH2D * hRecPiplusStartE3 = 0x0;

  TH2D * hRecProtonLastE2 = 0x0;
  TH2D * hRecProtonLastE3 = 0x0;
  TH2D * hRecPiplusLastE2 = 0x0;
  TH2D * hRecPiplusLastE3 = 0x0;

  TH2D * hRecProtonStartTME = 0x0;
  TH2D * hRecProtonLastTME = 0x0;
  TH2D * hRecPiplusStartTME = 0x0;
  TH2D * hRecPiplusLastTME = 0x0;

  TH2D * hRecPi0Nshower = 0x0;
  TH2D * hRecMpi0 = 0x0;
  TH2D * hRecLDMpi0 = 0x0;
  TH2D * hRecSLMpi0 = 0x0;
  TH2D * hRecShowerEnergy = 0x0;

  TH2D * hCutnHits = 0x0;
  TH2D * hCutNdEdx = 0x0;
  TH2D * hCutstartE2 = 0x0;
  TH2D * hCutstartE3 = 0x0;
  TH2D * hCutlastTME = 0x0;
  TH2D * hCuttrackScore = 0x0;
  TH2D * hCutemScore = 0x0;
  TH2D * hCutShowerTheta = 0x0;
  TH2D * hCutShowerPhi = 0x0;
  TH2D * hRecShowerDirectPhi = 0x0;
  TH2D * hRecShowerDiffTheta = 0x0;
  TH2D * hRecShowerDiffPhi = 0x0;
  TH2D * hCutShowerDist = 0x0;
  TH2D * hCutmichelScore = 0x0;
  TH2D * hCutmichelNhit = 0x0;
  TH2D * hCutmichelPerHitScore = 0x0;
  TH2D * hCutChi2NDF = 0x0;

  TH2D * hCutnproton = 0x0;
  TH2D * hCutnpiplus = 0x0;
  TH2D * hCutnshower = 0x0;
  TH2D * hCutnmichel = 0x0;

  //not used keep in case ->
  TH2D * hBeamNdEdx = 0x0;
  
  TH2D * hBeamStartTME = 0x0;
  TH2D * hBeamLastTME = 0x0;
  
  TH2D * hBeamStartE0 = 0x0;
  TH2D * hBeamStartE1 = 0x0;
  TH2D * hBeamStartE2 = 0x0;
  TH2D * hBeamStartE3 = 0x0;
  TH2D * hBeamStartE4 = 0x0;
  TH2D * hBeamStartE5 = 0x0;
  TH2D * hBeamLastE0 = 0x0;
  TH2D * hBeamLastE1 = 0x0;
  TH2D * hBeamLastE2 = 0x0;
  TH2D * hBeamLastE3 = 0x0;
  TH2D * hBeamLastE4 = 0x0;
  TH2D * hBeamLastE5 = 0x0;
  
  TH2D * hBeamPCStartTME = 0x0;
  TH2D * hBeamPCLastTME = 0x0;
  
  TH2D * hBeamPCStartE0 = 0x0;
  TH2D * hBeamPCStartE1 = 0x0;
  TH2D * hBeamPCStartE2 = 0x0;
  TH2D * hBeamPCStartE3 = 0x0;
  TH2D * hBeamPCStartE4 = 0x0;
  TH2D * hBeamPCStartE5 = 0x0;
  TH2D * hBeamPCLastE0 = 0x0;
  TH2D * hBeamPCLastE1 = 0x0;
  TH2D * hBeamPCLastE2 = 0x0;
  TH2D * hBeamPCLastE3 = 0x0;
  TH2D * hBeamPCLastE4 = 0x0;
  TH2D * hBeamPCLastE5 = 0x0;

  TH2D * hBeamLen = 0x0;
  TH2D * hBeamPCLen = 0x0;
  //<--


//==============================================================================
//==============================================================================

TTree * GetOutputTree(TList * lout, const TString tag)
{
  TTree * tout = new TTree("tree", tag); lout->Add(tout);
 
  //definitely need this to avoid memory-resident Tree
  tout->SetDirectory(0);

  tout->Branch("dalphat",&dalphat);
  tout->Branch("dphit",&dphit);
  tout->Branch("dpt",&dpt);
  tout->Branch("pn",&pn);
  tout->Branch("iniPimomentum",&iniPimomentum);
  tout->Branch("iniPitheta",&iniPitheta);
  tout->Branch("finPimomentum",&finPimomentum);
  tout->Branch("finPitheta",&finPitheta);
  tout->Branch("finProtonmomentum",&finProtonmomentum);
  tout->Branch("recProtonmomentum",&recProtonmomentum);
  tout->Branch("recPiPlusmomentum",&recPiPlusmomentum);
  tout->Branch("finProtontheta",&finProtontheta);
  tout->Branch("fin2Pmom",&fin2Pmom);
  tout->Branch("nproton",&nproton);
  tout->Branch("nneutron",&nneutron);
  tout->Branch("nPiZero",&nPiZero);
  tout->Branch("ngamma",&ngamma);
  tout->Branch("kSignal",&kSignal);
  tout->Branch("ndEdxCls",&ndEdxCls);
  tout->Branch("maxgammaEnergy",&maxgammaEnergy);
  tout->Branch("lastE0",&lastE0);
  tout->Branch("lastE1",&lastE1);
  tout->Branch("lastE2",&lastE2);
  tout->Branch("lastE3",&lastE3);
  tout->Branch("lastE4",&lastE4);
  tout->Branch("lastE5",&lastE5);
  tout->Branch("startE0",&startE0);
  tout->Branch("startE1",&startE1);
  tout->Branch("startE2",&startE2);
  tout->Branch("startE3",&startE3);
  tout->Branch("startE4",&startE4);
  tout->Branch("startE5",&startE5);
  tout->Branch("startTruncatedMeanE10",&startTruncatedMeanE10);
  tout->Branch("startTruncatedMeanE20",&startTruncatedMeanE20);
  tout->Branch("startTruncatedMeanE30",&startTruncatedMeanE30);
  tout->Branch("startTruncatedMeanE40",&startTruncatedMeanE40);
  tout->Branch("startTruncatedMeanE50",&startTruncatedMeanE50);
  tout->Branch("lastTruncatedMeanE",&lastTruncatedMeanE);
  tout->Branch("chi2",&chi2);
  tout->Branch("ndof",&ndof);

  tout->Branch("beamNdEdx",&beamNdEdx);
  tout->Branch("beamLastE0",&beamLastE0);
  tout->Branch("beamLastE1",&beamLastE1);
  tout->Branch("beamLastE2",&beamLastE2);
  tout->Branch("beamLastE3",&beamLastE3);
  tout->Branch("beamLastE4",&beamLastE4);
  tout->Branch("beamLastE5",&beamLastE5);
  tout->Branch("beamStartE0",&beamStartE0);
  tout->Branch("beamStartE1",&beamStartE1);
  tout->Branch("beamStartE2",&beamStartE2);
  tout->Branch("beamStartE3",&beamStartE3);
  tout->Branch("beamStartE4",&beamStartE4);
  tout->Branch("beamStartE5",&beamStartE5);

  tout->Branch("beamStartTME",&beamStartTME);
  tout->Branch("beamLastTME",&beamLastTME);

  //save input info
  tout->Branch("true_beam_PDG",&true_beam_PDG);
  tout->Branch("reco_beam_len",&reco_beam_len);
  //tout->Branch("nTrack",&nTrack);

  return tout;
}

TTree * GetInputTree(TFile * fin, const TString tname)
{
  TTree * tree=(TTree*) fin->Get(tname);
  if(!tree){
    cout<<"no tree!"<<endl;
    gDirectory->ls();
    exit(1);
  }

  //--------------------------------------- anaTruth ---------------------------------------
  tree->SetBranchAddress("true_beam_daughter_startPx", &true_beam_daughter_startPx);
  tree->SetBranchAddress("true_beam_daughter_startPy", &true_beam_daughter_startPy);
  tree->SetBranchAddress("true_beam_daughter_startPz", &true_beam_daughter_startPz);

  tree->SetBranchAddress("true_beam_daughter_PDG", &true_beam_daughter_PDG);
  tree->SetBranchAddress("true_beam_Pi0_decay_PDG", &true_beam_Pi0_decay_PDG);
  tree->SetBranchAddress("true_beam_grand_daughter_PDG", &true_beam_grand_daughter_PDG);
  tree->SetBranchAddress("true_beam_daughter_ID", &true_beam_daughter_ID);
  tree->SetBranchAddress("true_beam_Pi0_decay_ID", &true_beam_Pi0_decay_ID);
  tree->SetBranchAddress("true_beam_grand_daughter_ID", &true_beam_grand_daughter_ID);
  tree->SetBranchAddress("reco_daughter_PFP_true_byHits_ID", &reco_daughter_PFP_true_byHits_ID);
  tree->SetBranchAddress("reco_daughter_PFP_true_byHits_PDG", &reco_daughter_PFP_true_byHits_PDG);
  tree->SetBranchAddress("reco_daughter_allTrack_ID", &reco_daughter_allTrack_ID);

  tree->SetBranchAddress("reco_daughter_allTrack_calibrated_dEdX_SCE", &reco_daughter_allTrack_calibrated_dEdX_SCE);
  tree->SetBranchAddress("reco_daughter_allTrack_Chi2_proton", &reco_daughter_allTrack_Chi2_proton);
  tree->SetBranchAddress("reco_daughter_allTrack_Chi2_ndof", &reco_daughter_allTrack_Chi2_ndof);

  tree->SetBranchAddress("reco_daughter_PFP_ID", &reco_daughter_PFP_ID);
  tree->SetBranchAddress("reco_daughter_PFP_nHits", &reco_daughter_PFP_nHits);
  tree->SetBranchAddress("reco_daughter_PFP_trackScore_collection", &reco_daughter_PFP_trackScore_collection);
  tree->SetBranchAddress("reco_daughter_PFP_emScore_collection", &reco_daughter_PFP_emScore_collection);
  //tree->SetBranchAddress("reco_daughter_PFP_michelScore_collection", &input_michelScore_array);
  tree->SetBranchAddress("reco_daughter_allTrack_vertex_michel_score", &input_michelScore_array);
  tree->SetBranchAddress("reco_daughter_allTrack_vertex_nHits", &input_michelNhit_array);

  tree->SetBranchAddress("reco_daughter_allShower_ID", &reco_daughter_allShower_ID);
  tree->SetBranchAddress("reco_daughter_allShower_dirX", &reco_daughter_allShower_dirX);
  tree->SetBranchAddress("reco_daughter_allShower_dirY", &reco_daughter_allShower_dirY);
  tree->SetBranchAddress("reco_daughter_allShower_dirZ", &reco_daughter_allShower_dirZ);
  tree->SetBranchAddress("reco_daughter_allShower_energy", &reco_daughter_allShower_energy);
  tree->SetBranchAddress("reco_daughter_allShower_startX", &reco_daughter_allShower_startX);
  tree->SetBranchAddress("reco_daughter_allShower_startY", &reco_daughter_allShower_startY);
  tree->SetBranchAddress("reco_daughter_allShower_startZ", &reco_daughter_allShower_startZ);

  tree->SetBranchAddress("reco_daughter_allTrack_momByRange_proton", &reco_daughter_allTrack_momByRange_proton);
  tree->SetBranchAddress("reco_daughter_allTrack_momByRange_muon", &reco_daughter_allTrack_momByRange_muon);

  tree->SetBranchAddress("reco_daughter_allTrack_Theta", &reco_daughter_allTrack_Theta);
  tree->SetBranchAddress("reco_daughter_allTrack_Phi", &reco_daughter_allTrack_Phi);

  tree->SetBranchAddress("true_beam_endPx", &true_beam_endPx);
  tree->SetBranchAddress("true_beam_endPy", &true_beam_endPy);
  tree->SetBranchAddress("true_beam_endPz", &true_beam_endPz);

  tree->SetBranchAddress("true_beam_PDG", &true_beam_PDG);

  //--------------------------------------- anaRec ---------------------------------------
  tree->SetBranchAddress("data_BI_PDG_candidates", &data_BI_PDG_candidates);
  tree->SetBranchAddress("reco_beam_type", &reco_beam_type);

  tree->SetBranchAddress("reco_beam_trackDirX", &reco_beam_trackDirX);
  tree->SetBranchAddress("reco_beam_trackDirY", &reco_beam_trackDirY);
  tree->SetBranchAddress("reco_beam_trackDirZ", &reco_beam_trackDirZ);
  tree->SetBranchAddress("reco_beam_trackEndDirX", &reco_beam_trackEndDirX);
  tree->SetBranchAddress("reco_beam_trackEndDirY", &reco_beam_trackEndDirY);
  tree->SetBranchAddress("reco_beam_trackEndDirZ", &reco_beam_trackEndDirZ);

  //tree->SetBranchAddress("reco_beam_calo_endDirX", &reco_beam_calo_endDirX);
  //tree->SetBranchAddress("reco_beam_calo_endDirY", &reco_beam_calo_endDirY);
  //tree->SetBranchAddress("reco_beam_calo_endDirZ", &reco_beam_calo_endDirZ);
  
  tree->SetBranchAddress("reco_beam_startX", &reco_beam_startX);
  tree->SetBranchAddress("true_beam_startX", &true_beam_startX);
  tree->SetBranchAddress("true_beam_startDirX", &true_beam_startDirX);

  tree->SetBranchAddress("reco_beam_startY", &reco_beam_startY);
  tree->SetBranchAddress("true_beam_startY", &true_beam_startY);
  tree->SetBranchAddress("true_beam_startDirY", &true_beam_startDirY);

  tree->SetBranchAddress("reco_beam_startZ", &reco_beam_startZ);
  tree->SetBranchAddress("true_beam_startZ", &true_beam_startZ);
  tree->SetBranchAddress("true_beam_startDirZ", &true_beam_startDirZ);

  tree->SetBranchAddress("data_BI_X", &data_BI_X);
  tree->SetBranchAddress("data_BI_Y", &data_BI_Y);
  tree->SetBranchAddress("data_BI_dirX", &data_BI_dirX);
  tree->SetBranchAddress("data_BI_dirY", &data_BI_dirY);
  tree->SetBranchAddress("data_BI_dirZ", &data_BI_dirZ);
  tree->SetBranchAddress("data_BI_nMomenta", &data_BI_nMomenta);
  tree->SetBranchAddress("data_BI_nTracks", &data_BI_nTracks);

  tree->SetBranchAddress("reco_beam_endX", &reco_beam_endX);
  tree->SetBranchAddress("reco_beam_endY", &reco_beam_endY);
  tree->SetBranchAddress("reco_beam_endZ", &reco_beam_endZ);
  tree->SetBranchAddress("reco_beam_interactingEnergy", &reco_beam_interactingEnergy);
  tree->SetBranchAddress("true_beam_interactingEnergy", &true_beam_interactingEnergy);
  //tree->SetBranchAddress("new_true_beam_interactingEnergy", &new_true_beam_interactingEnergy);

  //to check the difference with _allTrack_
  tree->SetBranchAddress("reco_beam_len", &reco_beam_len);
  //tree->SetBranchAddress("reco_beam_allTrack_len", &reco_beam_len);
  tree->SetBranchAddress("reco_beam_calibrated_dEdX", &reco_beam_calibrated_dEdX);
  //tree->SetBranchAddress("reco_beam_allTrack_calibrated_dEdX", &reco_beam_calibrated_dEdX);

  return tree;
}

void IniRecHist(TList * lout, const TString tag)
{
  const int nPass = 2;
  const double Passmin = -0.5;
  const double Passmax = 1.5;

  hTruthBeamType = new TH1I("a0TruthBeamType"+tag,  "", 20, -0.5, 19.5); lout->Add(hTruthBeamType);
  hTruthSignal = new TH1I("a1TruthSignal"+tag,  "",  nPass, Passmin, Passmax); lout->Add(hTruthSignal);

  const int nparType = 11;
  const double parTypemin = 0.5;
  const double parTypemax = 11.5;
  
  const int nevtType = 3;
  const double evtTypemin = -0.5;
  const double evtTypemax = 2.5;

  const int nE = 50;
  const double Emin = 0;
  const double lastEmax = 20;
  const double startEmax =5;

  hBeamNdEdx   = new TH2D("b000BeamNdEdxSTKTXT"+tag,"", 50, 0, 100, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamNdEdx);

  hBeamStartE0 = new TH2D("b010BeamStartE0STKTXT"+tag,"", nE, Emin, startEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamStartE0);
  hBeamStartE1 = new TH2D("b010BeamStartE1STKTXT"+tag,"", nE, Emin, startEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamStartE1);
  hBeamStartE2 = new TH2D("b010BeamStartE2STKTXT"+tag,"", nE, Emin, startEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamStartE2);
  hBeamStartE3 = new TH2D("b010BeamStartE3STKTXT"+tag,"", nE, Emin, startEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamStartE3);
  hBeamStartE4 = new TH2D("b010BeamStartE4STKTXT"+tag,"", nE, Emin, startEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamStartE4);
  hBeamStartE5 = new TH2D("b010BeamStartE5STKTXT"+tag,"", nE, Emin, startEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamStartE5);
  hBeamStartTME= new TH2D("b011BeamStartTMESTK"+tag,"",nE*5, 1.2, 4.2, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamStartTME);

  hBeamLastE0  = new TH2D("b012BeamLastE0STKTXT"+tag,"", nE, Emin, lastEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamLastE0);
  hBeamLastE1  = new TH2D("b012BeamLastE1STKTXT"+tag,"", nE, Emin, lastEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamLastE1);
  hBeamLastE2  = new TH2D("b012BeamLastE2STKTXT"+tag,"", nE, Emin, lastEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamLastE2);
  hBeamLastE3  = new TH2D("b012BeamLastE3STKTXT"+tag,"", nE, Emin, lastEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamLastE3);
  hBeamLastE4  = new TH2D("b012BeamLastE4STKTXT"+tag,"", nE, Emin, lastEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamLastE4);
  hBeamLastE5  = new TH2D("b012BeamLastE5STKTXT"+tag,"", nE, Emin, lastEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamLastE5);
  hBeamLastTME = new TH2D("b013BeamLastTMESTK"+tag,"",nE*5, 0, 15, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamLastTME);

  hBeamPCStartE0 = new TH2D("b020BeamPCStartE0STKTXT"+tag,"", nE, Emin, startEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCStartE0);
  hBeamPCStartE1 = new TH2D("b020BeamPCStartE1STKTXT"+tag,"", nE, Emin, startEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCStartE1);
  hBeamPCStartE2 = new TH2D("b020BeamPCStartE2STKTXT"+tag,"", nE, Emin, startEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCStartE2);
  hBeamPCStartE3 = new TH2D("b020BeamPCStartE3STKTXT"+tag,"", nE, Emin, startEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCStartE3);
  hBeamPCStartE4 = new TH2D("b020BeamPCStartE4STKTXT"+tag,"", nE, Emin, startEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCStartE4);
  hBeamPCStartE5 = new TH2D("b020BeamPCStartE5STKTXT"+tag,"", nE, Emin, startEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCStartE5);
  hBeamPCStartTME= new TH2D("b021BeamPCStartTMESTK"+tag,"",nE*5, 1.2, 4.2, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCStartTME);

  hBeamPCLastE0  = new TH2D("b022BeamPCLastE0STKTXT"+tag,"", nE, Emin, lastEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCLastE0);
  hBeamPCLastE1  = new TH2D("b022BeamPCLastE1STKTXT"+tag,"", nE, Emin, lastEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCLastE1);
  hBeamPCLastE2  = new TH2D("b022BeamPCLastE2STKTXT"+tag,"", nE, Emin, lastEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCLastE2);
  hBeamPCLastE3  = new TH2D("b022BeamPCLastE3STKTXT"+tag,"", nE, Emin, lastEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCLastE3);
  hBeamPCLastE4  = new TH2D("b022BeamPCLastE4STKTXT"+tag,"", nE, Emin, lastEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCLastE4);
  hBeamPCLastE5  = new TH2D("b022BeamPCLastE5STKTXT"+tag,"", nE, Emin, lastEmax, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCLastE5);
  hBeamPCLastTME = new TH2D("b023BeamPCLastTMESTK"+tag,"",nE*5, 0, 15, nevtType, evtTypemin, evtTypemax); lout->Add(hBeamPCLastTME);

  //not used
  /*
  //sensitive to pi+ beam, but not to signal -> sensitive to pi+ beam non-signal, i.e. non-interacting
  const int nlen = 10;
  const double lenmin = 0;
  const double lenmax = 250;
  hBeamLen = new TH2D("p9BeamLenNOHPRFPURTXT"+tag,"", nlen, lenmin, lenmax, nPass, Passmin, Passmax); lout->Add(hBeamLen);
  hBeamPCLen = new TH2D("p9BeamPCLenNOHPRFPURTXT"+tag,"", nlen, lenmin, lenmax, nPass, Passmin, Passmax); lout->Add(hBeamPCLen);
  */

  const int nres = 20;
  const double resmin = -1;
  const double resmax = 1;

  const int nbmRes = 20;
  const double bmResmin = -0.5;
  const double bmResmax = 0.5;

  //beam
  const int nbmTheta = 80;
  const double bmThetamin = 0;
  const double bmThetamax = 60;//in deg
  //daughter
  const int ndTheta = 20;
  const double dThetamin = 0;
  const double dThetamax = 180;//in deg

  const int nmomentum = 30;
  const double momentummin = 0;
  const double momentummax = 1.2;

  const int nbmMomentum = 50;
  const double bmMomentummin = 0;
  const double bmMomentummax = 2;

  const int ndedx = 60;
  const double dedxmin = 0;
  const double dedxmax = 30;

  const int nscore = 50;
  const double scoremin = 0;
  const double scoremax = 1;

  const int ncounter = 10;
  const double countermin = -0.5;
  const double countermax = 9.5;

  //NOH, STK are tags for style::Process2DHist

  hBeamThetaRes       = new TH2D("b024BeamThetaResNOHTXT"+tag,"",      nbmTheta, bmThetamin, bmThetamax, 25, -20, 30); lout->Add(hBeamThetaRes);
  hRecBeamTheta       = new TH2D("b025RecBeamThetaSTKTXT"+tag,"",      nbmTheta, bmThetamin, bmThetamax, nevtType, evtTypemin, evtTypemax); lout->Add(hRecBeamTheta);
  hBeamMomentumRes    = new TH2D("b026BeamMomentumResNOHTXT"+tag,"",   nbmMomentum, bmMomentummin, bmMomentummax, nbmRes, bmResmin, bmResmax); lout->Add(hBeamMomentumRes);
  hRecBeamMomentum    = new TH2D("b027RecBeamMomentumSTKTXT"+tag,"",   nbmMomentum, bmMomentummin, bmMomentummax, nevtType, evtTypemin, evtTypemax); lout->Add(hRecBeamMomentum);

  hProtonThetaRes     = new TH2D("b100ProtonThetaResNOHTXT"+tag,"",    ndTheta, dThetamin, dThetamax, 25, -20, 30); lout->Add(hProtonThetaRes);
  hRecProtonTheta     = new TH2D("b101RecProtonThetaSTKTXT"+tag,"",     ndTheta, dThetamin, dThetamax, nparType, parTypemin, parTypemax); lout->Add(hRecProtonTheta);
  hProtonMomentumRes  = new TH2D("b102ProtonMomentumResNOHTXT"+tag,"", nmomentum, momentummin, momentummax, nres, -0.2, 0.2); lout->Add(hProtonMomentumRes);
  hRecProtonMomentum  = new TH2D("b103RecProtonMomentumSTKTXT"+tag,"",  nmomentum, momentummin, momentummax, nparType, parTypemin, parTypemax); lout->Add(hRecProtonMomentum);
  hRecProtonLastE2    = new TH2D("b104RecProtonLastE2STKTXT"+tag,"",     ndedx, dedxmin, dedxmax, nparType, parTypemin, parTypemax); lout->Add(hRecProtonLastE2);
  hRecProtonLastE3    = new TH2D("b104RecProtonLastE3STKTXT"+tag,"",     ndedx, dedxmin, dedxmax, nparType, parTypemin, parTypemax); lout->Add(hRecProtonLastE3);
  hRecProtonLastTME   = new TH2D("b105RecProtonLastTMESTKTXT"+tag,"",     ndedx, dedxmin, dedxmax, nparType, parTypemin, parTypemax); lout->Add(hRecProtonLastTME);
  hRecProtonStartE2   = new TH2D("b106RecProtonStartE2STKTXT"+tag,"",     ndedx, dedxmin, dedxmax, nparType, parTypemin, parTypemax); lout->Add(hRecProtonStartE2);
  hRecProtonStartE3   = new TH2D("b106RecProtonStartE3STKTXT"+tag,"",     ndedx, dedxmin, dedxmax, nparType, parTypemin, parTypemax); lout->Add(hRecProtonStartE3);
  hRecProtonStartTME  = new TH2D("b107RecProtonStartTMESTKTXT"+tag,"",     ndedx, dedxmin, dedxmax, nparType, parTypemin, parTypemax); lout->Add(hRecProtonStartTME);

  hPiplusThetaRes     = new TH2D("b200PiplusThetaResNOHTXT"+tag,"",        ndTheta, dThetamin, dThetamax, 25, -20, 30); lout->Add(hPiplusThetaRes);
  hRecPiplusTheta     = new TH2D("b201RecPiplusThetaSTKTXT"+tag,"",     ndTheta, dThetamin, dThetamax, nparType, parTypemin, parTypemax); lout->Add(hRecPiplusTheta);
  hPiplusMomentumRes  = new TH2D("b202PiplusMomentumResNOHTXT"+tag,"",     nmomentum, momentummin, momentummax, nres, resmin, resmax); lout->Add(hPiplusMomentumRes);
  hRecPiplusMomentum  = new TH2D("b203RecPiplusMomentumSTKTXT"+tag,"",  nmomentum, momentummin, momentummax, nparType, parTypemin, parTypemax); lout->Add(hRecPiplusMomentum);
  hRecPiplusLastE2    = new TH2D("b204RecPiplusLastE2STKTXT"+tag,"",     ndedx, dedxmin, dedxmax/3, nparType, parTypemin, parTypemax); lout->Add(hRecPiplusLastE2);
  hRecPiplusLastE3    = new TH2D("b204RecPiplusLastE3STKTXT"+tag,"",     ndedx, dedxmin, dedxmax/3, nparType, parTypemin, parTypemax); lout->Add(hRecPiplusLastE3);
  hRecPiplusLastTME   = new TH2D("b205RecPiplusLastTMESTKTXT"+tag,"",     ndedx, dedxmin, dedxmax/3, nparType, parTypemin, parTypemax); lout->Add(hRecPiplusLastTME);
  hRecPiplusStartE2   = new TH2D("b206RecPiplusStartE2STKTXT"+tag,"",     ndedx, dedxmin, dedxmax/2, nparType, parTypemin, parTypemax); lout->Add(hRecPiplusStartE2);
  hRecPiplusStartE3   = new TH2D("b206RecPiplusStartE3STKTXT"+tag,"",     ndedx, dedxmin, dedxmax/2, nparType, parTypemin, parTypemax); lout->Add(hRecPiplusStartE3);
  hRecPiplusStartTME  = new TH2D("b207RecPiplusStartTMESTKTXT"+tag,"",     ndedx, dedxmin, dedxmax/2, nparType, parTypemin, parTypemax); lout->Add(hRecPiplusStartTME);

  hRecPi0Nshower      = new TH2D("b300bRecPi0NshowerSTKTXT"+tag,"",      ncounter, countermin, countermax, nevtType, evtTypemin, evtTypemax); lout->Add(hRecPi0Nshower);
  hRecMpi0            = new TH2D("b301RecMpi0STKTXT"+tag,"",             15, 0, 0.3, nevtType, evtTypemin, evtTypemax); lout->Add(hRecMpi0);
  hRecShowerEnergy    = new TH2D("b302RecShowerEnergySTKTXT"+tag,"",     50, 0, 0.5, nparType, parTypemin, parTypemax); lout->Add(hRecShowerEnergy);
  hRecLDMpi0          = new TH2D("b303RecLDMpi0STKTXT"+tag,"",           15, 0, 0.3, nparType, parTypemin, parTypemax); lout->Add(hRecLDMpi0);
  hRecSLMpi0          = new TH2D("b303RecSLMpi0STKTXT"+tag,"",           15, 0, 0.3, nparType, parTypemin, parTypemax); lout->Add(hRecSLMpi0);
  hRecShowerDirectPhi = new TH2D("b304RecShowerDirectPhiSTKTXT"+tag,"",  30, -180, 180, nparType, parTypemin, parTypemax); lout->Add(hRecShowerDirectPhi);
  hRecShowerDiffTheta = new TH2D("b304RecShowerDiffThetaSTKTXT"+tag,"",  30, -90, 90, nparType, parTypemin, parTypemax); lout->Add(hRecShowerDiffTheta);
  hRecShowerDiffPhi   = new TH2D("b304RecShowerDiffPhiSTKTXT"+tag,"",    30, -90, 90, nparType, parTypemin, parTypemax); lout->Add(hRecShowerDiffPhi);

  hRecOtherPDG        = new TH1I("b400RecOtherPDGTXT"+tag,"", 25, -0.5, 24.5); lout->Add(hRecOtherPDG);

  hCutBeamID          = new TH1I("c000CutBeamIDTXT"+tag,"", 2, -0.5, 1.5); lout->Add(hCutBeamID);
  hCutBeamType        = new TH2D("c001CutBeamTypeSTKTXT"+tag,  "", 30, -4.5, 25.5, nevtType, evtTypemin, evtTypemax); lout->Add(hCutBeamType);
  hCutBeamPosPass     = new TH2D("c002CutBeamPosPassSTKTXT"+tag, "", 4, -0.5, 3.5, nevtType, evtTypemin, evtTypemax); lout->Add(hCutBeamPosPass);
  hCutBeamEndZ        = new TH2D("c003CutBeamEndZSTKTXT"+tag,"",50, 0, 500, nevtType, evtTypemin, evtTypemax); lout->Add(hCutBeamEndZ);
  hCutBeamEndZPass    = new TH2D("c004CutBeamEndZPassSTKTXT"+tag,"",4, -0.5, 3.5, nevtType, evtTypemin, evtTypemax); lout->Add(hCutBeamEndZPass);

  hCutNdEdx           = new TH2D("c100CutNdEdxSTKTXT"+tag,"",          50, 0, 50, nparType, parTypemin, parTypemax); lout->Add(hCutNdEdx);
  hCuttrackScore      = new TH2D("c101CuttrackScoreSTKTXT"+tag,"",     nscore, scoremin, scoremax, nparType, parTypemin, parTypemax); lout->Add(hCuttrackScore);
  hCutemScore         = new TH2D("c102CutemScoreSTKTXT"+tag,"",        nscore, scoremin, scoremax, nparType, parTypemin, parTypemax); lout->Add(hCutemScore);
  hCutmichelScore     = new TH2D("c103CutmichelScoreSTKTXT"+tag,"",    nscore, scoremin, scoremax, nparType, parTypemin, parTypemax); lout->Add(hCutmichelScore);
  hCutmichelNhit     = new TH2D("c103CutmichelNhitSTKTXT"+tag,"",      50, 0, 200, nparType, parTypemin, parTypemax); lout->Add(hCutmichelNhit);
  hCutmichelPerHitScore     = new TH2D("c103CutmichelPerHitScoreSTKTXT"+tag,"",    nscore, scoremin, scoremax, nparType, parTypemin, parTypemax); lout->Add(hCutmichelPerHitScore);
  hCutnHits           = new TH2D("c104CutnHitsSTKTXT"+tag,"",          50, 0, 500, nparType, parTypemin, parTypemax); lout->Add(hCutnHits);
  hCutChi2NDF         = new TH2D("c105CutChi2NDFSTKTXT"+tag,"",        30, 0, 500, nparType, parTypemin, parTypemax); lout->Add(hCutChi2NDF);
  hCutstartE2         = new TH2D("c106CutstartE2STKTXT"+tag,"",        ndedx, dedxmin, dedxmax, nparType, parTypemin, parTypemax); lout->Add(hCutstartE2);
  hCutstartE3         = new TH2D("c107CutstartE3STKTXT"+tag,"",        ndedx, dedxmin, dedxmax, nparType, parTypemin, parTypemax); lout->Add(hCutstartE3);
  hCutlastTME         = new TH2D("c108CutlastTMESTKTXT"+tag,"",        ndedx, dedxmin, dedxmax/3, nparType, parTypemin, parTypemax); lout->Add(hCutlastTME);
  hCutShowerTheta     = new TH2D("c109CutShowerThetaSTKTXT"+tag,"",    ndTheta, dThetamin, dThetamax, nparType, parTypemin, parTypemax); lout->Add(hCutShowerTheta);
  hCutShowerPhi       = new TH2D("c109CutShowerPhiSTKTXT"+tag,"",      30, -180, 180, nparType, parTypemin, parTypemax); lout->Add(hCutShowerPhi);
  hCutShowerDist      = new TH2D("c109CutShowerDistSTKTXT"+tag,"",     31, 0, 93, nparType, parTypemin, parTypemax); lout->Add(hCutShowerDist);

  hCutnshower         = new TH2D("c200CutnshowerSTKTXT"+tag,"", ncounter, countermin, countermax, nevtType, evtTypemin, evtTypemax); lout->Add(hCutnshower);
  hCutnmichel         = new TH2D("c201CutnmichelSTKTXT"+tag,"", ncounter, countermin, countermax, nevtType, evtTypemin, evtTypemax); lout->Add(hCutnmichel);
  hCutnpiplus         = new TH2D("c202CutnpiplusSTKTXT"+tag,"",  ncounter, countermin, countermax, nevtType, evtTypemin, evtTypemax); lout->Add(hCutnpiplus);
  hCutnproton         = new TH2D("c203CutnprotonSTKTXT"+tag,"", ncounter, countermin, countermax, nevtType, evtTypemin, evtTypemax); lout->Add(hCutnproton);
}

void IniTruthHist(TList * lout, const TString tag)
{
  hbeamType = new TH1I("h0beamTypeTXT"+tag,  "", 20, -0.5, 19.5); lout->Add(hbeamType);
  hndaughter = new TH1I("h1ndaughterTXT"+tag,"", 50, -0.5, 49.5); lout->Add(hndaughter);
  hnexcl = new TH1I("h2nexclTXT"+tag,"",2, -0.5, 1.5); lout->Add(hnexcl);
  hksignp = new TH2I("h2ksignpTXT"+tag,"",2, -0.5, 1.5, 2, -0.5, 1.5); lout->Add(hksignp);
  hselectedDaughterType = new TH1I("h3selectedDaughterTypeTXT"+tag, "", 21, -0.5, 20.5); lout->Add(hselectedDaughterType);
  hnproton = new TH1I("h4nprotonTXT"+tag,"",11, -0.5, 10.5); lout->Add(hnproton);
  hnneutron = new TH1I("h5nneutronTXT"+tag,"",11, -0.5, 10.5); lout->Add(hnneutron);
  hnPiZero = new TH1I("h6nPiZeroTXT"+tag,"",11, -0.5, 10.5); lout->Add(hnPiZero);
  hmomIniPi = new TH1D("hmomIniPiTXT"+tag,"", 50, 0, 2); lout->Add(hmomIniPi);
  hmomFinPi = new TH1D("hmomFinPiTXT"+tag,"", 50, 0, 2); lout->Add(hmomFinPi);
  hmomFinProton = new TH1D("hmomFinProtonTXT"+tag,"", 50, 0, 2); lout->Add(hmomFinProton);

  const double Ebin[]= {0.000000, 20.000000, 40.000000, 60.000000, 80.000000, 100.000000, 120.000000, 130.000000, 140.000000, 150.000000, 160.000000, 170.000000, 180.000000};
  hdalphat = new TH1D("dalphat","", sizeof(Ebin)/sizeof(double)-1, Ebin); lout->Add(hdalphat);

  const double Fbin[]={0.000000, 2.500000, 5.000000, 7.500000, 10.000000, 12.500000, 15.000000, 17.500000, 20.000000, 22.500000, 25.000000, 27.500000, 30.000000, 35.000000, 40.000000, 45.000000, 50.000000, 55.000000, 60.000000, 70.000000, 85.000000, 105.000000, 130.000000, 180.000000};
  hdphit = new TH1D("dphit","", sizeof(Fbin)/sizeof(double)-1, Fbin); lout->Add(hdphit);

   const double Gbin[]={0.000000, 0.025000, 0.050000, 0.075000, 0.100000, 0.125000, 0.150000, 0.175000, 0.200000, 0.225000, 0.250000, 0.275000, 0.300000, 0.350000, 0.400000, 0.450000, 0.500000, 0.550000, 0.600000, 0.650000, 0.700000, 0.800000, 1.000000, 1.200000, 2.000000};
   hdpt = new TH1D("dpt","", sizeof(Gbin)/sizeof(double)-1, Gbin); lout->Add(hdpt);

   const double Hbin[]={0.000000, 0.025000, 0.050000, 0.075000, 0.100000, 0.125000, 0.150000, 0.175000, 0.200000, 0.225000, 0.250000, 0.275000, 0.300000, 0.350000, 0.400000, 0.450000, 0.500000, 0.550000, 0.600000, 0.650000, 0.700000, 0.800000, 1.000000, 1.200000, 2.000000};
   hpn = new TH1D("pn","", sizeof(Hbin)/sizeof(double)-1, Hbin); lout->Add(hpn);
}

}

#endif
