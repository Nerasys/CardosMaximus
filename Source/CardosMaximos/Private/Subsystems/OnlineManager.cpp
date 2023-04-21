// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OnlineManager.h"

#include "CircleTypes.h"
#include "Core/PlayFabClientAPI.h"
#include "PlayFabUtilities.h"

void UOnlineManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// PlayFab init
	m_clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	UPlayFabUtilities::setPlayFabSettings("916E4", "B91YQQJRZ8JGBY7UTCSZXPY419PQ9Y743A6R96MXB18GJOTE85");

	m_playerData = NewObject<UPlayerData>();

	Init();
}

void UOnlineManager::Deinitialize()
{
	Super::Deinitialize();
}

void UOnlineManager::RegisterNewUser(FRequestCallback RegisterCallback, FString Email, FString Password, FString UserName)
{
	if(!m_clientAPI)
		return;
	
	PlayFab::ClientModels::FRegisterPlayFabUserRequest Request;
	Request.Email = Email;
	Request.Password = Password;
	Request.Username = UserName;

	m_clientAPI->RegisterPlayFabUser(Request,
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

void UOnlineManager::SetPlayerData(FRequestCallback SetPlayerDataCallback, TMap<FString, FString> Data)
{
	PlayFab::ClientModels::FUpdateUserDataRequest Request;
	Request.Data = Data;
	
	m_clientAPI->UpdateUserData(Request, PlayFab::UPlayFabClientAPI::FUpdateUserDataDelegate::CreateLambda([SetPlayerDataCallback](const PlayFab::ClientModels::FUpdateUserDataResult& result)
	{
		if(SetPlayerDataCallback.IsBound())
			SetPlayerDataCallback.Execute(true, "Set User Data Succeded");
	}),
		PlayFab::FPlayFabErrorDelegate::CreateLambda([SetPlayerDataCallback](const PlayFab::FPlayFabCppError& error)
	{
			if(SetPlayerDataCallback.IsBound())
				SetPlayerDataCallback.Execute(false, error.ErrorMessage);
	}));
}

void UOnlineManager::FetchPlayerData()
{
	if(!m_clientAPI || !IsPlayerLoggedIn())
		return;
	
	PlayFab::ClientModels::FGetUserDataRequest Request;
	Request.PlayFabId = m_playerData->GetPlayFabID();

	m_clientAPI->GetUserData(Request, PlayFab::UPlayFabClientAPI::FGetUserDataDelegate::CreateLambda([this](const PlayFab::ClientModels::FGetUserDataResult Result)
	{
		for(auto Data : Result.Data)
		{
			m_playerData->AddData(Data.Key, Data.Value.Value);
		}

		// Fetch data succeeded 
	}), PlayFab::FPlayFabErrorDelegate::CreateLambda([](const PlayFab::FPlayFabCppError& error)
	{
		
		// Fetch data failed
	}
	));
}

void UOnlineManager::GetPlayerInventory(FRequestCallback GetPlayerInventoryCallback)
{
	if(!m_clientAPI || !IsPlayerLoggedIn())
		return;

	PlayFab::ClientModels::FGetUserInventoryRequest Request;

	m_clientAPI->GetUserInventory(Request, PlayFab::UPlayFabClientAPI::FGetUserInventoryDelegate::CreateLambda([GetPlayerInventoryCallback](const PlayFab::ClientModels::FGetUserInventoryResult& Result)
	{
		FString Ret = "ABCurrency Amount : ";
		for(auto Currency : Result.VirtualCurrency)
		{
			if(Currency.Key == "AB")
				Ret.Append(FString::FromInt(Currency.Value));
		}

		if(GetPlayerInventoryCallback.IsBound())
			GetPlayerInventoryCallback.Execute(true, Ret);
		
	}), PlayFab::FPlayFabErrorDelegate::CreateLambda([GetPlayerInventoryCallback](const PlayFab::FPlayFabCppError& error)
	{
		if(GetPlayerInventoryCallback.IsBound())
			GetPlayerInventoryCallback.Execute(false, error.ErrorMessage);
	}));
}

bool UOnlineManager::IsPlayerLoggedIn()
{
	return m_playerData->IsPlayerLoggedIn();
}

UPlayerData* UOnlineManager::GetPlayerData()
{
	return m_playerData;
}

void UOnlineManager::SignInWithEmail(FRequestCallback LoginCallback, FString Email, FString Password)
{
	if(!m_clientAPI)
		return;
	
	PlayFab::ClientModels::FLoginWithEmailAddressRequest Request;
	Request.Email = Email;
	Request.Password = Password;

	m_clientAPI->LoginWithEmailAddress(Request,
	PlayFab::UPlayFabClientAPI::FLoginWithEmailAddressDelegate::CreateLambda([LoginCallback, this](const PlayFab::ClientModels::FLoginResult& result)
		{
			m_playerData->SetPlayerLoggedIn(true);
			m_playerData->SetPlayFabID(result.PlayFabId);
			FetchPlayerData();

			if(LoginCallback.IsBound())
				LoginCallback.Execute(true, "Login Succeded");
		}), PlayFab::FPlayFabErrorDelegate::CreateLambda([LoginCallback](const PlayFab::FPlayFabCppError& error)
		{
			if(LoginCallback.IsBound())
				LoginCallback.Execute(false, error.ErrorMessage);
		}));
}
