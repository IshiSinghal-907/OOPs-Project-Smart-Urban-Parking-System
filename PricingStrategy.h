#ifndef PRICING_STRATEGY_H
#define PRICING_STRATEGY_H

class PricingStrategy {
public:
    virtual double calculate(int hours) = 0;
    virtual ~PricingStrategy() {}
};

class NormalStrategy : public PricingStrategy {
public:
    double calculate(int hours) override { return hours * 10.0; }
};

class PeakHourStrategy : public PricingStrategy {
public:
    double calculate(int hours) override { return hours * 20.0; }
};

#endif
