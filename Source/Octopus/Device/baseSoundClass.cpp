// Fill out your copyright notice in the Description page of Project Settings.


#include "baseSoundClass.h"
#include "GameFramework/PlayerController.h"

// Sets default values
AbaseSoundClass::AbaseSoundClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AbaseSoundClass::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AbaseSoundClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

