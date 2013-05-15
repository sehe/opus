#include <stdexcept>
#include <memory>

struct OpusErrorException : public virtual std::exception
{
    OpusErrorException(int code) : code(code) {}
    const char* what() const noexcept;
private:
    const int code;
};

struct COpusCodec
{
    COpusCodec(int32_t sampling_rate = 48000, int channels = 1);

    bool decode(std::basic_ifstream<unsigned char>& fin,
                std::basic_ofstream<unsigned char>& fout);
private:
    struct Impl;
    std::shared_ptr<Impl> _pimpl;
};
