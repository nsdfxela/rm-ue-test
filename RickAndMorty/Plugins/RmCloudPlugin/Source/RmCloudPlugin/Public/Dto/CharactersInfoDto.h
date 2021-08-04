#pragma once
#include "CoreMinimal.h"
#include "Utils/JsonUtils.h"
#include "CharactersInfoDto.generated.h"


USTRUCT(BlueprintType)
struct FCharactersInfoDto
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    int Count;
    
};

namespace JsonUtils
{
    bool ParseDto(const FString& Json, FCharactersInfoDto& Result);
}
