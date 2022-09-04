/*
** EPITECH PROJECT, 2022
** game_engine
** File description:
** takeScreenshot
*/

#include <fstream>
#include <sys/stat.h>

#include "core/App.hpp"

static bool fileExists(const std::string &name)
{
    std::ifstream f(name.c_str());

    return f.good();
}

static std::string GetNextAvailableFilename(std::string const& filename)
{
    std::string alternateFilename = filename;
    int fileNameIndex = 1;
    std::string extension = filename.substr(filename.find_last_of(".") + 1);
    std::string filenameWithoutExtension =
    filename.substr(0, filename.find_last_of("."));

    while (fileExists(alternateFilename)) {
        alternateFilename = filenameWithoutExtension + "_" +
        std::to_string(fileNameIndex) + "." + extension;
        fileNameIndex += 1;
    }
    return alternateFilename;
}

void App::takeScreenshot(void) const
{
    sf::Texture texture;
    sf::Image image;
    sf::Vector2u size = _window.getSize();
    texture.create(size.x, size.y);
    texture.update(_window);
    image = texture.copyToImage();
    mkdir("screenshots", 0777);
    image.saveToFile(GetNextAvailableFilename("./screenshots/screenshot.png"));
}
