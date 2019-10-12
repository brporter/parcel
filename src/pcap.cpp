#include "pcap.hpp"
#include <fstream>

using namespace parcel;

PCap::PCap(const std::wstring& file)
{
    // standard
}

PCap::PCap(const PCap& other)
{
    // copy
    _blocks = other._blocks;
}

PCap::PCap(PCap&& other)
{
    // move
    // TODO: this is actually doing a copy
    _blocks = other._blocks;
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

uint16_t PCap::readChunk16(std::basic_ifstream<uint8_t>& ifs)
{
    std::uint32_t value;
    ifs.read(reinterpret_cast<uint8_t*>(&value), 2);

    return value;
}

uint32_t PCap::readChunk32(std::basic_ifstream<uint8_t>& ifs)
{
    std::uint32_t value;
    ifs.read(reinterpret_cast<uint8_t*>(&value), 4);

    return value;
}

