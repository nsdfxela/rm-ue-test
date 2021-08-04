#include "Dto/CharacterDto.h"

bool JsonUtils::ParseDto(const FString& Json, FCharacterDto& Result)
{
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Json);
    if (FJsonSerializer::Deserialize(Reader, JsonObject))
    {
        Result.Name = JsonObject->GetStringField("name");
        Result.Status = JsonObject->GetStringField("status");
        Result.Species = JsonObject->GetStringField("species");
        Result.Type = JsonObject->GetStringField("type");
        Result.Gender = JsonObject->GetStringField("gender");
        Result.Id = JsonObject->GetIntegerField("id");
        Result.Image = JsonObject->GetStringField("image");
        Result.Url = JsonObject->GetStringField("url");


        return true;
    }

    return false;
    return false;
}