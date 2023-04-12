// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OnlineManager.h"
#include "Core/PlayFabClientAPI.h"
#include "PlayFabUtilities.h"

void UOnlineManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// PlayFab init
	m_clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	UPlayFabUtilities::setPlayFabSettings("916E4", "B91YQQJRZ8JGBY7UTCSZXPY419PQ9Y743A6R96MXB18GJOTE85");
}

void UOnlineManager::Deinitialize()
{
	Super::Deinitialize();
}

void UOnlineManager::RegisterNewUser(FRegisterCallback RegisterCallback, FString Email, FString Password, FString UserName)
{
	if(!m_clientAPI)
		return;
	
	PlayFab::ClientModels::FRegisterPlayFabUserRequest request;
	request.Email = Email;
	request.Password = Password;
	request.Username = UserName;

	m_clientAPI->RegisterPlayFabUser(request,
PlayFab::UPlayFabClientAPI::FRegisterPlayFabUserDelegate::CreateLambda([RegisterCallback](const PlayFab::ClientModels::FRegisterPlayFabUserResult& result)
		{
			if(RegisterCallback.IsBound())
            		RegisterCallback.Execute(true, "User Registration Succeeded");
		}),
			PlayFab::FPlayFabErrorDelegate::CreateLambda([RegisterCallback](const PlayFab::FPlayFabCppError& error)
		{
			if(RegisterCallback.IsBound())
				RegisterCallback.Execute(false, error.ErrorMessage);
		}));
}

void UOnlineManager::SignInUser(FLoginCallback LoginCallback, FString Email, FString Password)
{
	PlayFab::ClientModels::FLoginWithEmailAddressRequest Request;
	Request.Email = Email;
	Request.Password = Password;

	m_clientAPI->LoginWithEmailAddress(Request,
	PlayFab::UPlayFabClientAPI::FLoginWithEmailAddressDelegate::CreateLambda([LoginCallback](const PlayFab::ClientModels::FLoginResult& result)
		{
			if(LoginCallback.IsBound())
				LoginCallback.Execute(true, "Login Succeded");
		}), PlayFab::FPlayFabErrorDelegate::CreateLambda([LoginCallback](const PlayFab::FPlayFabCppError& error)
		{
			if(LoginCallback.IsBound())
				LoginCallback.Execute(false, error.ErrorMessage);
		}));
}


