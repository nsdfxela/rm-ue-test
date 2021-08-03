#pragma once

#include "CoreMinimal.h"
#include "Http.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RmRestLibrary.generated.h"

UCLASS()
class URmRestLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
    const FString ROOT_API = FString::Printf(TEXT("https://rickandmortyapi.com/api"));



};