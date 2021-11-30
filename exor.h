#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>

#include "nand.h"

// TODO: Insert your code here
SC_MODULE(exor){
  public:
    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool> Z;

    SC_CTOR(exor) : A("A"), B("B"), Z("Z") {
        //portmap nand gates into an XOR gate
        setup();
    }


  private:
    sc_signal<bool> h1;
    sc_signal<bool> h2;
    sc_signal<bool> h3;
    nand a{"a"}; 
    nand b{"b"}; 
    nand c{"c"}; 
    nand d{"d"}; 

    void setup(){
        // Bind first NAND
        a.A.bind(A);
        a.B.bind(B);
        a.Z.bind(h1);

        // Bind second NAND
        b.A.bind(A);
        b.B.bind(h1);
        b.Z.bind(h2);

        // Bind third NAND
        c.A.bind(h1);
        c.B.bind(B);
        c.Z.bind(h3);

        // Bind forth NAND
        d.A.bind(h2);
        d.B.bind(h3);
        d.Z.bind(Z);

    }
};
#endif // EXOR_H
