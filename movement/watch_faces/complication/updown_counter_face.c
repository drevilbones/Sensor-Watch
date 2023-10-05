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

#include <stdlib.h>
#include <string.h>
#include "updown_counter_face.h"

// Custom Methods *************************************************

void display_count(updown_counter_state_t *state) {
    char buffer[14];
    sprintf(buffer, "CO  %03d  ", (int)(state->count));
    watch_display_string(buffer, 0);
}

void update_count(updown_counter_state_t *state, int8_t value) {
    //Increment or decrement the counter based on value
    if ((state->count < (int8_t)(999)) || (state->count > (int8_t)(-999))) {
        state->count = state->count + value;
    }
}

// Standard Methods ************************************************

void updown_counter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(updown_counter_state_t));
        memset(*context_ptr, 0, sizeof(updown_counter_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void updown_counter_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    updown_counter_state_t *state = (updown_counter_state_t *)context;

    // Handle any tasks related to your watch face coming on screen.
}

bool updown_counter_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    updown_counter_state_t *state = (updown_counter_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            display_count(state);
            break;
        case EVENT_TICK:
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // decrement counter
            update_count(state, -1);
            display_count(state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            // decrement by 10
            update_count(state, -10);
            display_count(state);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // reset and also supress LED
            // if EVENT_ALARM_BUTTON_UP then reset to 0
            break;
        case EVENT_ALARM_BUTTON_UP:
            // increment counter
            update_count(state, 1);
            display_count(state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            // increment by 10
            update_count(state, 10);
            display_count(state);
        case EVENT_TIMEOUT:
            // Ignore timeout
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // If the watch has gone to sleep, then we're probably not actively using the counter
            movement_move_to_face(0);
            break;
        default:
            // Movement's default loop handler will step in for any cases you don't handle above:
            // * EVENT_LIGHT_BUTTON_DOWN lights the LED
            // * EVENT_MODE_BUTTON_UP moves to the next watch face in the list
            // * EVENT_MODE_LONG_PRESS returns to the first watch face (or skips to the secondary watch face, if configured)
            // You can override any of these behaviors by adding a case for these events to this switch statement.
            return movement_default_loop_handler(event, settings);
    }

    // return true if the watch can enter standby mode. Generally speaking, you should always return true.
    // Exceptions:
    //  * If you are displaying a color using the low-level watch_set_led_color function, you should return false.
    //  * If you are sounding the buzzer using the low-level watch_set_buzzer_on function, you should return false.
    // Note that if you are driving the LED or buzzer using Movement functions like movement_illuminate_led or
    // movement_play_alarm, you can still return true. This guidance only applies to the low-level watch_ functions.
    return true;
}

void updown_counter_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

