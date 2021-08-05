#pragma once
#include "CoreMinimal.h"
#include "Utils/JsonUtils.h"
#include "CharacterDto.generated.h"


USTRUCT(BlueprintType)
struct FCharacterDto
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    int Id;
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    FString Name;
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    FString Status;
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    FString Species;
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    FString Type;
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    FString Gender;
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    FString Image;
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    FString Url;
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    FString Location;
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    FString Origin;
    
};

namespace JsonUtils
{
    bool ParseDto(const FString& Json, FCharacterDto& Result);
}
