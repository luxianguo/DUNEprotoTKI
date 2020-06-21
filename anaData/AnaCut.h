#ifndef _ANACUT_H_
#define _ANACUT_H_

using namespace std;

namespace AnaCut
{

int GetTruthFromRec(const int recidx, TLorentzVector *& momRefBeam)
{
  int pdg = -999;
  momRefBeam = 0x0;
  int trueidx = -999;

  if(AnaIO::reco_daughter_PFP_true_byHits_ID && AnaIO::reco_daughter_PFP_true_byHits_ID->size() ){//in data this Is size = 0 but not null

    const int truthID = (*AnaIO::reco_daughter_PFP_true_byHits_ID)[recidx];
    int counter = 0;
    for(unsigned int ii = 0; ii<AnaIO::true_beam_daughter_ID->size(); ii++){
      if(  (*AnaIO::true_beam_daughter_ID)[ii] == truthID ){
        if(counter){
          printf("GetTruthFromRec truthID found again %d %d\n", recidx, truthID); exit(1);
        }
        trueidx = ii;
        counter++;
      }
    }
    
    if(trueidx>=0){
      pdg = (*AnaIO::true_beam_daughter_PDG)[trueidx];
      
      momRefBeam = new TLorentzVector(AnaUtils::GetMomentumRefBeam(true, trueidx, pdg==2212));
    }
    
  }


  int truthParticleType = -999;
  if(pdg==2212){//proton
    truthParticleType = AnaUtils::gkProton;
  }
  else if(pdg==211){//pi+
    truthParticleType = AnaUtils::gkPiPlus;
  }
  else if(pdg==22){//gamma 
    truthParticleType = AnaUtils::gkOthers+1;
  }
  else if(pdg==-999){//shower no true
    truthParticleType = AnaUtils::gkShower;
  }
  else{//all others
    truthParticleType = AnaUtils::gkOthers;
  }

  return truthParticleType;
}

bool IsGoodPFP(const int ii, const bool kfill, const int truthParticleType)
{
  //
  //if not good, this PFP is not counted as anything, just ignored
  //

  const int NdEdx = (*AnaIO::reco_daughter_allTrack_calibrated_dEdX_SCE)[ii].size();

  if(kfill){
    style::FillInRange(AnaIO::hCutNdEdx, NdEdx, truthParticleType);
  }

  return true;

  //not using ESC cut, so ndEdx cut is not a must
  /*
    const int ndedxcut = kpi0 ? 6 : 16; //need E[3], at least 4 cls
    if(kPrintCutInfo){
    printf("check cut kpi0 %d ndedxcut %d\n", kpi0, ndedxcut);
    }
    if(NdEdx<ndedxcut){
    //do not count it as anything
    continue;
    }
  */

}

bool IsMichel(const int ii, const bool kfill, const int truthParticleType)
{
  //
  //Michel identifiation using score only for the momentum
  //michel is not found (all below 0.5, those above 0.5 are shower and other_type)
  //

  const double michelScore = (*AnaIO::reco_daughter_PFP_michelScore_collection)[ii];

  if(kfill){
    style::FillInRange(AnaIO::hCutmichelScore, michelScore, truthParticleType);
  }

  if( michelScore<=0.5 ){
    return false;
  }
   
  return true;
}

bool IsShower(const int ii, vector<TLorentzVector> & showerArray, const bool kfill, const int truthParticleType)
{
  //
  //shower identification using score only for the momentum
  //

  const double emScore     = (*AnaIO::reco_daughter_PFP_emScore_collection)[ii];
  
  if(kfill){
    style::FillInRange(AnaIO::hCutemScore, emScore, truthParticleType);
  }

  if( (*AnaIO::reco_daughter_allShower_ID)[ii]==-1 ){
    return false;
  }

  if( emScore <= 0.5 ){
    return false;
  }

  if(AnaIO::reco_daughter_allShower_energy){
    const TVector3 showerDir((*AnaIO::reco_daughter_allShower_dirX)[ii], 
                             (*AnaIO::reco_daughter_allShower_dirY)[ii], 
                             (*AnaIO::reco_daughter_allShower_dirZ)[ii] );

    const TVector3 showerMomentum = showerDir.Unit()*(*AnaIO::reco_daughter_allShower_energy)[ii] * 1E-3; //MeV to GeV
    const TLorentzVector showerLv( showerMomentum, showerMomentum.Mag() );
    showerArray.push_back(showerLv);
  }
  else{
    printf("shower energy null!!\n"); exit(1);
  }
  
  return true;
}
 

bool IsTrack(const int ii, const bool kfill, const int truthParticleType)
{
  //
  //common for IsProton and IsPiplus
  //

  const int nhits         = (*AnaIO::reco_daughter_PFP_nHits)[ii];
  /*//they are indeed different: 236 80
    if(nhits != NdEdx){
    printf("nhits!=dedx size %d %d\n", nhits, NdEdx); exit(1);
    }
  */

  const double trackScore = (*AnaIO::reco_daughter_PFP_trackScore_collection)[ii];

  //fill before any cuts
  if(kfill){
    style::FillInRange(AnaIO::hCutnHits, nhits, truthParticleType);
    style::FillInRange(AnaIO::hCuttrackScore, trackScore, truthParticleType);
  }

  if( (*AnaIO::reco_daughter_allTrack_ID)[ii]==-1 ){
    return false;
  }

  //track and em scores at 0.5 look reasonable as baseline (after 0.5 the proton fraction look flat)
  if(trackScore <= 0.5){
    return false;
  }

  if(nhits <= 40){
    return false;
  }

  //fill before doing chi2, no matter 
  if(kfill){
    const double Chi2NDF = AnaUtils::GetChi2NDF(ii);

    const vector<double> dedxarr = (*AnaIO::reco_daughter_allTrack_calibrated_dEdX_SCE)[ii];
    const double startE2 = dedxarr.size()<3? -999 : dedxarr[2];
    const double startE3 = dedxarr.size()<4? -999 : dedxarr[3];

    style::FillInRange(AnaIO::hCutChi2NDF, Chi2NDF, truthParticleType);
    style::FillInRange(AnaIO::hCutstartE2, startE2, truthParticleType);
    style::FillInRange(AnaIO::hCutstartE3, startE3, truthParticleType);
  }

  return true;
}

bool IsProton(const int ii, const bool kfill, const int truthParticleType, 
              const double startE2, const double startE3, const double startTME, 
              const double lastE2, const double lastE3, const double lastTME)
{
  //
  //proton identification
  //

  if(!IsTrack(ii, kfill, truthParticleType)){
    return false;
  }
 
  const double Chi2NDF    = AnaUtils::GetChi2NDF(ii);

  //use the same selection for proton with Chi2 because of better data-MC consistency
  if(Chi2NDF>=50){
    return false;
  }

  //------ no cuts any more, fill for selected protons
  if(kfill){
    style::FillInRange(AnaIO::hRecProtonStartE2, startE2, truthParticleType);
    style::FillInRange(AnaIO::hRecProtonStartE3, startE3, truthParticleType);
    style::FillInRange(AnaIO::hRecProtonStartTME, startTME, truthParticleType);
    style::FillInRange(AnaIO::hRecProtonLastE2, lastE2, truthParticleType);
    style::FillInRange(AnaIO::hRecProtonLastE3, lastE3, truthParticleType);
    style::FillInRange(AnaIO::hRecProtonLastTME, lastTME, truthParticleType);
  }

  return true;

  //------ old code, keep for the moment

  //========== proton tagging now! <<<
  //all signal protons have nhit below 260 <- only true for Pi0 analysis
  //const double cutNH = 260;
  
  /*
    if(kpi0){
    //all signal protons have startE3 > 9
    //with Chi2NDF cut  44/191 = 23% purity; without 46/197 = 23% purity, slightly higher efficiency
    //test if(startE2>10 && nhits<260 && startE3>9 && Chi2NDF<50){
    const double cutSE2 = 10;
    const double cutSE3 = 9;
    if(startE2>cutSE2 && nhits<cutNH && startE3>cutSE3){
    recParticleType = AnaUtils::gkProton;
    }
    
    if(kPrintCutInfo){
    printf("check cut kpi0 %d proton tag startE2 %.2f nhits %.0f startE3 %.2f\n", kpi0, cutSE2, cutNH, cutSE3); 
    }
    }
    else{
  */
  //no nhit 260 cut any more, better e*p
  // && nhits<cutNH){

}

bool IsPiplus(const int ii, const bool kfill, const int truthParticleType,
              const double startE2, const double startE3, const double startTME, 
              const double lastE2, const double lastE3, const double lastTME)
{
  //
  //piplus identification currently only using dEdx information, need to improve
  //

  //already filled in IsProton, so not here
  if(!IsTrack(ii, false, -999)){
    return false;
  }

  const double Chi2NDF    = AnaUtils::GetChi2NDF(ii);

  //proton and piplus should be exactly complementary within track
  if(Chi2NDF<50){
    return false;
  }

  //------ not cuts any more, fill for selected piplus
  if(kfill){
    style::FillInRange(AnaIO::hRecPiplusStartE2, startE2, truthParticleType);
    style::FillInRange(AnaIO::hRecPiplusStartE3, startE3, truthParticleType);
    style::FillInRange(AnaIO::hRecPiplusStartTME, startTME, truthParticleType);
    style::FillInRange(AnaIO::hRecPiplusLastE2, lastE2, truthParticleType);
    style::FillInRange(AnaIO::hRecPiplusLastE3, lastE3, truthParticleType);
    style::FillInRange(AnaIO::hRecPiplusLastTME, lastTME, truthParticleType);
  }

  return true;
}

void CountPFP(const bool kpi0, const int truthEventType, int & nproton, int & npiplus, int & nshower, int & nmichel, TLorentzVector *  & leadingPi0, const bool kprint, const bool kfill)
{
  //
  //to-do: need to pass out the proton and piplus
  //Example event (old print out):
  //rec 1/2 trueID 15 pdg 22 truemomentum 0.002512 recp -999.000000 resolution -397725.603302 nhits 7 trackScore 0.016739 emScore 0.983240 michelScore 0.289565 sum 1.289545
  //

  const int recsize = AnaIO::reco_daughter_PFP_ID->size();
  /*//checked, they are the same
  const int mbr     = AnaIO::reco_daughter_allTrack_momByRange_proton->size();
  if(recsize!=mbr){
    printf("recsize != mbr %d %d\n", recsize, mbr); exit(1); 
  }
  */

  nproton = 0;
  npiplus = 0;
  nshower = 0;
  nmichel = 0;
  int nPFP = 0;

  /* to-do:
  //proton and pion array only keeps the leading one, ie, only [0] will be returned
  //vector<TLorentzVector> protonArray; 
  //vector<TLorentzVector> pionArray; //that is non-proton actually
  */

  vector<TLorentzVector> showerArray;

  //static bool kPrintCutInfo = true;

  for(int ii=0; ii<recsize; ii++){

    //__________________________________________ Get Truth information __________________________________________
    TLorentzVector * truthMomRefBeam = 0x0;
    const int truthParticleType = GetTruthFromRec(ii, truthMomRefBeam);

    //__________________________________________ Cut PFP before counting -> no cut any more  __________________________________________
    //---> need to be done before any counting!!!
    if(!IsGoodPFP(ii, kfill, truthParticleType)){
      continue;
    }
    //<--- need to be done before any counting!!!

    //__________________________________________ Count without "continue"  __________________________________________
    double startE2, startE3, startTME, lastE2, lastE3, lastTME;
    AnaUtils::GetFSdEdx(ii, startE2, startE3, startTME, lastE2, lastE3, lastTME);

    int recParticleType = -999;

    if(IsProton(ii, kfill, truthParticleType, startE2, startE3, startTME, lastE2, lastE3, lastTME)){
      recParticleType = AnaUtils::gkProton;
      nproton++;
    }

    if(IsPiplus(ii, kfill, truthParticleType, startE2, startE3, startTME, lastE2, lastE3, lastTME)){
      if(recParticleType!=-999){
        printf("particle already identified!! %d\n", recParticleType); exit(1);
      }

      recParticleType = AnaUtils::gkPiPlus;
      npiplus++;
    }

    if(IsShower(ii, showerArray, kfill, truthParticleType)){
      nshower++;
    }

    if(IsMichel(ii, kfill, truthParticleType)){
      nmichel++;
    }
   
    //__________________________________________ Get Reco kinematics  __________________________________________
    const TLorentzVector recMomRefBeam = AnaUtils::GetMomentumRefBeam(false, ii, recParticleType==AnaUtils::gkProton);

    //__________________________________________ Print and Fill  __________________________________________
    if(kprint){
      //printf("test sig %d rii %d/%d tii %4d pdg %4d sE2 %6.1f sE3 %6.1f lE2 %6.1f lE3 %6.1f nhi %4d tkS %6.1f emS %6.1f miS %6.1f sum %6.1f chf %6.1f\n", truthEventType, ii, recsize, trueidx, pdg, startE2, startE3, lastE2, lastE3, nhits, trackScore, emScore, michelScore, trackScore+emScore+michelScore, Chi2NDF);
    }

    if(kfill){
      const double momentumRes = truthMomRefBeam? recMomRefBeam.P()/truthMomRefBeam->P()-1 : -999;
      const double thetaRes    = truthMomRefBeam? (recMomRefBeam.Theta()-truthMomRefBeam->Theta())*TMath::RadToDeg() : -999;
 
      if(recParticleType==AnaUtils::gkProton){
        if(truthParticleType == AnaUtils::gkProton){
          style::FillInRange(AnaIO::hProtonMomentumRes, truthMomRefBeam->P(), momentumRes);
          style::FillInRange(AnaIO::hProtonThetaRes, truthMomRefBeam->Theta()*TMath::RadToDeg(), thetaRes);
        }
        style::FillInRange(AnaIO::hRecProtonMomentum, recMomRefBeam.P(), truthParticleType);
        style::FillInRange(AnaIO::hRecProtonTheta, recMomRefBeam.Theta()*TMath::RadToDeg(), truthParticleType);
      
      }
      else if(recParticleType==AnaUtils::gkPiPlus){
        if(truthParticleType == AnaUtils::gkPiPlus){
          style::FillInRange(AnaIO::hPiplusMomentumRes, truthMomRefBeam->P(), momentumRes);
          style::FillInRange(AnaIO::hPiplusThetaRes, truthMomRefBeam->Theta()*TMath::RadToDeg(), thetaRes);
        }
        style::FillInRange(AnaIO::hRecPiplusMomentum, recMomRefBeam.P(), truthParticleType);
        style::FillInRange(AnaIO::hRecPiplusTheta, recMomRefBeam.Theta()*TMath::RadToDeg(), truthParticleType);
      }
    }
    
    //kPrintCutInfo = false;

    nPFP++;
  }

  if(recsize!=nPFP){
    printf("CountPFP not looping all!! %d %d\n", recsize, nPFP);
  }

  if(kprint){
    printf("CountPFP PFP size %d nlooped %d nshower %d nmichel %d npiplus %d nproton %d\n", recsize, nPFP, nshower, nmichel, npiplus, nproton);
  }

  //leading pi0 is event-level info
  if(kpi0){
    //only fill histnshowers when doing fill
    const bool kprint = false;
    leadingPi0 = AnaUtils::GetPiZero(truthEventType, showerArray, kprint, kfill);

    //for gkOnlySignal=true, this might be null due to non-reconstruction of shower    
    if(kfill && leadingPi0){
      style::FillInRange(AnaIO::hCutMpi0, leadingPi0->M(), truthEventType);
    }
  }

  if(kprint){
    printf("\n\n");
  }

}


bool CutTopology(const bool kpi0, const bool kFillBefore)
{
  //
  //number of particles defined in CountPFP needs to be optimized
  //

  int cutnproton = 0;
  int cutnpiplus = 0;
  int cutnshower = 0;
  int cutnmichel = 0;
  TLorentzVector * leadingPi0 = 0x0;  

  const bool kprint = false;
  const bool kfill = kFillBefore;
  CountPFP(kpi0, AnaIO::kSignal, cutnproton, cutnpiplus, cutnshower, cutnmichel, leadingPi0, kprint, kfill);
  
  const int filleventtype = AnaUtils::GetFillEventType();

  //______________________________________________ Do cuts below ______________________________________________ 

  //1. nshower
  style::FillInRange(AnaIO::hCutnshower, cutnshower, filleventtype);
  if(kpi0){
    if(cutnshower<2){
      return false;
    }
  }
  else{
    if(cutnshower>0){
      return false;
    }
  }
  
  //2. nmichel
  style::FillInRange(AnaIO::hCutnmichel, cutnmichel, filleventtype);
  if(kpi0){
    if(cutnmichel>0){
      return false;
    }
  }
  else{
    //not found in signal, need Michel to tell 2-proton events from p-pi; ignore michel count for the momentum, things will change after implementing it.
    /*
      if(cutnmichel!=1){
      continue;
      }
    */
  }
  
  //3. npiplus
  style::FillInRange(AnaIO::hCutnpiplus, cutnpiplus, filleventtype);
  if(kpi0){
    if(cutnpiplus!=0){
      return false;
    }
  }
  else{
    if(cutnpiplus!=1){
      return false;
    }
  }

  //4. nproton  
  style::FillInRange(AnaIO::hCutnproton, cutnproton, filleventtype);
  if(cutnproton!=1){
    return false;
  }
  
  return true;
}

bool CutBeamID(const std::vector<int> & pidCandidates)
{
  //https://github.com/calcuttj/PionStudies/blob/master/rDataFrame/eventSelection.h
  //line 149

  //https://github.com/calcuttj/PionStudies/blob/master/rDataFrame/eventSelection.C
  //line 128
  // auto data_all = data_frame
  //    .Define("beamPID", data_beam_PID, {"data_BI_PDG_candidates"})
  //line 157
  // .Filter("beamPID == true"); 

  return ( (std::find(pidCandidates.begin(), pidCandidates.end(), 211)) != pidCandidates.end());
};

bool Manual_beamPos_mc(const double beam_startX, const double beam_startY, const double beam_startZ, const double beam_dirX, const double beam_dirY,   const double beam_dirZ, const double true_dirX,   const double true_dirY, const double true_dirZ,   const double true_startX, const double true_startY, const double true_startZ) 
{
  //https://github.com/calcuttj/PionStudies/blob/master/rDataFrame/eventSelection.h

  //For MC from Owen Goodwins studies
  const double xlow = -3.,  xhigh = 7.,  ylow = -8.,  yhigh = 7.;
  const double zlow = 27.5,  zhigh = 32.5,  coslow = 0.93;

  const double projectX = (true_startX + -1*true_startZ*(true_dirX/true_dirZ) );
  const double projectY = (true_startY + -1*true_startZ*(true_dirY/true_dirZ) );
  const double cos = true_dirX*beam_dirX + true_dirY*beam_dirY + true_dirZ*beam_dirZ;

  if ( (beam_startX - projectX) < xlow )
    return false;
  
  if ( (beam_startX - projectX) > xhigh )
    return false;

  if ( (beam_startY - projectY) < ylow )
    return false;

  if ( (beam_startY - projectY) > yhigh )
    return false;
  
  if (beam_startZ < zlow || zhigh < beam_startZ)
    return false;
  
  if ( cos < coslow)
    return false;

  return true;
}


bool CutMCBeamPos()
{
  //https://github.com/calcuttj/PionStudies/blob/master/rDataFrame/eventSelection.C
  /*
.Define("passBeamCut", manual_beamPos_mc, 
            {"reco_beam_startX", "reco_beam_startY", "reco_beam_startZ",
             "reco_beam_trackDirX", "reco_beam_trackDirY", "reco_beam_trackDirZ",
             "true_beam_startDirX", "true_beam_startDirY", "true_beam_startDirZ",
             "true_beam_startX", "true_beam_startY", "true_beam_startZ"})
   */

  return Manual_beamPos_mc(AnaIO::reco_beam_startX, AnaIO::reco_beam_startY, AnaIO::reco_beam_startZ,
                           AnaIO::reco_beam_trackDirX, AnaIO::reco_beam_trackDirY, AnaIO::reco_beam_trackDirZ,
                           AnaIO::true_beam_startDirX, AnaIO::true_beam_startDirY, AnaIO::true_beam_startDirZ,
                           AnaIO::true_beam_startX, AnaIO::true_beam_startY, AnaIO::true_beam_startZ);
}


bool Manual_beamPos_data(const int event,            const double data_startX,
                         const double data_startY,   const double data_startZ,
                         const double data_dirX,     const double data_dirY,
                         const double data_dirZ,     const double data_BI_X,
                         const double data_BI_Y,     const double data_BI_dirX,
                         const double data_BI_dirY,  const double data_BI_dirZ,
                         const int data_BI_nMomenta, const int data_BI_nTracks) 
{

  //For Data from Owen Goodwin
  const double data_xlow = 0., data_xhigh = 10., data_ylow= -5.;
  const double data_yhigh= 10., data_zlow=30., data_zhigh=35., data_coslow=.93;

  const double deltaX = data_startX - data_BI_X;
  const double deltaY = data_startY - data_BI_Y;
  const double cos = data_BI_dirX*data_dirX + data_BI_dirY*data_dirY +
               data_BI_dirZ*data_dirZ;

  if(data_BI_nMomenta != 1 || data_BI_nTracks != 1)
    return false;

  if( (deltaX < data_xlow) || (deltaX > data_xhigh) )
    return false;

  if ( (deltaY < data_ylow) || (deltaY > data_yhigh) )
    return false;

  if ( (data_startZ < data_zlow) || (data_startZ > data_zhigh) )
    return false;

  if (cos < data_coslow)
    return false;

  return true;

};

bool CutDataBeamPos()
{
  //https://github.com/calcuttj/PionStudies/blob/master/rDataFrame/eventSelection.C
  /*
.Define("passBeamCut", manual_beamPos_data,
            {"event","reco_beam_startX", "reco_beam_startY", "reco_beam_startZ",
            "reco_beam_trackDirX", "reco_beam_trackDirY", "reco_beam_trackDirZ",
            "data_BI_X", "data_BI_Y", "data_BI_dirX", "data_BI_dirY",
            "data_BI_dirZ", "data_BI_nMomenta", "data_BI_nTracks"})
   */

  return Manual_beamPos_data(-999, AnaIO::reco_beam_startX, AnaIO::reco_beam_startY, AnaIO::reco_beam_startZ,
                             AnaIO::reco_beam_trackDirX, AnaIO::reco_beam_trackDirY, AnaIO::reco_beam_trackDirZ,
                             AnaIO::data_BI_X, AnaIO::data_BI_Y, AnaIO::data_BI_dirX, AnaIO::data_BI_dirY,
                             AnaIO::data_BI_dirZ, AnaIO::data_BI_nMomenta, AnaIO::data_BI_nTracks);
  
}


bool CutBeamAllInOne(const bool kmc)
{
  //
  //standard procedure from pion analyses
  //

  //1. beam ID cut
  if(kmc){
    //"In data the beam Instrumentation is able to filter for these events but is not inside the MC" 
    const bool mc_beampass =(AnaIO::true_beam_PDG == 211 || AnaIO::true_beam_PDG == -13);
    style::FillInRange(AnaIO::hCutbeamID, mc_beampass);
    if(!mc_beampass){
      return false;
    }
  }
  else{
    const bool data_beamID = CutBeamID((*AnaIO::data_BI_PDG_candidates));
    style::FillInRange(AnaIO::hCutbeamID, data_beamID);
    if(!data_beamID){
      return false;
    }
  }

  const int filleventtype = AnaUtils::GetFillEventType();

  //2. primary beam type cut
  style::FillInRange(AnaIO::hCutBeamType, AnaIO::reco_beam_type, filleventtype);
  if(AnaIO::reco_beam_type!=13){//13: Pandora "track like"
    return false;
  }
  
  //3. beam position cut
  const bool kBeamPosPass = kmc ? CutMCBeamPos() : CutDataBeamPos();
  style::FillInRange(AnaIO::hCutBeamPosPass, kBeamPosPass, filleventtype);
  if(!kBeamPosPass){
    return false;
  }
  
  //4. APA3 cut
  style::FillInRange(AnaIO::hCutBeamEndZ, AnaIO::reco_beam_endZ, filleventtype);
  style::FillInRange(AnaIO::hCutBeamEndZPass, !(AnaIO::reco_beam_endZ>=226), filleventtype);
  if(AnaIO::reco_beam_endZ>=226){
    return false;
  }
  
  return true;
}

bool GetBeamdEdx(const int evtType)
{
  //
  //calculate all beam dEdx
  //

  vector<double> startE, lastE;
  AnaUtils::GetdEdx( *AnaIO::reco_beam_calibrated_dEdX, startE, lastE, 2);

  AnaIO::beamNdEdx = startE.size();
  style::FillInRange(AnaIO::hBeamNdEdx, AnaIO::beamNdEdx, evtType);

  const bool kfailN = (AnaIO::beamNdEdx<6);
  if(kfailN){
    return false;
  }

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
  AnaIO::beamStartTME = AnaUtils::GetTruncatedMean(startE, 0, AnaIO::beamNdEdx-6-1, 0.05, 0.6);
  AnaIO::beamLastTME  = AnaUtils::GetTruncatedMean(lastE,  0, 5,                    0.4,  0.95);

  return true;
}

void FillBeamdEdx(const int evtType, const bool kBefore)
{
  //
  //
  //
  if(kBefore){

    GetBeamdEdx(evtType);

    //only for ndEdx>=6, otherwise a huge peak at underflow (0)
    if(AnaIO::beamNdEdx>=6){
      style::FillInRange(AnaIO::hBeamStartTME, AnaIO::beamStartTME, evtType);
      style::FillInRange(AnaIO::hBeamLastTME, AnaIO::beamLastTME, evtType);
      
      style::FillInRange(AnaIO::hBeamStartE0, AnaIO::beamStartE0, evtType);
      style::FillInRange(AnaIO::hBeamStartE1, AnaIO::beamStartE1, evtType);
      style::FillInRange(AnaIO::hBeamStartE2, AnaIO::beamStartE2, evtType);
      style::FillInRange(AnaIO::hBeamStartE3, AnaIO::beamStartE3, evtType);
      style::FillInRange(AnaIO::hBeamStartE4, AnaIO::beamStartE4, evtType);
      style::FillInRange(AnaIO::hBeamStartE5, AnaIO::beamStartE5, evtType);
      
      style::FillInRange(AnaIO::hBeamLastE0, AnaIO::beamLastE0, evtType);
      style::FillInRange(AnaIO::hBeamLastE1, AnaIO::beamLastE1, evtType);
      style::FillInRange(AnaIO::hBeamLastE2, AnaIO::beamLastE2, evtType);
      style::FillInRange(AnaIO::hBeamLastE3, AnaIO::beamLastE3, evtType);
      style::FillInRange(AnaIO::hBeamLastE4, AnaIO::beamLastE4, evtType);
      style::FillInRange(AnaIO::hBeamLastE5, AnaIO::beamLastE5, evtType);
    }
  }
  else{
    //fill all event even ndEdx<6
    //PC = Post-Cut
    style::FillInRange(AnaIO::hBeamPCStartTME,AnaIO::beamStartTME, evtType);
    style::FillInRange(AnaIO::hBeamPCLastTME, AnaIO::beamLastTME, evtType);
    
    style::FillInRange(AnaIO::hBeamPCStartE0, AnaIO::beamStartE0, evtType);
    style::FillInRange(AnaIO::hBeamPCStartE1, AnaIO::beamStartE1, evtType);
    style::FillInRange(AnaIO::hBeamPCStartE2, AnaIO::beamStartE2, evtType);
    style::FillInRange(AnaIO::hBeamPCStartE3, AnaIO::beamStartE3, evtType);
    style::FillInRange(AnaIO::hBeamPCStartE4, AnaIO::beamStartE4, evtType);
    style::FillInRange(AnaIO::hBeamPCStartE5, AnaIO::beamStartE5, evtType);
    
    style::FillInRange(AnaIO::hBeamPCLastE0, AnaIO::beamLastE0, evtType);
    style::FillInRange(AnaIO::hBeamPCLastE1, AnaIO::beamLastE1, evtType);
    style::FillInRange(AnaIO::hBeamPCLastE2, AnaIO::beamLastE2, evtType);
    style::FillInRange(AnaIO::hBeamPCLastE3, AnaIO::beamLastE3, evtType);
    style::FillInRange(AnaIO::hBeamPCLastE4, AnaIO::beamLastE4, evtType);
    style::FillInRange(AnaIO::hBeamPCLastE5, AnaIO::beamLastE5, evtType);
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

//end of namespace
}

#endif
