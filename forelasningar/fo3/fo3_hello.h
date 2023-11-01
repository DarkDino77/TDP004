#ifndef FO3_HELLO_H // Förhindrar fler inkluderingar av samma fil
#define FO3_HELLO_H

void hello();

#endif

// kompilera .cc filer, inkludera .h filer

/*

main.cc     hello.cc
   |           |
   v           v
 main.o      hello.o
    \         /
     \       /
       a.out

*/
