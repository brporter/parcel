#include <fstream>
#include <iostream>
#include <codecvt>
#include <locale>
#include <cstdint>
#include <cstdlib>
#include "pcap.h"

#define BLOCK_TYPE_LENGTH 4
#define BLOCK_LENGTH_LENGTH 4

std::uint32_t read_chunk(std::basic_ifstream<char>& ifs, std::uint32_t chunkLength)
{
    std::uint32_t value;
    ifs.read(reinterpret_cast<char*>(&value), chunkLength);

    return value;
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::wcerr << L"Usage: " << argv[0] << " [filename]" << std::endl;
        return 1;
    }

    // std::wstring_convert< std::codecvt<wchar_t, char, std::mbstate_t> > converter;
    // std::wstring fileName = converter.from_bytes(argv[1]);

    // parcel::PCap p(fileName);
    parcel::PCap p(argv[1]);

    auto b = p.block();

    switch (b->type())
    {
        case parcel::BlockType::SectionHeader:
            std::wcout << "Found a section header!" << std::endl;
            break;
        default:
            std::wcout << "Found some other thing" << std::endl;
            break;
    }

    // std::wcout << "Block Type: " << b->type() << std::endl;

    // std::ifstream file(argv[1], std::ifstream::binary);

    // while (file) {
    //     uint32_t blockType = read_chunk(file, BLOCK_TYPE_LENGTH);
    //     uint32_t blockLength = read_chunk(file, BLOCK_LENGTH_LENGTH);
    //     // uint32_t blockBody = read_chunk(file, blockLength - (BLOCK_TYPE_LENGTH + BLOCK_LENGTH_LENGTH) );

    //     parcel::Block myBlock((parcel::BlockType)blockType, blockLength); // , nullptr);

    //     std::wcout << "block type: " << std::hex << blockType << std::endl;
    //     std::wcout << "block length: " << blockLength << std::endl;

    //     file.seekg(blockLength - 8, std::ios_base::cur);
    // } 

    return 0;
}
