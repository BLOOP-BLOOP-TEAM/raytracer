/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** LoadConfig
*/

#include <iostream>
#include <libconfig.h++>
#include "LoadConfig.hpp"

int Raytracer::LoadConfig::loadConfigFile(const std::string &path)
{
    libconfig::Config cfg;

    try {
        cfg.readFile("example.cfg");
    } catch(const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        return EXIT_FAILURE;
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        return EXIT_FAILURE;
    }

}
