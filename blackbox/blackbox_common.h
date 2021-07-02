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

#ifndef BLACKBOX_COMMON_H
#define BLACKBOX_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include "hiview_log.h"

#define ERROR_INFO_HEADER "#### error info ####\r\n"
#define ERROR_INFO_HEADER_FORMAT "event: %s\r\nmodule: %s\r\nerrorDesc: %s\r\n"
#define ERROR_INFO_MAX_LEN 768
#define Min(a, b) (((a) > (b)) ? (b) : (a))
#define BBOX_PRINT_ERR(format, ...) HILOG_DEBUG(HILOG_MODULE_HIVIEW, "bbox: func: %s line: %d, Err: " \
    format, __func__, __LINE__, ##__VA_ARGS__)
#define BBOX_PRINT_INFO(format, ...) HILOG_DEBUG(HILOG_MODULE_HIVIEW, "bbox: Info: " format, ##__VA_ARGS__)

int FullWriteFile(const char *filePath, const char *buf,
    size_t bufSize, int isAppend);

#endif // BLACKBOX_COMMON_H