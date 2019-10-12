#ifndef PCAP_HPP
#define PCAP_HPP

#include <string>
#include <vector>
#include "block.hpp"

namespace parcel {
class PCap {
public:
    PCap() = delete;            // default
    PCap(const std::wstring&);  // standard
    PCap(const PCap&);          // copy
    PCap(PCap&&);               // move

    PCap& operator=(const PCap&);  // copy assignment
    PCap& operator=(PCap&&);       // move assignment

private:
    uint16_t readChunk16(std::basic_ifstream<uint8_t>&);
    uint32_t readChunk32(std::basic_ifstream<uint8_t>&);

    std::vector<Block> _blocks;
};

}  // namespace parcel
#endif
