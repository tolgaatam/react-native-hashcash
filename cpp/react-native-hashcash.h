#ifndef HASHCASH_H
#define HASHCASH_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <random>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <atomic>

// define fixed size integer types
#ifdef _MSC_VER
// Windows
typedef unsigned __int8  uint8_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;
#else
// GCC
#include <stdint.h>
#endif

// big endian architectures need #define __BYTE_ORDER __BIG_ENDIAN
#ifndef _MSC_VER
#if defined(__APPLE__) && defined(__MACH__)
#include <machine/endian.h>
#else
#include <endian.h>
#endif

#endif

std::string gen_random(short len);
std::string into_hex(int num);
int int_log(int num);
void solve_thread(int k, std::string baseString, std::string* result, long iterationPerThreadPerRound, std::atomic<long> * lastCounterEnd);

namespace hashcash {

  /// abstract base class
  class Hash
  {
  public:
    /// compute hash of a memory block
    virtual std::string operator()(const void* data, size_t numBytes) = 0;
    /// compute hash of a string, excluding final zero
    virtual std::string operator()(const std::string& text) = 0;

    /// add arbitrary number of bytes
    virtual void add(const void* data, size_t numBytes) = 0;

    /// return latest hash as hex characters
    virtual std::string getHash() = 0;

    /// restart
    virtual void reset() = 0;
  };

  class SHA256 //: public Hash
  {
  public:
    /// split into 64 byte blocks (=> 512 bits), hash is 32 bytes long
    enum { BlockSize = 512 / 8, HashBytes = 32 };

    /// same as reset()
    SHA256();

    /// compute SHA256 of a memory block
    std::string operator()(const void* data, size_t numBytes);
    /// compute SHA256 of a string, excluding final zero
    std::string operator()(const std::string& text);

    /// add arbitrary number of bytes
    void add(const void* data, size_t numBytes);

    /// return latest hash as 64 hex characters
    std::string getHash();
    /// return latest hash as bytes
    void        getHash(unsigned char buffer[HashBytes]);

    /// restart
    void reset();

  private:
    /// process 64 bytes
    void processBlock(const void* data);
    /// process everything left in the internal buffer
    void processBuffer();

    /// size of processed data in bytes
    uint64_t m_numBytes;
    /// valid bytes in m_buffer
    size_t   m_bufferSize;
    /// bytes not processed yet
    uint8_t  m_buffer[BlockSize];

    enum { HashValues = HashBytes / 4 };
    /// hash, stored as integers
    uint32_t m_hash[HashValues];
  };

  std::string calculateHashcash(int k, std::string identifier);
}

#endif /* HASHCASH_H */
