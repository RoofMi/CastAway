// Fill out your copyright notice in the Description page of Project Settings.


#include "NWaveSound.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ANWaveSound::ANWaveSound()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WaveSoundMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SetRootComponent(WaveSoundMesh);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> WaveSoundStaticMesh(TEXT("/Game/Assets/Palmtree/SM_Coconut.SM_Coconut"));
	if (WaveSoundStaticMesh.Succeeded())
	{
		WaveSoundMesh->SetStaticMesh(WaveSoundStaticMesh.Object);
	}

	static ConstructorHelpers::FObjectFinder<USoundWave> WaveSoundFinder(TEXT("/Game/Assets/Sound/SW_Wave.SW_Wave"));
	if (WaveSoundFinder.Succeeded())
	{
		WaveSound = WaveSoundFinder.Object;
	}

}

// Called when the game starts or when spawned
void ANWaveSound::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANWaveSound::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANWaveSound::PlaySound()
{
	UGameplayStatics::PlaySound2D(GetWorld(), Cast<USoundBase>(WaveSound), 1.0f, 1.0f, 0.0f);
}

