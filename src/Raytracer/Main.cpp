/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Main
*/

#include "Core.hpp"
#include "Raytracer.hpp"

int main(int ac, char **av)
{
    try {
        Raytracer::Core core;
        core.run();
    } catch (const std::runtime_error &e ) {
        std::cerr << "error" << std::endl;
        return EXIT_EPITECH;
    } catch (const std::exception &e) {
        std::cerr << "error" << std::endl;
        return EXIT_EPITECH;
    }
    return EXIT_SUCCESS;
}
