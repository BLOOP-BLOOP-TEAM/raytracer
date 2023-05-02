/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** RaytracerException
*/

#include <string>
#include <exception>

namespace Raytracer {
    class RaytracerException : public std::exception {
        public:
            RaytracerException(const std::string &message);
            
            const char *what() const noexcept override;

        protected:
        private:
            std::string _message;
    };
}
