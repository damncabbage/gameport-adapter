#pragma once

#include "Joystick.h"
#include "AnalogJoystick.h"

class GeniusF2000 : public Joystick {
public:

    bool init() override {
        return true;
    }

    bool update() override {
        // Ignore the 'third' axis (game port pin 11); it's just
        // floating on this joystick.

        m_state.axes[0] = m_joystick.getAxis(0); // Axis 0, X
        m_state.axes[1] = m_joystick.getAxis(1); // Axis 1, Y
        m_state.axes[2] = m_joystick.getAxis(3); // Axis 3, Z/Throttle
        m_state.buttons = m_joystick.getButtons();
        return true;
    }

    const State& getState() const override {
        return m_state;
    }

    const Description& getDescription() const override {
        static const Description description {
            "Genius Flight 2000 F-16", 3, 4, 0
        };
        return description;
    }

private:
  AnalogJoystick m_joystick;
  State m_state;
};
