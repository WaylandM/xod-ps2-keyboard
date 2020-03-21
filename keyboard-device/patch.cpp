//Tell XOD location of library to be wrapped
#pragma XOD require "https://github.com/techpaul/PS2KeyAdvanced"

// Include C++ library:
{{#global}}
#include <PS2KeyAdvanced.h>
#include <PS2KeyCode.h>
#include <PS2KeyTable.h>
{{/global}}

// Reserve memory to store an instance of the class PS2KeyAdvanced.
struct State {
    uint8_t mem[sizeof(PS2KeyAdvanced)];
};

// Define our custom type as a pointer on the class instance.
using Type = PS2KeyAdvanced*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    if (!isSettingUp()) return;

    auto state = getState(ctx);
    auto irqPin = getValue<input_CLOCK>(ctx);
    auto dataPin = getValue<input_DATA>(ctx);

    Type keyboard = new (state->mem) PS2KeyAdvanced();

    // Initialize the device
    keyboard->begin(dataPin, irqPin);

    // Disable Break codes (key release) from PS2KeyAdvanced
    keyboard->setNoBreak( 1 );
    // and set no repeat on CTRL, ALT, SHIFT, GUI while outputting
    keyboard->setNoRepeat( 1 );

    emitValue<output_DEV>(ctx, keyboard);
}
