#ifndef AMIIBO_H
#define AMIIBO_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define AMIIBO_BIN_SIZE 540 //all are of size 540
#define NFC_PAGE_SIZE 4 //135 (page width) x 4 (page size), 
#define NFC_PAGE_COUNT 135 // above


typedef struct {
    uint8_t data[AMIIBO_BIN_SIZE];
    int loaded;
    int tag_present;
} AmiiboContext;

int amiibo_load(AmiiboContext *ctx,const char *path);
void amiibo_set_tag_present(AmiiboContext *ctx, int present);
int amiibo_handle_command(AmiiboContext *ctx, const uint8_t *payload,
    int payload_len, uint8_t* reply_buf, int reply_buf_size);

#endif