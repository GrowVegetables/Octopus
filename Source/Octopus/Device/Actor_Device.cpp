// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor_Device.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
AActor_Device::AActor_Device()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	visualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	visualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Game/Mesh/Cube.Cube"));

	if (Cube.Succeeded())
	{
		visualMesh->SetStaticMesh(Cube.Object);
		visualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AActor_Device::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActor_Device::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->LookAt();
}

void AActor_Device::LookAt()
{
	APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	FVector mouseLocation, mouseRotator;
	playerController->DeprojectMousePositionToWorld(mouseLocation, mouseRotator);
	FVector actorLocation = GetActorLocation();
	mouseLocation.Z = actorLocation.Z;
	FRotator lookAtRotator = UKismetMathLibrary::FindLookAtRotation(actorLocation, mouseLocation);
	SetActorRotation(lookAtRotator);
}
