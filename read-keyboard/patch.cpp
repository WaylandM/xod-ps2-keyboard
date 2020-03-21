using Type = uint16_t;

struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `PS2KeyAdvanced` class instance
    auto keyboard = getValue<input_DEV>(ctx);

    Type code = keyboard->available();

    if (keyboard->available()){
        Type code = keyboard->read();
        if(code > 0){
            emitValue<output_CODE>(ctx, code);
        }
        emitValue<output_DONE>(ctx, 1);
    }
}
