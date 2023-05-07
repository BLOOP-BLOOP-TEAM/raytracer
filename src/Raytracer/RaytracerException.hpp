/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** RaytracerException
*/

#include <exception>
#include <string>

namespace Raytracer {
    class RaytracerException : public std::exception {
    public:
        explicit RaytracerException(const std::string &message);

        [[nodiscard]] const std::string &message() const noexcept;

    private:
        [[nodiscard]] const char *what() const noexcept override;

        std::string _message;
    };
}