// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayFab.h"
#include "Core/PlayFabError.h"
#include "Core/PlayFabClientDataModels.h"
#include "Logger.h"
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
  
  // public:
  // 	void OnSuccess(const PlayFab::ClientModels::FLoginResult& Result) const;
  // 	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;
  // 	
  // private:
  // 	PlayFabClientPtr m_clientAPI = nullptr; 	
	
};
