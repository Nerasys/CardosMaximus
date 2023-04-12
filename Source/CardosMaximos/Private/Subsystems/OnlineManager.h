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
	void SignInUser(FLoginCallback LoginCallback, FString Email, FString Password);

	UFUNCTION(BlueprintCallable)
	void RegisterNewUser(FRegisterCallback RegisterCallback, FString Email, FString Password, FString UserName);

private:
	
private:
  	PlayFabClientPtr m_clientAPI = nullptr; 	

};
