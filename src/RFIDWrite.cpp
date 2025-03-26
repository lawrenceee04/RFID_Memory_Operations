#include "RFIDWrite.h"

#include <Arduino.h>
#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>

extern MFRC522 mfrc522;

byte *stringToHex(String string)
{
    size_t stringLength = string.length();

    if (stringLength <= 752)
    {
        byte *hexArray = new byte[stringLength];

        for (size_t i = 0; i < stringLength; i++)
        {
            hexArray[i] = static_cast<uint8_t>(string[i]);
        }

        return hexArray;
    }

    return nullptr;
}

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

bool writeToDataBlock(byte block, String data)
{
    // byte size = data.length();

    return write(block, stringToHex(data), 16);
}