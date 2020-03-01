#include "pklib.h"
#include <cstddef>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <cassert>

typedef struct
{
    unsigned char * pbInBuff;           // Pointer to input data buffer
    unsigned char * pbInBuffEnd;        // End of the input buffer
    unsigned char * pbOutBuff;          // Pointer to output data buffer
    unsigned char * pbOutBuffEnd;       // Pointer to output data buffer
} TDataInfo;

unsigned int read_from_buffer(char *buf, unsigned  int *size, void *param)
{
    TDataInfo * pInfo = (TDataInfo *)param;
    unsigned int nMaxAvail = (unsigned int)(pInfo->pbInBuffEnd - pInfo->pbInBuff);
    unsigned int nToRead = *size;

    // Check the case when not enough data available
    if(nToRead > nMaxAvail)
        nToRead = nMaxAvail;
    
    // Load data and increment offsets
    memcpy(buf, pInfo->pbInBuff, nToRead);
    pInfo->pbInBuff += nToRead;
    assert(pInfo->pbInBuff <= pInfo->pbInBuffEnd);
    return nToRead;
}

void write_to_buffer(char *buf, unsigned  int *size, void *param)
{
    TDataInfo * pInfo = (TDataInfo *)param;
    unsigned int nMaxWrite = (unsigned int)(pInfo->pbOutBuffEnd - pInfo->pbOutBuff);
    unsigned int nToWrite = *size;

    // Check the case when not enough space in the output buffer
    if(nToWrite > nMaxWrite)
        nToWrite = nMaxWrite;

    // Write output data and increments offsets
    memcpy(pInfo->pbOutBuff, buf, nToWrite);
    pInfo->pbOutBuff += nToWrite;
    assert(pInfo->pbOutBuff <= pInfo->pbOutBuffEnd);
}

int explode_nocb(unsigned char *pvOutBuffer, int * pcbOutBuffer, unsigned char *pvInBuffer, int cbInBuffer)
{
    TDataInfo Info;                             // Data information
    //char * work_buf = STORM_ALLOC(char, EXP_BUFFER_SIZE);// Pklib's work buffer
    char * work_buf = (char *) malloc(sizeof(char) * EXP_BUFFER_SIZE);

    // Handle no-memory condition
    if(work_buf == NULL)
        return 0;

    // Fill data information structure
    memset(work_buf, 0, EXP_BUFFER_SIZE);
    Info.pbInBuff     = (unsigned char *)pvInBuffer;
    Info.pbInBuffEnd  = (unsigned char *)pvInBuffer + cbInBuffer;
    Info.pbOutBuff    = (unsigned char *)pvOutBuffer;
    Info.pbOutBuffEnd = (unsigned char *)pvOutBuffer + *pcbOutBuffer;

    // Do the decompression
    explode(read_from_buffer, write_to_buffer, work_buf, &Info);
    
    // If PKLIB is unable to decompress the data, return 0;
    if(Info.pbOutBuff == pvOutBuffer)
    {
        free(work_buf);
        return 0;
    }

    // Give away the number of decompressed bytes
    *pcbOutBuffer = (int)(Info.pbOutBuff - (unsigned char *)pvOutBuffer);
    free(work_buf);
    return 1;
}

void implode_nocb(unsigned char *pvOutBuffer, int * pcbOutBuffer, unsigned char *pvInBuffer, int cbInBuffer, int pCmpType, int nCmpLevel)
{
    TDataInfo Info;                                      // Data information
    char * work_buf = (char *) malloc(sizeof(char) * CMP_BUFFER_SIZE);// Pklib's work buffer
    unsigned int dict_size;                              // Dictionary size
    unsigned int ctype = pCmpType;                     // Compression type


    // Handle no-memory condition
    if(work_buf != NULL)
    {
        // Fill data information structure
        memset(work_buf, 0, CMP_BUFFER_SIZE);
        Info.pbInBuff     = (unsigned char *)pvInBuffer;
        Info.pbInBuffEnd  = (unsigned char *)pvInBuffer + cbInBuffer;
        Info.pbOutBuff    = (unsigned char *)pvOutBuffer;
        Info.pbOutBuffEnd = (unsigned char *)pvOutBuffer + *pcbOutBuffer;

        // if (cbInBuffer < 0x600)
        //     dict_size = CMP_IMPLODE_DICT_SIZE1;
        // else if(0x600 <= cbInBuffer && cbInBuffer < 0xC00)
        //     dict_size = CMP_IMPLODE_DICT_SIZE2;
        // else
        //     dict_size = CMP_IMPLODE_DICT_SIZE3;

        if (nCmpLevel == 1)
            dict_size = CMP_IMPLODE_DICT_SIZE1;
        else if(nCmpLevel == 2)
            dict_size = CMP_IMPLODE_DICT_SIZE2;
        else
            dict_size = CMP_IMPLODE_DICT_SIZE3;

        // Do the compression
        if(implode(read_from_buffer, write_to_buffer, work_buf, &Info, &ctype, &dict_size) == CMP_NO_ERROR)
            *pcbOutBuffer = (int)(Info.pbOutBuff - (unsigned char *)pvOutBuffer);

        free(work_buf);
    }
}