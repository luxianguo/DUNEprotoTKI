#ifndef _ANAUTILS_H_
#define _ANAUTILS_H_

using namespace std;

namespace AnaUtils
{

enum evtType{
             gkSignal = 0,
             gkEvtBkg,
             gkBmBkg
};
  
enum parType{

  //1-4
  gkProton=1,
  gkPiPlus,
  gkPiMinus,
  gkGamma,
  //gkEplusEminus,
  //gkMuon,

  //5-10
  gkSecondaryProton,
  gkSecondaryPiPlus,
  gkSecondaryPiMinus,
  gkSecondaryGamma,
  gkSecondaryEplusEminus,
  gkSecondaryMuon,

  //11
  gkOthers,

  //12-17
  gkNeutron,
  gkPiZero,
  gkElectron,
  gkPositron,
  gkMuPlus,
  gkMuMinus,

  //18
  gkKaon,

  //19
  gkNeutrino,

  //20
  gkHyperon,

  //21
  gkNucleus,

  //22
  gkNoTruth
};


int GetFillEventType()
{
  int filleventtype = -999;
  if(AnaIO::kSignal){
    filleventtype = gkSignal;
  }
  else if(AnaIO::true_beam_PDG==211){
    filleventtype = gkEvtBkg;
  }
  else{
    filleventtype = gkBmBkg;
  }
  
  return filleventtype;
}

double GetChi2NDF(const int ii)
{
  const double chi2       = (*AnaIO::reco_daughter_allTrack_Chi2_proton)[ii];
  const double ndof       = (*AnaIO::reco_daughter_allTrack_Chi2_ndof)[ii];

  const double chnf = chi2/(ndof+1E-10);

  //printf("testtest %f %f %f\n", chi2, ndof, chnf); exit(1);

  return chnf;
}

TVector3 GetRecBeamFull()
{
  const int version = -1;

  static bool kprint = false;

  if(!kprint){
    printf("AnaUtils::GetRecBeamFull using version %d\n", version);
    kprint = true;
  }

  TVector3 beamdir;

  if(version==-1){
    beamdir.SetXYZ(AnaIO::reco_beam_trackEndDirX, 
                           AnaIO::reco_beam_trackEndDirY, 
                           AnaIO::reco_beam_trackEndDirZ );
  }
  else{
    /*
    const int dirsize = AnaIO::reco_beam_calo_endDirX->size();
    printf("testtest %d\n", dirsize); exit(1);
    */
    //size = 4, [version]
    /*
      The direction variables are vectors with a few calculations of direction:
      [0] first element: unit vector between first and end points
      [1] second element: unit vector between first 2 points (start direction) and last 2 points (end direction)
      [2] third element: unit vector from 3D line fit of first/last 3 points (start/end direction)
      [3] fourth element: unit vector from 3D line fit of first/last 4 points (start/end direction)
     */

    printf("AnaUtils::GetRecBeamFull *calo* should not be used anymore\n\n"); exit(1);
    /*
    if(!AnaIO::reco_beam_calo_endDirX){
      printf("AnaIO::reco_beam_calo_endDirX null!\n"); exit(1);
    }
    
    beamdir.SetXYZ((*AnaIO::reco_beam_calo_endDirX)[version], 
                           (*AnaIO::reco_beam_calo_endDirY)[version], 
                           (*AnaIO::reco_beam_calo_endDirZ)[version] );
    */
  }

  double ke = AnaIO::reco_beam_interactingEnergy/1E3;//tested, endP highly consistent with AnaIO::true_beam_interactingEnergy/1E3;//
  if(ke<0){
    printf("AnaUtils::GetRecBeamFull ke<0 %f\n", ke); //exit(1);
    ke = 1E-10;
  }

  const double mpi = AnaFunctions::PionMass();
  const double pionEndP = TMath::Sqrt(ke*ke+2*ke*mpi);
  const TVector3 fullbeam = beamdir.Unit()*pionEndP;
  
  return fullbeam;
}


TVector3 GetTruthBeamFull()
{
  const TVector3 tmpbeam(AnaIO::true_beam_endPx, 
                         AnaIO::true_beam_endPy, 
                         AnaIO::true_beam_endPz );
  return tmpbeam;
}


TVector3 GetRecTrackVectLab(const int ii, const bool kProton)
{
  const double trackMBR = kProton? (*AnaIO::reco_daughter_allTrack_momByRange_proton)[ii] : (*AnaIO::reco_daughter_allTrack_momByRange_muon)[ii];
  TVector3 trackVectLab;
  trackVectLab.SetMagThetaPhi(trackMBR, (*AnaIO::reco_daughter_allTrack_Theta)[ii], (*AnaIO::reco_daughter_allTrack_Phi)[ii]);

  return trackVectLab;
}

TVector3 GetTruthTrackVectLab(const int ii)
{
  const TVector3 trackVectLab((*AnaIO::true_beam_daughter_startPx)[ii], 
                              (*AnaIO::true_beam_daughter_startPy)[ii], 
                              (*AnaIO::true_beam_daughter_startPz)[ii] );
  return trackVectLab;
}

TLorentzVector GetMomentumRefBeam(const bool isTruth, const int trackIndex, const bool kProton)
{
  const TVector3 tmpBeam = isTruth ? GetTruthBeamFull() : GetRecBeamFull();

  const TVector3 vecLab = isTruth ? GetTruthTrackVectLab(trackIndex) : GetRecTrackVectLab(trackIndex, kProton);

  //
  const double thetaRefBeam = AnaFunctions::GetThetaRef(vecLab, tmpBeam.Unit());

  TVector3 vectRefBeam;
  vectRefBeam.SetMagThetaPhi(vecLab.Mag(), thetaRefBeam, 0);

  TLorentzVector momentumRefBeam;
  momentumRefBeam.SetVectM(vectRefBeam, kProton? AnaFunctions::ProtonMass() : AnaFunctions::PionMass() );

  return momentumRefBeam;
}

TVector3 GetShowerVector(const int ii)
{
  const TVector3 vtx(AnaIO::reco_beam_endX, AnaIO::reco_beam_endY, AnaIO::reco_beam_endZ);
  const TVector3 shw((*AnaIO::reco_daughter_allShower_startX)[ii], (*AnaIO::reco_daughter_allShower_startY)[ii], (*AnaIO::reco_daughter_allShower_startZ)[ii]);

  const TVector3 dist=shw-vtx;
  return dist;
}

TLorentzVector * GetPiZero(const vector<TLorentzVector> & shws,  const vector<double> & showerEarr, const vector<int> & showerTypeArray, const bool kprint, const bool kfill)
{
  //
  //combine shower-shower pair and return the most energetic one
  //

  const int truthEventType = GetFillEventType();
  
  const int shsize = shws.size();
  if(kfill){
    style::FillInRange(AnaIO::hRecPi0Nshower, shsize, truthEventType);
  }

  TLorentzVector * outcopy = 0x0;

  //for gkOnlySignal=true, due to non-reconstruction of shower can fail this
  if(shsize>=2){
    const double* shE = &(showerEarr[0]);
    int *nindex = new int[shsize];

    TMath::Sort(shsize, shE, nindex, true);

    const TLorentzVector ldShower = shws[nindex[0]];
    const TLorentzVector slShower = shws[nindex[1]];

    outcopy = new TLorentzVector(ldShower+slShower);

    const double mpi0 = outcopy->M();
    if(kfill){
      style::FillInRange(AnaIO::hRecMpi0,   mpi0, truthEventType);
      if(truthEventType==gkSignal){
        style::FillInRange(AnaIO::hRecLDMpi0, mpi0, showerTypeArray[nindex[0]]);
        style::FillInRange(AnaIO::hRecSLMpi0, mpi0, showerTypeArray[nindex[1]]);
      }
    }
    
    delete nindex;

    //all combination followed by picking the leading Energy pi0 = use leading E showers directly to get pi0, identical results
    /*
    vector<TLorentzVector> piarr;
    int maxEidx = -999;
    double pi0Emax = -999;
    
    for(int ii = 0; ii<shsize; ii++){
      for(int kk = ii+1; kk<shsize; kk++){
        const TLorentzVector tmpgg = shws[ii]+shws[kk];
        if(kprint){
          printf("\n============ %d %d %d \n", shsize, ii, kk);
          tmpgg.Print();        
        }
        
        if(tmpgg.E() > pi0Emax){
          pi0Emax = tmpgg.E();
          maxEidx = piarr.size();
        }
        
        piarr.push_back(tmpgg);
      }
    }
    

    if(maxEidx>=0){
      outcopy = new TLorentzVector(piarr[maxEidx]);
    }
    */
    
  }
  
  return outcopy;
}

int GetParticleType(const int pdg)
{
  int type = -999;
  if(pdg==2212){
    type = gkProton;
  }
  else if(pdg==211){
    type = gkPiPlus;
  }
  else if(pdg==-211){
    type = gkPiMinus;
  }
  else if(pdg==111){
    type = gkPiZero;
  }
  else if(pdg==-11){
    type = gkPositron;
  }
  else if(pdg==11){
    type = gkElectron;
  }
  else if(pdg==-13){
    type = gkMuPlus;
  }
  else if(pdg==13){
    type = gkMuMinus;
  }
  else if(pdg==321||pdg==-321||pdg==310||pdg==130){
    type = gkKaon;
  }
  else if(pdg==2112){
    type = gkNeutron;
  }
  else if(pdg==22){
    type = gkGamma;
  }
  else if(pdg==14 || pdg==-14 || pdg==12 || pdg==-12){
    type = gkNeutrino;
  }
  else if(pdg==3122||pdg==3212||pdg==3222){
    type = gkHyperon;
  }
  else if(pdg>9999){
    type = gkNucleus;
  }
  else if(pdg==-1){
    type = gkNoTruth;
  }
  else{
    cout<<"AnaUtils::GetParticleType unknown pdg "<<pdg<<endl; exit(1);
  }

  return type;
}


vector<TLorentzVector> GetFSTruth(const bool kPiZero, int & protonIdx, int & piplusIdx, bool & tmpksig)
{
  //
  //if kPiZero false, return 1piplus and (1st and 2nd protons)
  //if kPiZero true, return (1st PiZero) and (1st and 2nd protons)
  //only use kPiZero in the end at filling
  //

  const vector<int> * pdg = AnaIO::true_beam_daughter_PDG;
  const vector<double> * px = AnaIO::true_beam_daughter_startPx;
  const vector<double> * py = AnaIO::true_beam_daughter_startPy;
  const vector<double> * pz = AnaIO::true_beam_daughter_startPz;
  TH1I * htype = AnaIO::hselectedDaughterType;
  //===

  const int np = pdg->size();
  AnaIO::nproton = 0;
  AnaIO::nneutron = 0;
  int npiplus = 0;
  AnaIO::nPiZero = 0;
  AnaIO::ngamma = 0;
  int npartialBkg = 0;
  TLorentzVector pPiplus, pPiZero, pProton, p2Proton;

  protonIdx = -999;
  int protonIndices[np];
  double protonmom[np];
  double PiZeromom[np];
  double gammamom[np];
  vector<TVector3> bufferProtonmom;
  vector<TVector3> bufferPiZeromom;
  vector<int> bufferType;

  for(int ii=0; ii<np; ii++){
    const int itype = GetParticleType((*pdg)[ii]);
    const TVector3 tmpp( (*px)[ii], (*py)[ii], (*pz)[ii] );

    if(itype==gkPiPlus){
      npiplus++;
      pPiplus.SetVectM(tmpp, AnaFunctions::PionMass());

      piplusIdx = ii;
    }
    else if(itype==gkProton){
      //ii is the location in the original vector
      protonIndices[AnaIO::nproton]=ii;

      protonmom[AnaIO::nproton] = tmpp.Mag();
      bufferProtonmom.push_back(tmpp);
      AnaIO::nproton++;
    }
    else if(itype==gkPiZero){
      PiZeromom[AnaIO::nPiZero] = tmpp.Mag();
      bufferPiZeromom.push_back(tmpp);
      AnaIO::nPiZero++;
    }
    else if(itype==gkNeutron){
      AnaIO::nneutron++;
    }
    else if(itype==gkGamma){
      gammamom[AnaIO::ngamma] = tmpp.Mag();
      AnaIO::ngamma++;
    }
    else if(itype==gkPiMinus||itype==gkKaon){
      npartialBkg++;
    }

    bufferType.push_back(itype);
  }

  //proton=======================
  int leadingProtonID = 0, subldProtonID = -999;
  if(AnaIO::nproton>1){
    int protonsortid[AnaIO::nproton];
    TMath::Sort(AnaIO::nproton, protonmom, protonsortid);
    leadingProtonID = protonsortid[0];
    subldProtonID = protonsortid[1];
    //printf("test %d %f %d %f\n", leadingProtonID, protonmom[leadingProtonID], subldProtonID, protonmom[subldProtonID]);
  }
  if(AnaIO::nproton>0){
    pProton.SetVectM(bufferProtonmom[leadingProtonID], AnaFunctions::ProtonMass());
    protonIdx = protonIndices[leadingProtonID];
  }
  if(AnaIO::nproton>1){
    p2Proton.SetVectM(bufferProtonmom[subldProtonID], AnaFunctions::ProtonMass());
  }
  //PiZero==============================
  int leadingPiZeroID = 0;
  if(AnaIO::nPiZero>1){
    int PiZerosortid[AnaIO::nPiZero];
    TMath::Sort(AnaIO::nPiZero, PiZeromom, PiZerosortid);
    leadingPiZeroID = PiZerosortid[0];
  }
  if(AnaIO::nPiZero>0){
    pPiZero.SetVectM(bufferPiZeromom[leadingPiZeroID], AnaFunctions::PiZeroMass());
  }
  //gamma====================================
  int leadinggammaID = 0;
  if(AnaIO::ngamma>1){
    int gammasortid[AnaIO::ngamma];
    TMath::Sort(AnaIO::ngamma, gammamom, gammasortid);
    leadinggammaID = gammasortid[0];
  }
  AnaIO::maxgammaEnergy = gammamom[leadinggammaID];
  //==========================================

  //fill vec regardless of tmpksig
  vector<TLorentzVector> vec;
  vec.push_back(kPiZero?pPiZero:pPiplus);
  vec.push_back(pProton);
  vec.push_back(p2Proton);
    
  if(npiplus!=1){
    piplusIdx = -999;
  }

  //Now need kPiZero
  tmpksig = false;
  if(AnaIO::nproton>=1 && npartialBkg ==0){
    if(kPiZero){
      if(AnaIO::nPiZero>0 && npiplus==0){
        tmpksig = true;
      }
    }
    else{//PiPlus
      if(npiplus==1 && AnaIO::nPiZero==0){
        tmpksig = true;
      }
    }
  }

  if(tmpksig && htype){
    const int nbt = bufferType.size();
    for(int ii=0; ii<nbt; ii++){
      htype->Fill(bufferType[ii]);
    }
  }

  return vec;
}


void SetFullSignal(const bool kpi0)
{
  //
  //p_leading 0.45-1, p_sublieading < 0.45, no cut on pi+
  //

  int  protonIdx = -999, piplusIdx = -999;
  vector<TLorentzVector> vecPiP = GetFSTruth(kpi0, protonIdx, piplusIdx, AnaIO::kSignal);
  
  AnaIO::finPimomentum = vecPiP[0].P();
  AnaIO::finProtonmomentum = vecPiP[1].P();
  AnaIO::fin2Pmom = vecPiP[2].P();
  
  //no phase space cut
  AnaIO::kSignal = AnaIO::kSignal && (AnaIO::true_beam_PDG==211);
  //with phase space cut
  //AnaIO::kSignal = AnaIO::kSignal && (AnaIO::finProtonmomentum>0.45 && AnaIO::fin2Pmom<0.45);
  AnaIO::kSignal = AnaIO::kSignal && (AnaIO::finProtonmomentum<1 && AnaIO::finProtonmomentum>0.45 && AnaIO::fin2Pmom<0.45);

  //no pi+ phase space cut
  //if(!kpi0){
    //AnaIO::kSignal = AnaIO::kSignal && (AnaIO::finPimomentum>0.15);
  //}
}

/*
double GetTruncatedMean(vector<double> array, const int nsample)
{
  const double fracTrun = 0.6;
  const double nterm = nsample*fracTrun;
  //either nsample<0, or total nterm is too small

  if(nterm<=0){
    return -999;
  }

  std::sort(array.begin(), array.begin()+nsample);

  double sum =0.0;

  for(unsigned int ii=0; ii< nterm; ii++){
    sum += array[ii];
  }
  return sum / (nterm+1E-10);
}
*/

double GetTruncatedMean(const vector<double> &tmparr, const unsigned int nsample0, const unsigned int nsample1, const double lowerFrac, const double upperFrac)
{
  //
  //for proton Bragg peak use 0.4-0.95. Seen by CDF of startE using signal proton samples in drawTracking
  //
  //The Bethe-Bloch or the Bragg peak part of the dEdx distribution? That will determine the truncation fractions:
  //Look at the dEdx distribution and choose a region of interest, say the 10-60% of the distribution, set the lower and upper fraction as 0.1 and 0.6.
  //Need to be careful with what dEdx[] range to sample. The first two ([0, 1]) and last two ([last, last-1]) are not well defined/measured and therefore do not include them.
  //Example: if Bethe-Bloch is the focus, do
  //double tme = GetTruncatedMean(dedx_vector, 2, dedx_vector_size-5, 0.1, 0.6)
  //

  //require nsample0<nsample1<size
  if(nsample1>=tmparr.size() || nsample0>=nsample1){
    return -999;
  }

  vector<double> array;
  for(unsigned int ii=nsample0; ii<=nsample1; ii++){
    array.push_back(tmparr[ii]);
  }

  const int iter0 = array.size()*lowerFrac;
  const int iter1 = array.size()*upperFrac;
  const int nterm = iter1-iter0;
  if( nterm<=0 ){
    return -999;
  }

  std::sort(array.begin(), array.end());

  double sum =0.0;
  for(int ii=iter0; ii< iter1; ii++){
    sum += array[ii];
  }
  return sum / ( nterm+1E-10);
}

int GetdEdx(const vector<double> &arraydEdx, vector<double> &startE, vector<double> &endE, const unsigned int padding=0)
{
  //
  //return a subset using non-0 padding
  //

  const unsigned int ncls = arraydEdx.size();

  if(ncls<=padding){
    return 0;
  }

  //start from [2] because [0] and [1] in both start and last are weird
  for(unsigned int kk=padding; kk<ncls; kk++){
    startE.push_back(arraydEdx[kk]);

    const double endpe = arraydEdx[ncls-1-kk];
    endE.push_back(endpe);
  }

  return startE.size();
}


void GetBeamdEdx(const int evtType)
{
  //
  //calculate all beam dEdx
  //

  vector<double> startE, lastE;
  GetdEdx( *AnaIO::reco_beam_calibrated_dEdX, startE, lastE, 2);

  AnaIO::beamNdEdx = startE.size();
  style::FillInRange(AnaIO::hBeamNdEdx, AnaIO::beamNdEdx, evtType);

  const bool kfailN = (AnaIO::beamNdEdx<6);

  //no bragg peak
  AnaIO::beamStartE0 = kfailN ? -999 : startE[0];
  AnaIO::beamStartE1 = kfailN ? -999 : startE[1];
  AnaIO::beamStartE2 = kfailN ? -999 : startE[2];
  AnaIO::beamStartE3 = kfailN ? -999 : startE[3];
  AnaIO::beamStartE4 = kfailN ? -999 : startE[4];
  AnaIO::beamStartE5 = kfailN ? -999 : startE[5];
  
  //has Bragg Peak
  AnaIO::beamLastE0 = kfailN ? -999 : lastE[0];
  AnaIO::beamLastE1 = kfailN ? -999 : lastE[1];
  AnaIO::beamLastE2 = kfailN ? -999 : lastE[2];
  AnaIO::beamLastE3 = kfailN ? -999 : lastE[3];
  AnaIO::beamLastE4 = kfailN ? -999 : lastE[4];
  AnaIO::beamLastE5 = kfailN ? -999 : lastE[5];

  //double GetTruncatedMean(const vector<double> &tmparr, const unsigned int nsample0, const unsigned int nsample1, const double lowerFrac, const double upperFrac)
  AnaIO::beamStartTME = kfailN ? -999 : GetTruncatedMean(startE, 0, AnaIO::beamNdEdx-6,   0.05, 0.6);
  AnaIO::beamLastTME  = kfailN ? -999 : GetTruncatedMean(lastE,  0, 5,                    0.4,  0.95);
}

void FillBeamKinematics(const int kmc)
{
  const int evtType = GetFillEventType();
  const TVector3 recBeamFull = GetRecBeamFull();
  
  if(kmc){
    const TVector3 truthBeam = GetTruthBeamFull();
    
    const double beamthetaRes    = (recBeamFull.Theta()-truthBeam.Theta())*TMath::RadToDeg();//use absolute difference 
    const double beammomentumRes = recBeamFull.Mag()/truthBeam.Mag()-1;
    
    style::FillInRange(AnaIO::hBeamThetaRes,    truthBeam.Theta()*TMath::RadToDeg(), beamthetaRes);
    style::FillInRange(AnaIO::hBeamMomentumRes, truthBeam.Mag(),                     beammomentumRes);
  }
  
  style::FillInRange(AnaIO::hRecBeamTheta,    recBeamFull.Theta()*TMath::RadToDeg(), evtType);
  style::FillInRange(AnaIO::hRecBeamMomentum, recBeamFull.Mag(),                     evtType);
}

void FillBeamdEdx(const bool kBefore)
{
  //
  //
  //

  const int evtType = GetFillEventType();
  
  if(kBefore){

    GetBeamdEdx(evtType);

    //allow n<6, just become underflow
    AnaIO::hBeamStartTME->Fill(AnaIO::beamStartTME, evtType);
    AnaIO::hBeamLastTME->Fill(AnaIO::beamLastTME, evtType);
    
    AnaIO::hBeamStartE0->Fill(AnaIO::beamStartE0, evtType);
    AnaIO::hBeamStartE1->Fill(AnaIO::beamStartE1, evtType);
    AnaIO::hBeamStartE2->Fill(AnaIO::beamStartE2, evtType);
    AnaIO::hBeamStartE3->Fill(AnaIO::beamStartE3, evtType);
    AnaIO::hBeamStartE4->Fill(AnaIO::beamStartE4, evtType);
    AnaIO::hBeamStartE5->Fill(AnaIO::beamStartE5, evtType);
    
    AnaIO::hBeamLastE0->Fill(AnaIO::beamLastE0, evtType);
    AnaIO::hBeamLastE1->Fill(AnaIO::beamLastE1, evtType);
    AnaIO::hBeamLastE2->Fill(AnaIO::beamLastE2, evtType);
    AnaIO::hBeamLastE3->Fill(AnaIO::beamLastE3, evtType);
    AnaIO::hBeamLastE4->Fill(AnaIO::beamLastE4, evtType);
    AnaIO::hBeamLastE5->Fill(AnaIO::beamLastE5, evtType);
  }
  else{
    //fill all event even ndEdx<6
    //PC = Post-Cut
    AnaIO::hBeamPCStartTME->Fill(AnaIO::beamStartTME, evtType);
    AnaIO::hBeamPCLastTME->Fill(AnaIO::beamLastTME, evtType);
    
    AnaIO::hBeamPCStartE0->Fill(AnaIO::beamStartE0, evtType);
    AnaIO::hBeamPCStartE1->Fill(AnaIO::beamStartE1, evtType);
    AnaIO::hBeamPCStartE2->Fill(AnaIO::beamStartE2, evtType);
    AnaIO::hBeamPCStartE3->Fill(AnaIO::beamStartE3, evtType);
    AnaIO::hBeamPCStartE4->Fill(AnaIO::beamStartE4, evtType);
    AnaIO::hBeamPCStartE5->Fill(AnaIO::beamStartE5, evtType);
    
    AnaIO::hBeamPCLastE0->Fill(AnaIO::beamLastE0, evtType);
    AnaIO::hBeamPCLastE1->Fill(AnaIO::beamLastE1, evtType);
    AnaIO::hBeamPCLastE2->Fill(AnaIO::beamLastE2, evtType);
    AnaIO::hBeamPCLastE3->Fill(AnaIO::beamLastE3, evtType);
    AnaIO::hBeamPCLastE4->Fill(AnaIO::beamLastE4, evtType);
    AnaIO::hBeamPCLastE5->Fill(AnaIO::beamLastE5, evtType);
  }

  //old code
  /*
//both need to tune for different energy
  //it is so clean that no need to cut on last since there is no Bragg peak form proton any more
  if(AnaIO::beamStartTME>2.8){
    return false;
  }
   */
}

int GetFSdEdx(const unsigned int ii, double & startE2, double & startE3, double & startTME, double & lastE2, double & lastE3, double & lastTME)
{
  const vector<double> recodEdxarray = (*AnaIO::reco_daughter_allTrack_calibrated_dEdX_SCE)[ii];

  vector<double> startEarray, lastEarray;
  //full range, no padding
  const int ndEdx = GetdEdx(recodEdxarray, startEarray, lastEarray);

  startE2 = ndEdx<3? -999: startEarray[2];
  startE3 = ndEdx<4? -999 :startEarray[3];
  lastE2 = ndEdx<3? -999: lastEarray[2];
  lastE3 = ndEdx<4? -999 :lastEarray[3];
  //has Bragg peak
  startTME = GetTruncatedMean(startEarray, 2, 6, 0.4,  0.95);

  //no Bragg peak
  lastTME  = GetTruncatedMean(lastEarray,  2, ndEdx-8, 0.05, 0.6);

  return ndEdx;
}

double GetRecFromTruth(const int protonIdx, const vector<double> * mombyrange)
{
  const int truthID = (*AnaIO::true_beam_daughter_ID)[protonIdx];

  vector<double> lastE, startE;

  static int ievent = 0;
  ievent++;

  double rpm = -999;
  int counter = 0;
  for(unsigned int ii = 0; ii < AnaIO::reco_daughter_PFP_true_byHits_ID->size(); ii++){
    if((*AnaIO::reco_daughter_PFP_true_byHits_ID)[ii] == truthID) {
      if((*AnaIO::reco_daughter_allTrack_ID)[ii] != -1) {//allTrack force reconstruction is successful assuming track

        //that actually can happen, but not often
        if(counter){
          printf("rpm already set!! %f %f %d %d\n", rpm, (*mombyrange)[ii], counter, ievent); //exit(1);
        }

        rpm = (*mombyrange)[ii];

        AnaIO::chi2 = (*AnaIO::reco_daughter_allTrack_Chi2_proton)[ii];
        AnaIO::ndof = (*AnaIO::reco_daughter_allTrack_Chi2_ndof)[ii];

        if(!AnaIO::reco_daughter_allTrack_calibrated_dEdX_SCE){
          printf("AnaIO::reco_daughter_allTrack_calibrated_dEdX_SCE null!\n"); exit(1);
        }

        GetdEdx( (*AnaIO::reco_daughter_allTrack_calibrated_dEdX_SCE)[ii], startE, lastE, 0);
        //printf("==================================\n");

        const int iter0 = 2;
        AnaIO::lastTruncatedMeanE = GetTruncatedMean(lastE, iter0, iter0-1+10, 0.0, 1.0);
        AnaIO::startTruncatedMeanE10 = GetTruncatedMean(startE, iter0, iter0-1+10, 0.4, 0.95);
        AnaIO::startTruncatedMeanE20 = GetTruncatedMean(startE, iter0, iter0-1+20, 0.4, 0.95);
        AnaIO::startTruncatedMeanE30 = GetTruncatedMean(startE, iter0, iter0-1+30, 0.4, 0.95);
        AnaIO::startTruncatedMeanE40 = GetTruncatedMean(startE, iter0, iter0-1+40, 0.4, 0.95);
        AnaIO::startTruncatedMeanE50 = GetTruncatedMean(startE, iter0, iter0-1+50, 0.4, 0.95);

        counter++;
      }
      /*there are indeed -1 due to fail allTrack assumption
      else{
        printf("getRecFromTruth id = -1!! %d %d\n", ii, (*AnaIO::reco_daughter_allTrack_ID)[ii]); exit(1);
      }
      */
    }
  }

  AnaIO::ndEdxCls = lastE.size();
  if(AnaIO::ndEdxCls>=6){
    AnaIO::lastE0 = lastE[0];
    AnaIO::lastE1 = lastE[1];
    AnaIO::lastE2 = lastE[2];
    AnaIO::lastE3 = lastE[3];
    AnaIO::lastE4 = lastE[4];
    AnaIO::lastE5 = lastE[5];
    
    AnaIO::startE0 = startE[0];
    AnaIO::startE1 = startE[1];
    AnaIO::startE2 = startE[2];
    AnaIO::startE3 = startE[3];
    AnaIO::startE4 = startE[4];
    AnaIO::startE5 = startE[5];
  }

  return rpm;
}




void PrintLegend()
{
  TCanvas * c1 = 0x0;

  const int overlayColor = kRed;

  {
  /*
  //1-4
  gkProton=1,
  gkPiPlus,
  gkPiMinus,
  gkGamma,
  //gkEplusEminus,
  //gkMuon,

  //5-10
  gkSecondaryProton,
  gkSecondaryPiPlus,
  gkSecondaryPiMinus,
  gkSecondaryGamma,
  gkSecondaryEplusEminus,
  gkSecondaryMuon,

  //11
  gkOthers
  */

  vector<TString> parType;
  parType.push_back("p");
  parType.push_back("#pi^{+}");
  parType.push_back("#pi^{#minus}");
  parType.push_back("#gamma");
  
  parType.push_back("2ry p");
  parType.push_back("2ry #pi^{+}");
  parType.push_back("2ry #pi^{#minus}");
  parType.push_back("2ry #gamma");
  parType.push_back("2ry e^{#pm}");
  parType.push_back("2ry #mu^{#pm}");
  
  parType.push_back("others");
  parType.push_back("data");

  vector<TString> htype;//need to matcy parType
  htype.push_back("f");
  htype.push_back("f");
  htype.push_back("f");
  htype.push_back("f");
  
  htype.push_back("f");
  htype.push_back("f");
  htype.push_back("f");
  htype.push_back("f");
  htype.push_back("f");
  htype.push_back("f");
  
  htype.push_back("f");
  htype.push_back("pl");

  const int mrks[]={1,1,1,1, 1,1,1,1,1,1, 1,6};
  int *cols=style::GetColorArray(parType.size());
  cols[parType.size()-1]=overlayColor;
  c1 = style::DrawLegend(parType, htype, cols, mrks, 4);

  c1->Print("output/legend_parType.eps");
  c1->Print("output/legend_parType.pdf");
  c1->Print("output/legend_parType.png");
  }

  {
  vector<TString> evtType;
  evtType.push_back("signal");
  evtType.push_back("background");
  evtType.push_back("non-#pi^{+} beam");
  evtType.push_back("data");

  vector<TString> htype;
  htype.push_back("f");
  htype.push_back("f");
  htype.push_back("f");
  htype.push_back("pl");

  int *cols=style::GetColorArray(4);
  cols[3]=overlayColor;
  const int mrks[]={1,1,1,6};
  c1 = style::DrawLegend(evtType, htype, cols, mrks);

  c1->Print("output/legend_evtType.eps");
  c1->Print("output/legend_evtType.pdf");
  c1->Print("output/legend_evtType.png");
  }
}

//=== end
}


#endif

