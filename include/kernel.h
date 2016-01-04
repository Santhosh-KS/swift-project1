/*
 * kernel/kernel.h
 *
 * Created by Simon Evans on 16/12/2015.
 * Copyright © 2015, 2016 Simon Evans. All rights reserved.
 *
 * Header file used by Swift to access certain C functions
 *
 */

#ifndef __KERNEL_H__
#define __KERNEL_H__

#include <stdint.h>
#include <stdarg.h>
#include "x86funcs.h"

// Export as [symbol]_addr suitable to use as an arg to UnsafePointer()
#define EXPORTED_SYMBOL_AS_VOIDPTR(x) extern const void *x##_addr;

// Export as [symbol]_addr as a unitptr_t to be manipulated as a UInt64
#define EXPORTED_SYMBOL_AS_UINTPTR(x) extern uintptr_t x##_addr;

EXPORTED_SYMBOL_AS_VOIDPTR(_text_start);
EXPORTED_SYMBOL_AS_VOIDPTR(_text_end);
EXPORTED_SYMBOL_AS_VOIDPTR(_data_start);
EXPORTED_SYMBOL_AS_VOIDPTR(_data_end);
EXPORTED_SYMBOL_AS_VOIDPTR(_bss_start);
EXPORTED_SYMBOL_AS_VOIDPTR(_bss_end);
EXPORTED_SYMBOL_AS_UINTPTR(divide_by_zero_stub);
EXPORTED_SYMBOL_AS_UINTPTR(debug_exception_stub);
EXPORTED_SYMBOL_AS_UINTPTR(nmi_stub);
EXPORTED_SYMBOL_AS_UINTPTR(single_step_stub);
EXPORTED_SYMBOL_AS_UINTPTR(overflow_stub);
EXPORTED_SYMBOL_AS_UINTPTR(bounds_stub);
EXPORTED_SYMBOL_AS_UINTPTR(invalid_opcode_stub);
EXPORTED_SYMBOL_AS_UINTPTR(unused_stub);
EXPORTED_SYMBOL_AS_UINTPTR(double_fault_stub);
EXPORTED_SYMBOL_AS_UINTPTR(invalid_tss_stub);
EXPORTED_SYMBOL_AS_UINTPTR(seg_not_present_stub);
EXPORTED_SYMBOL_AS_UINTPTR(stack_fault_stub);
EXPORTED_SYMBOL_AS_UINTPTR(gpf_stub);
EXPORTED_SYMBOL_AS_UINTPTR(page_fault_stub);
EXPORTED_SYMBOL_AS_UINTPTR(fpu_fault_stub);
EXPORTED_SYMBOL_AS_UINTPTR(alignment_exception_stub);
EXPORTED_SYMBOL_AS_UINTPTR(mce_stub);
EXPORTED_SYMBOL_AS_UINTPTR(simd_exception_stub);
EXPORTED_SYMBOL_AS_UINTPTR(test_breakpoint);


void set_print_functions_to_swift();
int kvprintf(const char *fmt, va_list args) __attribute__ ((format (printf, 1, 0)));
int kvsprintf(char *buf, const char *fmt, va_list args) __attribute__ ((format (printf, 2, 0)));


#endif  // __KERNEL_H__
