
/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Jose Fernando Lopez Fernandez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
 * to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef CDCC_LEX_HXX
#define CDCC_LEX_HXX

#include <cstdio>
#include <cstdlib>
#include <cctype>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#ifndef CDCC_TOKEN_HXX
#include <CDCC/Token.hxx>
#endif // CDCC_TOKEN_HXX

/** Overview:
 *
 *  yytext   - points to the current lexeme, which is not NUL-terminated
 *  yyleng   - the number of characters in the lexeme
 *  yylineno - the current input line number
 *  
 */

namespace CDCC
{
class Lexer
{
// TODO: Refactor this to be private
public:
    std::vector<std::string> inputFiles;

    //std::ifstream inputStream;

    std::vector<Token> tokens;

    char *yytext;
    int yyleng;
    int yylineno;

    char *current;
    char inputBuffer[128];

public:
    Lexer();

    Lexer(char *ptr, int len, int num);

    template <typename CharT, typename Traits = std::char_traits<CharT>>
    void setInputStream(const std::basic_streambuf<CharT, Traits>& streamBuffer);

    void lexFile(const std::filebuf& inputFileBuffer);

    void lex();

    std::vector<Token> tokensVector() const noexcept;

    void printTokens() const noexcept;
};

} // End namespace CDCC

#endif CDCC_LEX_HXX
