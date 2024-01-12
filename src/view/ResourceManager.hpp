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
    /**
     * On ne veut pas pouvoir faire de copie ni d'affectation pour cette classe car on ne veut qu'une seule instance
     * à tout moment car devoir aller chercher 2 fois une même resource dans notre arborressance de fichier
     * va à l'encontre du concept de ResourceManager
     * */
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    /**
     * loadTexture
     * */
	void loadTexture(string key, string filePath);
	Texture &getTexture(string key);

	void loadFont(string key, string filePath);
	Font &getFont(string key);
private:
	map<string, Texture> textures;
	map<string, Font> fonts;
};

#endif