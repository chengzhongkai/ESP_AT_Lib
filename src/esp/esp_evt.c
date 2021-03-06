/**	
 * \file            esp_evt.c
 * \brief           Event helper functions
 */
 
/*
 * Copyright (c) 2018 Tilen Majerle
 *  
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of ESP-AT.
 *
 * Author:          Tilen MAJERLE <tilen@majerle.eu>
 */
#include "esp/esp_private.h"
#include "esp/esp_evt.h"
#include "esp/esp_mem.h"

/**
 * \brief           Checks if reset was forced by user or not
 * \note            This function may only be used when event type is \ref ESP_CB_RESET
 * \param[in]       cb: Event data
 * \return          1 if forced by user, 0 otherwise
 */
uint8_t
esp_evt_reset_is_forced(esp_cb_t* cb) {
    return cb->cb.reset.forced;                 /* Return forced reset status */
}
