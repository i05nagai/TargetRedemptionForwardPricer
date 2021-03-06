#pragma once

#include "PathSimulatorDecorator.h"

#include <boost/shared_ptr.hpp>

class PathSimulatorExp : public PathSimulatorDecorator {
public:
    PathSimulatorExp(
        const boost::shared_ptr<const PathSimulatorBase>& innerSimulator);
    virtual ~PathSimulatorExp();

    /******************************************************************************
     * inherited virtual functions.
     ******************************************************************************/
    virtual void simulateOnePath(
        boost::numeric::ublas::vector<double>& processes,
        boost::numeric::ublas::matrix<double>& path,
        const std::vector<double>& observedTimes,
        std::vector<double>& randoms) const;

private:
};

