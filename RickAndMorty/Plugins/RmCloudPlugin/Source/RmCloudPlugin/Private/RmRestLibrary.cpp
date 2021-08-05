#include "RmRestLibrary.h"
#include "HttpModule.h"
#include "Utils/JsonUtils.h"

const FString URmRestLibrary::ROOT_API = FString::Printf(TEXT("https://rickandmortyapi.com/api"));

TSharedRef<IHttpRequest> GetApiRequest(const FString& URLString)
{
    FHttpModule* Http = &FHttpModule::Get();
    auto Request = Http->CreateRequest();
    Request->SetVerb(FString("GET"));
    Request->SetURL(URLString);
    return Request;
}

void URmRestLibrary::GetApiInfo(FApiRequestCompleteDelegate OnComplete)
{   
    auto Request = GetApiRequest(ROOT_API);
    Request->OnProcessRequestComplete().BindLambda([OnComplete](FHttpRequestPtr HttpRequest, FHttpResponsePtr Response, bool bWasSuccessful)
        {
            FString Content = Response->GetContentAsString();
            FApiDto Result;
            JsonUtils::ParseStringParamFromJsonString(Content, FString("characters"), Result.CharactersUrl);
            JsonUtils::ParseStringParamFromJsonString(Content, FString("locations"), Result.LocationsUrl);
            JsonUtils::ParseStringParamFromJsonString(Content, FString("episodes"), Result.EpisodesUrl);
            OnComplete.ExecuteIfBound(Result, 0);
        });
    Request->ProcessRequest();
}

void URmRestLibrary::GetAllCharactersInfo(const FString& CharacterApiUrl , FAllCharactersRequestCompleteDelegate OnComplete)
{   
    auto Request = GetApiRequest(CharacterApiUrl);
    Request->OnProcessRequestComplete().BindLambda([OnComplete](FHttpRequestPtr HttpRequest, FHttpResponsePtr Response, bool bWasSuccessful)
        {
            FString Content = Response->GetContentAsString();
            FCharactersInfoDto Result;
            JsonUtils::ParseDto(Content, Result);
            OnComplete.ExecuteIfBound(Result, 0);
        });
    Request->ProcessRequest();
}

void URmRestLibrary::GetFile(const FString& FileUrl, FFileRequestCompleteDelegate OnComplete)
{
    auto Request = GetApiRequest(FileUrl);
    Request->OnProcessRequestComplete().BindLambda([OnComplete](FHttpRequestPtr HttpRequest, FHttpResponsePtr Response, bool bWasSuccessful)
        {
            OnComplete.ExecuteIfBound(Response->GetContent(), 0);
        });
    Request->ProcessRequest();
}

void URmRestLibrary::GetCharacterInfo(const FString& CharacterApiUrl, int CharacterId,
    FCharacterRequestCompleteDelegate OnComplete)
{
    FString Url = FString::Printf(TEXT("%s/%d"), *CharacterApiUrl, CharacterId);
    auto Request = GetApiRequest(Url);
    Request->OnProcessRequestComplete().BindLambda([OnComplete](FHttpRequestPtr HttpRequest, FHttpResponsePtr Response, bool bWasSuccessful)
        {
            FString Content = Response->GetContentAsString();
            FCharacterDto Result;
            JsonUtils::ParseDto(Content, Result);
            OnComplete.ExecuteIfBound(Result, 0);
        });
    Request->ProcessRequest();

}
