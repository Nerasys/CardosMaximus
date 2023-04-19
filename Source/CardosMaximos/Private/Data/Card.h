// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UCard : public UObject
{
	GENERATED_BODY()

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
	UFUNCTION(BlueprintCallable)
	int GetP_ID() const;
	void SetP_ID(const int P_ID);
	UFUNCTION(BlueprintCallable)
	FString GetP_Name() const;
	void SetP_Name(const FString& P_Name);
	UFUNCTION(BlueprintCallable)
	FString GetP_Description() const;
	void SetP_Description(const FString& P_Description);
	UFUNCTION(BlueprintCallable)
	FString GetP_PathImg() const;
	void SetP_PathImg(const FString& P_PathImg);
	UFUNCTION(BlueprintCallable)
	FString GetP_ItemClass() const;
	void SetP_ItemClass(const FString& P_ItemClass);
	UFUNCTION(BlueprintCallable)
	TArray<int> GetP_Currencies() const;
	void SetP_Currencies(const TArray<int>& P_Currencies);
	static UCard* CreateNewCard(int ID, FString Name, FString Description, FString PathImg= "", FString ItemClass= "");
};
