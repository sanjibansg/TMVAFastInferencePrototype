// @(#)root/tmva/sofie $Id$
// Author: Sanjiban Sengupta, 2021

#ifndef TMVA_SOFIE_RMODELPARSER_KERAS
#define TMVA_SOFIE_RMODELPARSER_KERAS


#include <Python.h>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/arrayobject.h>


#include "SOFIE_common.hxx"
#include "OperatorList.hxx"

#include "TMVA/RModel.hxx"
#include "Rtypes.h"
#include "TString.h"
#include <vector>

using namespace TMVA;
using namespace TMVA::Experimental;
using namespace TMVA::Experimental::SOFIE;


namespace TMVA{
namespace Experimental{
namespace SOFIE{

enum class LayerType{
   DENSE = 0, RELU = 1, TRANSPOSE = 2 //order sensitive

};


namespace INTERNAL{
   std::unique_ptr<ROperator> make_ROperator_Gemm(std::string input,std::string output,std::string kernel,std::string bias,std::string dtype);
   std::unique_ptr<ROperator> make_ROperator_Relu(std::string input, std::string output, std::string dtype);
   std::unique_ptr<ROperator> make_ROperator_Transpose(std::string input, std::string output, std::vector<int_t> dims, std::string dtype);
}

namespace PyKeras{
    RModel Parse(std::string filepath);
  }
}
}
}

#endif //TMVA_SOFIE_RMODELPARSER_KERAS
