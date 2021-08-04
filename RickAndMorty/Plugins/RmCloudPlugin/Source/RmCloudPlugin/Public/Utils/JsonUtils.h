#pragma once
#include "CoreMinimal.h"

namespace JsonUtils
{
    bool ParseStringParamFromJsonString(const FString& JsonString, const FString& Key, FString& Result);
    //int32 ParseIntParamFromJsonString(FString JsonString, FString Key);
}