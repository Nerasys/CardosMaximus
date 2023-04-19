// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/DataManager.h"
#include "Data/Card.h"


TArray<UCard*> UDataManager::GetListCardsEpic() const
{
	return ListCardsEpic;
}


TArray<UCard*> UDataManager::GetListCardsLegendary() const
{
	return ListCardsLegendary;
}


TArray<UCard*> UDataManager::GetListCardsCommon() const
{
	return ListCardsCommon;
}


void UDataManager::Initialize(FSubsystemCollectionBase& Collection)
{

	Super::Initialize(Collection);
	
	UCard card1 = UCard(1,"Nathan","La premiere carte");
	UCard card2 = UCard(2,"Sylvain","La seconde carte");
	UCard card3 = UCard(3,"Jules","La troisieme carte");
	
	ListCardsCommon.Add(&card1);
	ListCardsCommon.Add(&card2);
	ListCardsCommon.Add(&card3);
}

void UDataManager::Deinitialize()
{
	Super::Deinitialize();
}