// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UWorld* world = GetWorld();
	if (world)
	{
		APlayerController* player = world->GetFirstPlayerController();
		FVector2D mousePos = FVector2D(0, 0);
		FVector worldPos = FVector(mousePos.X, mousePos.Y, 0);
		player->GetMousePosition(mousePos.X, mousePos.Y);
		UE_LOG(LogTemp, Warning, TEXT("%d,%d"), mousePos.X, mousePos.Y);
	}
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

