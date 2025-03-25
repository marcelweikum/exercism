#include "secret_handshake.h"

#include <algorithm>

namespace secret_handshake
{

    std::vector<std::string> commands(int n)
    {
        std::vector<std::string> code{};
        // std::string result = std::bitset<5>(n).to_string();

        // if (result[4] == '1')
        //     code.push_back("wink");
        // if (result[3] == '1')
        //     code.push_back("double blink");
        // if (result[2] == '1')
        //     code.push_back("close your eyes");
        // if (result[1] == '1')
        //     code.push_back("jump");
        // if (result[0] == '1')
        //     std::reverse(code.begin(), code.end());

        if (n & 0b00001)
            code.push_back("wink");
        if (n & 0b00010)
            code.push_back("double blink");
        if (n & 0b00100)
            code.push_back("close your eyes");
        if (n & 0b01000)
            code.push_back("jump");
        if (n & 0b10000)
            std::reverse(code.begin(), code.end());

        return code;
    }

} // namespace secret_handshake
