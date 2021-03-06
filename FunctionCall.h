#pragma once

#include "FunctionMathematics.h"

class FunctionCall : public FunctionMathematics {
public:
    /**************************************************************************
     * Constructers and Destructer.
     **************************************************************************/
    FunctionCall(const double strike);
    virtual ~FunctionCall();

    virtual double operator()(
        const boost::numeric::ublas::vector<double>& spot);
    virtual void calculateDifferential(
        const boost::numeric::ublas::vector<double>& spot,
        boost::numeric::ublas::vector<double>& result);
    
private:
    const double _strike;
            
};

