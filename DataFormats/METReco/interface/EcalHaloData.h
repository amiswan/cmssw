#ifndef DATAFORMATS_METRECO_ECALHALODATA_H
#define DATAFORMATS_METRECO_ECALHALODATA_H
/*
  [class]:  EcalHaloData
  [authors]: R. Remington, The University of Florida
  [description]: Container class to store beam halo data specific to the Ecal subdetector
  [date]: October 15, 2009
*/
#include "DataFormats/METReco/interface/PhiWedge.h"
#include <cmath>
#include "DataFormats/Common/interface/RefVector.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/RefProd.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"
#include "DataFormats/EgammaReco/interface/BasicCluster.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/METReco/interface/HaloClusterCandidateEB.h"
#include "DataFormats/METReco/interface/HaloClusterCandidateEE.h"

namespace reco {
  class EcalHaloData {
  public:
    //Constructor
    EcalHaloData();
    //Destructor
    ~EcalHaloData(){}
    
    // Number of Halo-like superclusters as a function of the roundness and angular cuts
    //int NumberOfHaloSuperClusters(int iRoundness=2, int iAngle=2) const;
    int NumberOfHaloSuperClusters(float roundness=100., float angle=4.0) const;
    
    // Return collection of 5-degree Phi Wedges built from Ecal RecHits
    const std::vector<PhiWedge>& GetPhiWedges() const {return PhiWedgeCollection;}
    std::vector<PhiWedge>& GetPhiWedges(){return PhiWedgeCollection;}
    
    // Get Reference to the SuperClusters
    edm::RefVector<reco::SuperClusterCollection>& GetSuperClusters(){return TheSuperClusterRefs;}
    const edm::RefVector<reco::SuperClusterCollection>& GetSuperClusters() const {return TheSuperClusterRefs;}


    // Store Shower Shape variables for SuperClusters
    edm::ValueMap<float>& GetShowerShapesRoundness(){ return ShowerShapes_Roundness;}    
    const edm::ValueMap<float>& GetShowerShapesRoundness()const { return ShowerShapes_Roundness;}    

    edm::ValueMap<float>& GetShowerShapesAngle() { return ShowerShapes_Angle;}
    const edm::ValueMap<float>& GetShowerShapesAngle() const { return ShowerShapes_Angle;}


    const std::vector<HaloClusterCandidateEB>& getHaloClusterCandidatesEB() const {return thehaloclustercands_eb;} 
    std::vector<HaloClusterCandidateEB>& getHaloClusterCandidatesEB(){return thehaloclustercands_eb;} 
    const std::vector<HaloClusterCandidateEE>& getHaloClusterCandidatesEE() const {return thehaloclustercands_ee;} 
    std::vector<HaloClusterCandidateEE>& getHaloClusterCandidatesEE(){return thehaloclustercands_ee;} 

    void setHaloClusterCandidatesEB(std::vector<HaloClusterCandidateEB> x){thehaloclustercands_eb =x;};
    void setHaloClusterCandidatesEE(std::vector<HaloClusterCandidateEE> x){thehaloclustercands_ee =x;};
  private:
    std::vector<PhiWedge> PhiWedgeCollection;
    edm::RefVector<reco::SuperClusterCollection> TheSuperClusterRefs;

    edm::ValueMap<float> ShowerShapes_Roundness;
    edm::ValueMap<float> ShowerShapes_Angle;
    
    std::vector<HaloClusterCandidateEB> thehaloclustercands_eb;
    std::vector<HaloClusterCandidateEE> thehaloclustercands_ee;

  };
}

#endif
