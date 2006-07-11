#ifndef HepPDTESSource_h
#define HepPDTESSource_h
// -*- C++ -*-
//
// Package:    HepPDTESSource
// Class:      HepPDTESSource
// 
/**\class HepPDTESSource HepPDTESSource.h PhysicsTools/HepPDTESSource/interface/HepPDTESSource.h

 Description: HepPDT particle data table ESSource

 Implementation:
    <Notes on implementation>
*/
//
// Original Author:  Luca Lista
//         Created:  Fri Mar 10 15:58:18 CET 2006
// $Id: HepPDTESSource.cc,v 1.2 2006/07/11 08:15:26 fmoortga Exp $
//
#include <memory>
#include <fstream>
#include "boost/shared_ptr.hpp"
#include <CLHEP/HepPDT/DefaultConfig.hh>
#include <CLHEP/HepPDT/TableBuilder.hh>
#include <CLHEP/HepPDT/ParticleDataTableT.hh>
#include "FWCore/Framework/interface/ESProducer.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetupRecordIntervalFinder.h"
#include "FWCore/Framework/interface/SourceFactory.h"
#include "SimGeneral/HepPDTRecord/interface/PDTRecord.h"
#include <climits>

class HepPDTESSource : public edm::ESProducer, public  edm::EventSetupRecordIntervalFinder {
public:
  /// constructor from parameter set
  HepPDTESSource( const edm::ParameterSet& );
  /// destructor
  ~HepPDTESSource();
  /// define the particle data table type
  typedef DefaultConfig::ParticleDataTable PDT;
  /// define the return type
  typedef std::auto_ptr<PDT> ReturnType;
  /// return the particle table
  ReturnType produce( const PDTRecord & );
  /// set validity interval
  void setIntervalFor( const edm::eventsetup::EventSetupRecordKey &,
		       const edm::IOVSyncValue &,
		       edm::ValidityInterval & );

private:
  std::string pdtFileName;
};
#endif
