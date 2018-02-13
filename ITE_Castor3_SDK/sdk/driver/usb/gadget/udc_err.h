﻿#ifndef	UDC_ERROR_H
#define	UDC_ERROR_H

#ifdef __cplusplus
extern "C" {
#endif


#define ERR_UDC_BASE	0xD000

#define ERR_UDC_ALLOC_CTXT_FAIL			(ERR_UDC_BASE + 0x01)
#define ERR_UDC_NOT_INIT				(ERR_UDC_BASE + 0x02)
#define ERR_UDC_INVAL_PARAM				(ERR_UDC_BASE + 0x03)
#define ERR_UDC_DOUBLE_REGISTER			(ERR_UDC_BASE + 0x04)
#define ERR_UDC_BIND_FAIL				(ERR_UDC_BASE + 0x05)
#define ERR_UDC_ALLOC_REQ_FAIL			(ERR_UDC_BASE + 0x06)
#define ERR_UDC_UNREG_NULL_DEV			(ERR_UDC_BASE + 0x07)
#define ERR_UDC_UNREG_INVAILD_DRIVER	(ERR_UDC_BASE + 0x08)
#define ERR_UDC_REQ_PARAM_INVALID		(ERR_UDC_BASE + 0x09)
#define ERR_UDC_EP_PARAM_INVALID		(ERR_UDC_BASE + 0x0A)
#define ERR_UDC_EP_ENABLE_INVALID1		(ERR_UDC_BASE + 0x0B)
#define ERR_UDC_EP_ENABLE_EP0   		(ERR_UDC_BASE + 0x0C)
#define ERR_UDC_EP_ENABLE_NOT_READY		(ERR_UDC_BASE + 0x0D)
#define ERR_UDC_EP_ENABLE_INVALID2		(ERR_UDC_BASE + 0x0E)
#define ERR_UDC_EP_ENABLE_INVALID3		(ERR_UDC_BASE + 0x0F)
#define ERR_UDC_EP_DISABLE_NO_DEV  		(ERR_UDC_BASE + 0x10)
#define ERR_UDC_EP_DISABLE_EP0   		(ERR_UDC_BASE + 0x11)
#define ERR_UDC_EP_NOT_ENABLE   		(ERR_UDC_BASE + 0x12)
#define ERR_UDC_ALLOC_EP0REQ_FAIL		(ERR_UDC_BASE + 0x13)
#define ERR_UDC_DEQUE_NO_DEV	 		(ERR_UDC_BASE + 0x14)
#define ERR_UDC_DEQUE_NO_DRIVER	 		(ERR_UDC_BASE + 0x15)
#define ERR_UDC_DEQUE_INVALID	 		(ERR_UDC_BASE + 0x16)
#define ERR_UDC_FIFO_FLUSH_NO_DEV 		(ERR_UDC_BASE + 0x17)
#define ERR_UDC_FIFO_FLUSH_INACTIVE		(ERR_UDC_BASE + 0x18)
#define ERR_UDC_FIFO_FLUSH_NOT_ENABLE	(ERR_UDC_BASE + 0x19)
#define ERR_UDC_FIFO_STATUS_NO_DEV 		(ERR_UDC_BASE + 0x1A)
#define ERR_UDC_FIFO_STATUS_NO_SUPP		(ERR_UDC_BASE + 0x1B)
#define ERR_UDC_FIFO_STATUS_NOT_ENABLE	(ERR_UDC_BASE + 0x1C)



#ifdef __cplusplus
}
#endif

#endif
