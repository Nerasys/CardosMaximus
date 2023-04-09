// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UIManager.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class UUIManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	// Subsystem implem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	// --------


};
