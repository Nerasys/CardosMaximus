// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/UIManager.h"

#include "Logger.h"

void UUIManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	LOG("UIManager Init");
}

void UUIManager::Deinitialize()
{
	Super::Deinitialize();
	
}
