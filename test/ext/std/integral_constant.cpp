/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/ext/std/integral_constant.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/integral.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/type.hpp>

// instances
#include <test/auto/constant.hpp>
#include <test/auto/integral_constant.hpp>

#include <type_traits>
using namespace boost::hana;


namespace boost { namespace hana { namespace test {
    template <>
    auto instances<ext::std::IntegralConstant> = tuple(
        type<Constant>,
        type<IntegralConstant>
    );

    template <>
    auto objects<ext::std::IntegralConstant> = tuple(
        ::std::integral_constant<int, 0>{},
        ::std::integral_constant<int, 1>{},
        ::std::integral_constant<int, 2>{},
        ::std::integral_constant<int, 3>{},

        ::std::true_type{},
        ::std::false_type{}
    );
}}}


int main() {
    test::check_datatype<ext::std::IntegralConstant>();

    // interoperation with Integral
    {
        BOOST_HANA_CONSTANT_ASSERT(std::integral_constant<int, 1>{} == int_<1>);
        BOOST_HANA_CONSTANT_ASSERT(std::integral_constant<int, 1>{} == long_<1>);

        BOOST_HANA_CONSTANT_ASSERT(std::integral_constant<int, 2>{} != int_<3>);
    }

    // Constant
    {
        // value
        {
            static_assert(value(std::integral_constant<int, 0>{}) == 0, "");
            static_assert(value(std::integral_constant<int, 1>{}) == 1, "");
        }
    }
}
