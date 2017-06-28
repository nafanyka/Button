//
// Created by nafanya on 01.05.2017.
//

#ifndef NAF_BUTTON_H
#define NAF_BUTTON_H

#include "../../Timer/src/Timer.h"

namespace NAF {
    class Button {
    public:
        Button(int pin);                    // constructor: input pullup enabled by default
        Button(int pin, bool input_pullup); // overloaded constructor: flag available to disable input pullup
        void setDebounceTimeout(unsigned long value);
        bool isPressed();
        bool isReleased();
        bool onPressed();
        bool onReleased();
        void invertReading();
    private:
        int _pin;
        unsigned long _debounce_timeout = 10; // ms
        bool _has_been_pressed  = false;
        bool _has_been_released = false;
        bool _invert = true;
        bool _temp_reading;
        void _inputPullup();
        void _disableInputPullup();
        Timer _pressed_debounce;
        Timer _released_debounce;
    };
}

#endif //NAF_BUTTON_H
