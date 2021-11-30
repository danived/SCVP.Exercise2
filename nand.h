#ifndef NAND_H
#define NAND_H

#include <systemc.h>

SC_MODULE(nand)
{
    public:
    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool> Z;

    SC_CTOR(nand)
    {
        SC_METHOD(process);
        sensitive << A << B;
    }
    private:
    void process()
    {
        Z.write(!(A.read() & B.read()));
    }
};

#endif
