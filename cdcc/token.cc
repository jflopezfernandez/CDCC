
#include <CDCC/Token.hxx>

namespace CDCC
{
constexpr int TokenTypeToInt(const TokenType& tokenType) noexcept
{
    const auto value = [=](const TokenType& type) {
        return static_cast<int>(type);
    }(tokenType);

    return value;
}

Token::Token()
    : type(TokenType::null)
{
    // Default constructor
}

Token::Token(const TokenType& tokenType)
    : type(tokenType)
{
    // Custom constructor
}

std::string Token::toString() const noexcept
{
    const std::string stringifyToken = [=](const TokenType& tokenType) {
        if (tokenType == TokenType::EndOfInput)
        {
            return "END_OF_INPUT";
        }
        else if (tokenType == TokenType::Semicolon)
        {
            return "SEMICOLON";
        }
        else if (tokenType == TokenType::OperatorPlus)
        {
            return "OPERATOR_PLUS";
        }
        else if (tokenType == TokenType::OperatorTimes)
        {
            return "OPERATOR_TIMES";
        }
        else if (tokenType == TokenType::LeftParens)
        {
            return "LEFT_PARENS";
        }
        else if (tokenType == TokenType::RightParens)
        {
            return "RIGHT_PARENS";
        }
        else if (tokenType == TokenType::NumOrID)
        {
            return "NUM_OR_ID";
        }
        else if (tokenType == TokenType::null)
        {
            return "NUL";
        }
        else
        {
            return "UNKNOWN_TOKEN";
        }
    }(type);

    return stringifyToken;
}

} // End namespace CDCC
