// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NWaveSound.generated.h"

UCLASS()
class PROJECTN_API ANWaveSound : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ANWaveSound();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void PlaySound();

	UPROPERTY(VisibleAnywhere, Category = Mesh)
		UStaticMeshComponent* WaveSoundMesh;

	UPROPERTY(VisibleAnywhere, Category = Sound)
		USoundWave* WaveSound;
};
