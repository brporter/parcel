#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <cstdint>
#include <memory>

namespace parcel {
enum class BlockType {
    Reserved = 0x00000000,
    InterfaceDescription = 0x00000001,
    Packet = 0x00000002,
    SimplePacket = 0x00000003,
    NameResolution = 0x00000004,
    InterfaceStatistics = 0x00000005,
    EnhancedPacket = 0x00000006,
    IRIGTimestamp = 0x00000007,
    ARINC429 = 0x00000008,
    Custom = 0x00000BAD,
    CustomDoNotCopy = 0x40000BAD,
    SectionHeader = 0x0A0D0D0A
};

class Block {
public:
    Block() = delete;
    Block(const Block&);  // copy
    Block(Block&&);       // move
    ~Block();

    Block& operator=(const Block&) noexcept;  // copy assignment
    Block& operator=(Block&&) noexcept;       // move assignment

    enum BlockType type() const;
    std::uint32_t length() const;
    std::shared_ptr<std::uint8_t> body() const;

private:
    enum BlockType _blockType;
    std::uint32_t _blockLength;
    std::uint8_t _blockBody[];
};
}  // namespace parcel

#endif
