#pragma once
#include "CoreMinimal.h"
#include "ApiDto.generated.h"


USTRUCT(BlueprintType)
struct FApiDto
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    FString CharactersUrl;
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    FString LocationsUrl;
    UPROPERTY(BlueprintReadWrite, Category = "Default")
    FString EpisodesUrl;
};
