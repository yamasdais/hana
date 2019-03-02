// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/hana/assert.hpp>
#include <boost/hana/bool.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/find_if.hpp>
#include <boost/hana/functional/always.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/optional.hpp>
#include <boost/hana/wstring.hpp>
namespace hana = boost::hana;


int main() {
    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::find_if(BOOST_HANA_AUTO_STRING(L""), hana::always(hana::true_c)),
        hana::nothing
    ));

    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::find_if(BOOST_HANA_AUTO_STRING(L"abcd"), hana::equal.to(hana::wchar_c<L'a'>)),
        hana::just(hana::wchar_c<L'a'>)
    ));

    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::find_if(BOOST_HANA_AUTO_STRING(L"abcd"), hana::equal.to(hana::wchar_c<L'c'>)),
        hana::just(hana::wchar_c<L'c'>)
    ));

    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::find_if(BOOST_HANA_AUTO_STRING(L"abcd"), hana::equal.to(hana::wchar_c<L'd'>)),
        hana::just(hana::wchar_c<L'd'>)
    ));

    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::find_if(BOOST_HANA_AUTO_STRING(L"abcd\xef01"), hana::equal.to(hana::wchar_c<L'\xef01'>)),
        hana::just(hana::wchar_c<L'\xef01'>)
    ));

    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::find_if(BOOST_HANA_AUTO_STRING(L"abcd\xef01"), hana::equal.to(hana::wchar_c<L'\x01'>)),
        hana::nothing
    ));
}
