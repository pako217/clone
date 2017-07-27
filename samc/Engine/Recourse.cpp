
#include "EnginePCH.h"
#include "Recourse.h"

namespace samc
{
ResourceDefinition::ResourceDefinition(ResourceType type, std::string name, std::string path)
	: m_type(type)
	, m_name(std::move(name))
	, m_path(std::move(path))
{
}

std::shared_ptr<samc::Resource> ResourceDefinition::getResource()
{
	//if the resource is loaded already, Just return it
	auto ptr = m_ptr.lock();
	if (ptr)
		return ptr;
	load();
	return m_ptr.lock();
}
}

