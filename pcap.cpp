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
    _captureHardware = other._captureHardware;
    _captureApp = other._captureApp;
    _captureOs = other._captureOs;

    _majorVersion = other._majorVersion;
    _minorVersion = other._minorVersion;
}

PCap::PCap(PCap&& other)
{
    // move 
    _captureHardware = other._captureHardware;
    _captureApp = other._captureApp;
    _captureOs = other._captureOs;

    _majorVersion = other._majorVersion;
    _minorVersion = other._minorVersion;

    other._captureHardware.clear();
    other._captureApp.clear();
    other._captureOs.clear();
    other._minorVersion = 0;
    other._majorVersion = 0;
}

PCap& PCap::operator=(const PCap& other)
{
    // copy assignment
    _captureHardware = other._captureHardware;
    _captureApp = other._captureApp;
    _captureOs = other._captureOs;

    _majorVersion = other._majorVersion;
    _minorVersion = other._minorVersion;

    return *this;
}

PCap& PCap::operator=(PCap&& other)
{
    // move assignment
    if (this != &other)
    {
        _captureHardware = other._captureHardware;
        _captureApp = other._captureApp;
        _captureOs = other._captureOs;

        _majorVersion = other._majorVersion;
        _minorVersion = other._minorVersion;
    
        other._captureHardware.clear();
        other._captureApp.clear();
        other._captureOs.clear();
        other._minorVersion = 0;
        other._majorVersion = 0;
    }

    return *this;
}
           
std::wstring PCap::captureHardware()
{
}

std::wstring PCap::captureOs()
{
}

std::wstring PCap::captureApp()
{
}

uint16_t PCap::majorVersion()
{
}

uint16_t PCap::minorVersion()
{
}
