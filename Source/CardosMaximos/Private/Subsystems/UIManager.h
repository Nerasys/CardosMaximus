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

public:

	// Getters
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString GetUserName();
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString GetUserEmail();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString GetUserPassword();

	//Setters
	UFUNCTION(BlueprintCallable)
	void SetUserName(FString UserName);
	
	UFUNCTION(BlueprintCallable)
	void SetUserEmail(FString UserName);
	
	UFUNCTION(BlueprintCallable)
	void SetUserPassword(FString UserName);
	
private:
	FString m_userName;
	FString m_userEmail;
	FString m_userPassword;
};
