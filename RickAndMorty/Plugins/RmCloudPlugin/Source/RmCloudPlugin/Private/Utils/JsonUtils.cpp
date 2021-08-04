#include "Utils/JsonUtils.h"

bool JsonUtils::ParseStringParamFromJsonString(const FString& JsonString, const FString& Key, FString& Result)
{
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
    if (FJsonSerializer::Deserialize(Reader, JsonObject))
    {
        auto value = JsonObject->GetStringField(Key);
        std::swap(value, Result);
        return true;
    }

    return false;
};