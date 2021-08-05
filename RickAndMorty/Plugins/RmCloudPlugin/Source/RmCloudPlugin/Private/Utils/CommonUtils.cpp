#include "Utils/CommonUtils.h"

FString UCommonUtils::CharacterToString(const FCharacterDto& CharacterDto)
{
    FString result;
    result.Append(FString::Printf(TEXT("Id: %d \n"), CharacterDto.Id));
    result.Append(FString::Printf(TEXT("Name: %s \n"), *CharacterDto.Name));
    result.Append(FString::Printf(TEXT("Gender: %s \n"), *CharacterDto.Gender));
    result.Append(FString::Printf(TEXT("Status: %s \n"), *CharacterDto.Status));
    result.Append(FString::Printf(TEXT("Url: %s \n"), *CharacterDto.Url));
    result.Append(FString::Printf(TEXT("Type: %s \n"), *CharacterDto.Type));
    result.Append(FString::Printf(TEXT("Species: %s \n"), *CharacterDto.Species));
    result.Append(FString::Printf(TEXT("Location: %s \n"), *CharacterDto.Location));
    result.Append(FString::Printf(TEXT("Origin: %s \n"), *CharacterDto.Origin));
    return result;
}