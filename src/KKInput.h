#pragma once

#include <array>

#include "types.h"
namespace KKInput {
    using namespace melonDS;
    struct Kontrols {
        Kontrols() = default;
        explicit Kontrols(const std::array<u8, 91>& data) : Kontrols() {
            read(data);
        }

        void read(const std::array<u8, 91>& data);

        enum States {
            Unk,
            ButtonsKnobs,
            Wheels,
        };

        enum D_STICK_FLAGS {
            TOUCHED = 1 << 2,
            PRESSED = 1 << 3,
            LEFT = 1 << 4,
            UP = 1 << 5,
            DOWN = 1 << 6,
            RIGHT = 1 << 7,
        };

        u8 state{};

        bool buttonAuto{};
        bool buttonQuantize{};
        bool buttonArp{};
        bool buttonScale{};
        bool buttonPlay{};
        bool buttonLoop{};
        bool buttonUndo{};
        bool buttonShift{};

        bool buttonStop{};
        bool buttonRec{};
        bool buttonTempo{};
        bool buttonMetro{};
        bool buttonPresetUp{};
        bool buttonRight{};
        bool buttonPresetDown{};
        bool buttonLeft{};

        bool buttonMute{};
        bool buttonSolo{};
        bool buttonScene{};
        bool buttonPattern{};
        bool buttonTrack{};
        bool buttonKeyMode{};
        bool buttonClear{};

        bool buttonMixer{};
        bool buttonPlugin{};
        bool buttonBrowser{};
        bool buttonSetup{};
        bool buttonInstance{};
        bool buttonMidi{};

        bool buttonOctaveDown{};
        bool buttonOctaveUp{};
        bool buttonFixedVel{};

        u8 dStick{};
        u8 knobField{};
        u16 knobVals[8]{};
        u8 transposeLevel{};
    };
} // namespace KKInput