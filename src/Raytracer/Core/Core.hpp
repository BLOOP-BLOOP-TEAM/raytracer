/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Core
*/

#pragma once

namespace Raytracer {
    class Core {
    public:
        Core();

        ~Core() = default;
        void run();

    protected:
    private:
        bool _isRunning;
    };
}