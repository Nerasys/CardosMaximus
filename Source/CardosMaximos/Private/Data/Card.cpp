// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/Card.h"

int UCard::GetP_ID() const
{
	return p_ID;
}

void UCard::SetP_ID(const int P_ID)
{
	p_ID = P_ID;
}

FString UCard::GetP_Name() const
{
	return p_name;
}

void UCard::SetP_Name(const FString& P_Name)
{
	p_name = P_Name;
}

FString UCard::GetP_Description() const
{
	return p_description;
}

void UCard::SetP_Description(const FString& P_Description)
{
	p_description = P_Description;
}

FString UCard::GetP_PathImg() const
{
	return p_pathIMG;
}

void UCard::SetP_PathImg(const FString& P_PathImg)
{
	p_pathIMG = P_PathImg;
}

FString UCard::GetP_ItemClass() const
{
	return p_itemClass;
}

void UCard::SetP_ItemClass(const FString& P_ItemClass)
{
	p_itemClass = P_ItemClass;
}

TArray<int> UCard::GetP_Currencies() const
{
	return p_currencies;
}

void UCard::SetP_Currencies(const TArray<int>& P_Currencies)
{
	p_currencies = P_Currencies;
}

UCard::UCard()
{
}

UCard::UCard(int ID, FString Name, FString Description, FString PathImg, FString ItemClass)
{
	p_ID = ID;
	p_name = Name;
	p_description = Description;
	p_pathIMG = PathImg;
	p_itemClass = ItemClass;
}
