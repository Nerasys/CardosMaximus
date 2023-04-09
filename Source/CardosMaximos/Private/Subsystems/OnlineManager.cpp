// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OnlineManager.h"
#include "Core/PlayFabClientAPI.h"
#include "PlayFabUtilities.h"

void UOnlineManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	m_clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	UPlayFabUtilities::setPlayFabSettings("916E4", "B91YQQJRZ8JGBY7UTCSZXPY419PQ9Y743A6R96MXB18GJOTE85");
}

void UOnlineManager::Deinitialize()
{
	Super::Deinitialize();
}

void UOnlineManager::OnRegister(FString Email, FString Password, FString UserName)
{
	if(!m_clientAPI)
		return;
	
	PlayFab::ClientModels::FRegisterPlayFabUserRequest request;
	request.Email = Email;
	request.Password = Password;
	request.Username = UserName;

	m_clientAPI->RegisterPlayFabUser(request, PlayFab::UPlayFabClientAPI::FRegisterPlayFabUserDelegate::CreateLambda([](const PlayFab::ClientModels::FRegisterPlayFabUserResult& result)
		{
			UE_LOG(LogTemp, Warning, TEXT("ONLINE MANAGER : ONREGISTER : %s"), *result.Username);
		}),
		PlayFab::FPlayFabErrorDelegate::CreateLambda([](const PlayFab::FPlayFabCppError& error)
		{
			UE_LOG(LogTemp, Warning, TEXT("ONLINE MANAGER : ONREGISTER ERROR"));
		}));
}


