#include "gtest/gtest.h"

#include "options/BlackScholes.h"


const double eps = 0.01;
const double risklessRate = 0.05;
const double spot = 100.;
const BlackScholes bs(Volatility(0.15, 365));

TEST(BlackScholesTest, PriceEuropeanCall) {
    const EuropeanOption eu_call(new Call, 90, 105.);
    ASSERT_NEAR(1.52, bs.price(risklessRate, spot, eu_call), eps);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
