// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerData.h"

UPlayerData::UPlayerData()
{
}

UPlayerData::~UPlayerData()
{
}

bool UPlayerData::IsPlayerLoggedIn()
{
	return m_playerLoggedIn;
}

void UPlayerData::SetPlayerLoggedIn(bool PlayerLogged)
{
	m_playerLoggedIn = PlayerLogged;
}

FString UPlayerData::GetPlayFabID()
{
	return m_playFabID;
}

void UPlayerData::SetPlayFabID(FString PlayFabID)
{
	m_playFabID = PlayFabID;
}

TMap<FString, FString> UPlayerData::GetData()
{
	return m_data;
}

void UPlayerData::SetData(TMap<FString, FString> Data)
{
	m_data = Data;
}

bool UPlayerData::AddData(FString Key, FString Value)
{
	if(m_data.Contains(Key))
		return false;
	
	m_data.Add(Key, Value);

	return true;
}
