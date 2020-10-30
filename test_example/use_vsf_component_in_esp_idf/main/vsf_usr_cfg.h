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
#define VSF_USE_JSON                                    ENABLED

// Application configure
#define APP_USE_LINUX_DEMO                              DISABLED
#   define APP_USE_LINUX_MOUNT_FILE_DEMO                DISABLED
#define APP_USE_USBH_DEMO                               DISABLED
#   define APP_USE_DFU_HOST_DEMO                        DISABLED
#define APP_USE_USBD_DEMO                               DISABLED
#   define APP_USE_USBD_CDC_DEMO                        DISABLED
#   define APP_USE_USBD_MSC_DEMO                        DISABLED
#   define APP_USE_USBD_UVC_DEMO                        DISABLED
#   define APP_USE_USBD_USER_DEMO                       DISABLED
#define APP_USE_SCSI_DEMO                               DISABLED
#define APP_USE_AUDIO_DEMO                              DISABLED
#define APP_USE_TGUI_DEMO                               DISABLED
#define APP_USE_SDL2_DEMO                               DISABLED
#define APP_USE_KERNEL_TEST                             DISABLED
#define APP_USE_JSON_DEMO                               DISABLED

// VSF_LINUX_USE_SIMPLE_LIBC conflicts with c++
#define APP_USE_CPP_DEMO                                DISABLED
#define VSF_LINUX_USE_SIMPLE_LIBC                       DISABLED
// if VSF_LINUX_USE_SIMPLE_LIBC is enabled, need VSF_USE_SIMPLE_SSCANF and VSF_USE_SIMPLE_SPRINTF
#define VSF_USE_SIMPLE_SSCANF                           DISABLED
#define VSF_USE_SIMPLE_SPRINTF                          DISABLED

// 3rd-party demos
#define APP_USE_XBOOT_XUI_DEMO                          DISABLED
#define APP_USE_AWTK_DEMO                               DISABLED
#define APP_USE_NNOM_DEMO                               DISABLED
#define APP_USE_LVGL_DEMO                               DISABLED
#   define APP_LVGL_DEMO_CFG_TOUCH_REMAP                DISABLED
#   define APP_LVGL_DEMO_CFG_FREETYPE                   ENABLED
#   define APP_LVGL_DEMO_CFG_FREETYPE_MAX_FACES         4
#   define APP_LVGL_DEMO_CFG_COLOR_DEPTH                16
#   define APP_LVGL_DEMO_CFG_HOR_RES                    256
#   define APP_LVGL_DEMO_CFG_VER_RES                    256
#define APP_USE_BTSTACK_DEMO                            DISABLED
#define APP_USE_VSFVM_DEMO                              DISABLED
// select one for tcpip stack
#define APP_USE_VSFIP_DEMO                              DISABLED
#define APP_USE_LWIP_DEMO                               DISABLED
#define APP_USE_SOCKET_DEMO                             DISABLED
#define APP_USE_GATO_DEMO                               DISABLED
#define APP_USE_NUKLEAR_DEMO                            DISABLED

#if APP_USE_TGUI_DEMO == ENABLED || APP_USE_XBOOT_XUI_DEMO == ENABLED || APP_LVGL_DEMO_CFG_FREETYPE == ENABLED
#   define APP_USE_FREETYPE_DEMO                        ENABLED
#endif

// component configure
#define VSF_USE_HEAP                                    ENABLED
#   define VSF_HEAP_CFG_MCB_MAGIC_EN                    ENABLED
#   define VSF_HEAP_SIZE                                0x1000000
#   define VSF_HEAP_CFG_MCB_ALIGN_BIT                   12      // 4K alignment

#define VSF_USE_VIDEO                                   DISABLED
#define VSF_USE_AUDIO                                   DISABLED
#   define VSF_AUDIO_USE_DECODER_WAV                    DISABLED
#   define VSF_AUDIO_USE_PLAY                           DISABLED
#   define VSF_AUDIO_USE_CATURE                         DISABLED

// UI runs in vsf_prio_0, other modules runs above vsf_prio_1
#if APP_USE_AWTK_DEMO == ENABLED || APP_USE_LVGL_DEMO == ENABLED || APP_USE_XBOOT_XUI_DEMO == ENABLED || APP_USE_TGUI_DEMO == ENABLED
#   if VSF_ARCH_SWI_NUM == 0
#       define VSF_USBH_CFG_EDA_PRIORITY                vsf_prio_0
#   else
#       define VSF_USBH_CFG_EDA_PRIORITY                vsf_prio_1
#   endif
#   if VSF_ARCH_PRI_NUM == 1
#       define APP_CFG_USBH_HW_PRIO                     vsf_arch_prio_0
#   else
#       define APP_CFG_USBH_HW_PRIO                     vsf_arch_prio_1
#   endif
#endif

#define VSF_USE_INPUT                                   DISABLED
#   define VSF_INPUT_USE_HID                            ENABLED
#   define VSF_INPUT_USE_DS4                            ENABLED
#   define VSF_INPUT_USE_NSPRO                          ENABLED
#   define VSF_INPUT_USE_XB360                          ENABLED
#   define VSF_INPUT_USE_XB1                            ENABLED

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
#define WEAK_VSF_DRIVER_INIT
#define WEAK_VSF_HEAP_MALLOC_ALIGNED

#if VSF_USE_LINUX == ENABLED
#   define WEAK_VSF_LINUX_CREATE_FHS
#endif

#if APP_USE_BTSTACK_DEMO == ENABLED && APP_USE_USBH_DEMO == ENABLED
#   define WEAK_VSF_USBH_BTHCI_ON_NEW
#   define WEAK_VSF_USBH_BTHCI_ON_DEL
#   define WEAK_VSF_USBH_BTHCI_ON_PACKET

#   define WEAK_VSF_BLUETOOTH_H2_ON_NEW
#endif

#define WEAK_VSF_SCSI_ON_NEW
#define WEAK_VSF_SCSI_ON_DELETE

#if APP_USE_USBH_DEMO == ENABLED
#   define WEAK_VSF_USBH_UAC_ON_NEW
#endif

#if APP_USE_VSFVM_DEMO == ENABLED
#   define WEAK_VSF_PLUG_IN_ON_KERNEL_IDLE

#   define WEAK_VSFVM_SET_BYTECODE_IMP
#   define WEAK_VSFVM_GET_RES_IMP
#   define WEAK_VSFVM_GET_BYTECODE_IMP
#endif

#if APP_USE_VSFIP_DEMO == ENABLED || APP_USE_LWIP_DEMO == ENABLED
#   define WEAK_VSF_PNP_ON_NETDRV_CONNECT
#   define WEAK_VSF_PNP_ON_NETDRV_CONNECTED

#   if APP_USE_VSFIP_DEMO == ENABLED
#       define WEAK_VSFIP_DHCPC_ON_FINISH

#       define WEAK_VSFIP_MEM_SOCKET_GET
#       define WEAK_VSFIP_MEM_SOCKET_FREE
#       define WEAK_VSFIP_MEM_TCP_PCB_GET
#       define WEAK_VSFIP_MEM_TCP_PCB_FREE
#       define WEAK_VSFIP_MEM_NETBUF_GET
#       define WEAK_VSFIP_MEM_NETBUF_FREE
#   endif
#endif

/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/


#endif      // __VSF_USR_CFG_FREERTOS_H__
/* EOF */
