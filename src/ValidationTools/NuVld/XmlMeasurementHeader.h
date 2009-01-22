//_____________________________________________________________________________
/*!

\class    genie::nuvld::XmlMeasurementHeader

\brief

\author   Costas Andreopoulos (Rutherford Lab.)  <costas.andreopoulos \at stfc.ac.uk>

\created  August 2003
*/
//_____________________________________________________________________________

#ifndef _MEASUREMENT_HEADER_H_
#define _MEASUREMENT_HEADER_H_

#include <string>
#include <vector>
#include <iostream>

#include "ValidationTools/NuVld/XmlCitation.h"

using std::string;
using std::ostream;
using std::endl;
using std::cerr;
using std::vector;

namespace genie {
namespace nuvld {

const int c_meas_header_ntags = 9;
const string c_meas_header_tag[c_meas_header_ntags] = {
   string("observable"),
   string("target"),
   string("reaction"),
   string("A"),              /* defaults to 1, only set for COHERENT XSEC */
   string("exposure"),
   string("exposure_units"),
   string("data_source"),
   string("npoints"),
   string("err_status"),
};

class XmlMeasurementHeader
{
public:

  XmlMeasurementHeader();
  XmlMeasurementHeader(const XmlMeasurementHeader & header);
  virtual ~XmlMeasurementHeader() { }

  void Add(string key, string value = "");
  void Add(XmlCitation * ref);

  virtual const string XmlObservable    (void) const { return _observable;     }
  virtual const string Target        (void) const { return _target;         }
  virtual const string Reaction      (void) const { return _reaction;       }
  virtual const string A             (void) const { return _A;              }
  virtual const string Exposure      (void) const { return _exposure;       }
  virtual const string ExposureUnits (void) const { return _exposure_units; }
  virtual const string DataSource    (void) const { return _data_source;    }
  virtual const string Tag           (void) const { return _tag;            }
  virtual const string NPoints       (void) const { return _npoints;        }
  virtual const string ErrorStatus   (void) const { return _err_status;     }
  virtual const string Comment       (void) const { return _comment;        }

  const vector<XmlCitation *> & GetRefs(void) const { return *_refs; }

  friend ostream & operator << (ostream & stream, const XmlMeasurementHeader & header);

protected:

  vector<XmlCitation *> * _refs;

  string  _observable;
  string  _target;
  string  _reaction;
  string  _A;
  string  _exposure;
  string  _exposure_units;
  string  _data_source;
  string  _tag;
  string  _npoints;
  string  _err_status;
  string  _comment;
};

} // nuvld namespace
} // genie namespace

#endif // _MEASUREMENT_HEADER_H_