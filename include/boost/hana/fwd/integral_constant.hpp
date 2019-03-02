/*!
@file
Forward declares `boost::hana::integral_constant`.

@copyright Louis Dionne 2013-2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FWD_INTEGRAL_CONSTANT_HPP
#define BOOST_HANA_FWD_INTEGRAL_CONSTANT_HPP

#include <boost/hana/config.hpp>
#include <boost/hana/detail/integral_constant.hpp>

#include <cstddef>


BOOST_HANA_NAMESPACE_BEGIN
    //! Creates an `integral_constant` holding the given compile-time value.
    //! @relates hana::integral_constant
    //!
    //! Specifically, `integral_c<T, v>` is a `hana::integral_constant`
    //! holding the compile-time value `v` of an integral type `T`.
    //!
    //!
    //! @tparam T
    //! The type of the value to hold in the `integral_constant`.
    //! It must be an integral type.
    //!
    //! @tparam v
    //! The integral value to hold in the `integral_constant`.
    //!
    //!
    //! Example
    //! -------
    //! @snippet example/integral_constant.cpp integral_c
    template <typename T, T v>
    constexpr integral_constant<T, v> integral_c{};


    //! @relates hana::integral_constant
    template <bool b>
    using bool_ = integral_constant<bool, b>;

    //! @relates hana::integral_constant
    template <bool b>
    constexpr bool_<b> bool_c{};

    //! @relates hana::integral_constant
    using true_ = bool_<true>;

    //! @relates hana::integral_constant
    constexpr auto true_c = bool_c<true>;

    //! @relates hana::integral_constant
    using false_ = bool_<false>;

    //! @relates hana::integral_constant
    constexpr auto false_c = bool_c<false>;


    //! @relates hana::integral_constant
    template <char c>
    using char_ = integral_constant<char, c>;

    //! @relates hana::integral_constant
    template <char c>
    constexpr char_<c> char_c{};


    //! @relates hana::integral_constant
    template <wchar_t c>
    using wchar_ = integral_constant<wchar_t, c>;

    //! @relates hana::integral_constant
    template <wchar_t c>
    constexpr wchar_<c> wchar_c{};


    //! @relates hana::integral_constant
    template <char16_t c>
    using char16_ = integral_constant<char16_t, c>;

    //! @relates hana::integral_constant
    template <char16_t c>
    constexpr char16_<c> char16_c{};


    //! @relates hana::integral_constant
    template <char32_t c>
    using char32_ = integral_constant<char32_t, c>;

    //! @relates hana::integral_constant
    template <char32_t c>
    constexpr char32_<c> char32_c{};


    //! @relates hana::integral_constant
    template <typename CharT, CharT c>
    using basic_char_ = integral_constant<CharT, c>;

    //! @relates hana::integral_constant
    template <typename CharT, CharT c>
    constexpr basic_char_<CharT, c> basic_char_c{};


    //! @relates hana::integral_constant
    template <short i>
    using short_ = integral_constant<short, i>;

    //! @relates hana::integral_constant
    template <short i>
    constexpr short_<i> short_c{};


    //! @relates hana::integral_constant
    template <unsigned short i>
    using ushort_ = integral_constant<unsigned short, i>;

    //! @relates hana::integral_constant
    template <unsigned short i>
    constexpr ushort_<i> ushort_c{};


    //! @relates hana::integral_constant
    template <int i>
    using int_ = integral_constant<int, i>;

    //! @relates hana::integral_constant
    template <int i>
    constexpr int_<i> int_c{};


    //! @relates hana::integral_constant
    template <unsigned int i>
    using uint = integral_constant<unsigned int, i>;

    //! @relates hana::integral_constant
    template <unsigned int i>
    constexpr uint<i> uint_c{};


    //! @relates hana::integral_constant
    template <long i>
    using long_ = integral_constant<long, i>;

    //! @relates hana::integral_constant
    template <long i>
    constexpr long_<i> long_c{};


    //! @relates hana::integral_constant
    template <unsigned long i>
    using ulong = integral_constant<unsigned long, i>;

    //! @relates hana::integral_constant
    template <unsigned long i>
    constexpr ulong<i> ulong_c{};


    //! @relates hana::integral_constant
    template <long long i>
    using llong = integral_constant<long long, i>;

    //! @relates hana::integral_constant
    template <long long i>
    constexpr llong<i> llong_c{};


    //! @relates hana::integral_constant
    template <unsigned long long i>
    using ullong = integral_constant<unsigned long long, i>;

    //! @relates hana::integral_constant
    template <unsigned long long i>
    constexpr ullong<i> ullong_c{};


    //! @relates hana::integral_constant
    template <std::size_t i>
    using size_t = integral_constant<std::size_t, i>;

    //! @relates hana::integral_constant
    template <std::size_t i>
    constexpr size_t<i> size_c{};


    namespace literals {
        //! Creates a `hana::integral_constant` from a literal.
        //! @relatesalso boost::hana::integral_constant
        //!
        //! The literal is parsed at compile-time and the result is returned
        //! as a `llong<...>`.
        //!
        //! @note
        //! We use `llong<...>` instead of `ullong<...>` because using an
        //! unsigned type leads to unexpected behavior when doing stuff like
        //! `-1_c`. If we used an unsigned type, `-1_c` would be something
        //! like `ullong<-1>` which is actually `ullong<something huge>`.
        //!
        //!
        //! Example
        //! -------
        //! @snippet example/integral_constant.cpp literals
        template <char ...c>
        constexpr auto operator"" _c();
    }
BOOST_HANA_NAMESPACE_END

#endif // !BOOST_HANA_FWD_INTEGRAL_CONSTANT_HPP
