#include "RFIDSector.h"
#include <Arduino.h>

#include "RFIDSector.h"

sector::sector(byte sectorNumber)
{
    this->sectorNumber = sectorNumber;
    this->firstBlock = sectorNumber * 4;
    this->secondBlock = this->firstBlock + 1;
    this->thirdBlock = this->secondBlock + 1;
    this->trailerBlockAddress = this->secondBlock + 1;
}