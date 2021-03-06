#pragma once

#include "TimeIndexManager.h"

#include <boost/shared_ptr.hpp>

class Maturities
{
public:
    Maturities(
        const std::vector<double>& observedTimes, 
        const std::vector<std::size_t>& maturityIndice);
    ~Maturities();
    
    double operator[](const std::size_t index) const;
    std::size_t size() const;
    std::size_t translateMaturityIndexToAssetIndex(
        const std::size_t maturityIndex) const;
    std::size_t translateMaturityIndexToTimeIndex(
        const std::size_t maturityIndex) const;
    std::size_t findIndexIncludingTime(const double time) const;

private:
    const boost::shared_ptr<const TimeIndexManager> _maturities;
            
};
