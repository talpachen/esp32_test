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


#define VSF_ARCH_SWI_NUM                                4
#define VSF_HAL_USE_USART                               DISABLED
#define VSF_KERNEL_CFG_NON_STANDALONE                   ENABLED

#define VSF_USE_FIFO                                    ENABLED


// component configure
#define VSF_USE_HEAP                                    ENABLED
#   define VSF_HEAP_CFG_MCB_MAGIC_EN                    ENABLED
#   define VSF_HEAP_SIZE                                0x1000
#   define VSF_HEAP_CFG_MCB_ALIGN_BIT                   12      // 4K alignment

// VSF_USE_USB_DEVICE will be enabled if target chip supports USBD
//#define VSF_USE_USB_DEVICE                              ENABLED
#   define VSF_USBD_CFG_USE_EDA                         ENABLED
#   define VSF_USBD_USE_CDCACM                          ENABLED
#   define VSF_USBD_USE_MSC                             ENABLED
#   define VSF_USBD_USE_UVC                             ENABLED
#   define APP_CFG_USBD_VID                             0xA7A8
#   define APP_CFG_USBD_PID                             0x2348

#define VSF_USE_MAL                                     DISABLED
#   define VSF_MAL_USE_MEM_MAL                          ENABLED
#   define VSF_MAL_USE_FAKEFAT32_MAL                    ENABLED
#   define VSF_MAL_USE_SCSI_MAL                         ENABLED
#   define VSF_MAL_USE_FILE_MAL                         ENABLED

#define VSF_USE_SCSI                                    DISABLED
#   define VSF_SCSI_USE_MAL_SCSI                        ENABLED

#define VSF_USE_FS                                      DISABLED
#   define VSF_FS_USE_MEMFS                             ENABLED
#   define VSF_FS_USE_FATFS                             ENABLED

#define VSF_USE_TRACE                                   DISABLED
#define USRAPP_CFG_STDIO_EN                             ENABLED

#define VSF_USE_LINUX                                   DISABLED
#   define VSF_LINUX_USE_LIBUSB                         VSF_USE_USB_HOST
#   define VSF_LINUX_USE_BUSYBOX                        ENABLED

#ifndef USRAPP_CFG_LINUX_TTY_DEBUT_STREAM
#   define USRAPP_CFG_LINUX_TTY_DEBUG_STREAM            0
#   define USRAPP_CFG_LINUX_TTY_UART                    1
#   define USRAPP_CFG_LINUX_TTY_CDC                     2
#endif
#   define USRAPP_CFG_LINUX_TTY                         USRAPP_CFG_LINUX_TTY_DEBUG_STREAM

#define VSF_USE_STREAM                                  DISABLED
#define VSF_USE_SIMPLE_STREAM                           ENABLED
#define VSF_HAL_USE_DEBUG_STREAM                        ENABLED


#ifndef USRAPP_CFG_DCD_TYPE_DEFAULT
#   define USRAPP_CFG_DCD_TYPE_DEFAULT                  0
#   define USRAPP_CFG_DCD_TYPE_DWCOTG                   1
#   define USRAPP_CFG_DCD_TYPE_MUSB_FDRC                2
#endif

#define USRAPP_CFG_FAKEFAT32                            ENABLED


#if __IS_COMPILER_LLVM__
#   pragma clang diagnostic ignored "-Wbuiltin-requires-header"
#   pragma clang diagnostic ignored "-Wmicrosoft-include"
#   pragma clang diagnostic ignored "-Winconsistent-dllimport"
#   pragma clang diagnostic ignored "-Wimplicit-function-declaration"
#endif

#define ASSERT(...)                                     assert(__VA_ARGS__)
//#define ASSERT(...)

#define VSF_SYSTIMER_FREQ                               (0ul)

#define VSF_USE_USB_DEVICE                              DISABLED
#   if VSF_ARCH_SWI_NUM == 0
#       define VSF_USBD_CFG_EDA_PRIORITY                vsf_prio_0
#   else
#       define VSF_USBD_CFG_EDA_PRIORITY                vsf_prio_1
#   endif
#   if VSF_ARCH_PRI_NUM == 1
#       define VSF_USBD_CFG_HW_PRIORITY                 vsf_arch_prio_0
#   else
#       define VSF_USBD_CFG_HW_PRIORITY                 vsf_arch_prio_1
#   endif
#   define USRAPP_CFG_USBD_DEV                          VSF_USB_DC0

#define VSF_USBH_CFG_ENABLE_ROOT_HUB                    DISABLED
#define VSF_USBH_USE_HUB                                DISABLED

#if APP_USE_TGUI_DEMO == ENABLED
#   define APP_CFG_TGUI_RES_DIR                         "./ui/"
#endif

#if APP_USE_XBOOT_XUI_DEMO == ENABLED
#   define APP_CFG_XBOOT_RES_DIR                        "./ui/"
#endif

#if APP_USE_VSFIP_DEMO == ENABLED || APP_USE_LWIP_DEMO == ENABLED
#   define VSF_NETDRV_USE_WPCAP                         ENABLED
#       define VSF_NETDRV_WPCAP_CFG_HW_PRIORITY         vsf_arch_prio_0
//  TODO: modify the virtual mac address
#   define APP_NETDRV_WPCAP_CFG_MAC                     0xDC,0xFB,0x48,0x7B,0x9C,0x88
#endif

#if APP_USE_SDL2_DEMO == ENABLED
#   define APP_CFG_SDL2_DEMO_COLOR_RGB565
#endif

#define VSF_LINUX_CFG_STACKSIZE                         (60 * 1024)
#define VSF_TRACE_CFG_COLOR_EN                          ENABLED
#define VSH_ECHO                                        1

/*----------------------------------------------------------------------------*
 * Regarget Weak interface                                                    *
 *----------------------------------------------------------------------------*/

#define WEAK_VSF_KERNEL_ERR_REPORT
#define WEAK___POST_VSF_KERNEL_INIT
#define WEAK_VSF_SYSTIMER_EVTHANDLER
#define WEAK_VSF_ARCH_REQ___SYSTIMER_RESOLUTION___FROM_USR
#define WEAK_VSF_ARCH_REQ___SYSTIMER_FREQ___FROM_USR
//#define WEAK_VSF_DRIVER_INIT
#define WEAK_VSF_HEAP_MALLOC_ALIGNED


/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/


#endif      // __VSF_USR_CFG_FREERTOS_H__
/* EOF */
