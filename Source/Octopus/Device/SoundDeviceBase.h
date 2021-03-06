// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SoundDeviceBase.generated.h"

UCLASS()
class OCTOPUS_API ASoundDeviceBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASoundDeviceBase();

	UPROPERTY(EditAnywhere)
	int32 TestUproperty;

	UPROPERTY(EditAnywhere)
	UStaticMesh* StaticMesh;

	UPROPERTY(EditAnywhere)
	UMaterial* Material;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
