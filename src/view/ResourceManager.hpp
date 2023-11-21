#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>

using namespace std;

class ResourceManager {
	public:
		ResourceManager() {}
		virtual ~ResourceManager() {}

		void loadTexture(string key, string filePath);
		sf::Texture &getTexture(string key);

		void loadFont(string key, string filePath);
		sf::Font &getFont(string key);
	private:
		map<string, sf::Texture> textures;
		map<string, sf::Font> fonts;
};

#endif