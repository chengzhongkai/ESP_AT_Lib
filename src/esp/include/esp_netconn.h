/**
 * \file            esp_netconn.h
 * \brief           API functions for sequential calls
 */
 
/*
 *
 * Copyright (c) 2017, Tilen MAJERLE
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *  * Neither the name of the author nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * \author          Tilen MAJERLE <tilen@majerle.eu>
 */
#ifndef __ESP_NETCONN_H
#define __ESP_NETCONN_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "esp.h"

/**
 * \brief           Sequential API structure
 */
typedef struct {
    uint16_t port;                              /*!< Port on which we are listening */
    esp_conn_t* conn;                           /*!< Pointer to actual connection */
    
    esp_sys_sem_t mbox_accept;                  /*!< List of active connections waiting to be processed */
    esp_sys_sem_t mbox_receive;                 /*!< Message queue for receive mbox */
} esp_netconn_t;

esp_netconn_t* esp_netconn_new(void);
espr_t          esp_netconn_delete(esp_netconn_t* nc);
espr_t          esp_netconn_bind(esp_netconn_t* nc, uint16_t port);
espr_t          esp_netconn_listen(esp_netconn_t* nc);
espr_t          esp_netconn_connect(esp_netconn_t* nc, const char* host, uint16_t port);
espr_t          esp_netconn_accept(esp_netconn_t* nc, esp_netconn_t** new_api);
espr_t          esp_netconn_write(esp_netconn_t* nc, const void* data, size_t btw);
espr_t          esp_netconn_receive(esp_netconn_t* nc, esp_pbuf_t** pbuf);
espr_t          esp_netconn_close(esp_netconn_t* nc);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __ESP_NETCONN_H */
