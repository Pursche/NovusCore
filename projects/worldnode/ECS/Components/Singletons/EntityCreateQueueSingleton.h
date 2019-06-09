/*
    MIT License

    Copyright (c) 2018-2019 NovusCore

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/
#pragma once
#include <NovusTypes.h>
#include <Utils/ConcurrentQueue.h>
#include "../../NovusEnums.h"
#include "../../Message.h"
#include "../../Game/ObjectGuid/ObjectGuid.h"

struct EntityCreationInformation
{
    u32 lowGuid = 0;
    u32 entryId = 0;
};

struct ItemCreationInformation : EntityCreationInformation
{
    static ItemCreationInformation* Create(u32 inLowGuid, u32 inEntryId, u8 inBagSlot, u32 inBagPosition, u32 inCharacterEntityId, ObjectGuid inCharacterGuid)
    {
        ItemCreationInformation* information = new ItemCreationInformation();

        information->lowGuid = inLowGuid;
        information->entryId = inEntryId;
        information->bagSlot = inBagSlot;
        information->bagPosition = inBagPosition;
        information->characterEntityId = inCharacterEntityId;
        information->characterGuid = inCharacterGuid;

        return information;
    }

    u8 bagSlot = 0;
    u32 bagPosition = 0;
    u32 characterEntityId = 0;
    ObjectGuid characterGuid;
};

struct EntityCreationRequest
{
    EntityTypeID typeId;
    EntityCreationInformation* typeInformation;
};
struct EntityCreateQueueSingleton
{
    moodycamel::ConcurrentQueue<EntityCreationRequest>* newEntityQueue;
};
