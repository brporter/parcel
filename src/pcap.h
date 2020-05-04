#ifndef PCAP_H
#define PCAP_H

#include <string>
#include <vector>
#include <fstream>
#include "block.h"

namespace parcel {
class PCap {
public:
    PCap() = delete;            // default
    PCap(const char*);  // standard
    PCap(const PCap&);          // copy
    PCap(PCap&&);               // move

    PCap& operator=(const PCap&);  // copy assignment
    PCap& operator=(PCap&&);       // move assignment

    // Parse the next block
    std::unique_ptr<Block> block() noexcept;

private:
    std::uint16_t readChunk16(std::basic_ifstream<std::uint8_t>&);
    std::uint32_t readChunk32(std::basic_ifstream<std::uint8_t>&);
    std::uint8_t* readBlock(std::basic_ifstream<std::uint8_t>&, std::int32_t);

    std::basic_ifstream<std::uint8_t> _ifs;

    std::vector<Block> _blocks;
};

}  // namespace parcel
#endif
