// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerData.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayFab.h"
#include "PlayFabClientDataModels.h"
#include "PlayFabError.h"
#include "OnlineManager.generated.h"

DECLARE_DYNAMIC_DELEGATE_TwoParams(FRequestCallback, bool, HasSucceeded, FString, Msg);

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

	UFUNCTION(BlueprintImplementableEvent)
	void Init();

	UFUNCTION(BlueprintCallable)
	UPlayerData* GetPlayerData();
	
	UFUNCTION(BlueprintCallable)
	void SignInWithEmail(FRequestCallback LoginCallback, FString Email, FString Password);

	UFUNCTION(BlueprintCallable)
	void RegisterNewUser(FRequestCallback RegisterCallback, FString Email, FString Password, FString UserName);

	UFUNCTION(BlueprintCallable)
	void RetrivePlayerData(FRequestCallback RetrivePlayerDataCallback);
	
	UFUNCTION(BlueprintCallable)
	void SetPlayerData(FRequestCallback SetPlayerDataCallback, TMap<FString, FString> Data);

	UFUNCTION(BlueprintCallable)
	void GetPlayerInventory(FRequestCallback GetPlayerInventoryCallback);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsPlayerLoggedIn();

private:

private:
  	PlayFabClientPtr m_clientAPI = nullptr;
	UPlayerData* m_playerData = nullptr;
};
