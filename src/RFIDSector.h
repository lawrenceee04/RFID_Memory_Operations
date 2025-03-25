#ifndef RFIDSector_H
#define RFIDSector_H

#include <Arduino.h>

struct sector
{
    byte sectorNumber;
    byte firstBlock;
    byte secondBlock;
    byte thirdBlock;
    byte trailerBlockAddress;

    sector(byte sectorNumber);
};

#endif