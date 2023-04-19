// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Card.generated.h"

/**
 * 
 */
UCLASS()
class UCard : public UDataAsset
{
	GENERATED_BODY()
	
public:
	int GetP_ID() const;
	void SetP_ID(const int P_ID);
	FString GetP_Name() const;
	void SetP_Name(const FString& P_Name);
	FString GetP_Description() const;
	void SetP_Description(const FString& P_Description);
	FString GetP_PathImg() const;
	void SetP_PathImg(const FString& P_PathImg);
	FString GetP_ItemClass() const;
	void SetP_ItemClass(const FString& P_ItemClass);
	TArray<int> GetP_Currencies() const;
	void SetP_Currencies(const TArray<int>& P_Currencies);

private:
	int p_ID;
	FString p_name;
	FString p_description;
	FString p_pathIMG;
	FString p_itemClass;
	TArray<int> p_currencies;

public:
	UCard();
	UCard(int ID, FString Name, FString Description, FString PathImg= "", FString ItemClass= "");
	
};
