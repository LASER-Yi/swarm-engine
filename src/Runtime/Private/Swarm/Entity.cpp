#include "Swarm/Entity.h"
#include "Swarm/Definition.h"

namespace Swarm
{

FEntity::FEntity(Swarm::EntityIndex InIndex) : EntityIndex(InIndex) {}

void FEntity::Reset() { EntityIndex = Swarm::InvalidIndex; }

} // namespace Swarm
