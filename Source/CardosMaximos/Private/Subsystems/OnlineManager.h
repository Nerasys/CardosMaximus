// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayFab.h"
#include "PlayFabClientDataModels.h"
#include "PlayFabError.h"
#include "OnlineManager.generated.h"

DECLARE_DYNAMIC_DELEGATE_TwoParams(FLoginCallback, bool, HasSucceeded, FString, Msg);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FRegisterCallback, bool, HasSucceeded, FString, Msg);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FSetPlayerDataCallback, bool, HasSucceeded, FString, Msg);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FGetPlayerDataCallback, bool, HasSucceeded, FString, Msg);

/**
 * 
 */
UCLASS()
class UOnlineManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
		
	// Subsystem implem
   	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
   	virtual void Deinitialize() override;
   	// --------

public:
	
	UFUNCTION(BlueprintCallable)
	void SignInWithEmail(FLoginCallback LoginCallback, FString Email, FString Password);

	UFUNCTION(BlueprintCallable)
	void RegisterNewUser(FRegisterCallback RegisterCallback, FString Email, FString Password, FString UserName);

	UFUNCTION(BlueprintCallable)
	void SetPlayerData(FSetPlayerDataCallback SetPlayerDataCallback, TMap<FString, FString> Data);

	UFUNCTION(BlueprintCallable)
	void GetPlayerData(FGetPlayerDataCallback GetPlayerDataCallback);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsPlayerLoggedIn();
	
private:
  	PlayFabClientPtr m_clientAPI = nullptr;

	// Player related data
	bool m_playerLogged;
	FString m_playerPlayFabID;
	
};
