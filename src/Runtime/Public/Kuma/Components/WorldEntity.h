#pragma once

#include "CoreMinimal.h"
#include "Kuma/Entities/KumaEntity.h"

#include <memory>
#include <set>

struct FWorldEntityComponent : public Swarm::IComponent<FWorldEntityComponent>
{
    std::set<std::shared_ptr<FKumaEntity>> Entities;
};
