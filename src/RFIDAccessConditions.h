#pragma once

#ifndef RFIDAccessConditions_H
#define RFIDAccessConditions_H

#include <Arduino.h>

struct accessConditions
{
    bool C0[3];
    bool C1[3];
    bool C2[3];
    bool C3[3];
};

struct accessBits
{
    byte byte6;
    byte byte7;
    byte byte8;
};

accessBits calculateAccessBits(accessConditions ac);

#endif
