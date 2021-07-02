/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "blackbox_common.h"
#ifdef PLATFORM_HI3861
#include <hi_fs.h>
#endif

#ifdef PLATFORM_HI3861
int FullWriteFile(const char *filePath, const char *buf,
    size_t bufSize, int isAppend)
{
    int fd;
    int totalToWrite = (int) bufSize;
    int totalWrite = 0;

    if (filePath == NULL || buf == NULL || bufSize == 0) {
        BBOX_PRINT_ERR("filePath: %p, buf: %p, bufSize: %lu!\n",
            filePath, buf, bufSize);
            return -1;
    }

    fd = hi_open(filePath, HI_FS_O_WRONLY | HI_FS_O_CREAT |
        (isAppend ? HI_FS_O_APPEND : HI_FS_O_TRUNC));
    if (fd < 0) {
        BBOX_PRINT_ERR("Create file [%s] failed!\n", filePath);
        return -1;
    }

    while (totalToWrite > 0) {
        int writeThisTime = hi_write(fd, buf, totalToWrite);
        if (writeThisTime < 0) {
            BBOX_PRINT_ERR("Failed to write file: %s\n", filePath);
            (void)hi_close(fd);
            return -1;
        }
        buf += writeThisTime;
        totalToWrite -= writeThisTime;
        totalWrite += writeThisTime;
    }
    (void)hi_close(fd);

    return totalWrite == (int)bufSize ? 0 : -1;
}
#else
int FullWriteFile(const char *filePath, const char *buf,
    size_t bufSize, int isAppend)
{
    FILE *fp;
    int totalToWrite = (int) bufSize;
    int totalWrite = 0;

    if (filePath == NULL || buf == NULL || bufSize == 0) {
        BBOX_PRINT_ERR("filePath: %p, buf: %p, bufSize: %lu!\n",
            filePath, buf, bufSize);
            return -1;
    }

    fp = fopen(filePath, (isAppend == 0) ? "wb" : "ab");
    if (fp == NULL) {
        BBOX_PRINT_ERR("Create file [%s] failed!\n", filePath);
        return -1;
    }
    while (totalToWrite > 0) {
        int writeThisTime = fwrite(buf, 1, totalToWrite, fp);
        if (writeThisTime < 0) {
            BBOX_PRINT_ERR("Failed to write file: %s\n", filePath);
            fclose(fp);
            return -1;
        }
        buf += writeThisTime;
        totalToWrite -= writeThisTime;
        totalWrite += writeThisTime;
    }
    fclose(fp);

    return totalWrite == (int)bufSize ? 0 : -1; 
}
#endif
