/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** RaytracerException
*/

#include <string>
#include <exception>

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
            RaytracerException(const std::string &message);
            
            /**
            * @brief function that print the message set
            *
            * This function is used when an error is catched to print the
            * message set on the construction of the object.
            */
            const char *what() const noexcept override;

        protected:
        private:
            std::string _message;
    };
}
