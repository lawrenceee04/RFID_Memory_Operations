#include "RFIDAuthenticate.h"

#include <Arduino.h>
#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>

extern MFRC522 mfrc522;

bool authenticate(bool authenticateKeyAOrKeyB, byte *key, byte sectorTrailer)
{
    MFRC522::MIFARE_Key authKey;
    MFRC522Constants::PICC_Command authenticate;

    if (authenticateKeyAOrKeyB == 0)
    {
        memcpy(authKey.keyByte, key, sizeof(authKey.keyByte));
        authenticate = MFRC522Constants::PICC_CMD_MF_AUTH_KEY_A;
    }
    else
    {
        memcpy(authKey.keyByte, key, sizeof(authKey.keyByte));
        authenticate = MFRC522Constants::PICC_CMD_MF_AUTH_KEY_B;
    }

    MFRC522::StatusCode status = mfrc522.PCD_Authenticate(authenticate, sectorTrailer, &authKey, &(mfrc522.uid));

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