#include <iostream>
#include <iomanip>

int main() {
    char inputChar;

    std::cout << "Enter a character: ";
    std::cin >> inputChar;

    int unicodeCode = static_cast<int>(inputChar);

    std::cout << "Unicode code point for '" << inputChar << "' is: U+" << std::hex << std::uppercase << unicodeCode << std::endl;

    return 0;
}
