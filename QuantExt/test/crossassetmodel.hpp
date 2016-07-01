/*
 Copyright (C) 2016 Quaternion Risk Management Ltd
 All rights reserved.

 This file is part of OpenRiskEngine, a free-software/open-source library
 for transparent pricing and risk analysis - http://openriskengine.org

 OpenRiskEngine is free software: you can redistribute it and/or modify it
 under the terms of the Modified BSD License.  You should have received a
 copy of the license along with this program; if not, please email
 <users@openriskengine.org>. The license is also available online at
 <http://openriskengine.org/license.shtml>.

 This program is distributed on the basis that it will form a useful
 contribution to risk analytics and model standardisation, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
*/


#ifndef quantext_test_crossassetmodel_hpp
#define quantext_test_crossassetmodel_hpp

#include <boost/test/unit_test.hpp>

/* remember to document new and/or updated tests in the Doxygen
   comment block of the corresponding class */

namespace testsuite {

    //! Cross Asset Model Test Suite
class CrossAssetModelTest {
  public:
    //! Test consistency of Bermudan pricing in Lgm1f and Gsr models
    static void testBermudanLgm1fGsr();
    static void testBermudanLgmInvariances();
    static void testNonstandardBermudanSwaption();
    static void testLgm1fCalibration();
    static void testCcyLgm3fForeignPayouts();
    static void testLgm5fFxCalibration();
    static void testLgm5fFullCalibration();
    static void testLgm5fMoments();
    static void testLgmGsrEquivalence();
    static void testLgmMcWithShift();
    static void testCorrelationRecovery();
    static boost::unit_test_framework::test_suite *suite();
};

}

#endif
