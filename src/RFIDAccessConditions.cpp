#include "RFIDAccessConditions.h"
#include <Arduino.h>

// Access conditions for the RFID tags

// Data block 0
// bool C0[3] = {0, 0, 0};

// Data block 1
// bool C1[3] = {0, 0, 0};

// Data block 2
// bool C2[3] = {0, 0, 0};

// Sector Trailer
// bool C3[3] = {0, 0, 1};

byte combineToByte(bool boolArray[8])
{
    byte byteValue = 0;
    for (size_t i = 0; i < 8; ++i)
    {
        byteValue |= (boolArray[i] ? 1 : 0) << (7 - i);
    }
    return byteValue;
}

byte inverseCombineToByte(bool boolArray[8])
{
    byte byteValue = 0;
    for (size_t i = 0; i < 8; ++i)
    {
        byteValue |= (boolArray[i] ? 0 : 1) << (7 - i); // Modified to use (7-i) for MSB at index 0
    }
    return byteValue;
}

byte inverseHalfCombineToByte(bool boolArray[8])
{
    byte byteValue = 0;
    for (size_t i = 0; i < 4; ++i)
    {
        byteValue |= (boolArray[i] ? 1 : 0) << (7 - i); // Keep first 4 bits unchanged (MSB)
    }
    for (size_t i = 4; i < 8; ++i)
    {
        byteValue |= (boolArray[i] ? 0 : 1) << (7 - i); // Invert last 4 bits (LSB)
    }
    return byteValue;
}

accessBits calculateAccessBits(accessConditions ac)
{
    accessBits ab;

    bool byte6[8] = {ac.C3[1], ac.C2[1], ac.C1[1], ac.C0[1], ac.C3[0], ac.C2[0], ac.C1[0], ac.C0[0]};
    bool byte7[8] = {ac.C3[0], ac.C2[0], ac.C1[0], ac.C0[0], ac.C3[2], ac.C2[2], ac.C1[2], ac.C0[2]};
    bool byte8[8] = {ac.C3[2], ac.C2[2], ac.C1[2], ac.C0[2], ac.C3[1], ac.C2[1], ac.C1[1], ac.C0[1]};

    ab.byte6 = inverseCombineToByte(byte6);
    ab.byte7 = inverseHalfCombineToByte(byte7);
    ab.byte8 = combineToByte(byte8);

    return ab;
}