#ifndef ASCIIHEX_H
#define ASCIIHEX_H

class AsciiHex
{
    public:
        // Hexadecimal to ASCII conversion
        void hex2ascii(byte * hex, char * ascii);
        // ASCII to Hexadecimal conversion
        void ascii2hex(char * ascii, byte * hex);
};

#endif