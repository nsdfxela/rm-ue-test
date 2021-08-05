#pragma once

#include "CoreMinimal.h"
#include "Http.h"
#include "Dto/ApiDto.h"
#include "Dto/CharactersInfoDto.h"
#include "Dto/CharacterDto.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RmRestLibrary.generated.h"

DECLARE_DELEGATE_TwoParams(FApiRequestCompleteDelegate, FApiDto, int32);
DECLARE_DELEGATE_TwoParams(FAllCharactersRequestCompleteDelegate, FCharactersInfoDto, int32);
DECLARE_DELEGATE_TwoParams(FCharacterRequestCompleteDelegate, FCharacterDto, int32);

UCLASS()
class URmRestLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    static const FString ROOT_API;
    static void GetApiInfo(FApiRequestCompleteDelegate OnComplete);
    static void GetAllCharactersInfo(const FString& CharacterApiUrl, FAllCharactersRequestCompleteDelegate OnComplete);
    static void GetCharacterInfo(const FString& CharacterApiUrl, int CharacterId, FCharacterRequestCompleteDelegate OnComplete);
};