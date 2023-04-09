// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayFab.h"
#include "OnlineManager.generated.h"

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
	void OnRegister(FString Email, FString Password, FString UserName);

private:
  	PlayFabClientPtr m_clientAPI = nullptr; 	
	
};
