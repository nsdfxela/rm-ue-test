#include "Dto/CharactersInfoDto.h"

bool JsonUtils::ParseDto(const FString& Json, FCharactersInfoDto& Result)
{
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Json);
    if (FJsonSerializer::Deserialize(Reader, JsonObject))
    {
        auto info = JsonObject->GetObjectField("info");
        auto count = info->GetIntegerField("count");
        Result.Count = count;
        return true;
    }

    return false;
}

