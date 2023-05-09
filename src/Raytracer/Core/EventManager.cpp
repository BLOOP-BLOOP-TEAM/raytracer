/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** _eventManager
*/

#include <SFML/Graphics.hpp>
#include "EventManager.hpp"

// ---------------------- KEYBOARD KEYS ---------------------- //
static const std::map<sf::Keyboard::Key, const std::string> KeyboardKeys = {
    {sf::Keyboard::Key::A, "KEY_A_PRESSED"},
    {sf::Keyboard::Key::B, "KEY_B_PRESSED"},
    {sf::Keyboard::Key::C, "KEY_C_PRESSED"},
    {sf::Keyboard::Key::D, "KEY_D_PRESSED"},
    {sf::Keyboard::Key::E, "KEY_E_PRESSED"},
    {sf::Keyboard::Key::F, "KEY_F_PRESSED"},
    {sf::Keyboard::Key::G, "KEY_G_PRESSED"},
    {sf::Keyboard::Key::H, "KEY_H_PRESSED"},
    {sf::Keyboard::Key::I, "KEY_I_PRESSED"},
    {sf::Keyboard::Key::J, "KEY_J_PRESSED"},
    {sf::Keyboard::Key::K, "KEY_K_PRESSED"},
    {sf::Keyboard::Key::L, "KEY_L_PRESSED"},
    {sf::Keyboard::Key::M, "KEY_M_PRESSED"},
    {sf::Keyboard::Key::N, "KEY_N_PRESSED"},
    {sf::Keyboard::Key::O, "KEY_O_PRESSED"},
    {sf::Keyboard::Key::P, "KEY_P_PRESSED"},
    {sf::Keyboard::Key::Q, "KEY_Q_PRESSED"},
    {sf::Keyboard::Key::R, "KEY_R_PRESSED"},
    {sf::Keyboard::Key::S, "KEY_S_PRESSED"},
    {sf::Keyboard::Key::T, "KEY_T_PRESSED"},
    {sf::Keyboard::Key::U, "KEY_U_PRESSED"},
    {sf::Keyboard::Key::V, "KEY_V_PRESSED"},
    {sf::Keyboard::Key::W, "KEY_W_PRESSED"},
    {sf::Keyboard::Key::X, "KEY_X_PRESSED"},
    {sf::Keyboard::Key::Y, "KEY_Y_PRESSED"},
    {sf::Keyboard::Key::Z, "KEY_Z_PRESSED"},
    {sf::Keyboard::Key::Num0, "KEY_0_PRESSED"},
    {sf::Keyboard::Key::Num1, "KEY_1_PRESSED"},
    {sf::Keyboard::Key::Num2, "KEY_2_PRESSED"},
    {sf::Keyboard::Key::Num3, "KEY_3_PRESSED"},
    {sf::Keyboard::Key::Num4, "KEY_4_PRESSED"},
    {sf::Keyboard::Key::Num5, "KEY_5_PRESSED"},
    {sf::Keyboard::Key::Num6, "KEY_6_PRESSED"},
    {sf::Keyboard::Key::Num7, "KEY_7_PRESSED"},
    {sf::Keyboard::Key::Num8, "KEY_8_PRESSED"},
    {sf::Keyboard::Key::Num9, "KEY_9_PRESSED"},
    {sf::Keyboard::Key::Space, "KEY_SPACE_PRESSED"},
    {sf::Keyboard::Key::Return, "KEY_ENTER_PRESSED"},
    {sf::Keyboard::Key::Escape, "KEY_ESC_PRESSED"},
    {sf::Keyboard::Key::Up, "KEY_UP_PRESSED"},
    {sf::Keyboard::Key::Down, "KEY_DOWN_PRESSED"},
    {sf::Keyboard::Key::Left, "KEY_LEFT_PRESSED"},
    {sf::Keyboard::Key::Right, "KEY_RIGHT_PRESSED"},
    {sf::Keyboard::Key::Tab, "KEY_TAB_PRESSED"},
    {sf::Keyboard::Key::BackSpace, "KEY_BACKSPACE_PRESSED"},
    {sf::Keyboard::Key::Delete, "KEY_DEL_PRESSED"},
    {sf::Keyboard::Key::LShift, "KEY_SHIFT_PRESSED"},
    {sf::Keyboard::Key::RShift, "KEY_SHIFT_PRESSED"},
    {sf::Keyboard::Key::LControl, "KEY_CTRL_PRESSED"},
    {sf::Keyboard::Key::RControl, "KEY_CTRL_PRESSED"},
    {sf::Keyboard::Key::LAlt, "KEY_ALT_PRESSED"},
    {sf::Keyboard::Key::RAlt, "KEY_ALT_PRESSED"},
    {sf::Keyboard::Key::F1, "KEY_F1_PRESSED"},
    {sf::Keyboard::Key::F2, "KEY_F2_PRESSED"},
    {sf::Keyboard::Key::F3, "KEY_F3_PRESSED"},
    {sf::Keyboard::Key::F4, "KEY_F4_PRESSED"},
    {sf::Keyboard::Key::F5, "KEY_F5_PRESSED"},
    {sf::Keyboard::Key::F6, "KEY_F6_PRESSED"},
    {sf::Keyboard::Key::F7, "KEY_F7_PRESSED"},
    {sf::Keyboard::Key::F8, "KEY_F8_PRESSED"},
    {sf::Keyboard::Key::F9, "KEY_F9_PRESSED"},
    {sf::Keyboard::Key::F10, "KEY_F10_PRESSED"},
    {sf::Keyboard::Key::F11, "KEY_F11_PRESSED"},
    {sf::Keyboard::Key::F12, "KEY_F12_PRESSED"}
};


Raytracer::EventManager::EventManager(sf::RenderWindow &window) : _window(window), _isCtrlActive(false)
{
}

bool Raytracer::EventManager::isCtrlActive() const
{
    return _isCtrlActive;
}

void Raytracer::EventManager::update()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _events.push_back("Quit");
            _window.close();
        }
        if (_event.type == sf::Event::KeyPressed && KeyboardKeys.find(_event.key.code) != KeyboardKeys.end()) {
            _events.push_back(KeyboardKeys.at(_event.key.code));
            if (KeyboardKeys.at(_event.key.code) == "KEY_CTRL_PRESSED")
                _isCtrlActive = !_isCtrlActive;
        }
    }
}

bool Raytracer::EventManager::isEventTriggered(const std::string &event) const
{
    for (auto &e : _events) {
        if (e == event)
            return true;
    }
    return false;
}

void Raytracer::EventManager::clear()
{
    _events.clear();
}
