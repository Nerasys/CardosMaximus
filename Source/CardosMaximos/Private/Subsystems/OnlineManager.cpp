// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OnlineManager.h"

void UOnlineManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	LOG("Online Manager Init");
}

void UOnlineManager::Deinitialize()
{
	Super::Deinitialize();
	
	
}
