#ifndef PCAP_H
#define PCAP_H

#include <string>
#include <vector>
#include <fstream>
#include "block.h"

namespace parcel {
class PCap {
public:
    PCap() = delete;                // default
    PCap(const PCap&) = delete;     // copy

    PCap(std::unique_ptr<std::ifstream> &&); // standard
    PCap(PCap&&);               // move

    PCap& operator=(const PCap&);  // copy assignment
    PCap& operator=(PCap&&);       // move assignment

    // Parse the next block
    std::unique_ptr<Block> block() noexcept;

private:
    std::uint16_t readChunk16(std::ifstream&);
    std::uint32_t readChunk32(std::ifstream&);
    std::uint8_t* readBlock(std::ifstream&, std::int32_t);

    std::unique_ptr<std::ifstream> _ifs;

    std::vector<Block> _blocks;
};

}  // namespace parcel
#endif
