#include "pcap.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <errno.h>

using namespace parcel;

PCap::PCap(std::unique_ptr<std::ifstream>&& file)
    : _ifs(std::move(file))
{ }

PCap::PCap(PCap&& other)
{
    _ifs = std::move(other._ifs);
}

PCap& PCap::operator=(const PCap& other)
{
    // copy assignment
    _blocks = other._blocks;

    return *this;
}

PCap& PCap::operator=(PCap&& other)
{
    // move assignment
    if (this != &other) {
        _blocks = other._blocks;  // TODO: this is copying not moving
    }

    return *this;
}

std::unique_ptr<Block> PCap::block() noexcept
{
    std::unique_ptr<parcel::Block> retVal;

    if (_ifs && _ifs->is_open())
    {
        auto blockType = static_cast<parcel::BlockType>(readChunk32(*_ifs));
        auto blockLength = readChunk32(*_ifs);
        auto blockBody = readBlock(*_ifs, blockLength - 8);

        retVal = std::make_unique<Block>(
                blockType, 
                blockLength, 
                std::unique_ptr<uint8_t>(blockBody)
        );

        _ifs->seekg(blockLength - 8, std::ios_base::cur);
    }

    return retVal;
}

/* private methods */
std::uint8_t* PCap::readBlock(std::ifstream& ifs, std::int32_t length)
{
    std::uint8_t* block = new std::uint8_t[length];

    ifs.read(reinterpret_cast<char*>(block), length);

    return block;
}

std::uint16_t PCap::readChunk16(std::ifstream& ifs)
{
    std::uint16_t value;
    ifs.read(reinterpret_cast<char*>(&value), 2);

    return value;
}

std::uint32_t PCap::readChunk32(std::ifstream& ifs)
{
    std::uint32_t value;

    ifs.read(reinterpret_cast<char*>(&value), 4);

    return value;
}

