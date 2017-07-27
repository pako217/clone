#pragma once

namespace samc
{
enum class ResourceType
{
	Texture
	// TODO : ADD other types
};
// Forward declaration
class Resource;

//Metadata for a resource
//This contains the information needed to load a resource, and a weak_ptr to the loaded resource, if it's loaded
//already
class ResourceDefinition
{
public:
	ResourceDefinition(ResourceType type, std::string name, std::string path);
	std::shared_ptr<Resource> getResource();
private:
	virtual void load() = 0;
	std::string m_name;
	std::string m_path;
	ResourceType m_type;
	std::weak_ptr<Resource> m_ptr;

};
// Base class for resources	
class Resource
{
public:

private:

};

class TextureDefinition : ResourceDefinition
{
private:
	virtual void load() override;

};


class Texture : public Resource
{


};

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
private:
	std::unordered_map<std::string, std::unique_ptr<ResourceDefinition>> m_res;
};

}

