//____________________________________________________________________________
/*!

\class    genie::XclsTag

\brief    Contains minimal information for tagging exclusive processes.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          STFC, Rutherford Appleton Laboratory

\created  December 08, 2004

\cpright  Copyright (c) 2003-2013, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//___________________________________________________________________________

#ifndef _FINAL_STATE_H_
#define _FINAL_STATE_H_

#include <iostream>
#include <string>

#include <TObject.h>

#include "BaryonResonance/BaryonResonance.h"

using std::ostream;
using std::string;

namespace genie {

class XclsTag : public TObject {

public:
  XclsTag();
  XclsTag(const XclsTag & xcls);
 ~XclsTag();

  // Getting exclusive intermediate and/or final state information
  bool IsCharmEvent     (void) const { return fIsCharmEvent;     }
  bool IsInclusiveCharm (void) const;
  int  CharmHadronPdg   (void) const { return fCharmedHadronPdg; }
  int  NProtons         (void) const { return fNProtons;  }
  int  NNeutrons        (void) const { return fNNeutrons; }
  int  NPi0             (void) const { return fNPi0;      }
  int  NPiPlus          (void) const { return fNPiPlus;   }
  int  NPiMinus         (void) const { return fNPiMinus;  }
  int  NNucleons        (void) const { return fNNeutrons + fNProtons;       }
  int  NPions           (void) const { return fNPi0 + fNPiPlus + fNPiMinus; }
  bool KnownResonance   (void) const { return (fResonance != kNoResonance); }
  Resonance_t Resonance (void) const { return fResonance; }
  int  DecayMode        (void) const { return fDecayMode; }

  // Ssetting exclusive final state information
  void SetCharm       (int charm_pdgc = 0);
  void SetNPions      (int npi_plus, int npi_0, int npi_minus);
  void SetNNucleons   (int np, int nn);
  void SetNProtons    (int np) { fNProtons  = np; }
  void SetNNeutrons   (int nn) { fNNeutrons = nn; }
  void UnsetCharm     (void);
  void ResetNPions    (void);
  void ResetNNucleons (void);
  void SetResonance   (Resonance_t res);
  void SetDecayMode   (int decay_mode);

  // Copy, reset, print itself and build string code
  void   Reset    (void);                          ///< reset object
  void   Copy     (const XclsTag & xcls);          ///< copy input XclsTag object
  string AsString (void) const;                    ///< pack into a string code
  void   Print    (ostream & stream) const;        ///< print

  XclsTag &        operator =  (const XclsTag & xcls);                  ///< copy
  friend ostream & operator << (ostream& stream, const XclsTag & xcls); ///< print

private:

  // Private data members
  bool        fIsCharmEvent;     ///< true if we have charm production
  int         fCharmedHadronPdg; ///< charmed hadron pdg-code
  int         fNProtons;         ///< # of p's in the f/s hadronic system
  int         fNNeutrons;        ///< # of n's in the f/s hadronic system
  int         fNPi0;             ///< # of pi^0's in the f/s hadronic system
  int         fNPiPlus;          ///< # of pi^+'s in the f/s hadronic system
  int         fNPiMinus;         ///< # of pi^-'s in the f/s hadronic system
  Resonance_t fResonance;        ///< baryon resonance excited by probe
  int         fDecayMode;

ClassDef(XclsTag,2)
};

}      // namespace

#endif // _FINAL_STATE_H_
