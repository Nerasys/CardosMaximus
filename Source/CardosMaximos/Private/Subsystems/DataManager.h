// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/Card.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DataManager.generated.h"

UCLASS()
class UDataManager : public UGameInstanceSubsystem
{


	GENERATED_BODY()


	// TArray<TObjectPtr<Card>>
	// TSoftObjectPtr<Card> pointeur vers asset non loadé, avant use il faut le Get() / Load()

public:
	
	UFUNCTION(BlueprintCallable)
	TArray<UCard*> GetListCardsEpic() const;
	UFUNCTION(BlueprintCallable)
	TArray<UCard*> GetListCardsLegendary() const;
	UFUNCTION(BlueprintCallable)
	TArray<UCard*> GetListCardsCommon() const;


private:
	 TArray<UCard*> ListCardsEpic;
	 TArray<UCard*> ListCardsLegendary;
	 TArray<UCard*> ListCardsCommon;
	
	// Subsystem implem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

public:
	
	
};
