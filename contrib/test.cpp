// (c) Seth Heeren 2013
//
// Based on src/opus_demo.c in opus-1.0.2
// License see http://www.opus-codec.org/license/
#include <fstream>
#include <iostream>

#include "COpusCodec.hpp"

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <input> <output>\n";
        return 255;
    }
    std::basic_ifstream<unsigned char> fin(argv[1], std::ios::binary);
    if(!fin)
    {
        throw std::runtime_error("Could not open input file");
    }
    std::basic_ofstream<unsigned char> fout(argv[2], std::ios::binary);
    if(!fout)
    {
        throw std::runtime_error("Could not open output file");
    }
    try
    {
        COpusCodec codec;
        while(codec.decode(fin, fout))
        {
            ;
        }
    }
    catch(OpusErrorException const& e)
    {
        std::cerr << "OpusErrorException: " << e.what() << "\n";
        return 255;
    }
}
