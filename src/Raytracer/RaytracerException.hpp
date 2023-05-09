/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** RaytracerException
*/

#include <exception>
#include <string>

namespace Raytracer {
    /**
     * @brief The RaytracerException class
     *
     * The RaytracerException class is used when we need to throw an exception
     * 
     * To use it you must build the object with the message you want to print
     * when you throw.
     */
    class RaytracerException : public std::exception {
        public:
            /**
             * @brief The constructor of RaytracerException
             * 
             * @param message string that will define the message in _message
             */
            explicit RaytracerException(const std::string &message);

            const std::string &message() const noexcept;
            
        private:

            /**
             * @brief Function that print the message set
             *
             * This function is used when an error is catched to print the
             * message set on the construction of the object.
             */
            [[nodiscard]] const char *what() const noexcept override;

            std::string _message;
    };
}
