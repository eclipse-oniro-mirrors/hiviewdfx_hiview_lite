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

#ifndef BLACKBOX_ADAPTER_H
#define BLACKBOX_ADAPTER_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif //__cplusplus
#endif //__cplusplus

#ifndef __user
#define __user
#endif

#include <stdio.h>
#include <stdlib.h>

#ifndef WEAK
#define WEAK __attribute__((weak))
#endif

/* The following functions need to be implemented by yourself */
extern void SystemModuleDump(const char *logDir, struct ErrorInfo *info);
extern void SystemModuleReset(struct ErrorInfo *info);
extern int SystemModuleGetLastLogInfo(struct ErrorInfo *info);
extern int SystemModuleSaveLastLog(const char *logDir, struct ErrorInfo *info);
extern int FullWriteFile(const char *filePath, const char *buf, unsigned int bufSize, int isAppend);
extern char *GetFaultLogPath(void);
extern void RebootSystem(void);

/* The following functions have been implemented in the kernel */
extern unsigned int LOS_BinarySemCreate(unsigned short count, unsigned int *semHandle);
extern unsigned int LOS_SemPend(unsigned int semHandle, unsigned int timeout);
extern unsigned int LOS_SemPost(unsigned int semHandle);

#ifdef __cplusplus
#if __cplusplus
}
#endif //__cplusplus
#endif //__cplusplus

#endif // BLACKBOX_ADAPTER_H