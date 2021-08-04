#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Engine/EngineTypes.h"
#include "Dto/ApiDto.h"
#include "Dto/CharacterDto.h"
#include "Dto/CharactersInfoDto.h"
#include "RmRequestBlueprintNodes.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAsyncApiRequestCompleteDelegate, const FApiDto&, Api, int32, Code);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAsyncAllCharactersRequestCompleteDelegate, const FCharactersInfoDto&, Api, int32, Code);


UCLASS()
class UAsyncGetApiInfo : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "RickAndMorty|Cloud")
    static UAsyncGetApiInfo* AsyncGetApiInfo(UObject* WorldContextObject);
    virtual void Activate() override;
    UPROPERTY(BlueprintAssignable)
    FAsyncApiRequestCompleteDelegate Completed;
protected:
    void OnComplete(FApiDto Dto, int32 Code);
};

UCLASS()
class UAsyncGetAllCharactersInfo : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "RickAndMorty|Cloud")
    static UAsyncGetAllCharactersInfo* AsyncGetAllCharactersInfo(UObject* WorldContextObject, const FString& CharacterApiUrl);
    virtual void Activate() override;
    UPROPERTY(BlueprintAssignable)
    FAsyncAllCharactersRequestCompleteDelegate Completed;
protected:
    UPROPERTY()
    FString CharacterApiUrl;
    void OnComplete(FCharactersInfoDto Dto, int32 Code);
};