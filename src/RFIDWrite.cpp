#include "RFIDWrite.h"

#include <Arduino.h>
#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>

extern MFRC522 mfrc522;

bool write(byte block, byte *buffer, byte size)
{
    MFRC522::StatusCode status = mfrc522.MIFARE_Write(block, buffer, size);

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