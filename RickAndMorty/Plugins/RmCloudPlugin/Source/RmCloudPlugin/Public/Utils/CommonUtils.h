#pragma once

#include "CoreMinimal.h"
#include "Dto/CharacterDto.h"
#include "CommonUtils.generated.h"


UCLASS()
class UCommonUtils : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "RickAndMorty|Utils")
    static FString CharacterToString(const FCharacterDto& CharacterDto);
};
