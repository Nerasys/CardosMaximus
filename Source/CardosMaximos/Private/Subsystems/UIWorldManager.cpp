// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/UIWorldManager.h"

#include "Logger.h"

void UUIWorldManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	LOG("UIManager Init");

	InitBP();
}

void UUIWorldManager::Deinitialize()
{
	Super::Deinitialize();
	
}

FString UUIWorldManager::GetUserName()
{
	return m_userName;
}

FString UUIWorldManager::GetUserEmail()
{
	return m_userEmail;
}

FString UUIWorldManager::GetUserPassword()
{
	return m_userPassword;
}

void UUIWorldManager::SetUserName(FString UserName)
{
	m_userName = UserName;
}

void UUIWorldManager::SetUserEmail(FString UserEmail)
{
	m_userEmail = UserEmail;
}

void UUIWorldManager::SetUserPassword(FString UserPassword)
{
	m_userPassword = UserPassword;
}

UGameInstance* UUIWorldManager::GetNoContextGameInstance()
{
	return GetWorld()->GetGameInstance();
}
