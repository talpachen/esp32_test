/*****************************************************************************
 *   Copyright(C)2009-2019 by VSF Team                                       *
 *                                                                           *
 *  Licensed under the Apache License, Version 2.0 (the "License");          *
 *  you may not use this file except in compliance with the License.         *
 *  You may obtain a copy of the License at                                  *
 *                                                                           *
 *     http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                           *
 *  Unless required by applicable law or agreed to in writing, software      *
 *  distributed under the License is distributed on an "AS IS" BASIS,        *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 *  See the License for the specific language governing permissions and      *
 *  limitations under the License.                                           *
 *                                                                           *
 ****************************************************************************/


//! \note User Level Application Configuration

#ifndef __VSF_USR_CFG_H__
#define __VSF_USR_CFG_H__

/*============================ INCLUDES ======================================*/
/*============================ MACROS ========================================*/


#define VSF_DRIVER_HEADER           "vsf_usr_cfg.h" // fake include
#define __RTOS__
#define __FREERTOS__

#define VSF_OS_CFG_PRIORITY_NUM                         1
#define VSF_OS_CFG_MAIN_MODE                            VSF_OS_CFG_MAIN_MODE_IDLE

#define VSF_KERNEL_CFG_SUPPORT_SYNC                     DISABLED
#   define VSF_KERNEL_CFG_SUPPORT_SYNC_IRQ              DISABLED
#   define VSF_KERNEL_CFG_SUPPORT_BITMAP_EVENT          DISABLED
#   define VSF_KERNEL_CFG_SUPPORT_MSG_QUEUE             DISABLED
#define VSF_KERNEL_CFG_EDA_SUPPORT_PT                   DISABLED
#define VSF_KERNEL_CFG_EDA_SUPPORT_TIMER                DISABLED
#   define VSF_KERNEL_CFG_CALLBACK_TIMER                DISABLED
#define VSF_KERNEL_CFG_EDA_SUPPORT_SUB_CALL             DISABLED
#define VSF_KERNEL_CFG_EDA_SUPPORT_FSM                  DISABLED

#define VSF_KERNEL_CFG_ALLOW_KERNEL_BEING_PREEMPTED     DISABLED
#   define VSF_KERNEL_CFG_SUPPORT_DYNAMIC_PRIOTIRY      DISABLED
#   define VSF_OS_CFG_EVTQ_BITSIZE                      4

#define VSF_USE_HEAP                                    DISABLED
#   define VSF_HEAP_CFG_MCB_MAGIC_EN                    DISABLED
#   define VSF_HEAP_SIZE                                0x1000

#define VSF_USE_KERNEL_SIMPLE_SHELL                     ENABLED
#define VSF_KERNEL_CFG_SUPPORT_THREAD                   DISABLED

//#define VSF_OS_CFG_EVTQ_POOL_SIZE                     16
//#define VSF_OS_CFG_DEFAULT_TASK_FRAME_POOL_SIZE       16
//#define VSF_OS_CFG_ADD_EVTQ_TO_IDLE                   DISABLED
//#define VSF_OS_CFG_MAIN_STACK_SIZE                    2048

#define VSF_USE_USB_DEVICE                              ENABLED
#   define VSF_USBD_CFG_USE_EDA                         DISABLED
#   define VSF_USBD_CFG_HW_PRIORITY                     vsf_arch_prio_0
#   define VSF_USBD_CFG_EDA_PRIORITY                    vsf_prio_0
#   define VSF_USBD_CFG_RAW_MODE                        ENABLED
#   define VSF_USBD_CFG_STREAM_EN                       DISABLED

#define VSF_USE_TRACE                                   DISABLED
#define VSF_USE_SERVICE_VSFSTREAM                       DISABLED

/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/


#endif      // __VSF_USR_CFG_FREERTOS_H__
/* EOF */
