#include "RFIDRead.h"

#include <Arduino.h>

bool read(byte block, byte *buffer, byte size)
{
    MFRC522::StatusCode status = mfrc522.MIFARE_Read(block, buffer, &size);

    switch (status)
    {
    case 0:
        return true;
        break;

    default:
        return false;
        break;
    }
}