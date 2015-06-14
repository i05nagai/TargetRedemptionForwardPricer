#include "CashFlowAsian.h"

/******************************************************************************
 * Constructers and Destructers.
 ******************************************************************************/
CashFlowAsian::CashFlowAsian(
    const std::size_t cashFlowDateIndex,
    const std::size_t spotIndex,
    const std::vector<std::size_t>& timeIndice)
    :
     _cashFlow(cashFlowDateIndex),
    _spotIndex(spotIndex),
    _timeIndice(timeIndice)
{
}

CashFlowAsian::~CashFlowAsian() 
{
}

/******************************************************************************
 * inherited pure virtual functions.
 ******************************************************************************/
double CashFlowAsian::operator()(
    const boost::numeric::ublas::matrix<double>& path) const
{
    const double average = calculateAsian(path);

    return average;
}

std::size_t CashFlowAsian::getCashFlowDateIndex() const
{
    return _cashFlow.getCashFlowDateIndex();
}

/******************************************************************************
 * private functions.
 ******************************************************************************/
double CashFlowAsian::calculateAsian(
    const boost::numeric::ublas::matrix<double>& path) const
{
    double average = 0.0;
    for (std::size_t timeIndex = 0; timeIndex < _timeIndice.size(); ++timeIndex) {
        average += path(_spotIndex, _timeIndice[timeIndex]);
    }

    return average / _timeIndice.size();
}

