/*
 * MIT License
 *
 * Copyright (c) 2023 Nick_Scratch
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef UPDOWN_COUNTER_FACE_H_
#define UPDOWN_COUNTER_FACE_H_

#include "movement.h"

/*
 * Increment / Decrement Counter
 *
 * A counter that can go in both directions. 
 * Alarm increments the counter, light decrements.
 * Long-press either to move by 10.
 * Supports negative values.
 *
 * The face resigns when the watch goes to sleep, so maybe
 * not super usable with an aggressive sleep timer
 */

typedef struct {
    int8_t count;
} updown_counter_state_t;

// Custom
void display_count(updown_counter_state_t *state);
void update_count(updown_counter_state_t *state, int8_t value);

// Standard
void updown_counter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void updown_counter_face_activate(movement_settings_t *settings, void *context);
bool updown_counter_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void updown_counter_face_resign(movement_settings_t *settings, void *context);

#define updown_counter_face ((const watch_face_t){ \
    updown_counter_face_setup, \
    updown_counter_face_activate, \
    updown_counter_face_loop, \
    updown_counter_face_resign, \
    NULL, \
})

#endif // UPDOWN_COUNTER_FACE_H_

