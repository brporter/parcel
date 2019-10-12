#include <fstream>
#include <iostream>

#define BLOCK_TYPE_LENGTH 4
#define BLOCK_LENGTH_LENGTH 4

std::uint32_t read_chunk(std::basic_ifstream<char>& ifs)
{
    std::uint32_t value;
    ifs.read(reinterpret_cast<char*>(&value), 4);

    return value;
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::wcerr << L"Usage: " << argv[0] << " [filename]" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1], std::ifstream::binary);

    while (file) {
        uint32_t blockType = read_chunk(file);
        uint32_t blockLength = read_chunk(file);

        std::wcout << "block type: " << std::hex << blockType << std::endl;
        std::wcout << "block length: " << blockLength << std::endl;

        file.seekg(blockLength - 8, std::ios_base::cur);
    }

    return 0;
}
