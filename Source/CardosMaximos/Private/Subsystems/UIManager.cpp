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

FString UUIManager::GetUserName()
{
	return m_userName;
}

FString UUIManager::GetUserEmail()
{
	return m_userEmail;
}

FString UUIManager::GetUserPassword()
{
	return m_userPassword;
}

void UUIManager::SetUserName(FString UserName)
{
	m_userName = UserName;
}

void UUIManager::SetUserEmail(FString UserEmail)
{
	m_userEmail = UserEmail;
}

void UUIManager::SetUserPassword(FString UserPassword)
{
	m_userPassword = UserPassword;
}
