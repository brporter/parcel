#include "block.h"

using namespace parcel;

Block::Block(BlockType type, std::uint32_t length, std::unique_ptr<std::uint8_t> blockBody) //, std::uint32_t blockBody[])
    : _blockType(type), _blockLength(length), _blockBody(std::move(blockBody))
{ }

Block::Block(const Block&) {}

Block::Block(Block&&) {}

Block::~Block() {}

Block& Block::operator=(const Block&) noexcept {}
Block& Block::operator=(Block&&) noexcept {}

enum BlockType Block::type() const { return _blockType; }

std::uint32_t Block::length() const { return _blockLength; }

const std::uint8_t* Block::body() const { return _blockBody.get(); }

