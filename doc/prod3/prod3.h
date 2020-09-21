//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Sep 21 14:37:17 2020 by ROOT version 6.20/04
// from TTree beamana/beam analysis tree
// found on file: ../../DUNEprotoTKI_data/v3_9_18_20/pionana_Prod3_mc_1GeV_9_18_20.root
//////////////////////////////////////////////////////////

#ifndef prod3_h
#define prod3_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "string"

class prod3 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           subrun;
   Int_t           event;
   Int_t           MC;
   Int_t           reco_beam_type;
   Double_t        reco_beam_startX;
   Double_t        reco_beam_startY;
   Double_t        reco_beam_startZ;
   Double_t        reco_beam_endX;
   Double_t        reco_beam_endY;
   Double_t        reco_beam_endZ;
   Double_t        reco_beam_len;
   Double_t        reco_beam_alt_len;
   Double_t        reco_beam_calo_startX;
   Double_t        reco_beam_calo_startY;
   Double_t        reco_beam_calo_startZ;
   Double_t        reco_beam_calo_endX;
   Double_t        reco_beam_calo_endY;
   Double_t        reco_beam_calo_endZ;
   vector<double>  *reco_beam_calo_startDirX;
   vector<double>  *reco_beam_calo_startDirY;
   vector<double>  *reco_beam_calo_startDirZ;
   vector<double>  *reco_beam_calo_endDirX;
   vector<double>  *reco_beam_calo_endDirY;
   vector<double>  *reco_beam_calo_endDirZ;
   Double_t        reco_beam_trackDirX;
   Double_t        reco_beam_trackDirY;
   Double_t        reco_beam_trackDirZ;
   Double_t        reco_beam_trackEndDirX;
   Double_t        reco_beam_trackEndDirY;
   Double_t        reco_beam_trackEndDirZ;
   Double_t        reco_beam_vtxX;
   Double_t        reco_beam_vtxY;
   Double_t        reco_beam_vtxZ;
   Int_t           reco_beam_vertex_nHits;
   Double_t        reco_beam_vertex_michel_score;
   Int_t           reco_beam_trackID;
   vector<double>  *reco_beam_dQdX;
   vector<double>  *reco_beam_dEdX;
   vector<double>  *reco_beam_calibrated_dEdX;
   vector<double>  *reco_beam_resRange;
   vector<double>  *reco_beam_TrkPitch;
   vector<double>  *reco_beam_calo_wire;
   vector<double>  *reco_beam_calo_wire_z;
   vector<double>  *reco_beam_calo_tick;
   vector<int>     *reco_beam_calo_TPC;
   vector<int>     *reco_beam_hit_true_ID;
   vector<int>     *reco_beam_hit_true_slice;
   vector<int>     *reco_beam_hit_true_origin;
   Int_t           reco_beam_nTrackDaughters;
   Int_t           reco_beam_nShowerDaughters;
   Bool_t          reco_beam_flipped;
   Bool_t          reco_beam_passes_beam_cuts;
   Int_t           reco_beam_PFP_ID;
   Int_t           reco_beam_PFP_nHits;
   Double_t        reco_beam_PFP_trackScore;
   Double_t        reco_beam_PFP_emScore;
   Double_t        reco_beam_PFP_michelScore;
   Double_t        reco_beam_PFP_trackScore_collection;
   Double_t        reco_beam_PFP_emScore_collection;
   Double_t        reco_beam_PFP_michelScore_collection;
   Int_t           reco_beam_allTrack_ID;
   Bool_t          reco_beam_allTrack_beam_cuts;
   Bool_t          reco_beam_allTrack_flipped;
   Double_t        reco_beam_allTrack_len;
   Double_t        reco_beam_allTrack_startX;
   Double_t        reco_beam_allTrack_startY;
   Double_t        reco_beam_allTrack_startZ;
   Double_t        reco_beam_allTrack_endX;
   Double_t        reco_beam_allTrack_endY;
   Double_t        reco_beam_allTrack_endZ;
   Double_t        reco_beam_allTrack_trackDirX;
   Double_t        reco_beam_allTrack_trackDirY;
   Double_t        reco_beam_allTrack_trackDirZ;
   Double_t        reco_beam_allTrack_trackEndDirX;
   Double_t        reco_beam_allTrack_trackEndDirY;
   Double_t        reco_beam_allTrack_trackEndDirZ;
   vector<double>  *reco_beam_allTrack_resRange;
   vector<double>  *reco_beam_allTrack_calibrated_dEdX;
   Double_t        reco_beam_allTrack_Chi2_proton;
   Int_t           reco_beam_allTrack_Chi2_ndof;
   vector<double>  *reco_track_startX;
   vector<double>  *reco_track_startY;
   vector<double>  *reco_track_startZ;
   vector<double>  *reco_track_endX;
   vector<double>  *reco_track_endY;
   vector<double>  *reco_track_endZ;
   vector<double>  *reco_track_michel_score;
   vector<int>     *reco_track_ID;
   vector<int>     *reco_track_nHits;
   vector<int>     *reco_daughter_PFP_true_byHits_PDG;
   vector<int>     *reco_daughter_PFP_true_byHits_ID;
   vector<int>     *reco_daughter_PFP_true_byHits_origin;
   vector<int>     *reco_daughter_PFP_true_byHits_parID;
   vector<int>     *reco_daughter_PFP_true_byHits_parPDG;
   vector<string>  *reco_daughter_PFP_true_byHits_process;
   vector<unsigned long> *reco_daughter_PFP_true_byHits_sharedHits;
   vector<unsigned long> *reco_daughter_PFP_true_byHits_emHits;
   vector<double>  *reco_daughter_PFP_true_byHits_len;
   vector<double>  *reco_daughter_PFP_true_byHits_startX;
   vector<double>  *reco_daughter_PFP_true_byHits_startY;
   vector<double>  *reco_daughter_PFP_true_byHits_startZ;
   vector<double>  *reco_daughter_PFP_true_byHits_endX;
   vector<double>  *reco_daughter_PFP_true_byHits_endY;
   vector<double>  *reco_daughter_PFP_true_byHits_endZ;
   vector<double>  *reco_daughter_PFP_true_byHits_startPx;
   vector<double>  *reco_daughter_PFP_true_byHits_startPy;
   vector<double>  *reco_daughter_PFP_true_byHits_startPz;
   vector<double>  *reco_daughter_PFP_true_byHits_startP;
   vector<double>  *reco_daughter_PFP_true_byHits_startE;
   vector<string>  *reco_daughter_PFP_true_byHits_endProcess;
   vector<double>  *reco_daughter_PFP_true_byHits_purity;
   vector<double>  *reco_daughter_PFP_true_byHits_completeness;
   vector<int>     *reco_daughter_PFP_true_byE_PDG;
   vector<double>  *reco_daughter_PFP_true_byE_len;
   vector<double>  *reco_daughter_PFP_true_byE_completeness;
   vector<double>  *reco_daughter_PFP_true_byE_purity;
   vector<int>     *reco_daughter_allTrack_ID;
   vector<vector<double> > *reco_daughter_allTrack_dQdX_SCE;
   vector<vector<double> > *reco_daughter_allTrack_dEdX_SCE;
   vector<vector<double> > *reco_daughter_allTrack_resRange_SCE;
   vector<vector<double> > *reco_daughter_allTrack_calibrated_dEdX_SCE;
   vector<double>  *reco_daughter_allTrack_Chi2_proton;
   vector<int>     *reco_daughter_allTrack_Chi2_ndof;
   vector<double>  *reco_daughter_allTrack_Chi2_proton_plane0;
   vector<double>  *reco_daughter_allTrack_Chi2_proton_plane1;
   vector<int>     *reco_daughter_allTrack_Chi2_ndof_plane0;
   vector<int>     *reco_daughter_allTrack_Chi2_ndof_plane1;
   vector<vector<double> > *reco_daughter_allTrack_calibrated_dEdX_SCE_plane0;
   vector<vector<double> > *reco_daughter_allTrack_calibrated_dEdX_SCE_plane1;
   vector<vector<double> > *reco_daughter_allTrack_resRange_plane0;
   vector<vector<double> > *reco_daughter_allTrack_resRange_plane1;
   vector<double>  *reco_daughter_allTrack_Theta;
   vector<double>  *reco_daughter_allTrack_Phi;
   vector<double>  *reco_daughter_allTrack_len;
   vector<double>  *reco_daughter_allTrack_alt_len;
   vector<double>  *reco_daughter_allTrack_startX;
   vector<double>  *reco_daughter_allTrack_startY;
   vector<double>  *reco_daughter_allTrack_startZ;
   vector<double>  *reco_daughter_allTrack_endX;
   vector<double>  *reco_daughter_allTrack_endY;
   vector<double>  *reco_daughter_allTrack_endZ;
   vector<double>  *reco_daughter_allTrack_dR;
   vector<double>  *reco_daughter_allTrack_to_vertex;
   vector<double>  *reco_daughter_allTrack_vertex_michel_score;
   vector<int>     *reco_daughter_allTrack_vertex_nHits;
   vector<int>     *reco_daughter_allShower_ID;
   vector<double>  *reco_daughter_allShower_len;
   vector<double>  *reco_daughter_allShower_startX;
   vector<double>  *reco_daughter_allShower_startY;
   vector<double>  *reco_daughter_allShower_startZ;
   vector<double>  *reco_daughter_allShower_dirX;
   vector<double>  *reco_daughter_allShower_dirY;
   vector<double>  *reco_daughter_allShower_dirZ;
   vector<double>  *reco_daughter_allShower_energy;
   vector<int>     *reco_daughter_PFP_ID;
   vector<int>     *reco_daughter_PFP_nHits;
   vector<int>     *reco_daughter_PFP_nHits_collection;
   vector<double>  *reco_daughter_PFP_trackScore;
   vector<double>  *reco_daughter_PFP_emScore;
   vector<double>  *reco_daughter_PFP_michelScore;
   vector<double>  *reco_daughter_PFP_trackScore_collection;
   vector<double>  *reco_daughter_PFP_emScore_collection;
   vector<double>  *reco_daughter_PFP_michelScore_collection;
   Int_t           true_beam_PDG;
   Int_t           true_beam_ID;
   string          *true_beam_endProcess;
   Double_t        true_beam_endX;
   Double_t        true_beam_endY;
   Double_t        true_beam_endZ;
   Double_t        true_beam_startX;
   Double_t        true_beam_startY;
   Double_t        true_beam_startZ;
   Double_t        true_beam_startPx;
   Double_t        true_beam_startPy;
   Double_t        true_beam_startPz;
   Double_t        true_beam_startP;
   Double_t        true_beam_endPx;
   Double_t        true_beam_endPy;
   Double_t        true_beam_endPz;
   Double_t        true_beam_endP;
   Double_t        true_beam_startDirX;
   Double_t        true_beam_startDirY;
   Double_t        true_beam_startDirZ;
   Int_t           true_beam_nElasticScatters;
   vector<double>  *true_beam_elastic_costheta;
   vector<double>  *true_beam_elastic_X;
   vector<double>  *true_beam_elastic_Y;
   vector<double>  *true_beam_elastic_Z;
   vector<double>  *true_beam_elastic_deltaE;
   vector<double>  *true_beam_elastic_IDE_edep;
   Double_t        true_beam_IDE_totalDep;
   Bool_t          true_beam_IDE_found_in_recoVtx;
   Int_t           true_beam_nHits;
   vector<vector<int> > *true_beam_reco_byHits_PFP_ID;
   vector<vector<int> > *true_beam_reco_byHits_PFP_nHits;
   vector<vector<int> > *true_beam_reco_byHits_allTrack_ID;
   Int_t           true_daughter_nPi0;
   Int_t           true_daughter_nPiPlus;
   Int_t           true_daughter_nProton;
   Int_t           true_daughter_nNeutron;
   Int_t           true_daughter_nPiMinus;
   Int_t           true_daughter_nNucleus;
   Int_t           reco_beam_vertex_slice;
   vector<int>     *true_beam_daughter_PDG;
   vector<int>     *true_beam_daughter_ID;
   vector<double>  *true_beam_daughter_len;
   vector<double>  *true_beam_daughter_startX;
   vector<double>  *true_beam_daughter_startY;
   vector<double>  *true_beam_daughter_startZ;
   vector<double>  *true_beam_daughter_startPx;
   vector<double>  *true_beam_daughter_startPy;
   vector<double>  *true_beam_daughter_startPz;
   vector<double>  *true_beam_daughter_startP;
   vector<double>  *true_beam_daughter_endX;
   vector<double>  *true_beam_daughter_endY;
   vector<double>  *true_beam_daughter_endZ;
   vector<string>  *true_beam_daughter_Process;
   vector<string>  *true_beam_daughter_endProcess;
   vector<int>     *true_beam_daughter_nHits;
   vector<vector<int> > *true_beam_daughter_reco_byHits_PFP_ID;
   vector<vector<int> > *true_beam_daughter_reco_byHits_PFP_nHits;
   vector<vector<double> > *true_beam_daughter_reco_byHits_PFP_trackScore;
   vector<vector<int> > *true_beam_daughter_reco_byHits_allTrack_ID;
   vector<vector<double> > *true_beam_daughter_reco_byHits_allTrack_startX;
   vector<vector<double> > *true_beam_daughter_reco_byHits_allTrack_startY;
   vector<vector<double> > *true_beam_daughter_reco_byHits_allTrack_startZ;
   vector<vector<double> > *true_beam_daughter_reco_byHits_allTrack_endX;
   vector<vector<double> > *true_beam_daughter_reco_byHits_allTrack_endY;
   vector<vector<double> > *true_beam_daughter_reco_byHits_allTrack_endZ;
   vector<vector<double> > *true_beam_daughter_reco_byHits_allTrack_len;
   vector<vector<int> > *true_beam_daughter_reco_byHits_allShower_ID;
   vector<vector<double> > *true_beam_daughter_reco_byHits_allShower_startX;
   vector<vector<double> > *true_beam_daughter_reco_byHits_allShower_startY;
   vector<vector<double> > *true_beam_daughter_reco_byHits_allShower_startZ;
   vector<vector<double> > *true_beam_daughter_reco_byHits_allShower_len;
   vector<int>     *true_beam_Pi0_decay_ID;
   vector<int>     *true_beam_Pi0_decay_parID;
   vector<int>     *true_beam_Pi0_decay_PDG;
   vector<double>  *true_beam_Pi0_decay_startP;
   vector<double>  *true_beam_Pi0_decay_startPx;
   vector<double>  *true_beam_Pi0_decay_startPy;
   vector<double>  *true_beam_Pi0_decay_startPz;
   vector<double>  *true_beam_Pi0_decay_startX;
   vector<double>  *true_beam_Pi0_decay_startY;
   vector<double>  *true_beam_Pi0_decay_startZ;
   vector<double>  *true_beam_Pi0_decay_len;
   vector<int>     *true_beam_Pi0_decay_nHits;
   vector<vector<int> > *true_beam_Pi0_decay_reco_byHits_PFP_ID;
   vector<vector<int> > *true_beam_Pi0_decay_reco_byHits_PFP_nHits;
   vector<vector<double> > *true_beam_Pi0_decay_reco_byHits_PFP_trackScore;
   vector<vector<int> > *true_beam_Pi0_decay_reco_byHits_allTrack_ID;
   vector<vector<double> > *true_beam_Pi0_decay_reco_byHits_allTrack_startX;
   vector<vector<double> > *true_beam_Pi0_decay_reco_byHits_allTrack_startY;
   vector<vector<double> > *true_beam_Pi0_decay_reco_byHits_allTrack_startZ;
   vector<vector<double> > *true_beam_Pi0_decay_reco_byHits_allTrack_endX;
   vector<vector<double> > *true_beam_Pi0_decay_reco_byHits_allTrack_endY;
   vector<vector<double> > *true_beam_Pi0_decay_reco_byHits_allTrack_endZ;
   vector<vector<double> > *true_beam_Pi0_decay_reco_byHits_allTrack_len;
   vector<vector<int> > *true_beam_Pi0_decay_reco_byHits_allShower_ID;
   vector<vector<double> > *true_beam_Pi0_decay_reco_byHits_allShower_startX;
   vector<vector<double> > *true_beam_Pi0_decay_reco_byHits_allShower_startY;
   vector<vector<double> > *true_beam_Pi0_decay_reco_byHits_allShower_startZ;
   vector<vector<double> > *true_beam_Pi0_decay_reco_byHits_allShower_len;
   vector<int>     *true_beam_grand_daughter_ID;
   vector<int>     *true_beam_grand_daughter_parID;
   vector<int>     *true_beam_grand_daughter_PDG;
   vector<int>     *true_beam_grand_daughter_nHits;
   vector<string>  *true_beam_grand_daughter_Process;
   vector<string>  *true_beam_grand_daughter_endProcess;
   string          *reco_beam_true_byE_endProcess;
   string          *reco_beam_true_byE_process;
   Int_t           reco_beam_true_byE_origin;
   Int_t           reco_beam_true_byE_PDG;
   Int_t           reco_beam_true_byE_ID;
   string          *reco_beam_true_byHits_endProcess;
   string          *reco_beam_true_byHits_process;
   Int_t           reco_beam_true_byHits_origin;
   Int_t           reco_beam_true_byHits_PDG;
   Int_t           reco_beam_true_byHits_ID;
   Bool_t          reco_beam_true_byE_matched;
   Bool_t          reco_beam_true_byHits_matched;
   Double_t        reco_beam_true_byHits_purity;
   vector<string>  *true_beam_processes;
   vector<int>     *true_beam_process_slice;
   vector<int>     *true_beam_process_dSlice;
   vector<int>     *true_beam_process_matched;
   Double_t        data_BI_P;
   vector<double>  *data_BI_TOF;
   vector<int>     *data_BI_TOF_Chan;
   Double_t        data_BI_X;
   Double_t        data_BI_Y;
   Double_t        data_BI_Z;
   Double_t        data_BI_dirX;
   Double_t        data_BI_dirY;
   Double_t        data_BI_dirZ;
   Int_t           data_BI_nFibersP1;
   Int_t           data_BI_nFibersP2;
   Int_t           data_BI_nFibersP3;
   vector<int>     *data_BI_PDG_candidates;
   Int_t           data_BI_nTracks;
   Int_t           data_BI_nMomenta;
   Bool_t          quality_reco_view_0_hits_in_TPC5;
   Bool_t          quality_reco_view_1_hits_in_TPC5;
   Bool_t          quality_reco_view_2_hits_in_TPC5;
   Double_t        quality_reco_max_lateral;
   Double_t        quality_reco_max_segment;
   Double_t        quality_reco_view_0_max_segment;
   Double_t        quality_reco_view_1_max_segment;
   Double_t        quality_reco_view_2_max_segment;
   Double_t        quality_reco_view_0_wire_backtrack;
   Double_t        quality_reco_view_1_wire_backtrack;
   Double_t        quality_reco_view_2_wire_backtrack;
   vector<double>  *quality_reco_view_0_wire;
   vector<double>  *quality_reco_view_1_wire;
   vector<double>  *quality_reco_view_2_wire;
   vector<double>  *quality_reco_view_2_z;
   vector<double>  *quality_reco_view_0_tick;
   vector<double>  *quality_reco_view_1_tick;
   vector<double>  *quality_reco_view_2_tick;
   Double_t        reco_beam_Chi2_proton;
   Int_t           reco_beam_Chi2_ndof;
   vector<double>  *reco_beam_cosmic_candidate_lower_hits;
   vector<double>  *reco_beam_cosmic_candidate_upper_hits;
   vector<int>     *reco_beam_cosmic_candidate_ID;
   Bool_t          beam_has_cosmic_IDE;
   vector<int>     *cosmic_has_beam_IDE;
   Int_t           n_cosmics_with_beam_IDE;
   vector<double>  *reco_daughter_allTrack_momByRange_proton;
   vector<double>  *reco_daughter_allTrack_momByRange_muon;
   Double_t        reco_beam_momByRange_proton;
   Double_t        reco_beam_momByRange_muon;
   vector<double>  *reco_daughter_allTrack_momByRange_alt_proton;
   vector<double>  *reco_daughter_allTrack_momByRange_alt_muon;
   Double_t        reco_beam_momByRange_alt_proton;
   Double_t        reco_beam_momByRange_alt_muon;
   Double_t        reco_beam_true_byE_endPx;
   Double_t        reco_beam_true_byE_endPy;
   Double_t        reco_beam_true_byE_endPz;
   Double_t        reco_beam_true_byE_endE;
   Double_t        reco_beam_true_byE_endP;
   Double_t        reco_beam_true_byE_startPx;
   Double_t        reco_beam_true_byE_startPy;
   Double_t        reco_beam_true_byE_startPz;
   Double_t        reco_beam_true_byE_startE;
   Double_t        reco_beam_true_byE_startP;
   Double_t        reco_beam_true_byHits_endPx;
   Double_t        reco_beam_true_byHits_endPy;
   Double_t        reco_beam_true_byHits_endPz;
   Double_t        reco_beam_true_byHits_endE;
   Double_t        reco_beam_true_byHits_endP;
   Double_t        reco_beam_true_byHits_startPx;
   Double_t        reco_beam_true_byHits_startPy;
   Double_t        reco_beam_true_byHits_startPz;
   Double_t        reco_beam_true_byHits_startE;
   Double_t        reco_beam_true_byHits_startP;
   vector<double>  *reco_beam_incidentEnergies;
   Double_t        reco_beam_interactingEnergy;
   vector<double>  *true_beam_incidentEnergies;
   Double_t        true_beam_interactingEnergy;
   vector<int>     *true_beam_slices;
   vector<int>     *true_beam_slices_found;
   vector<int>     *true_beam_slices_nIDEs;
   vector<double>  *true_beam_slices_deltaE;
   Double_t        em_energy;
   vector<double>  *true_beam_traj_X;
   vector<double>  *true_beam_traj_Y;
   vector<double>  *true_beam_traj_Z;
   vector<double>  *true_beam_traj_KE;
   vector<double>  *g4rw_primary_weights;
   vector<double>  *g4rw_primary_plus_sigma_weight;
   vector<double>  *g4rw_primary_minus_sigma_weight;
   vector<string>  *g4rw_primary_var;
   vector<double>  *g4rw_alt_primary_plus_sigma_weight;
   vector<double>  *g4rw_alt_primary_minus_sigma_weight;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_subrun;   //!
   TBranch        *b_event;   //!
   TBranch        *b_MC;   //!
   TBranch        *b_reco_beam_type;   //!
   TBranch        *b_reco_beam_startX;   //!
   TBranch        *b_reco_beam_startY;   //!
   TBranch        *b_reco_beam_startZ;   //!
   TBranch        *b_reco_beam_endX;   //!
   TBranch        *b_reco_beam_endY;   //!
   TBranch        *b_reco_beam_endZ;   //!
   TBranch        *b_reco_beam_len;   //!
   TBranch        *b_reco_beam_alt_len;   //!
   TBranch        *b_reco_beam_calo_startX;   //!
   TBranch        *b_reco_beam_calo_startY;   //!
   TBranch        *b_reco_beam_calo_startZ;   //!
   TBranch        *b_reco_beam_calo_endX;   //!
   TBranch        *b_reco_beam_calo_endY;   //!
   TBranch        *b_reco_beam_calo_endZ;   //!
   TBranch        *b_reco_beam_calo_startDirX;   //!
   TBranch        *b_reco_beam_calo_startDirY;   //!
   TBranch        *b_reco_beam_calo_startDirZ;   //!
   TBranch        *b_reco_beam_calo_endDirX;   //!
   TBranch        *b_reco_beam_calo_endDirY;   //!
   TBranch        *b_reco_beam_calo_endDirZ;   //!
   TBranch        *b_reco_beam_trackDirX;   //!
   TBranch        *b_reco_beam_trackDirY;   //!
   TBranch        *b_reco_beam_trackDirZ;   //!
   TBranch        *b_reco_beam_trackEndDirX;   //!
   TBranch        *b_reco_beam_trackEndDirY;   //!
   TBranch        *b_reco_beam_trackEndDirZ;   //!
   TBranch        *b_reco_beam_vtxX;   //!
   TBranch        *b_reco_beam_vtxY;   //!
   TBranch        *b_reco_beam_vtxZ;   //!
   TBranch        *b_reco_beam_vertex_nHits;   //!
   TBranch        *b_reco_beam_vertex_michel_score;   //!
   TBranch        *b_reco_beam_trackID;   //!
   TBranch        *b_reco_beam_dQdX;   //!
   TBranch        *b_reco_beam_dEdX;   //!
   TBranch        *b_reco_beam_calibrated_dEdX;   //!
   TBranch        *b_reco_beam_resRange;   //!
   TBranch        *b_reco_beam_TrkPitch;   //!
   TBranch        *b_reco_beam_calo_wire;   //!
   TBranch        *b_reco_beam_calo_wire_z;   //!
   TBranch        *b_reco_beam_calo_tick;   //!
   TBranch        *b_reco_beam_calo_TPC;   //!
   TBranch        *b_reco_beam_hit_true_ID;   //!
   TBranch        *b_reco_beam_hit_true_slice;   //!
   TBranch        *b_reco_beam_hit_true_origin;   //!
   TBranch        *b_reco_beam_nTrackDaughters;   //!
   TBranch        *b_reco_beam_nShowerDaughters;   //!
   TBranch        *b_reco_beam_flipped;   //!
   TBranch        *b_reco_beam_passes_beam_cuts;   //!
   TBranch        *b_reco_beam_PFP_ID;   //!
   TBranch        *b_reco_beam_PFP_nHits;   //!
   TBranch        *b_reco_beam_PFP_trackScore;   //!
   TBranch        *b_reco_beam_PFP_emScore;   //!
   TBranch        *b_reco_beam_PFP_michelScore;   //!
   TBranch        *b_reco_beam_PFP_trackScore_collection;   //!
   TBranch        *b_reco_beam_PFP_emScore_collection;   //!
   TBranch        *b_reco_beam_PFP_michelScore_collection;   //!
   TBranch        *b_reco_beam_allTrack_ID;   //!
   TBranch        *b_reco_beam_allTrack_beam_cuts;   //!
   TBranch        *b_reco_beam_allTrack_flipped;   //!
   TBranch        *b_reco_beam_allTrack_len;   //!
   TBranch        *b_reco_beam_allTrack_startX;   //!
   TBranch        *b_reco_beam_allTrack_startY;   //!
   TBranch        *b_reco_beam_allTrack_startZ;   //!
   TBranch        *b_reco_beam_allTrack_endX;   //!
   TBranch        *b_reco_beam_allTrack_endY;   //!
   TBranch        *b_reco_beam_allTrack_endZ;   //!
   TBranch        *b_reco_beam_allTrack_trackDirX;   //!
   TBranch        *b_reco_beam_allTrack_trackDirY;   //!
   TBranch        *b_reco_beam_allTrack_trackDirZ;   //!
   TBranch        *b_reco_beam_allTrack_trackEndDirX;   //!
   TBranch        *b_reco_beam_allTrack_trackEndDirY;   //!
   TBranch        *b_reco_beam_allTrack_trackEndDirZ;   //!
   TBranch        *b_reco_beam_allTrack_resRange;   //!
   TBranch        *b_reco_beam_allTrack_calibrated_dEdX;   //!
   TBranch        *b_reco_beam_allTrack_Chi2_proton;   //!
   TBranch        *b_reco_beam_allTrack_Chi2_ndof;   //!
   TBranch        *b_reco_track_startX;   //!
   TBranch        *b_reco_track_startY;   //!
   TBranch        *b_reco_track_startZ;   //!
   TBranch        *b_reco_track_endX;   //!
   TBranch        *b_reco_track_endY;   //!
   TBranch        *b_reco_track_endZ;   //!
   TBranch        *b_reco_track_michel_score;   //!
   TBranch        *b_reco_track_ID;   //!
   TBranch        *b_reco_track_nHits;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_PDG;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_ID;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_origin;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_parID;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_parPDG;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_process;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_sharedHits;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_emHits;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_len;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_startX;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_startY;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_startZ;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_endX;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_endY;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_endZ;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_startPx;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_startPy;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_startPz;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_startP;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_startE;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_endProcess;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_purity;   //!
   TBranch        *b_reco_daughter_PFP_true_byHits_completeness;   //!
   TBranch        *b_reco_daughter_PFP_true_byE_PDG;   //!
   TBranch        *b_reco_daughter_PFP_true_byE_len;   //!
   TBranch        *b_reco_daughter_PFP_true_byE_completeness;   //!
   TBranch        *b_reco_daughter_PFP_true_byE_purity;   //!
   TBranch        *b_reco_daughter_allTrack_ID;   //!
   TBranch        *b_reco_daughter_allTrack_dQdX_SCE;   //!
   TBranch        *b_reco_daughter_allTrack_dEdX_SCE;   //!
   TBranch        *b_reco_daughter_allTrack_resRange_SCE;   //!
   TBranch        *b_reco_daughter_allTrack_calibrated_dEdX_SCE;   //!
   TBranch        *b_reco_daughter_allTrack_Chi2_proton;   //!
   TBranch        *b_reco_daughter_allTrack_Chi2_ndof;   //!
   TBranch        *b_reco_daughter_allTrack_Chi2_proton_plane0;   //!
   TBranch        *b_reco_daughter_allTrack_Chi2_proton_plane1;   //!
   TBranch        *b_reco_daughter_allTrack_Chi2_ndof_plane0;   //!
   TBranch        *b_reco_daughter_allTrack_Chi2_ndof_plane1;   //!
   TBranch        *b_reco_daughter_allTrack_calibrated_dEdX_SCE_plane0;   //!
   TBranch        *b_reco_daughter_allTrack_calibrated_dEdX_SCE_plane1;   //!
   TBranch        *b_reco_daughter_allTrack_resRange_plane0;   //!
   TBranch        *b_reco_daughter_allTrack_resRange_plane1;   //!
   TBranch        *b_reco_daughter_allTrack_Theta;   //!
   TBranch        *b_reco_daughter_allTrack_Phi;   //!
   TBranch        *b_reco_daughter_allTrack_len;   //!
   TBranch        *b_reco_daughter_allTrack_alt_len;   //!
   TBranch        *b_reco_daughter_allTrack_startX;   //!
   TBranch        *b_reco_daughter_allTrack_startY;   //!
   TBranch        *b_reco_daughter_allTrack_startZ;   //!
   TBranch        *b_reco_daughter_allTrack_endX;   //!
   TBranch        *b_reco_daughter_allTrack_endY;   //!
   TBranch        *b_reco_daughter_allTrack_endZ;   //!
   TBranch        *b_reco_daughter_allTrack_dR;   //!
   TBranch        *b_reco_daughter_allTrack_to_vertex;   //!
   TBranch        *b_reco_daughter_allTrack_vertex_michel_score;   //!
   TBranch        *b_reco_daughter_allTrack_vertex_nHits;   //!
   TBranch        *b_reco_daughter_allShower_ID;   //!
   TBranch        *b_reco_daughter_allShower_len;   //!
   TBranch        *b_reco_daughter_allShower_startX;   //!
   TBranch        *b_reco_daughter_allShower_startY;   //!
   TBranch        *b_reco_daughter_allShower_startZ;   //!
   TBranch        *b_reco_daughter_allShower_dirX;   //!
   TBranch        *b_reco_daughter_allShower_dirY;   //!
   TBranch        *b_reco_daughter_allShower_dirZ;   //!
   TBranch        *b_reco_daughter_allShower_energy;   //!
   TBranch        *b_reco_daughter_PFP_ID;   //!
   TBranch        *b_reco_daughter_PFP_nHits;   //!
   TBranch        *b_reco_daughter_PFP_nHits_collection;   //!
   TBranch        *b_reco_daughter_PFP_trackScore;   //!
   TBranch        *b_reco_daughter_PFP_emScore;   //!
   TBranch        *b_reco_daughter_PFP_michelScore;   //!
   TBranch        *b_reco_daughter_PFP_trackScore_collection;   //!
   TBranch        *b_reco_daughter_PFP_emScore_collection;   //!
   TBranch        *b_reco_daughter_PFP_michelScore_collection;   //!
   TBranch        *b_true_beam_PDG;   //!
   TBranch        *b_true_beam_ID;   //!
   TBranch        *b_true_beam_endProcess;   //!
   TBranch        *b_true_beam_endX;   //!
   TBranch        *b_true_beam_endY;   //!
   TBranch        *b_true_beam_endZ;   //!
   TBranch        *b_true_beam_startX;   //!
   TBranch        *b_true_beam_startY;   //!
   TBranch        *b_true_beam_startZ;   //!
   TBranch        *b_true_beam_startPx;   //!
   TBranch        *b_true_beam_startPy;   //!
   TBranch        *b_true_beam_startPz;   //!
   TBranch        *b_true_beam_startP;   //!
   TBranch        *b_true_beam_endPx;   //!
   TBranch        *b_true_beam_endPy;   //!
   TBranch        *b_true_beam_endPz;   //!
   TBranch        *b_true_beam_endP;   //!
   TBranch        *b_true_beam_startDirX;   //!
   TBranch        *b_true_beam_startDirY;   //!
   TBranch        *b_true_beam_startDirZ;   //!
   TBranch        *b_true_beam_nElasticScatters;   //!
   TBranch        *b_true_beam_elastic_costheta;   //!
   TBranch        *b_true_beam_elastic_X;   //!
   TBranch        *b_true_beam_elastic_Y;   //!
   TBranch        *b_true_beam_elastic_Z;   //!
   TBranch        *b_true_beam_elastic_deltaE;   //!
   TBranch        *b_true_beam_elastic_IDE_edep;   //!
   TBranch        *b_true_beam_IDE_totalDep;   //!
   TBranch        *b_true_beam_IDE_found_in_recoVtx;   //!
   TBranch        *b_true_beam_nHits;   //!
   TBranch        *b_true_beam_reco_byHits_PFP_ID;   //!
   TBranch        *b_true_beam_reco_byHits_PFP_nHits;   //!
   TBranch        *b_true_beam_reco_byHits_allTrack_ID;   //!
   TBranch        *b_true_daughter_nPi0;   //!
   TBranch        *b_true_daughter_nPiPlus;   //!
   TBranch        *b_true_daughter_nProton;   //!
   TBranch        *b_true_daughter_nNeutron;   //!
   TBranch        *b_true_daughter_nPiMinus;   //!
   TBranch        *b_true_daughter_nNucleus;   //!
   TBranch        *b_reco_beam_vertex_slice;   //!
   TBranch        *b_true_beam_daughter_PDG;   //!
   TBranch        *b_true_beam_daughter_ID;   //!
   TBranch        *b_true_beam_daughter_len;   //!
   TBranch        *b_true_beam_daughter_startX;   //!
   TBranch        *b_true_beam_daughter_startY;   //!
   TBranch        *b_true_beam_daughter_startZ;   //!
   TBranch        *b_true_beam_daughter_startPx;   //!
   TBranch        *b_true_beam_daughter_startPy;   //!
   TBranch        *b_true_beam_daughter_startPz;   //!
   TBranch        *b_true_beam_daughter_startP;   //!
   TBranch        *b_true_beam_daughter_endX;   //!
   TBranch        *b_true_beam_daughter_endY;   //!
   TBranch        *b_true_beam_daughter_endZ;   //!
   TBranch        *b_true_beam_daughter_Process;   //!
   TBranch        *b_true_beam_daughter_endProcess;   //!
   TBranch        *b_true_beam_daughter_nHits;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_PFP_ID;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_PFP_nHits;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_PFP_trackScore;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_allTrack_ID;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_allTrack_startX;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_allTrack_startY;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_allTrack_startZ;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_allTrack_endX;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_allTrack_endY;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_allTrack_endZ;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_allTrack_len;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_allShower_ID;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_allShower_startX;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_allShower_startY;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_allShower_startZ;   //!
   TBranch        *b_true_beam_daughter_reco_byHits_allShower_len;   //!
   TBranch        *b_true_beam_Pi0_decay_ID;   //!
   TBranch        *b_true_beam_Pi0_decay_parID;   //!
   TBranch        *b_true_beam_Pi0_decay_PDG;   //!
   TBranch        *b_true_beam_Pi0_decay_startP;   //!
   TBranch        *b_true_beam_Pi0_decay_startPx;   //!
   TBranch        *b_true_beam_Pi0_decay_startPy;   //!
   TBranch        *b_true_beam_Pi0_decay_startPz;   //!
   TBranch        *b_true_beam_Pi0_decay_startX;   //!
   TBranch        *b_true_beam_Pi0_decay_startY;   //!
   TBranch        *b_true_beam_Pi0_decay_startZ;   //!
   TBranch        *b_true_beam_Pi0_decay_len;   //!
   TBranch        *b_true_beam_Pi0_decay_nHits;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_PFP_ID;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_PFP_nHits;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_PFP_trackScore;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_allTrack_ID;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_allTrack_startX;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_allTrack_startY;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_allTrack_startZ;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_allTrack_endX;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_allTrack_endY;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_allTrack_endZ;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_allTrack_len;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_allShower_ID;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_allShower_startX;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_allShower_startY;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_allShower_startZ;   //!
   TBranch        *b_true_beam_Pi0_decay_reco_byHits_allShower_len;   //!
   TBranch        *b_true_beam_grand_daughter_ID;   //!
   TBranch        *b_true_beam_grand_daughter_parID;   //!
   TBranch        *b_true_beam_grand_daughter_PDG;   //!
   TBranch        *b_true_beam_grand_daughter_nHits;   //!
   TBranch        *b_true_beam_grand_daughter_Process;   //!
   TBranch        *b_true_beam_grand_daughter_endProcess;   //!
   TBranch        *b_reco_beam_true_byE_endProcess;   //!
   TBranch        *b_reco_beam_true_byE_process;   //!
   TBranch        *b_reco_beam_true_byE_origin;   //!
   TBranch        *b_reco_beam_true_byE_PDG;   //!
   TBranch        *b_reco_beam_true_byE_ID;   //!
   TBranch        *b_reco_beam_true_byHits_endProcess;   //!
   TBranch        *b_reco_beam_true_byHits_process;   //!
   TBranch        *b_reco_beam_true_byHits_origin;   //!
   TBranch        *b_reco_beam_true_byHits_PDG;   //!
   TBranch        *b_reco_beam_true_byHits_ID;   //!
   TBranch        *b_reco_beam_true_byE_matched;   //!
   TBranch        *b_reco_beam_true_byHits_matched;   //!
   TBranch        *b_reco_beam_true_byHits_purity;   //!
   TBranch        *b_true_beam_processes;   //!
   TBranch        *b_true_beam_process_slice;   //!
   TBranch        *b_true_beam_process_dSlice;   //!
   TBranch        *b_true_beam_process_matched;   //!
   TBranch        *b_data_BI_P;   //!
   TBranch        *b_data_BI_TOF;   //!
   TBranch        *b_data_BI_TOF_Chan;   //!
   TBranch        *b_data_BI_X;   //!
   TBranch        *b_data_BI_Y;   //!
   TBranch        *b_data_BI_Z;   //!
   TBranch        *b_data_BI_dirX;   //!
   TBranch        *b_data_BI_dirY;   //!
   TBranch        *b_data_BI_dirZ;   //!
   TBranch        *b_data_BI_nFibersP1;   //!
   TBranch        *b_data_BI_nFibersP2;   //!
   TBranch        *b_data_BI_nFibersP3;   //!
   TBranch        *b_data_BI_PDG_candidates;   //!
   TBranch        *b_data_BI_nTracks;   //!
   TBranch        *b_data_BI_nMomenta;   //!
   TBranch        *b_quality_reco_view_0_hits_in_TPC5;   //!
   TBranch        *b_quality_reco_view_1_hits_in_TPC5;   //!
   TBranch        *b_quality_reco_view_2_hits_in_TPC5;   //!
   TBranch        *b_quality_reco_max_lateral;   //!
   TBranch        *b_quality_reco_max_segment;   //!
   TBranch        *b_quality_reco_view_0_max_segment;   //!
   TBranch        *b_quality_reco_view_1_max_segment;   //!
   TBranch        *b_quality_reco_view_2_max_segment;   //!
   TBranch        *b_quality_reco_view_0_wire_backtrack;   //!
   TBranch        *b_quality_reco_view_1_wire_backtrack;   //!
   TBranch        *b_quality_reco_view_2_wire_backtrack;   //!
   TBranch        *b_quality_reco_view_0_wire;   //!
   TBranch        *b_quality_reco_view_1_wire;   //!
   TBranch        *b_quality_reco_view_2_wire;   //!
   TBranch        *b_quality_reco_view_2_z;   //!
   TBranch        *b_quality_reco_view_0_tick;   //!
   TBranch        *b_quality_reco_view_1_tick;   //!
   TBranch        *b_quality_reco_view_2_tick;   //!
   TBranch        *b_reco_beam_Chi2_proton;   //!
   TBranch        *b_reco_beam_Chi2_ndof;   //!
   TBranch        *b_reco_beam_cosmic_candidate_lower_hits;   //!
   TBranch        *b_reco_beam_cosmic_candidate_upper_hits;   //!
   TBranch        *b_reco_beam_cosmic_candidate_ID;   //!
   TBranch        *b_beam_has_cosmic_IDE;   //!
   TBranch        *b_cosmic_has_beam_IDE;   //!
   TBranch        *b_n_cosmics_with_beam_IDE;   //!
   TBranch        *b_reco_daughter_allTrack_momByRange_proton;   //!
   TBranch        *b_reco_daughter_allTrack_momByRange_muon;   //!
   TBranch        *b_reco_beam_momByRange_proton;   //!
   TBranch        *b_reco_beam_momByRange_muon;   //!
   TBranch        *b_reco_daughter_allTrack_momByRange_alt_proton;   //!
   TBranch        *b_reco_daughter_allTrack_momByRange_alt_muon;   //!
   TBranch        *b_reco_beam_momByRange_alt_proton;   //!
   TBranch        *b_reco_beam_momByRange_alt_muon;   //!
   TBranch        *b_reco_beam_true_byE_endPx;   //!
   TBranch        *b_reco_beam_true_byE_endPy;   //!
   TBranch        *b_reco_beam_true_byE_endPz;   //!
   TBranch        *b_reco_beam_true_byE_endE;   //!
   TBranch        *b_reco_beam_true_byE_endP;   //!
   TBranch        *b_reco_beam_true_byE_startPx;   //!
   TBranch        *b_reco_beam_true_byE_startPy;   //!
   TBranch        *b_reco_beam_true_byE_startPz;   //!
   TBranch        *b_reco_beam_true_byE_startE;   //!
   TBranch        *b_reco_beam_true_byE_startP;   //!
   TBranch        *b_reco_beam_true_byHits_endPx;   //!
   TBranch        *b_reco_beam_true_byHits_endPy;   //!
   TBranch        *b_reco_beam_true_byHits_endPz;   //!
   TBranch        *b_reco_beam_true_byHits_endE;   //!
   TBranch        *b_reco_beam_true_byHits_endP;   //!
   TBranch        *b_reco_beam_true_byHits_startPx;   //!
   TBranch        *b_reco_beam_true_byHits_startPy;   //!
   TBranch        *b_reco_beam_true_byHits_startPz;   //!
   TBranch        *b_reco_beam_true_byHits_startE;   //!
   TBranch        *b_reco_beam_true_byHits_startP;   //!
   TBranch        *b_reco_beam_incidentEnergies;   //!
   TBranch        *b_reco_beam_interactingEnergy;   //!
   TBranch        *b_true_beam_incidentEnergies;   //!
   TBranch        *b_true_beam_interactingEnergy;   //!
   TBranch        *b_true_beam_slices;   //!
   TBranch        *b_true_beam_slices_found;   //!
   TBranch        *b_true_beam_slices_nIDEs;   //!
   TBranch        *b_true_beam_slices_deltaE;   //!
   TBranch        *b_em_energy;   //!
   TBranch        *b_true_beam_traj_X;   //!
   TBranch        *b_true_beam_traj_Y;   //!
   TBranch        *b_true_beam_traj_Z;   //!
   TBranch        *b_true_beam_traj_KE;   //!
   TBranch        *b_g4rw_primary_weights;   //!
   TBranch        *b_g4rw_primary_plus_sigma_weight;   //!
   TBranch        *b_g4rw_primary_minus_sigma_weight;   //!
   TBranch        *b_g4rw_primary_var;   //!
   TBranch        *b_g4rw_alt_primary_plus_sigma_weight;   //!
   TBranch        *b_g4rw_alt_primary_minus_sigma_weight;   //!

   prod3(TTree *tree=0);
   virtual ~prod3();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef prod3_cxx
prod3::prod3(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../../DUNEprotoTKI_data/v3_9_18_20/pionana_Prod3_mc_1GeV_9_18_20.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../../DUNEprotoTKI_data/v3_9_18_20/pionana_Prod3_mc_1GeV_9_18_20.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("../../DUNEprotoTKI_data/v3_9_18_20/pionana_Prod3_mc_1GeV_9_18_20.root:/pionana");
      dir->GetObject("beamana",tree);

   }
   Init(tree);
}

prod3::~prod3()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t prod3::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t prod3::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void prod3::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   reco_beam_calo_startDirX = 0;
   reco_beam_calo_startDirY = 0;
   reco_beam_calo_startDirZ = 0;
   reco_beam_calo_endDirX = 0;
   reco_beam_calo_endDirY = 0;
   reco_beam_calo_endDirZ = 0;
   reco_beam_dQdX = 0;
   reco_beam_dEdX = 0;
   reco_beam_calibrated_dEdX = 0;
   reco_beam_resRange = 0;
   reco_beam_TrkPitch = 0;
   reco_beam_calo_wire = 0;
   reco_beam_calo_wire_z = 0;
   reco_beam_calo_tick = 0;
   reco_beam_calo_TPC = 0;
   reco_beam_hit_true_ID = 0;
   reco_beam_hit_true_slice = 0;
   reco_beam_hit_true_origin = 0;
   reco_beam_allTrack_resRange = 0;
   reco_beam_allTrack_calibrated_dEdX = 0;
   reco_track_startX = 0;
   reco_track_startY = 0;
   reco_track_startZ = 0;
   reco_track_endX = 0;
   reco_track_endY = 0;
   reco_track_endZ = 0;
   reco_track_michel_score = 0;
   reco_track_ID = 0;
   reco_track_nHits = 0;
   reco_daughter_PFP_true_byHits_PDG = 0;
   reco_daughter_PFP_true_byHits_ID = 0;
   reco_daughter_PFP_true_byHits_origin = 0;
   reco_daughter_PFP_true_byHits_parID = 0;
   reco_daughter_PFP_true_byHits_parPDG = 0;
   reco_daughter_PFP_true_byHits_process = 0;
   reco_daughter_PFP_true_byHits_sharedHits = 0;
   reco_daughter_PFP_true_byHits_emHits = 0;
   reco_daughter_PFP_true_byHits_len = 0;
   reco_daughter_PFP_true_byHits_startX = 0;
   reco_daughter_PFP_true_byHits_startY = 0;
   reco_daughter_PFP_true_byHits_startZ = 0;
   reco_daughter_PFP_true_byHits_endX = 0;
   reco_daughter_PFP_true_byHits_endY = 0;
   reco_daughter_PFP_true_byHits_endZ = 0;
   reco_daughter_PFP_true_byHits_startPx = 0;
   reco_daughter_PFP_true_byHits_startPy = 0;
   reco_daughter_PFP_true_byHits_startPz = 0;
   reco_daughter_PFP_true_byHits_startP = 0;
   reco_daughter_PFP_true_byHits_startE = 0;
   reco_daughter_PFP_true_byHits_endProcess = 0;
   reco_daughter_PFP_true_byHits_purity = 0;
   reco_daughter_PFP_true_byHits_completeness = 0;
   reco_daughter_PFP_true_byE_PDG = 0;
   reco_daughter_PFP_true_byE_len = 0;
   reco_daughter_PFP_true_byE_completeness = 0;
   reco_daughter_PFP_true_byE_purity = 0;
   reco_daughter_allTrack_ID = 0;
   reco_daughter_allTrack_dQdX_SCE = 0;
   reco_daughter_allTrack_dEdX_SCE = 0;
   reco_daughter_allTrack_resRange_SCE = 0;
   reco_daughter_allTrack_calibrated_dEdX_SCE = 0;
   reco_daughter_allTrack_Chi2_proton = 0;
   reco_daughter_allTrack_Chi2_ndof = 0;
   reco_daughter_allTrack_Chi2_proton_plane0 = 0;
   reco_daughter_allTrack_Chi2_proton_plane1 = 0;
   reco_daughter_allTrack_Chi2_ndof_plane0 = 0;
   reco_daughter_allTrack_Chi2_ndof_plane1 = 0;
   reco_daughter_allTrack_calibrated_dEdX_SCE_plane0 = 0;
   reco_daughter_allTrack_calibrated_dEdX_SCE_plane1 = 0;
   reco_daughter_allTrack_resRange_plane0 = 0;
   reco_daughter_allTrack_resRange_plane1 = 0;
   reco_daughter_allTrack_Theta = 0;
   reco_daughter_allTrack_Phi = 0;
   reco_daughter_allTrack_len = 0;
   reco_daughter_allTrack_alt_len = 0;
   reco_daughter_allTrack_startX = 0;
   reco_daughter_allTrack_startY = 0;
   reco_daughter_allTrack_startZ = 0;
   reco_daughter_allTrack_endX = 0;
   reco_daughter_allTrack_endY = 0;
   reco_daughter_allTrack_endZ = 0;
   reco_daughter_allTrack_dR = 0;
   reco_daughter_allTrack_to_vertex = 0;
   reco_daughter_allTrack_vertex_michel_score = 0;
   reco_daughter_allTrack_vertex_nHits = 0;
   reco_daughter_allShower_ID = 0;
   reco_daughter_allShower_len = 0;
   reco_daughter_allShower_startX = 0;
   reco_daughter_allShower_startY = 0;
   reco_daughter_allShower_startZ = 0;
   reco_daughter_allShower_dirX = 0;
   reco_daughter_allShower_dirY = 0;
   reco_daughter_allShower_dirZ = 0;
   reco_daughter_allShower_energy = 0;
   reco_daughter_PFP_ID = 0;
   reco_daughter_PFP_nHits = 0;
   reco_daughter_PFP_nHits_collection = 0;
   reco_daughter_PFP_trackScore = 0;
   reco_daughter_PFP_emScore = 0;
   reco_daughter_PFP_michelScore = 0;
   reco_daughter_PFP_trackScore_collection = 0;
   reco_daughter_PFP_emScore_collection = 0;
   reco_daughter_PFP_michelScore_collection = 0;
   true_beam_endProcess = 0;
   true_beam_elastic_costheta = 0;
   true_beam_elastic_X = 0;
   true_beam_elastic_Y = 0;
   true_beam_elastic_Z = 0;
   true_beam_elastic_deltaE = 0;
   true_beam_elastic_IDE_edep = 0;
   true_beam_reco_byHits_PFP_ID = 0;
   true_beam_reco_byHits_PFP_nHits = 0;
   true_beam_reco_byHits_allTrack_ID = 0;
   true_beam_daughter_PDG = 0;
   true_beam_daughter_ID = 0;
   true_beam_daughter_len = 0;
   true_beam_daughter_startX = 0;
   true_beam_daughter_startY = 0;
   true_beam_daughter_startZ = 0;
   true_beam_daughter_startPx = 0;
   true_beam_daughter_startPy = 0;
   true_beam_daughter_startPz = 0;
   true_beam_daughter_startP = 0;
   true_beam_daughter_endX = 0;
   true_beam_daughter_endY = 0;
   true_beam_daughter_endZ = 0;
   true_beam_daughter_Process = 0;
   true_beam_daughter_endProcess = 0;
   true_beam_daughter_nHits = 0;
   true_beam_daughter_reco_byHits_PFP_ID = 0;
   true_beam_daughter_reco_byHits_PFP_nHits = 0;
   true_beam_daughter_reco_byHits_PFP_trackScore = 0;
   true_beam_daughter_reco_byHits_allTrack_ID = 0;
   true_beam_daughter_reco_byHits_allTrack_startX = 0;
   true_beam_daughter_reco_byHits_allTrack_startY = 0;
   true_beam_daughter_reco_byHits_allTrack_startZ = 0;
   true_beam_daughter_reco_byHits_allTrack_endX = 0;
   true_beam_daughter_reco_byHits_allTrack_endY = 0;
   true_beam_daughter_reco_byHits_allTrack_endZ = 0;
   true_beam_daughter_reco_byHits_allTrack_len = 0;
   true_beam_daughter_reco_byHits_allShower_ID = 0;
   true_beam_daughter_reco_byHits_allShower_startX = 0;
   true_beam_daughter_reco_byHits_allShower_startY = 0;
   true_beam_daughter_reco_byHits_allShower_startZ = 0;
   true_beam_daughter_reco_byHits_allShower_len = 0;
   true_beam_Pi0_decay_ID = 0;
   true_beam_Pi0_decay_parID = 0;
   true_beam_Pi0_decay_PDG = 0;
   true_beam_Pi0_decay_startP = 0;
   true_beam_Pi0_decay_startPx = 0;
   true_beam_Pi0_decay_startPy = 0;
   true_beam_Pi0_decay_startPz = 0;
   true_beam_Pi0_decay_startX = 0;
   true_beam_Pi0_decay_startY = 0;
   true_beam_Pi0_decay_startZ = 0;
   true_beam_Pi0_decay_len = 0;
   true_beam_Pi0_decay_nHits = 0;
   true_beam_Pi0_decay_reco_byHits_PFP_ID = 0;
   true_beam_Pi0_decay_reco_byHits_PFP_nHits = 0;
   true_beam_Pi0_decay_reco_byHits_PFP_trackScore = 0;
   true_beam_Pi0_decay_reco_byHits_allTrack_ID = 0;
   true_beam_Pi0_decay_reco_byHits_allTrack_startX = 0;
   true_beam_Pi0_decay_reco_byHits_allTrack_startY = 0;
   true_beam_Pi0_decay_reco_byHits_allTrack_startZ = 0;
   true_beam_Pi0_decay_reco_byHits_allTrack_endX = 0;
   true_beam_Pi0_decay_reco_byHits_allTrack_endY = 0;
   true_beam_Pi0_decay_reco_byHits_allTrack_endZ = 0;
   true_beam_Pi0_decay_reco_byHits_allTrack_len = 0;
   true_beam_Pi0_decay_reco_byHits_allShower_ID = 0;
   true_beam_Pi0_decay_reco_byHits_allShower_startX = 0;
   true_beam_Pi0_decay_reco_byHits_allShower_startY = 0;
   true_beam_Pi0_decay_reco_byHits_allShower_startZ = 0;
   true_beam_Pi0_decay_reco_byHits_allShower_len = 0;
   true_beam_grand_daughter_ID = 0;
   true_beam_grand_daughter_parID = 0;
   true_beam_grand_daughter_PDG = 0;
   true_beam_grand_daughter_nHits = 0;
   true_beam_grand_daughter_Process = 0;
   true_beam_grand_daughter_endProcess = 0;
   reco_beam_true_byE_endProcess = 0;
   reco_beam_true_byE_process = 0;
   reco_beam_true_byHits_endProcess = 0;
   reco_beam_true_byHits_process = 0;
   true_beam_processes = 0;
   true_beam_process_slice = 0;
   true_beam_process_dSlice = 0;
   true_beam_process_matched = 0;
   data_BI_TOF = 0;
   data_BI_TOF_Chan = 0;
   data_BI_PDG_candidates = 0;
   quality_reco_view_0_wire = 0;
   quality_reco_view_1_wire = 0;
   quality_reco_view_2_wire = 0;
   quality_reco_view_2_z = 0;
   quality_reco_view_0_tick = 0;
   quality_reco_view_1_tick = 0;
   quality_reco_view_2_tick = 0;
   reco_beam_cosmic_candidate_lower_hits = 0;
   reco_beam_cosmic_candidate_upper_hits = 0;
   reco_beam_cosmic_candidate_ID = 0;
   cosmic_has_beam_IDE = 0;
   reco_daughter_allTrack_momByRange_proton = 0;
   reco_daughter_allTrack_momByRange_muon = 0;
   reco_daughter_allTrack_momByRange_alt_proton = 0;
   reco_daughter_allTrack_momByRange_alt_muon = 0;
   reco_beam_incidentEnergies = 0;
   true_beam_incidentEnergies = 0;
   true_beam_slices = 0;
   true_beam_slices_found = 0;
   true_beam_slices_nIDEs = 0;
   true_beam_slices_deltaE = 0;
   true_beam_traj_X = 0;
   true_beam_traj_Y = 0;
   true_beam_traj_Z = 0;
   true_beam_traj_KE = 0;
   g4rw_primary_weights = 0;
   g4rw_primary_plus_sigma_weight = 0;
   g4rw_primary_minus_sigma_weight = 0;
   g4rw_primary_var = 0;
   g4rw_alt_primary_plus_sigma_weight = 0;
   g4rw_alt_primary_minus_sigma_weight = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("subrun", &subrun, &b_subrun);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("MC", &MC, &b_MC);
   fChain->SetBranchAddress("reco_beam_type", &reco_beam_type, &b_reco_beam_type);
   fChain->SetBranchAddress("reco_beam_startX", &reco_beam_startX, &b_reco_beam_startX);
   fChain->SetBranchAddress("reco_beam_startY", &reco_beam_startY, &b_reco_beam_startY);
   fChain->SetBranchAddress("reco_beam_startZ", &reco_beam_startZ, &b_reco_beam_startZ);
   fChain->SetBranchAddress("reco_beam_endX", &reco_beam_endX, &b_reco_beam_endX);
   fChain->SetBranchAddress("reco_beam_endY", &reco_beam_endY, &b_reco_beam_endY);
   fChain->SetBranchAddress("reco_beam_endZ", &reco_beam_endZ, &b_reco_beam_endZ);
   fChain->SetBranchAddress("reco_beam_len", &reco_beam_len, &b_reco_beam_len);
   fChain->SetBranchAddress("reco_beam_alt_len", &reco_beam_alt_len, &b_reco_beam_alt_len);
   fChain->SetBranchAddress("reco_beam_calo_startX", &reco_beam_calo_startX, &b_reco_beam_calo_startX);
   fChain->SetBranchAddress("reco_beam_calo_startY", &reco_beam_calo_startY, &b_reco_beam_calo_startY);
   fChain->SetBranchAddress("reco_beam_calo_startZ", &reco_beam_calo_startZ, &b_reco_beam_calo_startZ);
   fChain->SetBranchAddress("reco_beam_calo_endX", &reco_beam_calo_endX, &b_reco_beam_calo_endX);
   fChain->SetBranchAddress("reco_beam_calo_endY", &reco_beam_calo_endY, &b_reco_beam_calo_endY);
   fChain->SetBranchAddress("reco_beam_calo_endZ", &reco_beam_calo_endZ, &b_reco_beam_calo_endZ);
   fChain->SetBranchAddress("reco_beam_calo_startDirX", &reco_beam_calo_startDirX, &b_reco_beam_calo_startDirX);
   fChain->SetBranchAddress("reco_beam_calo_startDirY", &reco_beam_calo_startDirY, &b_reco_beam_calo_startDirY);
   fChain->SetBranchAddress("reco_beam_calo_startDirZ", &reco_beam_calo_startDirZ, &b_reco_beam_calo_startDirZ);
   fChain->SetBranchAddress("reco_beam_calo_endDirX", &reco_beam_calo_endDirX, &b_reco_beam_calo_endDirX);
   fChain->SetBranchAddress("reco_beam_calo_endDirY", &reco_beam_calo_endDirY, &b_reco_beam_calo_endDirY);
   fChain->SetBranchAddress("reco_beam_calo_endDirZ", &reco_beam_calo_endDirZ, &b_reco_beam_calo_endDirZ);
   fChain->SetBranchAddress("reco_beam_trackDirX", &reco_beam_trackDirX, &b_reco_beam_trackDirX);
   fChain->SetBranchAddress("reco_beam_trackDirY", &reco_beam_trackDirY, &b_reco_beam_trackDirY);
   fChain->SetBranchAddress("reco_beam_trackDirZ", &reco_beam_trackDirZ, &b_reco_beam_trackDirZ);
   fChain->SetBranchAddress("reco_beam_trackEndDirX", &reco_beam_trackEndDirX, &b_reco_beam_trackEndDirX);
   fChain->SetBranchAddress("reco_beam_trackEndDirY", &reco_beam_trackEndDirY, &b_reco_beam_trackEndDirY);
   fChain->SetBranchAddress("reco_beam_trackEndDirZ", &reco_beam_trackEndDirZ, &b_reco_beam_trackEndDirZ);
   fChain->SetBranchAddress("reco_beam_vtxX", &reco_beam_vtxX, &b_reco_beam_vtxX);
   fChain->SetBranchAddress("reco_beam_vtxY", &reco_beam_vtxY, &b_reco_beam_vtxY);
   fChain->SetBranchAddress("reco_beam_vtxZ", &reco_beam_vtxZ, &b_reco_beam_vtxZ);
   fChain->SetBranchAddress("reco_beam_vertex_nHits", &reco_beam_vertex_nHits, &b_reco_beam_vertex_nHits);
   fChain->SetBranchAddress("reco_beam_vertex_michel_score", &reco_beam_vertex_michel_score, &b_reco_beam_vertex_michel_score);
   fChain->SetBranchAddress("reco_beam_trackID", &reco_beam_trackID, &b_reco_beam_trackID);
   fChain->SetBranchAddress("reco_beam_dQdX", &reco_beam_dQdX, &b_reco_beam_dQdX);
   fChain->SetBranchAddress("reco_beam_dEdX", &reco_beam_dEdX, &b_reco_beam_dEdX);
   fChain->SetBranchAddress("reco_beam_calibrated_dEdX", &reco_beam_calibrated_dEdX, &b_reco_beam_calibrated_dEdX);
   fChain->SetBranchAddress("reco_beam_resRange", &reco_beam_resRange, &b_reco_beam_resRange);
   fChain->SetBranchAddress("reco_beam_TrkPitch", &reco_beam_TrkPitch, &b_reco_beam_TrkPitch);
   fChain->SetBranchAddress("reco_beam_calo_wire", &reco_beam_calo_wire, &b_reco_beam_calo_wire);
   fChain->SetBranchAddress("reco_beam_calo_wire_z", &reco_beam_calo_wire_z, &b_reco_beam_calo_wire_z);
   fChain->SetBranchAddress("reco_beam_calo_tick", &reco_beam_calo_tick, &b_reco_beam_calo_tick);
   fChain->SetBranchAddress("reco_beam_calo_TPC", &reco_beam_calo_TPC, &b_reco_beam_calo_TPC);
   fChain->SetBranchAddress("reco_beam_hit_true_ID", &reco_beam_hit_true_ID, &b_reco_beam_hit_true_ID);
   fChain->SetBranchAddress("reco_beam_hit_true_slice", &reco_beam_hit_true_slice, &b_reco_beam_hit_true_slice);
   fChain->SetBranchAddress("reco_beam_hit_true_origin", &reco_beam_hit_true_origin, &b_reco_beam_hit_true_origin);
   fChain->SetBranchAddress("reco_beam_nTrackDaughters", &reco_beam_nTrackDaughters, &b_reco_beam_nTrackDaughters);
   fChain->SetBranchAddress("reco_beam_nShowerDaughters", &reco_beam_nShowerDaughters, &b_reco_beam_nShowerDaughters);
   fChain->SetBranchAddress("reco_beam_flipped", &reco_beam_flipped, &b_reco_beam_flipped);
   fChain->SetBranchAddress("reco_beam_passes_beam_cuts", &reco_beam_passes_beam_cuts, &b_reco_beam_passes_beam_cuts);
   fChain->SetBranchAddress("reco_beam_PFP_ID", &reco_beam_PFP_ID, &b_reco_beam_PFP_ID);
   fChain->SetBranchAddress("reco_beam_PFP_nHits", &reco_beam_PFP_nHits, &b_reco_beam_PFP_nHits);
   fChain->SetBranchAddress("reco_beam_PFP_trackScore", &reco_beam_PFP_trackScore, &b_reco_beam_PFP_trackScore);
   fChain->SetBranchAddress("reco_beam_PFP_emScore", &reco_beam_PFP_emScore, &b_reco_beam_PFP_emScore);
   fChain->SetBranchAddress("reco_beam_PFP_michelScore", &reco_beam_PFP_michelScore, &b_reco_beam_PFP_michelScore);
   fChain->SetBranchAddress("reco_beam_PFP_trackScore_collection", &reco_beam_PFP_trackScore_collection, &b_reco_beam_PFP_trackScore_collection);
   fChain->SetBranchAddress("reco_beam_PFP_emScore_collection", &reco_beam_PFP_emScore_collection, &b_reco_beam_PFP_emScore_collection);
   fChain->SetBranchAddress("reco_beam_PFP_michelScore_collection", &reco_beam_PFP_michelScore_collection, &b_reco_beam_PFP_michelScore_collection);
   fChain->SetBranchAddress("reco_beam_allTrack_ID", &reco_beam_allTrack_ID, &b_reco_beam_allTrack_ID);
   fChain->SetBranchAddress("reco_beam_allTrack_beam_cuts", &reco_beam_allTrack_beam_cuts, &b_reco_beam_allTrack_beam_cuts);
   fChain->SetBranchAddress("reco_beam_allTrack_flipped", &reco_beam_allTrack_flipped, &b_reco_beam_allTrack_flipped);
   fChain->SetBranchAddress("reco_beam_allTrack_len", &reco_beam_allTrack_len, &b_reco_beam_allTrack_len);
   fChain->SetBranchAddress("reco_beam_allTrack_startX", &reco_beam_allTrack_startX, &b_reco_beam_allTrack_startX);
   fChain->SetBranchAddress("reco_beam_allTrack_startY", &reco_beam_allTrack_startY, &b_reco_beam_allTrack_startY);
   fChain->SetBranchAddress("reco_beam_allTrack_startZ", &reco_beam_allTrack_startZ, &b_reco_beam_allTrack_startZ);
   fChain->SetBranchAddress("reco_beam_allTrack_endX", &reco_beam_allTrack_endX, &b_reco_beam_allTrack_endX);
   fChain->SetBranchAddress("reco_beam_allTrack_endY", &reco_beam_allTrack_endY, &b_reco_beam_allTrack_endY);
   fChain->SetBranchAddress("reco_beam_allTrack_endZ", &reco_beam_allTrack_endZ, &b_reco_beam_allTrack_endZ);
   fChain->SetBranchAddress("reco_beam_allTrack_trackDirX", &reco_beam_allTrack_trackDirX, &b_reco_beam_allTrack_trackDirX);
   fChain->SetBranchAddress("reco_beam_allTrack_trackDirY", &reco_beam_allTrack_trackDirY, &b_reco_beam_allTrack_trackDirY);
   fChain->SetBranchAddress("reco_beam_allTrack_trackDirZ", &reco_beam_allTrack_trackDirZ, &b_reco_beam_allTrack_trackDirZ);
   fChain->SetBranchAddress("reco_beam_allTrack_trackEndDirX", &reco_beam_allTrack_trackEndDirX, &b_reco_beam_allTrack_trackEndDirX);
   fChain->SetBranchAddress("reco_beam_allTrack_trackEndDirY", &reco_beam_allTrack_trackEndDirY, &b_reco_beam_allTrack_trackEndDirY);
   fChain->SetBranchAddress("reco_beam_allTrack_trackEndDirZ", &reco_beam_allTrack_trackEndDirZ, &b_reco_beam_allTrack_trackEndDirZ);
   fChain->SetBranchAddress("reco_beam_allTrack_resRange", &reco_beam_allTrack_resRange, &b_reco_beam_allTrack_resRange);
   fChain->SetBranchAddress("reco_beam_allTrack_calibrated_dEdX", &reco_beam_allTrack_calibrated_dEdX, &b_reco_beam_allTrack_calibrated_dEdX);
   fChain->SetBranchAddress("reco_beam_allTrack_Chi2_proton", &reco_beam_allTrack_Chi2_proton, &b_reco_beam_allTrack_Chi2_proton);
   fChain->SetBranchAddress("reco_beam_allTrack_Chi2_ndof", &reco_beam_allTrack_Chi2_ndof, &b_reco_beam_allTrack_Chi2_ndof);
   fChain->SetBranchAddress("reco_track_startX", &reco_track_startX, &b_reco_track_startX);
   fChain->SetBranchAddress("reco_track_startY", &reco_track_startY, &b_reco_track_startY);
   fChain->SetBranchAddress("reco_track_startZ", &reco_track_startZ, &b_reco_track_startZ);
   fChain->SetBranchAddress("reco_track_endX", &reco_track_endX, &b_reco_track_endX);
   fChain->SetBranchAddress("reco_track_endY", &reco_track_endY, &b_reco_track_endY);
   fChain->SetBranchAddress("reco_track_endZ", &reco_track_endZ, &b_reco_track_endZ);
   fChain->SetBranchAddress("reco_track_michel_score", &reco_track_michel_score, &b_reco_track_michel_score);
   fChain->SetBranchAddress("reco_track_ID", &reco_track_ID, &b_reco_track_ID);
   fChain->SetBranchAddress("reco_track_nHits", &reco_track_nHits, &b_reco_track_nHits);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_PDG", &reco_daughter_PFP_true_byHits_PDG, &b_reco_daughter_PFP_true_byHits_PDG);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_ID", &reco_daughter_PFP_true_byHits_ID, &b_reco_daughter_PFP_true_byHits_ID);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_origin", &reco_daughter_PFP_true_byHits_origin, &b_reco_daughter_PFP_true_byHits_origin);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_parID", &reco_daughter_PFP_true_byHits_parID, &b_reco_daughter_PFP_true_byHits_parID);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_parPDG", &reco_daughter_PFP_true_byHits_parPDG, &b_reco_daughter_PFP_true_byHits_parPDG);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_process", &reco_daughter_PFP_true_byHits_process, &b_reco_daughter_PFP_true_byHits_process);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_sharedHits", &reco_daughter_PFP_true_byHits_sharedHits, &b_reco_daughter_PFP_true_byHits_sharedHits);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_emHits", &reco_daughter_PFP_true_byHits_emHits, &b_reco_daughter_PFP_true_byHits_emHits);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_len", &reco_daughter_PFP_true_byHits_len, &b_reco_daughter_PFP_true_byHits_len);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_startX", &reco_daughter_PFP_true_byHits_startX, &b_reco_daughter_PFP_true_byHits_startX);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_startY", &reco_daughter_PFP_true_byHits_startY, &b_reco_daughter_PFP_true_byHits_startY);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_startZ", &reco_daughter_PFP_true_byHits_startZ, &b_reco_daughter_PFP_true_byHits_startZ);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_endX", &reco_daughter_PFP_true_byHits_endX, &b_reco_daughter_PFP_true_byHits_endX);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_endY", &reco_daughter_PFP_true_byHits_endY, &b_reco_daughter_PFP_true_byHits_endY);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_endZ", &reco_daughter_PFP_true_byHits_endZ, &b_reco_daughter_PFP_true_byHits_endZ);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_startPx", &reco_daughter_PFP_true_byHits_startPx, &b_reco_daughter_PFP_true_byHits_startPx);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_startPy", &reco_daughter_PFP_true_byHits_startPy, &b_reco_daughter_PFP_true_byHits_startPy);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_startPz", &reco_daughter_PFP_true_byHits_startPz, &b_reco_daughter_PFP_true_byHits_startPz);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_startP", &reco_daughter_PFP_true_byHits_startP, &b_reco_daughter_PFP_true_byHits_startP);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_startE", &reco_daughter_PFP_true_byHits_startE, &b_reco_daughter_PFP_true_byHits_startE);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_endProcess", &reco_daughter_PFP_true_byHits_endProcess, &b_reco_daughter_PFP_true_byHits_endProcess);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_purity", &reco_daughter_PFP_true_byHits_purity, &b_reco_daughter_PFP_true_byHits_purity);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byHits_completeness", &reco_daughter_PFP_true_byHits_completeness, &b_reco_daughter_PFP_true_byHits_completeness);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byE_PDG", &reco_daughter_PFP_true_byE_PDG, &b_reco_daughter_PFP_true_byE_PDG);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byE_len", &reco_daughter_PFP_true_byE_len, &b_reco_daughter_PFP_true_byE_len);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byE_completeness", &reco_daughter_PFP_true_byE_completeness, &b_reco_daughter_PFP_true_byE_completeness);
   fChain->SetBranchAddress("reco_daughter_PFP_true_byE_purity", &reco_daughter_PFP_true_byE_purity, &b_reco_daughter_PFP_true_byE_purity);
   fChain->SetBranchAddress("reco_daughter_allTrack_ID", &reco_daughter_allTrack_ID, &b_reco_daughter_allTrack_ID);
   fChain->SetBranchAddress("reco_daughter_allTrack_dQdX_SCE", &reco_daughter_allTrack_dQdX_SCE, &b_reco_daughter_allTrack_dQdX_SCE);
   fChain->SetBranchAddress("reco_daughter_allTrack_dEdX_SCE", &reco_daughter_allTrack_dEdX_SCE, &b_reco_daughter_allTrack_dEdX_SCE);
   fChain->SetBranchAddress("reco_daughter_allTrack_resRange_SCE", &reco_daughter_allTrack_resRange_SCE, &b_reco_daughter_allTrack_resRange_SCE);
   fChain->SetBranchAddress("reco_daughter_allTrack_calibrated_dEdX_SCE", &reco_daughter_allTrack_calibrated_dEdX_SCE, &b_reco_daughter_allTrack_calibrated_dEdX_SCE);
   fChain->SetBranchAddress("reco_daughter_allTrack_Chi2_proton", &reco_daughter_allTrack_Chi2_proton, &b_reco_daughter_allTrack_Chi2_proton);
   fChain->SetBranchAddress("reco_daughter_allTrack_Chi2_ndof", &reco_daughter_allTrack_Chi2_ndof, &b_reco_daughter_allTrack_Chi2_ndof);
   fChain->SetBranchAddress("reco_daughter_allTrack_Chi2_proton_plane0", &reco_daughter_allTrack_Chi2_proton_plane0, &b_reco_daughter_allTrack_Chi2_proton_plane0);
   fChain->SetBranchAddress("reco_daughter_allTrack_Chi2_proton_plane1", &reco_daughter_allTrack_Chi2_proton_plane1, &b_reco_daughter_allTrack_Chi2_proton_plane1);
   fChain->SetBranchAddress("reco_daughter_allTrack_Chi2_ndof_plane0", &reco_daughter_allTrack_Chi2_ndof_plane0, &b_reco_daughter_allTrack_Chi2_ndof_plane0);
   fChain->SetBranchAddress("reco_daughter_allTrack_Chi2_ndof_plane1", &reco_daughter_allTrack_Chi2_ndof_plane1, &b_reco_daughter_allTrack_Chi2_ndof_plane1);
   fChain->SetBranchAddress("reco_daughter_allTrack_calibrated_dEdX_SCE_plane0", &reco_daughter_allTrack_calibrated_dEdX_SCE_plane0, &b_reco_daughter_allTrack_calibrated_dEdX_SCE_plane0);
   fChain->SetBranchAddress("reco_daughter_allTrack_calibrated_dEdX_SCE_plane1", &reco_daughter_allTrack_calibrated_dEdX_SCE_plane1, &b_reco_daughter_allTrack_calibrated_dEdX_SCE_plane1);
   fChain->SetBranchAddress("reco_daughter_allTrack_resRange_plane0", &reco_daughter_allTrack_resRange_plane0, &b_reco_daughter_allTrack_resRange_plane0);
   fChain->SetBranchAddress("reco_daughter_allTrack_resRange_plane1", &reco_daughter_allTrack_resRange_plane1, &b_reco_daughter_allTrack_resRange_plane1);
   fChain->SetBranchAddress("reco_daughter_allTrack_Theta", &reco_daughter_allTrack_Theta, &b_reco_daughter_allTrack_Theta);
   fChain->SetBranchAddress("reco_daughter_allTrack_Phi", &reco_daughter_allTrack_Phi, &b_reco_daughter_allTrack_Phi);
   fChain->SetBranchAddress("reco_daughter_allTrack_len", &reco_daughter_allTrack_len, &b_reco_daughter_allTrack_len);
   fChain->SetBranchAddress("reco_daughter_allTrack_alt_len", &reco_daughter_allTrack_alt_len, &b_reco_daughter_allTrack_alt_len);
   fChain->SetBranchAddress("reco_daughter_allTrack_startX", &reco_daughter_allTrack_startX, &b_reco_daughter_allTrack_startX);
   fChain->SetBranchAddress("reco_daughter_allTrack_startY", &reco_daughter_allTrack_startY, &b_reco_daughter_allTrack_startY);
   fChain->SetBranchAddress("reco_daughter_allTrack_startZ", &reco_daughter_allTrack_startZ, &b_reco_daughter_allTrack_startZ);
   fChain->SetBranchAddress("reco_daughter_allTrack_endX", &reco_daughter_allTrack_endX, &b_reco_daughter_allTrack_endX);
   fChain->SetBranchAddress("reco_daughter_allTrack_endY", &reco_daughter_allTrack_endY, &b_reco_daughter_allTrack_endY);
   fChain->SetBranchAddress("reco_daughter_allTrack_endZ", &reco_daughter_allTrack_endZ, &b_reco_daughter_allTrack_endZ);
   fChain->SetBranchAddress("reco_daughter_allTrack_dR", &reco_daughter_allTrack_dR, &b_reco_daughter_allTrack_dR);
   fChain->SetBranchAddress("reco_daughter_allTrack_to_vertex", &reco_daughter_allTrack_to_vertex, &b_reco_daughter_allTrack_to_vertex);
   fChain->SetBranchAddress("reco_daughter_allTrack_vertex_michel_score", &reco_daughter_allTrack_vertex_michel_score, &b_reco_daughter_allTrack_vertex_michel_score);
   fChain->SetBranchAddress("reco_daughter_allTrack_vertex_nHits", &reco_daughter_allTrack_vertex_nHits, &b_reco_daughter_allTrack_vertex_nHits);
   fChain->SetBranchAddress("reco_daughter_allShower_ID", &reco_daughter_allShower_ID, &b_reco_daughter_allShower_ID);
   fChain->SetBranchAddress("reco_daughter_allShower_len", &reco_daughter_allShower_len, &b_reco_daughter_allShower_len);
   fChain->SetBranchAddress("reco_daughter_allShower_startX", &reco_daughter_allShower_startX, &b_reco_daughter_allShower_startX);
   fChain->SetBranchAddress("reco_daughter_allShower_startY", &reco_daughter_allShower_startY, &b_reco_daughter_allShower_startY);
   fChain->SetBranchAddress("reco_daughter_allShower_startZ", &reco_daughter_allShower_startZ, &b_reco_daughter_allShower_startZ);
   fChain->SetBranchAddress("reco_daughter_allShower_dirX", &reco_daughter_allShower_dirX, &b_reco_daughter_allShower_dirX);
   fChain->SetBranchAddress("reco_daughter_allShower_dirY", &reco_daughter_allShower_dirY, &b_reco_daughter_allShower_dirY);
   fChain->SetBranchAddress("reco_daughter_allShower_dirZ", &reco_daughter_allShower_dirZ, &b_reco_daughter_allShower_dirZ);
   fChain->SetBranchAddress("reco_daughter_allShower_energy", &reco_daughter_allShower_energy, &b_reco_daughter_allShower_energy);
   fChain->SetBranchAddress("reco_daughter_PFP_ID", &reco_daughter_PFP_ID, &b_reco_daughter_PFP_ID);
   fChain->SetBranchAddress("reco_daughter_PFP_nHits", &reco_daughter_PFP_nHits, &b_reco_daughter_PFP_nHits);
   fChain->SetBranchAddress("reco_daughter_PFP_nHits_collection", &reco_daughter_PFP_nHits_collection, &b_reco_daughter_PFP_nHits_collection);
   fChain->SetBranchAddress("reco_daughter_PFP_trackScore", &reco_daughter_PFP_trackScore, &b_reco_daughter_PFP_trackScore);
   fChain->SetBranchAddress("reco_daughter_PFP_emScore", &reco_daughter_PFP_emScore, &b_reco_daughter_PFP_emScore);
   fChain->SetBranchAddress("reco_daughter_PFP_michelScore", &reco_daughter_PFP_michelScore, &b_reco_daughter_PFP_michelScore);
   fChain->SetBranchAddress("reco_daughter_PFP_trackScore_collection", &reco_daughter_PFP_trackScore_collection, &b_reco_daughter_PFP_trackScore_collection);
   fChain->SetBranchAddress("reco_daughter_PFP_emScore_collection", &reco_daughter_PFP_emScore_collection, &b_reco_daughter_PFP_emScore_collection);
   fChain->SetBranchAddress("reco_daughter_PFP_michelScore_collection", &reco_daughter_PFP_michelScore_collection, &b_reco_daughter_PFP_michelScore_collection);
   fChain->SetBranchAddress("true_beam_PDG", &true_beam_PDG, &b_true_beam_PDG);
   fChain->SetBranchAddress("true_beam_ID", &true_beam_ID, &b_true_beam_ID);
   fChain->SetBranchAddress("true_beam_endProcess", &true_beam_endProcess, &b_true_beam_endProcess);
   fChain->SetBranchAddress("true_beam_endX", &true_beam_endX, &b_true_beam_endX);
   fChain->SetBranchAddress("true_beam_endY", &true_beam_endY, &b_true_beam_endY);
   fChain->SetBranchAddress("true_beam_endZ", &true_beam_endZ, &b_true_beam_endZ);
   fChain->SetBranchAddress("true_beam_startX", &true_beam_startX, &b_true_beam_startX);
   fChain->SetBranchAddress("true_beam_startY", &true_beam_startY, &b_true_beam_startY);
   fChain->SetBranchAddress("true_beam_startZ", &true_beam_startZ, &b_true_beam_startZ);
   fChain->SetBranchAddress("true_beam_startPx", &true_beam_startPx, &b_true_beam_startPx);
   fChain->SetBranchAddress("true_beam_startPy", &true_beam_startPy, &b_true_beam_startPy);
   fChain->SetBranchAddress("true_beam_startPz", &true_beam_startPz, &b_true_beam_startPz);
   fChain->SetBranchAddress("true_beam_startP", &true_beam_startP, &b_true_beam_startP);
   fChain->SetBranchAddress("true_beam_endPx", &true_beam_endPx, &b_true_beam_endPx);
   fChain->SetBranchAddress("true_beam_endPy", &true_beam_endPy, &b_true_beam_endPy);
   fChain->SetBranchAddress("true_beam_endPz", &true_beam_endPz, &b_true_beam_endPz);
   fChain->SetBranchAddress("true_beam_endP", &true_beam_endP, &b_true_beam_endP);
   fChain->SetBranchAddress("true_beam_startDirX", &true_beam_startDirX, &b_true_beam_startDirX);
   fChain->SetBranchAddress("true_beam_startDirY", &true_beam_startDirY, &b_true_beam_startDirY);
   fChain->SetBranchAddress("true_beam_startDirZ", &true_beam_startDirZ, &b_true_beam_startDirZ);
   fChain->SetBranchAddress("true_beam_nElasticScatters", &true_beam_nElasticScatters, &b_true_beam_nElasticScatters);
   fChain->SetBranchAddress("true_beam_elastic_costheta", &true_beam_elastic_costheta, &b_true_beam_elastic_costheta);
   fChain->SetBranchAddress("true_beam_elastic_X", &true_beam_elastic_X, &b_true_beam_elastic_X);
   fChain->SetBranchAddress("true_beam_elastic_Y", &true_beam_elastic_Y, &b_true_beam_elastic_Y);
   fChain->SetBranchAddress("true_beam_elastic_Z", &true_beam_elastic_Z, &b_true_beam_elastic_Z);
   fChain->SetBranchAddress("true_beam_elastic_deltaE", &true_beam_elastic_deltaE, &b_true_beam_elastic_deltaE);
   fChain->SetBranchAddress("true_beam_elastic_IDE_edep", &true_beam_elastic_IDE_edep, &b_true_beam_elastic_IDE_edep);
   fChain->SetBranchAddress("true_beam_IDE_totalDep", &true_beam_IDE_totalDep, &b_true_beam_IDE_totalDep);
   fChain->SetBranchAddress("true_beam_IDE_found_in_recoVtx", &true_beam_IDE_found_in_recoVtx, &b_true_beam_IDE_found_in_recoVtx);
   fChain->SetBranchAddress("true_beam_nHits", &true_beam_nHits, &b_true_beam_nHits);
   fChain->SetBranchAddress("true_beam_reco_byHits_PFP_ID", &true_beam_reco_byHits_PFP_ID, &b_true_beam_reco_byHits_PFP_ID);
   fChain->SetBranchAddress("true_beam_reco_byHits_PFP_nHits", &true_beam_reco_byHits_PFP_nHits, &b_true_beam_reco_byHits_PFP_nHits);
   fChain->SetBranchAddress("true_beam_reco_byHits_allTrack_ID", &true_beam_reco_byHits_allTrack_ID, &b_true_beam_reco_byHits_allTrack_ID);
   fChain->SetBranchAddress("true_daughter_nPi0", &true_daughter_nPi0, &b_true_daughter_nPi0);
   fChain->SetBranchAddress("true_daughter_nPiPlus", &true_daughter_nPiPlus, &b_true_daughter_nPiPlus);
   fChain->SetBranchAddress("true_daughter_nProton", &true_daughter_nProton, &b_true_daughter_nProton);
   fChain->SetBranchAddress("true_daughter_nNeutron", &true_daughter_nNeutron, &b_true_daughter_nNeutron);
   fChain->SetBranchAddress("true_daughter_nPiMinus", &true_daughter_nPiMinus, &b_true_daughter_nPiMinus);
   fChain->SetBranchAddress("true_daughter_nNucleus", &true_daughter_nNucleus, &b_true_daughter_nNucleus);
   fChain->SetBranchAddress("reco_beam_vertex_slice", &reco_beam_vertex_slice, &b_reco_beam_vertex_slice);
   fChain->SetBranchAddress("true_beam_daughter_PDG", &true_beam_daughter_PDG, &b_true_beam_daughter_PDG);
   fChain->SetBranchAddress("true_beam_daughter_ID", &true_beam_daughter_ID, &b_true_beam_daughter_ID);
   fChain->SetBranchAddress("true_beam_daughter_len", &true_beam_daughter_len, &b_true_beam_daughter_len);
   fChain->SetBranchAddress("true_beam_daughter_startX", &true_beam_daughter_startX, &b_true_beam_daughter_startX);
   fChain->SetBranchAddress("true_beam_daughter_startY", &true_beam_daughter_startY, &b_true_beam_daughter_startY);
   fChain->SetBranchAddress("true_beam_daughter_startZ", &true_beam_daughter_startZ, &b_true_beam_daughter_startZ);
   fChain->SetBranchAddress("true_beam_daughter_startPx", &true_beam_daughter_startPx, &b_true_beam_daughter_startPx);
   fChain->SetBranchAddress("true_beam_daughter_startPy", &true_beam_daughter_startPy, &b_true_beam_daughter_startPy);
   fChain->SetBranchAddress("true_beam_daughter_startPz", &true_beam_daughter_startPz, &b_true_beam_daughter_startPz);
   fChain->SetBranchAddress("true_beam_daughter_startP", &true_beam_daughter_startP, &b_true_beam_daughter_startP);
   fChain->SetBranchAddress("true_beam_daughter_endX", &true_beam_daughter_endX, &b_true_beam_daughter_endX);
   fChain->SetBranchAddress("true_beam_daughter_endY", &true_beam_daughter_endY, &b_true_beam_daughter_endY);
   fChain->SetBranchAddress("true_beam_daughter_endZ", &true_beam_daughter_endZ, &b_true_beam_daughter_endZ);
   fChain->SetBranchAddress("true_beam_daughter_Process", &true_beam_daughter_Process, &b_true_beam_daughter_Process);
   fChain->SetBranchAddress("true_beam_daughter_endProcess", &true_beam_daughter_endProcess, &b_true_beam_daughter_endProcess);
   fChain->SetBranchAddress("true_beam_daughter_nHits", &true_beam_daughter_nHits, &b_true_beam_daughter_nHits);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_PFP_ID", &true_beam_daughter_reco_byHits_PFP_ID, &b_true_beam_daughter_reco_byHits_PFP_ID);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_PFP_nHits", &true_beam_daughter_reco_byHits_PFP_nHits, &b_true_beam_daughter_reco_byHits_PFP_nHits);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_PFP_trackScore", &true_beam_daughter_reco_byHits_PFP_trackScore, &b_true_beam_daughter_reco_byHits_PFP_trackScore);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_allTrack_ID", &true_beam_daughter_reco_byHits_allTrack_ID, &b_true_beam_daughter_reco_byHits_allTrack_ID);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_allTrack_startX", &true_beam_daughter_reco_byHits_allTrack_startX, &b_true_beam_daughter_reco_byHits_allTrack_startX);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_allTrack_startY", &true_beam_daughter_reco_byHits_allTrack_startY, &b_true_beam_daughter_reco_byHits_allTrack_startY);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_allTrack_startZ", &true_beam_daughter_reco_byHits_allTrack_startZ, &b_true_beam_daughter_reco_byHits_allTrack_startZ);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_allTrack_endX", &true_beam_daughter_reco_byHits_allTrack_endX, &b_true_beam_daughter_reco_byHits_allTrack_endX);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_allTrack_endY", &true_beam_daughter_reco_byHits_allTrack_endY, &b_true_beam_daughter_reco_byHits_allTrack_endY);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_allTrack_endZ", &true_beam_daughter_reco_byHits_allTrack_endZ, &b_true_beam_daughter_reco_byHits_allTrack_endZ);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_allTrack_len", &true_beam_daughter_reco_byHits_allTrack_len, &b_true_beam_daughter_reco_byHits_allTrack_len);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_allShower_ID", &true_beam_daughter_reco_byHits_allShower_ID, &b_true_beam_daughter_reco_byHits_allShower_ID);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_allShower_startX", &true_beam_daughter_reco_byHits_allShower_startX, &b_true_beam_daughter_reco_byHits_allShower_startX);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_allShower_startY", &true_beam_daughter_reco_byHits_allShower_startY, &b_true_beam_daughter_reco_byHits_allShower_startY);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_allShower_startZ", &true_beam_daughter_reco_byHits_allShower_startZ, &b_true_beam_daughter_reco_byHits_allShower_startZ);
   fChain->SetBranchAddress("true_beam_daughter_reco_byHits_allShower_len", &true_beam_daughter_reco_byHits_allShower_len, &b_true_beam_daughter_reco_byHits_allShower_len);
   fChain->SetBranchAddress("true_beam_Pi0_decay_ID", &true_beam_Pi0_decay_ID, &b_true_beam_Pi0_decay_ID);
   fChain->SetBranchAddress("true_beam_Pi0_decay_parID", &true_beam_Pi0_decay_parID, &b_true_beam_Pi0_decay_parID);
   fChain->SetBranchAddress("true_beam_Pi0_decay_PDG", &true_beam_Pi0_decay_PDG, &b_true_beam_Pi0_decay_PDG);
   fChain->SetBranchAddress("true_beam_Pi0_decay_startP", &true_beam_Pi0_decay_startP, &b_true_beam_Pi0_decay_startP);
   fChain->SetBranchAddress("true_beam_Pi0_decay_startPx", &true_beam_Pi0_decay_startPx, &b_true_beam_Pi0_decay_startPx);
   fChain->SetBranchAddress("true_beam_Pi0_decay_startPy", &true_beam_Pi0_decay_startPy, &b_true_beam_Pi0_decay_startPy);
   fChain->SetBranchAddress("true_beam_Pi0_decay_startPz", &true_beam_Pi0_decay_startPz, &b_true_beam_Pi0_decay_startPz);
   fChain->SetBranchAddress("true_beam_Pi0_decay_startX", &true_beam_Pi0_decay_startX, &b_true_beam_Pi0_decay_startX);
   fChain->SetBranchAddress("true_beam_Pi0_decay_startY", &true_beam_Pi0_decay_startY, &b_true_beam_Pi0_decay_startY);
   fChain->SetBranchAddress("true_beam_Pi0_decay_startZ", &true_beam_Pi0_decay_startZ, &b_true_beam_Pi0_decay_startZ);
   fChain->SetBranchAddress("true_beam_Pi0_decay_len", &true_beam_Pi0_decay_len, &b_true_beam_Pi0_decay_len);
   fChain->SetBranchAddress("true_beam_Pi0_decay_nHits", &true_beam_Pi0_decay_nHits, &b_true_beam_Pi0_decay_nHits);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_PFP_ID", &true_beam_Pi0_decay_reco_byHits_PFP_ID, &b_true_beam_Pi0_decay_reco_byHits_PFP_ID);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_PFP_nHits", &true_beam_Pi0_decay_reco_byHits_PFP_nHits, &b_true_beam_Pi0_decay_reco_byHits_PFP_nHits);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_PFP_trackScore", &true_beam_Pi0_decay_reco_byHits_PFP_trackScore, &b_true_beam_Pi0_decay_reco_byHits_PFP_trackScore);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_allTrack_ID", &true_beam_Pi0_decay_reco_byHits_allTrack_ID, &b_true_beam_Pi0_decay_reco_byHits_allTrack_ID);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_allTrack_startX", &true_beam_Pi0_decay_reco_byHits_allTrack_startX, &b_true_beam_Pi0_decay_reco_byHits_allTrack_startX);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_allTrack_startY", &true_beam_Pi0_decay_reco_byHits_allTrack_startY, &b_true_beam_Pi0_decay_reco_byHits_allTrack_startY);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_allTrack_startZ", &true_beam_Pi0_decay_reco_byHits_allTrack_startZ, &b_true_beam_Pi0_decay_reco_byHits_allTrack_startZ);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_allTrack_endX", &true_beam_Pi0_decay_reco_byHits_allTrack_endX, &b_true_beam_Pi0_decay_reco_byHits_allTrack_endX);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_allTrack_endY", &true_beam_Pi0_decay_reco_byHits_allTrack_endY, &b_true_beam_Pi0_decay_reco_byHits_allTrack_endY);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_allTrack_endZ", &true_beam_Pi0_decay_reco_byHits_allTrack_endZ, &b_true_beam_Pi0_decay_reco_byHits_allTrack_endZ);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_allTrack_len", &true_beam_Pi0_decay_reco_byHits_allTrack_len, &b_true_beam_Pi0_decay_reco_byHits_allTrack_len);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_allShower_ID", &true_beam_Pi0_decay_reco_byHits_allShower_ID, &b_true_beam_Pi0_decay_reco_byHits_allShower_ID);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_allShower_startX", &true_beam_Pi0_decay_reco_byHits_allShower_startX, &b_true_beam_Pi0_decay_reco_byHits_allShower_startX);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_allShower_startY", &true_beam_Pi0_decay_reco_byHits_allShower_startY, &b_true_beam_Pi0_decay_reco_byHits_allShower_startY);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_allShower_startZ", &true_beam_Pi0_decay_reco_byHits_allShower_startZ, &b_true_beam_Pi0_decay_reco_byHits_allShower_startZ);
   fChain->SetBranchAddress("true_beam_Pi0_decay_reco_byHits_allShower_len", &true_beam_Pi0_decay_reco_byHits_allShower_len, &b_true_beam_Pi0_decay_reco_byHits_allShower_len);
   fChain->SetBranchAddress("true_beam_grand_daughter_ID", &true_beam_grand_daughter_ID, &b_true_beam_grand_daughter_ID);
   fChain->SetBranchAddress("true_beam_grand_daughter_parID", &true_beam_grand_daughter_parID, &b_true_beam_grand_daughter_parID);
   fChain->SetBranchAddress("true_beam_grand_daughter_PDG", &true_beam_grand_daughter_PDG, &b_true_beam_grand_daughter_PDG);
   fChain->SetBranchAddress("true_beam_grand_daughter_nHits", &true_beam_grand_daughter_nHits, &b_true_beam_grand_daughter_nHits);
   fChain->SetBranchAddress("true_beam_grand_daughter_Process", &true_beam_grand_daughter_Process, &b_true_beam_grand_daughter_Process);
   fChain->SetBranchAddress("true_beam_grand_daughter_endProcess", &true_beam_grand_daughter_endProcess, &b_true_beam_grand_daughter_endProcess);
   fChain->SetBranchAddress("reco_beam_true_byE_endProcess", &reco_beam_true_byE_endProcess, &b_reco_beam_true_byE_endProcess);
   fChain->SetBranchAddress("reco_beam_true_byE_process", &reco_beam_true_byE_process, &b_reco_beam_true_byE_process);
   fChain->SetBranchAddress("reco_beam_true_byE_origin", &reco_beam_true_byE_origin, &b_reco_beam_true_byE_origin);
   fChain->SetBranchAddress("reco_beam_true_byE_PDG", &reco_beam_true_byE_PDG, &b_reco_beam_true_byE_PDG);
   fChain->SetBranchAddress("reco_beam_true_byE_ID", &reco_beam_true_byE_ID, &b_reco_beam_true_byE_ID);
   fChain->SetBranchAddress("reco_beam_true_byHits_endProcess", &reco_beam_true_byHits_endProcess, &b_reco_beam_true_byHits_endProcess);
   fChain->SetBranchAddress("reco_beam_true_byHits_process", &reco_beam_true_byHits_process, &b_reco_beam_true_byHits_process);
   fChain->SetBranchAddress("reco_beam_true_byHits_origin", &reco_beam_true_byHits_origin, &b_reco_beam_true_byHits_origin);
   fChain->SetBranchAddress("reco_beam_true_byHits_PDG", &reco_beam_true_byHits_PDG, &b_reco_beam_true_byHits_PDG);
   fChain->SetBranchAddress("reco_beam_true_byHits_ID", &reco_beam_true_byHits_ID, &b_reco_beam_true_byHits_ID);
   fChain->SetBranchAddress("reco_beam_true_byE_matched", &reco_beam_true_byE_matched, &b_reco_beam_true_byE_matched);
   fChain->SetBranchAddress("reco_beam_true_byHits_matched", &reco_beam_true_byHits_matched, &b_reco_beam_true_byHits_matched);
   fChain->SetBranchAddress("reco_beam_true_byHits_purity", &reco_beam_true_byHits_purity, &b_reco_beam_true_byHits_purity);
   fChain->SetBranchAddress("true_beam_processes", &true_beam_processes, &b_true_beam_processes);
   fChain->SetBranchAddress("true_beam_process_slice", &true_beam_process_slice, &b_true_beam_process_slice);
   fChain->SetBranchAddress("true_beam_process_dSlice", &true_beam_process_dSlice, &b_true_beam_process_dSlice);
   fChain->SetBranchAddress("true_beam_process_matched", &true_beam_process_matched, &b_true_beam_process_matched);
   fChain->SetBranchAddress("data_BI_P", &data_BI_P, &b_data_BI_P);
   fChain->SetBranchAddress("data_BI_TOF", &data_BI_TOF, &b_data_BI_TOF);
   fChain->SetBranchAddress("data_BI_TOF_Chan", &data_BI_TOF_Chan, &b_data_BI_TOF_Chan);
   fChain->SetBranchAddress("data_BI_X", &data_BI_X, &b_data_BI_X);
   fChain->SetBranchAddress("data_BI_Y", &data_BI_Y, &b_data_BI_Y);
   fChain->SetBranchAddress("data_BI_Z", &data_BI_Z, &b_data_BI_Z);
   fChain->SetBranchAddress("data_BI_dirX", &data_BI_dirX, &b_data_BI_dirX);
   fChain->SetBranchAddress("data_BI_dirY", &data_BI_dirY, &b_data_BI_dirY);
   fChain->SetBranchAddress("data_BI_dirZ", &data_BI_dirZ, &b_data_BI_dirZ);
   fChain->SetBranchAddress("data_BI_nFibersP1", &data_BI_nFibersP1, &b_data_BI_nFibersP1);
   fChain->SetBranchAddress("data_BI_nFibersP2", &data_BI_nFibersP2, &b_data_BI_nFibersP2);
   fChain->SetBranchAddress("data_BI_nFibersP3", &data_BI_nFibersP3, &b_data_BI_nFibersP3);
   fChain->SetBranchAddress("data_BI_PDG_candidates", &data_BI_PDG_candidates, &b_data_BI_PDG_candidates);
   fChain->SetBranchAddress("data_BI_nTracks", &data_BI_nTracks, &b_data_BI_nTracks);
   fChain->SetBranchAddress("data_BI_nMomenta", &data_BI_nMomenta, &b_data_BI_nMomenta);
   fChain->SetBranchAddress("quality_reco_view_0_hits_in_TPC5", &quality_reco_view_0_hits_in_TPC5, &b_quality_reco_view_0_hits_in_TPC5);
   fChain->SetBranchAddress("quality_reco_view_1_hits_in_TPC5", &quality_reco_view_1_hits_in_TPC5, &b_quality_reco_view_1_hits_in_TPC5);
   fChain->SetBranchAddress("quality_reco_view_2_hits_in_TPC5", &quality_reco_view_2_hits_in_TPC5, &b_quality_reco_view_2_hits_in_TPC5);
   fChain->SetBranchAddress("quality_reco_max_lateral", &quality_reco_max_lateral, &b_quality_reco_max_lateral);
   fChain->SetBranchAddress("quality_reco_max_segment", &quality_reco_max_segment, &b_quality_reco_max_segment);
   fChain->SetBranchAddress("quality_reco_view_0_max_segment", &quality_reco_view_0_max_segment, &b_quality_reco_view_0_max_segment);
   fChain->SetBranchAddress("quality_reco_view_1_max_segment", &quality_reco_view_1_max_segment, &b_quality_reco_view_1_max_segment);
   fChain->SetBranchAddress("quality_reco_view_2_max_segment", &quality_reco_view_2_max_segment, &b_quality_reco_view_2_max_segment);
   fChain->SetBranchAddress("quality_reco_view_0_wire_backtrack", &quality_reco_view_0_wire_backtrack, &b_quality_reco_view_0_wire_backtrack);
   fChain->SetBranchAddress("quality_reco_view_1_wire_backtrack", &quality_reco_view_1_wire_backtrack, &b_quality_reco_view_1_wire_backtrack);
   fChain->SetBranchAddress("quality_reco_view_2_wire_backtrack", &quality_reco_view_2_wire_backtrack, &b_quality_reco_view_2_wire_backtrack);
   fChain->SetBranchAddress("quality_reco_view_0_wire", &quality_reco_view_0_wire, &b_quality_reco_view_0_wire);
   fChain->SetBranchAddress("quality_reco_view_1_wire", &quality_reco_view_1_wire, &b_quality_reco_view_1_wire);
   fChain->SetBranchAddress("quality_reco_view_2_wire", &quality_reco_view_2_wire, &b_quality_reco_view_2_wire);
   fChain->SetBranchAddress("quality_reco_view_2_z", &quality_reco_view_2_z, &b_quality_reco_view_2_z);
   fChain->SetBranchAddress("quality_reco_view_0_tick", &quality_reco_view_0_tick, &b_quality_reco_view_0_tick);
   fChain->SetBranchAddress("quality_reco_view_1_tick", &quality_reco_view_1_tick, &b_quality_reco_view_1_tick);
   fChain->SetBranchAddress("quality_reco_view_2_tick", &quality_reco_view_2_tick, &b_quality_reco_view_2_tick);
   fChain->SetBranchAddress("reco_beam_Chi2_proton", &reco_beam_Chi2_proton, &b_reco_beam_Chi2_proton);
   fChain->SetBranchAddress("reco_beam_Chi2_ndof", &reco_beam_Chi2_ndof, &b_reco_beam_Chi2_ndof);
   fChain->SetBranchAddress("reco_beam_cosmic_candidate_lower_hits", &reco_beam_cosmic_candidate_lower_hits, &b_reco_beam_cosmic_candidate_lower_hits);
   fChain->SetBranchAddress("reco_beam_cosmic_candidate_upper_hits", &reco_beam_cosmic_candidate_upper_hits, &b_reco_beam_cosmic_candidate_upper_hits);
   fChain->SetBranchAddress("reco_beam_cosmic_candidate_ID", &reco_beam_cosmic_candidate_ID, &b_reco_beam_cosmic_candidate_ID);
   fChain->SetBranchAddress("beam_has_cosmic_IDE", &beam_has_cosmic_IDE, &b_beam_has_cosmic_IDE);
   fChain->SetBranchAddress("cosmic_has_beam_IDE", &cosmic_has_beam_IDE, &b_cosmic_has_beam_IDE);
   fChain->SetBranchAddress("n_cosmics_with_beam_IDE", &n_cosmics_with_beam_IDE, &b_n_cosmics_with_beam_IDE);
   fChain->SetBranchAddress("reco_daughter_allTrack_momByRange_proton", &reco_daughter_allTrack_momByRange_proton, &b_reco_daughter_allTrack_momByRange_proton);
   fChain->SetBranchAddress("reco_daughter_allTrack_momByRange_muon", &reco_daughter_allTrack_momByRange_muon, &b_reco_daughter_allTrack_momByRange_muon);
   fChain->SetBranchAddress("reco_beam_momByRange_proton", &reco_beam_momByRange_proton, &b_reco_beam_momByRange_proton);
   fChain->SetBranchAddress("reco_beam_momByRange_muon", &reco_beam_momByRange_muon, &b_reco_beam_momByRange_muon);
   fChain->SetBranchAddress("reco_daughter_allTrack_momByRange_alt_proton", &reco_daughter_allTrack_momByRange_alt_proton, &b_reco_daughter_allTrack_momByRange_alt_proton);
   fChain->SetBranchAddress("reco_daughter_allTrack_momByRange_alt_muon", &reco_daughter_allTrack_momByRange_alt_muon, &b_reco_daughter_allTrack_momByRange_alt_muon);
   fChain->SetBranchAddress("reco_beam_momByRange_alt_proton", &reco_beam_momByRange_alt_proton, &b_reco_beam_momByRange_alt_proton);
   fChain->SetBranchAddress("reco_beam_momByRange_alt_muon", &reco_beam_momByRange_alt_muon, &b_reco_beam_momByRange_alt_muon);
   fChain->SetBranchAddress("reco_beam_true_byE_endPx", &reco_beam_true_byE_endPx, &b_reco_beam_true_byE_endPx);
   fChain->SetBranchAddress("reco_beam_true_byE_endPy", &reco_beam_true_byE_endPy, &b_reco_beam_true_byE_endPy);
   fChain->SetBranchAddress("reco_beam_true_byE_endPz", &reco_beam_true_byE_endPz, &b_reco_beam_true_byE_endPz);
   fChain->SetBranchAddress("reco_beam_true_byE_endE", &reco_beam_true_byE_endE, &b_reco_beam_true_byE_endE);
   fChain->SetBranchAddress("reco_beam_true_byE_endP", &reco_beam_true_byE_endP, &b_reco_beam_true_byE_endP);
   fChain->SetBranchAddress("reco_beam_true_byE_startPx", &reco_beam_true_byE_startPx, &b_reco_beam_true_byE_startPx);
   fChain->SetBranchAddress("reco_beam_true_byE_startPy", &reco_beam_true_byE_startPy, &b_reco_beam_true_byE_startPy);
   fChain->SetBranchAddress("reco_beam_true_byE_startPz", &reco_beam_true_byE_startPz, &b_reco_beam_true_byE_startPz);
   fChain->SetBranchAddress("reco_beam_true_byE_startE", &reco_beam_true_byE_startE, &b_reco_beam_true_byE_startE);
   fChain->SetBranchAddress("reco_beam_true_byE_startP", &reco_beam_true_byE_startP, &b_reco_beam_true_byE_startP);
   fChain->SetBranchAddress("reco_beam_true_byHits_endPx", &reco_beam_true_byHits_endPx, &b_reco_beam_true_byHits_endPx);
   fChain->SetBranchAddress("reco_beam_true_byHits_endPy", &reco_beam_true_byHits_endPy, &b_reco_beam_true_byHits_endPy);
   fChain->SetBranchAddress("reco_beam_true_byHits_endPz", &reco_beam_true_byHits_endPz, &b_reco_beam_true_byHits_endPz);
   fChain->SetBranchAddress("reco_beam_true_byHits_endE", &reco_beam_true_byHits_endE, &b_reco_beam_true_byHits_endE);
   fChain->SetBranchAddress("reco_beam_true_byHits_endP", &reco_beam_true_byHits_endP, &b_reco_beam_true_byHits_endP);
   fChain->SetBranchAddress("reco_beam_true_byHits_startPx", &reco_beam_true_byHits_startPx, &b_reco_beam_true_byHits_startPx);
   fChain->SetBranchAddress("reco_beam_true_byHits_startPy", &reco_beam_true_byHits_startPy, &b_reco_beam_true_byHits_startPy);
   fChain->SetBranchAddress("reco_beam_true_byHits_startPz", &reco_beam_true_byHits_startPz, &b_reco_beam_true_byHits_startPz);
   fChain->SetBranchAddress("reco_beam_true_byHits_startE", &reco_beam_true_byHits_startE, &b_reco_beam_true_byHits_startE);
   fChain->SetBranchAddress("reco_beam_true_byHits_startP", &reco_beam_true_byHits_startP, &b_reco_beam_true_byHits_startP);
   fChain->SetBranchAddress("reco_beam_incidentEnergies", &reco_beam_incidentEnergies, &b_reco_beam_incidentEnergies);
   fChain->SetBranchAddress("reco_beam_interactingEnergy", &reco_beam_interactingEnergy, &b_reco_beam_interactingEnergy);
   fChain->SetBranchAddress("true_beam_incidentEnergies", &true_beam_incidentEnergies, &b_true_beam_incidentEnergies);
   fChain->SetBranchAddress("true_beam_interactingEnergy", &true_beam_interactingEnergy, &b_true_beam_interactingEnergy);
   fChain->SetBranchAddress("true_beam_slices", &true_beam_slices, &b_true_beam_slices);
   fChain->SetBranchAddress("true_beam_slices_found", &true_beam_slices_found, &b_true_beam_slices_found);
   fChain->SetBranchAddress("true_beam_slices_nIDEs", &true_beam_slices_nIDEs, &b_true_beam_slices_nIDEs);
   fChain->SetBranchAddress("true_beam_slices_deltaE", &true_beam_slices_deltaE, &b_true_beam_slices_deltaE);
   fChain->SetBranchAddress("em_energy", &em_energy, &b_em_energy);
   fChain->SetBranchAddress("true_beam_traj_X", &true_beam_traj_X, &b_true_beam_traj_X);
   fChain->SetBranchAddress("true_beam_traj_Y", &true_beam_traj_Y, &b_true_beam_traj_Y);
   fChain->SetBranchAddress("true_beam_traj_Z", &true_beam_traj_Z, &b_true_beam_traj_Z);
   fChain->SetBranchAddress("true_beam_traj_KE", &true_beam_traj_KE, &b_true_beam_traj_KE);
   fChain->SetBranchAddress("g4rw_primary_weights", &g4rw_primary_weights, &b_g4rw_primary_weights);
   fChain->SetBranchAddress("g4rw_primary_plus_sigma_weight", &g4rw_primary_plus_sigma_weight, &b_g4rw_primary_plus_sigma_weight);
   fChain->SetBranchAddress("g4rw_primary_minus_sigma_weight", &g4rw_primary_minus_sigma_weight, &b_g4rw_primary_minus_sigma_weight);
   fChain->SetBranchAddress("g4rw_primary_var", &g4rw_primary_var, &b_g4rw_primary_var);
   fChain->SetBranchAddress("g4rw_alt_primary_plus_sigma_weight", &g4rw_alt_primary_plus_sigma_weight, &b_g4rw_alt_primary_plus_sigma_weight);
   fChain->SetBranchAddress("g4rw_alt_primary_minus_sigma_weight", &g4rw_alt_primary_minus_sigma_weight, &b_g4rw_alt_primary_minus_sigma_weight);
   Notify();
}

Bool_t prod3::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void prod3::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t prod3::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef prod3_cxx
