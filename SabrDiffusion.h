#pragma once

#include "Diffusion.h"

class SabrDiffusion : public Diffusion {
public:
    /**************************************************************************
     * Constructers and Destructer.
     **************************************************************************/
    SabrDiffusion(const double beta, const double volatility,
        const boost::numeric::ublas::matrix<double>& correlation);
    virtual ~SabrDiffusion();

    /**************************************************************************
     * inherited  operators.
     **************************************************************************/
    virtual void operator()(
        const double time, 
        const boost::numeric::ublas::vector<double>& states,
        boost::numeric::ublas::matrix<double>& diffusion) const;

private:
    /**************************************************************************
     * private variables
     **************************************************************************/
    const double _beta;
    const double _volatility;
    const boost::numeric::ublas::matrix<double> _correlation;
    
};
