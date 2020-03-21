//Tell XOD location of library to be wrapped
#pragma XOD require "https://github.com/techpaul/PS2KeyAdvanced"
#pragma XOD require "https://github.com/techpaul/PS2KeyMap"

// Include C++ library:
{{#global}}
#include <PS2KeyAdvanced.h>
#include <PS2KeyCode.h>
#include <PS2KeyTable.h>
#include <PS2KeyData.h>
#include <PS2KeyMap.h>
{{/global}}

struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    //auto inValue = getValue<input_IN>(ctx);
    //emitValue<output_OUT>(ctx, inValue);
}
