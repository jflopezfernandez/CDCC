
#include <CDCC/Lex.hxx>

namespace CDCC
{
Lexer::Lexer()
    : yytext(nullptr), yyleng(0), yylineno(0), current(nullptr), inputBuffer { 0 }
{
    // Default constructor
}

Lexer::Lexer(char *ptr, int len, int num)
    : yytext(ptr), yyleng(len), yylineno(num), current(nullptr), inputBuffer { 0 }
{
    // Custom constructor
}

template <typename CharT, typename Traits = std::char_traits<CharT>>
void Lexer::setInputStream(const std::basic_streambuf<CharT, Traits>& streamBuffer)
{
    //inputStream { streamBuffer };
}

void Lexer::lexFile(const std::filebuf& inputFileBuffer)
{
    // TODO: Implement lexFile
}

void Lexer::lex()
{
    // TODO: Fix this bullshit

    /*for (const auto& file : inputFiles)
    {
        std::filebuf inputFile { file, std::ios::in };

        if (!inputFile.is_open())
        {
            std::cerr << "[Error]: Failed to open source file.\n";

            std::exit(EXIT_FAILURE);
        }

        lexFile(inputFile);
    }*/
}

std::vector<Token> Lexer::tokensVector() const noexcept
{
    return std::vector<Token> { tokens };
}

void Lexer::printTokens() const noexcept
{
    for (const auto& token : tokens)
    {
        std::cout << token << "\n";
    }
}

} // End namespace CDCC
