
/** ****************************************************************************
 * 
 *                          
 *                          The MIT License (MIT)
 *                          
 *                          
 *  ****************************************************************************
 *
 *              Copyright (c) 2018 Jose Fernando Lopez Fernandez
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to
 *  deal in the Software without restriction, including without limitation the 
 *  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
 *  sell copies of the Software, and to permit persons to whom the Software is 
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in 
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 *  IN THE SOFTWARE.
 *
 *  ****************************************************************************/

#undef NDEBUG

#include <cassert>

/** ****************************************************************************
 *
 *
 *                 MODIFIED SIMPLE EXPRESSION GRAMMAR COMPILER
 *
 *
 *  ****************************************************************************
 *
 *  @file main.cpp
 *
 *  @author Jose Fernando Lopez Fernandez
 *  
 *  @data 10-May-2018
 *  
 *  @details In this project, we are building a compiler for a simple modified
 *  expression grammar. our goal is to take simple arithmetic expressions as
 *  input and generate code that evaluates those expressions at runtime.
 *
 *
 *  ****************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

#include <CDCC/Lex.hxx>

using namespace CDCC;

template <class T>
auto Forward(T&& arg)
{
    return static_cast<T&&>(arg);
}

template <class T>
auto passThrough(T&& t) -> decltype (auto)
{
    return static_cast<typename std::remove_reference<T>::type&&>(t);
}

struct Thing
{
    constexpr static auto value = 127;

    auto operator()() const noexcept -> decltype (value) { return value; }

    auto operator()(const int n) const noexcept -> decltype (Forward<decltype(value)>(value * n)) { return value * n; }

    auto operator[](const int n) const noexcept -> decltype (value) { return value * n; }
};

int main(int argc, char *argv[])
{
    Thing t1;

    const auto result = t1(3);

    std::cout << std::boolalpha << "Is rvalue reference? " << std::is_rvalue_reference<decltype(result)>::value << "\n";

    std::cout << std::boolalpha << "Is rvalue reference? " << std::is_rvalue_reference<decltype(passThrough(8))>::value << "\n";

    std::cout << std::boolalpha << "Is rvalue reference? " << std::is_rvalue_reference<decltype(passThrough(std::move("8")))>::value << "\n";

    std::cout << std::boolalpha << "Is rvalue reference? " << std::is_rvalue_reference<decltype(passThrough(false))>::value;



    //if (argc == 1)
    //{
    //    std::cerr << "You must specify an input file.\n";

    //    return EXIT_FAILURE;
    //}

    //Lexer lexer;

    //// Load the input files
    //for (auto i = 1; i < argc; i++)
    //{
    //    lexer.inputFiles.emplace_back(argv[i]);
    //}

    //std::cout << "\n";

    //for (const auto& file : lexer.inputFiles)
    //{
    //    std::cout << file << "\n";
    //}


    //// Once the lexer is revving, start analyzing the source files
    //lexer.lex();

    //// After lexing, print all lexed tokens
    //lexer.printTokens();

    return EXIT_SUCCESS;
}