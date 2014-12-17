// (c) Seth Heeren 2013
//
// Based on src/opus_demo.c in opus-1.0.2
// License see http://www.opus-codec.org/license/
#include <stdexcept>
#include <memory>
#include <iosfwd>

struct OpusErrorException : public virtual std::exception
{
    OpusErrorException(int code) : code(code) {}
    const char* what() const noexcept;
private:
    const int code;
};

struct COpusCodec
{
    COpusCodec(int32_t sampling_rate, int channels);
    ~COpusCodec();

    bool decode_frame(std::istream& fin, std::ostream& fout);
private:
    struct Impl;
    std::unique_ptr<Impl> _pimpl;
};
