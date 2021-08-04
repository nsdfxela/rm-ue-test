#include "RmRequestBlueprintNodes.h"
#include "RmRestLibrary.h"

UAsyncGetApiInfo* UAsyncGetApiInfo::AsyncGetApiInfo(UObject* WorldContextObject)
{
    UAsyncGetApiInfo* Action = NewObject<UAsyncGetApiInfo>();
   
    return Action;
}

void UAsyncGetApiInfo::OnComplete(FApiDto Dto, int32 Code)
{

}

void UAsyncGetApiInfo::Activate()
{
    URmRestLibrary::GetApiInfo(FApiRequestCompleteDelegate::CreateUObject(this, &UAsyncGetApiInfo::OnComplete));
}
