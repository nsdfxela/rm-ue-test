#include "RmRequestBlueprintNodes.h"
#include "RmRestLibrary.h"

UAsyncGetApiInfo* UAsyncGetApiInfo::AsyncGetApiInfo(UObject* WorldContextObject)
{
    UAsyncGetApiInfo* Action = NewObject<UAsyncGetApiInfo>();
   
    return Action;
}

void UAsyncGetApiInfo::OnComplete(FApiDto Dto, int32 Code)
{
    Completed.Broadcast(Dto, Code);
    SetReadyToDestroy();
}

void UAsyncGetApiInfo::Activate()
{
    URmRestLibrary::GetApiInfo(FApiRequestCompleteDelegate::CreateUObject(this, &UAsyncGetApiInfo::OnComplete));
}

UAsyncGetAllCharactersInfo* UAsyncGetAllCharactersInfo::AsyncGetAllCharactersInfo(UObject* WorldContextObject, const FString& CharacterApiUrl)
{
    UAsyncGetAllCharactersInfo* Action = NewObject<UAsyncGetAllCharactersInfo>();
    Action->CharacterApiUrl = CharacterApiUrl;
    return Action;
}

void UAsyncGetAllCharactersInfo::OnComplete(FCharactersInfoDto Dto, int32 Code)
{
    Completed.Broadcast(Dto, Code);
    SetReadyToDestroy();
}

void UAsyncGetAllCharactersInfo::Activate()
{
    URmRestLibrary::GetAllCharactersInfo(CharacterApiUrl, FAllCharactersRequestCompleteDelegate::CreateUObject(this, &UAsyncGetAllCharactersInfo::OnComplete));
}

void UAsyncGetCharacterInfo::OnComplete(FCharacterDto Dto, int32 Code)
{
    Completed.Broadcast(Dto, Code);
    SetReadyToDestroy();
}

void UAsyncGetCharacterInfo::Activate()
{
    URmRestLibrary::GetCharacterInfo(CharacterApiUrl, CharacterId, FCharacterRequestCompleteDelegate::CreateUObject(this, &UAsyncGetCharacterInfo::OnComplete));
}

UAsyncGetCharacterInfo* UAsyncGetCharacterInfo::AsyncGetCharacterInfo(UObject* WorldContextObject,
    const FString& CharacterApiUrl, int CharacterId)
{
    UAsyncGetCharacterInfo* Action = NewObject<UAsyncGetCharacterInfo>();
    Action->CharacterApiUrl = CharacterApiUrl;
    Action->CharacterId = CharacterId;
    return Action;
}