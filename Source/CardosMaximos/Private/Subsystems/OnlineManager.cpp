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
}

void UOnlineManager::Deinitialize()
{
	Super::Deinitialize();
}

void UOnlineManager::RegisterNewUser(FRegisterCallback RegisterCallback, FString Email, FString Password, FString UserName)
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

void UOnlineManager::SetPlayerData(FSetPlayerDataCallback SetPlayerDataCallback, TMap<FString, FString> Data)
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

void UOnlineManager::GetPlayerData(FGetPlayerDataCallback GetPlayerDataCallback)
{
	if(!m_clientAPI || !IsPlayerLoggedIn())
		return;
	
	PlayFab::ClientModels::FGetUserDataRequest Request;
	Request.PlayFabId = m_playerPlayFabID;

	m_clientAPI->GetUserData(Request, PlayFab::UPlayFabClientAPI::FGetUserDataDelegate::CreateLambda([GetPlayerDataCallback](const PlayFab::ClientModels::FGetUserDataResult Result)
	{
		FString ret = "Ret keys : ";
		for(auto values : Result.Data)
		{
			ret.Append(values.Key).Append(" / "); 
		}

		if(GetPlayerDataCallback.IsBound())
			GetPlayerDataCallback.Execute(true, ret);
	}), PlayFab::FPlayFabErrorDelegate::CreateLambda([GetPlayerDataCallback](const PlayFab::FPlayFabCppError& error)
	{
		if(GetPlayerDataCallback.IsBound())
			GetPlayerDataCallback.Execute(false, error.ErrorMessage);
	}
	));
}

void UOnlineManager::GetPlayerInventory(FGetPlayerInventoryCallback GetPlayerInventoryCallback)
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
	return m_playerLogged;
}

void UOnlineManager::SignInWithEmail(FLoginCallback LoginCallback, FString Email, FString Password)
{
	if(!m_clientAPI)
		return;
	
	PlayFab::ClientModels::FLoginWithEmailAddressRequest Request;
	Request.Email = Email;
	Request.Password = Password;

	m_clientAPI->LoginWithEmailAddress(Request,
	PlayFab::UPlayFabClientAPI::FLoginWithEmailAddressDelegate::CreateLambda([LoginCallback, this](const PlayFab::ClientModels::FLoginResult& result)
		{
			m_playerLogged = true;
			m_playerPlayFabID = result.PlayFabId;
		
			if(LoginCallback.IsBound())
				LoginCallback.Execute(true, "Login Succeded");
		}), PlayFab::FPlayFabErrorDelegate::CreateLambda([LoginCallback](const PlayFab::FPlayFabCppError& error)
		{
			if(LoginCallback.IsBound())
				LoginCallback.Execute(false, error.ErrorMessage);
		}));
}