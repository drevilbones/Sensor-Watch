/*
 * MIT License
 *
 * Copyright (c) 2023 Nick Scratch
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

#ifndef RPG_DICE_FACE_H_
#define RPG_DICE_FACE_H_

#include "movement.h"

/*
 * RPG DICE ROLLER WATCH FACE
 *
 * TODO: describe use
 *
 */

typedef struct {
    uint8_t num;
    uint8_t side_index; //the index of const uint8_t D_SIDES[]
    uint8_t total;
} rpg_dice_state_t;

void rpg_dice_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void rpg_dice_face_activate(movement_settings_t *settings, void *context);
bool rpg_dice_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void rpg_dice_face_resign(movement_settings_t *settings, void *context);

#define rpg_dice_face ((const watch_face_t){ \
    rpg_dice_face_setup, \
    rpg_dice_face_activate, \
    rpg_dice_face_loop, \
    rpg_dice_face_resign, \
    NULL, \
})

#endif // RPG_DICE_FACE_H_

