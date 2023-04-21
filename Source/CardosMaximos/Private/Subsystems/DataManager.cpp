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

	UCard* card1 = UCard::CreateNewCard(1,"Nathan","La premiere carte");
	UCard* card2 = UCard::CreateNewCard(2,"Sylvain","La seconde carte");
	UCard* card3 = UCard::CreateNewCard(3,"Jules","La troisieme carte");
	UCard* card4 = UCard::CreateNewCard(3,"Jules","La troisieme carte");
	UCard* card5 = UCard::CreateNewCard(3,"Jules","La troisieme carte");
	UCard* card6 = UCard::CreateNewCard(3,"Jules","La troisieme carte");
	UCard* card7 = UCard::CreateNewCard(3,"Jules","La troisieme carte");
	UCard* card8 = UCard::CreateNewCard(3,"Jules","La troisieme carte");
	UCard* card9 = UCard::CreateNewCard(3,"Jules","La troisieme carte");
	UCard* card10 = UCard::CreateNewCard(3,"Jules","La troisieme carte");
	UCard* card11 = UCard::CreateNewCard(3,"Jules","La troisieme carte");
	UCard* card12 = UCard::CreateNewCard(3,"Jules","La troisieme carte");
	UCard* card13 = UCard::CreateNewCard(3,"Jules","La troisieme carte");
	
	
	ListCardsCommon.Add(card1);
	ListCardsCommon.Add(card2);
	ListCardsCommon.Add(card3);
	ListCardsCommon.Add(card4);
	ListCardsCommon.Add(card5);
	ListCardsCommon.Add(card6);
	ListCardsCommon.Add(card7);
	ListCardsCommon.Add(card8);
	ListCardsCommon.Add(card9);
	ListCardsCommon.Add(card10);
	ListCardsCommon.Add(card11);
	ListCardsCommon.Add(card12);
	ListCardsCommon.Add(card13);
}

void UDataManager::Deinitialize()
{
	Super::Deinitialize();
}