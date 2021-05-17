#ifndef ASCIIHEX_H
#define ASCIIHEX_H

class AsciiHex
{
    public:
        // Hexadecimal to ASCII conversion
        void hex2ascii(char * hex, char * ascii);
        // ASCII to Hexadecimal conversion
        void ascii2hex(char * ascii, char * hex);
};

#endif