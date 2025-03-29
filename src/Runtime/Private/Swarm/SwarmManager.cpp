#include "CoreMinimal.h"
#include "Swarm/SwarmDefine.h"

#include "Swarm/SwarmManager.h"

namespace Swarm
{

void FComponentArray::Remove(Swarm::ComponentIndex Index) { UNUSED_VAR(Index); }

Manager::Manager() {}

Manager::~Manager() {}

void Manager::Update(float DeltaTime)
{
    // TODO: Refactor system update via multithreading

    for (const auto& System : Systems)
    {
        System->Update(DeltaTime);
    }
}

void Manager::RemoveEntity(FEntity& Entity)
{
    const auto& EntityComponents =
        EntityToComponents[Entity.GetUnderlyingIndex()];

    for (const FEntityComponent& Component : EntityComponents)
    {
        Components[Component.Type].Remove(Component.Index);
    }

    FreeEntityIndices.push(Entity.GetUnderlyingIndex());

    Entity.Reset();
}

} // namespace Swarm
