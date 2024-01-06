#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class ResourceManager {
public:
    ResourceManager() = default;
	virtual ~ResourceManager() = default;
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

	void loadTexture(string key, string filePath);
	Texture &getTexture(string key);

	void loadFont(string key, string filePath);
	Font &getFont(string key);
private:
	map<string, Texture> textures;
	map<string, Font> fonts;
};

#endif