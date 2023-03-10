// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"


// Sets default values
AMover::AMover()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("sphere"));
	
	Scene->SetupAttachment(GetRootComponent());
	sphere->SetupAttachment(Scene);
}

// Called when the game starts or when spawned
void AMover::BeginPlay()
{
	Super::BeginPlay();

	bIsUp = true;
	const FVector Location =  GetActorLocation();
	if(!bSide){
	    CurrentZ  = Location.Z;
    	MinHeight = Location.Z;
    	MaxHeight = Location.Z + Max;
	}
	else{
	    CurrentZ  = Location.Y;
        	MinHeight = Location.Y;
        	MaxHeight = Location.Y + Max;
	}
	
	
}

// Called every frame
void AMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float Val = Speed * DeltaTime;
	if(bIsUp)
	{
		CurrentZ = (Val) +CurrentZ;
	}
	else
	{
		CurrentZ =  CurrentZ - (Val) ;	
	}

	FVector Location = GetActorLocation();
	if(!bSide)
	{
	    Location.Z = CurrentZ;
	}
	else
	{
	    Location.Y = CurrentZ;
	}
	
	SetActorLocation(Location);

	if(CurrentZ>MaxHeight)
	{
		bIsUp = false;	
		if(CurrentZ<MinHeight)
		{
			bIsUp = true;	
		}
	}
	else if(CurrentZ<MinHeight)
	{
		bIsUp = true;	
	}
	
}

