#include "CoreMinimal.h"

#include "Swarm/SwarmDefine.h"
#include "Swarm/SwarmManager.h"

namespace Swarm
{

FComponentArray::FComponentArray()
    : ContainerType(Swarm::Invalid), ComponentSize(0)
{
}

void FComponentArray::Remove(Swarm::ComponentIndex Index) { UNUSED_VAR(Index); }

KManager::KManager() {}

KManager::~KManager() {}

void KManager::Update(float DeltaTime)
{
    // TODO: Refactor system update via multithreading

    for (const auto& System : Systems)
    {
        System->Update(DeltaTime);
    }
}

void KManager::RemoveEntity(FEntity& Entity)
{
    const auto& EntityComponents =
        EntityToComponents[Entity.GetUnderlyingIndex()];

    for (const auto& [InComponentType, InComponentIndex] : EntityComponents)
    {
        Components[InComponentType].Remove(InComponentIndex);
    }

    FreeEntityIndices.push(Entity.GetUnderlyingIndex());

    Entity.Reset();
}

} // namespace Swarm
