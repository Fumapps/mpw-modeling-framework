/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_ENTITY_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_ENTITY_H

#include <memory>
#include <string>
#include "ReflectivePropertyObject.h"

namespace basetypes {

/**
 * Base class of an entity which defines property modifications used by commands. It makes use of the generic type Object to provide a reflection-like possibility to set values by property-names.
 * 
 * Note: In Java it can be simply realized by reflection, but in languages like C++ a reflection-like modification access-layer will be generated.
 */
class Entity: public std::enable_shared_from_this<Entity>,
		public ReflectivePropertyObject {

public:

	virtual ~Entity() = default;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK_ENTITY_H

