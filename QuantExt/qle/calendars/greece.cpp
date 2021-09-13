/*
 Copyright (C) 2021 Quaternion Risk Management Ltd
 All rights reserved.

 This file is part of ORE, a free-software/open-source library
 for transparent pricing and risk analysis - http://opensourcerisk.org

 ORE is free software: you can redistribute it and/or modify it
 under the terms of the Modified BSD License.  You should have received a
 copy of the license along with this program.
 The license is also available online at <http://opensourcerisk.org>

 This program is distributed on the basis that it will form a useful
 contribution to risk analytics and model standardisation, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
*/
#include <qle/calendars/ireland.hpp>
#include <qle/time/dateutilities.hpp>
#include <ql/errors.hpp>

namespace QuantExt {
    using namespace QuantLib;

    Ireland::Ireland() {
        // all calendar instances on the same market share the same
        // implementation instance
        impl_ = boost::make_shared<Ireland::DublinImpl>();
    }

    bool Ireland::DublinImpl::isBusinessDay(const Date& date) const {
        Weekday w = date.weekday();
        Day d = date.dayOfMonth(), dd = date.dayOfYear();
        Month m = date.month();
        Year y = date.year();
        Day em = easterMonday(y);

        auto firstMondayMay = Date::nthWeekday(1, Monday, May, y);
        auto firstMondayJune = Date::nthWeekday(1, Monday, June, y);

        if (isWeekend(w)
            // New Year's Day (possibly moved to Monday)
            || ((d == 1 || ((d == 2 || d == 3) && w == Monday)) &&
                m == January)
            // Good Friday
            || (dd == em-3)
            // Easter Monday
            || (dd == em)
            // St. Patrick's Day (possibly moved to Monday)
            || (m == Mar && ((d == 13) || ((d == 14 || d == 15) && w == Monday)))
            // first Monday of May 
            || (m == May && d == Date::nthWeekday(1, Monday, May, y).dayOfMonth())
            // first Monday of June 
            || (m == June && d == Date::nthWeekday(1, Monday, June, y).dayOfMonth())
            // first Monday of August 
            || (m == August && d == Date::nthWeekday(1, Monday, August, y).dayOfMonth())
            // last Monday of October
            || (m == October && d == DateUtilities::lastWeekday(Monday, October, y).dayOfMonth())
            // Christmas (possibly moved to Monday or Tuesday)
            || ((d == 25 || (d == 27 && (w == Monday || w == Tuesday)))
                && m == December)
            // Boxing Day (possibly moved to Monday or Tuesday)
            || ((d == 26 || (d == 28 && (w == Monday || w == Tuesday)))
                && m == December))
            return false; // NOLINT(readability-simplify-boolean-expr)
        return true;
    }

}

