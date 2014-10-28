/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/integral.hpp>

#include <boost/hana/tuple.hpp>
#include <boost/hana/type.hpp>

#include <cstddef>
#include <test/auto/base.hpp>
#include <test/auto/constant.hpp>
#include <test/auto/integral_constant.hpp>
#include <type_traits>
using namespace boost::hana;


namespace boost { namespace hana { namespace test {
    template <>
    auto objects<Integral> = tuple(
        integral<int, 0>,
        integral<int, 1>,
        integral<int, 2>,
        integral<int, 3>,

        integral<unsigned long, 0>,
        integral<unsigned long, 1>,
        integral<unsigned long, 2>,
        integral<unsigned long, 3>
    );

    template <>
    auto instances<Integral> = tuple(
        type<Constant>,
        type<IntegralConstant>
    );
}}}


int main() {
    test::check_datatype<Integral>();

    // Integral's API (like std::integral_constant)
    {
        // operator()
        static_assert(size_t<0>() == 0, "");
        static_assert(size_t<1>() == 1, "");
        static_assert(int_<-3>() == -3, "");

        // decltype(operator())
        BOOST_HANA_CONSTANT_ASSERT(decltype_(size_t<0>()) == type<std::size_t>);
        BOOST_HANA_CONSTANT_ASSERT(decltype_(int_<-3>()) == type<int>);

        // conversions
        constexpr std::size_t a = size_t<0>, b = size_t<1>;
        static_assert(a == 0 && b == 1, "");

        constexpr int c = int_<0>, d = int_<-3>;
        static_assert(c == 0 && d == -3, "");

        // nested ::value
        static_assert(decltype(int_<1>)::value == 1, "");

        // nested ::type
        static_assert(std::is_same<
            decltype(int_<1>)::type,
            std::remove_cv_t<decltype(int_<1>)>
        >{}, "");

        // nested ::value_type
        static_assert(std::is_same<decltype(int_<1>)::value_type, int>{}, "");
    }

    // Extensions to std::integral_constant
    {
        // times member function
        {
            int counter = 0;
            int_<3>.times([&] { ++counter; });
            BOOST_HANA_RUNTIME_ASSERT(counter == 3);
        }

        // Arithmetic operators
        {
            BOOST_HANA_CONSTANT_ASSERT(+int_<1> == int_<1>);
            BOOST_HANA_CONSTANT_ASSERT(-int_<1> == int_<-1>);
            BOOST_HANA_CONSTANT_ASSERT(int_<1> + int_<2> == int_<3>);
            BOOST_HANA_CONSTANT_ASSERT(int_<1> - int_<2> == int_<-1>);
            BOOST_HANA_CONSTANT_ASSERT(int_<3> * int_<2> == int_<6>);
            BOOST_HANA_CONSTANT_ASSERT(int_<6> / int_<3> == int_<2>);
            BOOST_HANA_CONSTANT_ASSERT(int_<6> % int_<4> == int_<2>);
            BOOST_HANA_CONSTANT_ASSERT(~int_<6> == int_<~6>);
            BOOST_HANA_CONSTANT_ASSERT((int_<6> & int_<3>) == int_<6 & 3>);
            BOOST_HANA_CONSTANT_ASSERT(int_<6> | int_<3> == int_<6 | 3>);
            BOOST_HANA_CONSTANT_ASSERT(int_<6> ^ int_<3> == int_<6 ^ 3>);
            BOOST_HANA_CONSTANT_ASSERT((int_<6> << int_<3>) == int_<(6 << 3)>);
            BOOST_HANA_CONSTANT_ASSERT((int_<6> >> int_<3>) == int_<(6 >> 3)>);
        }

        // Comparison operators
        {
            BOOST_HANA_CONSTANT_ASSERT(int_<0> == int_<0>);
            BOOST_HANA_CONSTANT_ASSERT(int_<1> != int_<0>);
            BOOST_HANA_CONSTANT_ASSERT(int_<0> < int_<1>);
            BOOST_HANA_CONSTANT_ASSERT(int_<0> <= int_<1>);
            BOOST_HANA_CONSTANT_ASSERT(int_<0> <= int_<0>);
            BOOST_HANA_CONSTANT_ASSERT(int_<1> > int_<0>);
            BOOST_HANA_CONSTANT_ASSERT(int_<1> >= int_<0>);
            BOOST_HANA_CONSTANT_ASSERT(int_<0> >= int_<0>);
        }

        // Logical operators
        {
            BOOST_HANA_CONSTANT_ASSERT(int_<3> || int_<0>);
            BOOST_HANA_CONSTANT_ASSERT(int_<3> && int_<1>);
            BOOST_HANA_CONSTANT_ASSERT(!int_<0>);
            BOOST_HANA_CONSTANT_ASSERT(!!int_<3>);
        }

        // Creation with user-defined literals
        {
            using namespace boost::hana::literals;

            BOOST_HANA_CONSTANT_ASSERT(0_c == llong<0>);
            BOOST_HANA_CONSTANT_ASSERT(1_c == llong<1>);
            BOOST_HANA_CONSTANT_ASSERT(12_c == llong<12>);
            BOOST_HANA_CONSTANT_ASSERT(123_c == llong<123>);
            BOOST_HANA_CONSTANT_ASSERT(1234567_c == llong<1234567>);
            BOOST_HANA_CONSTANT_ASSERT(-34_c == llong<-34>);

            BOOST_HANA_CONSTANT_ASSERT(decltype_(-1234_c) == decltype_(llong<-1234>));
            BOOST_HANA_CONSTANT_ASSERT(-12_c < 0_c);
        }
    }

    // Constant
    {
        // value
        {
            static_assert(value(integral<int, 0>) == 0, "");
            static_assert(value(integral<int, 1>) == 1, "");
        }
    }

    // IntegralConstant
    {
        // integral_constant
        {
            BOOST_HANA_CONSTANT_ASSERT(equal(
                integral_constant<Integral, int, 3>,
                integral<int, 3>
            ));
        }
    }
}
