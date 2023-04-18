// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayFabClientDataModels.h"
#include "PlayerData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UPlayerData : public UObject
{
	GENERATED_BODY()
	UPlayerData();
	~UPlayerData();

public:

	UFUNCTION(BlueprintCallable)
	bool IsPlayerLoggedIn();

	UFUNCTION(BlueprintCallable)
	void SetPlayerLoggedIn(bool PlayerLogged);

	UFUNCTION(BlueprintCallable)
	FString GetPlayFabID();

	UFUNCTION(BlueprintCallable)
	void SetPlayFabID(FString PlayFabID);

	UFUNCTION(BlueprintCallable)
	TMap<FString, FString> GetData();

	UFUNCTION(BlueprintCallable)
	void SetData(TMap<FString, FString> Data);

	UFUNCTION(BlueprintCallable)
	bool AddData(FString Key, FString Value);
	
private:
	
	bool m_playerLoggedIn = false;
	
	FString m_playFabID = "No playfab ID";
	
	TMap<FString, FString> m_data;
};
