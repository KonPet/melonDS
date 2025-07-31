#include <iostream>

#include "KKInput.h"

namespace KKInput {
    void Kontrols::read(const std::array<u8, 91>& data) {
        state = data[0x00];
        if (state == ButtonsKnobs) {
            buttonAuto = (data[0x02] & (1 << 0)) != 0;
            buttonQuantize = (data[0x02] & (1 << 1)) != 0;
            buttonArp = (data[0x02] & (1 << 2)) != 0;
            buttonScale = (data[0x02] & (1 << 3)) != 0;
            buttonPlay = (data[0x02] & (1 << 4)) != 0;
            buttonLoop = (data[0x02] & (1 << 5)) != 0;
            buttonUndo = (data[0x02] & (1 << 6)) != 0;
            buttonShift = (data[0x02] & (1 << 7)) != 0;

            buttonStop = (data[0x03] & (1 << 0)) != 0;
            buttonRec = (data[0x03] & (1 << 1)) != 0;
            buttonTempo = (data[0x03] & (1 << 2)) != 0;
            buttonMetro = (data[0x03] & (1 << 3)) != 0;
            buttonPresetUp = (data[0x03] & (1 << 4)) != 0;
            buttonRight = (data[0x03] & (1 << 5)) != 0;
            buttonPresetDown = (data[0x03] & (1 << 6)) != 0;
            buttonLeft = (data[0x03] & (1 << 7)) != 0;

            buttonMute = (data[0x04] & (1 << 0)) != 0;
            buttonSolo = (data[0x04] & (1 << 1)) != 0;
            buttonScene = (data[0x04] & (1 << 2)) != 0;
            buttonPattern = (data[0x04] & (1 << 3)) != 0;
            buttonTrack = (data[0x04] & (1 << 4)) != 0;
            buttonClear = (data[0x04] & (1 << 5)) != 0;
            buttonKeyMode = (data[0x04] & (1 << 6)) != 0;

            buttonMixer = (data[0x05] & (1 << 0)) != 0;
            buttonPlugin = (data[0x05] & (1 << 1)) != 0;
            buttonBrowser = (data[0x05] & (1 << 2)) != 0;
            buttonSetup = (data[0x05] & (1 << 3)) != 0;
            buttonInstance = (data[0x05] & (1 << 4)) != 0;
            buttonMidi = (data[0x05] & (1 << 5)) != 0;

            dStick = data[0x06];

            knobField = data[0x07];

            buttonOctaveDown = (data[0x08] & (1 << 0)) != 0;
            buttonOctaveUp = (data[0x08] & (1 << 1)) != 0;
            buttonFixedVel = (data[0x08] & (1 << 2)) != 0;

            for (int knob = 0; knob < 8; knob++) {
                knobVals[knob] = data[0x0a + 2 * knob + 0];
                knobVals[knob] |= data[0x0a + 2 * knob + 1] << 8;
            }

            transposeLevel = data[0x1f];
        }
    }
} // namespace KKInput