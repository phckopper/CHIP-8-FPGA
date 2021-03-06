// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU.h for the primary calling header

#include "VCPU.h"
#include "VCPU__Syms.h"

//==========

VL_CTOR_IMP(VCPU) {
    VCPU__Syms* __restrict vlSymsp = __VlSymsp = new VCPU__Syms(this, name());
    VCPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VCPU::__Vconfigure(VCPU__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VCPU::~VCPU() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VCPU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VCPU::eval\n"); );
    VCPU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VCPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("src/CPU.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VCPU::_eval_initial_loop(VCPU__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("src/CPU.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VCPU::_sequent__TOP__1(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_sequent__TOP__1\n"); );
    VCPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__CPU__DOT__state;
    CData/*3:0*/ __Vdlyvdim0__CPU__DOT__vx__v0;
    CData/*7:0*/ __Vdlyvval__CPU__DOT__vx__v0;
    CData/*0:0*/ __Vdlyvset__CPU__DOT__vx__v0;
    CData/*7:0*/ __Vdlyvval__CPU__DOT__vx__v1;
    CData/*0:0*/ __Vdlyvset__CPU__DOT__vx__v1;
    CData/*3:0*/ __Vdlyvdim0__CPU__DOT__vx__v2;
    CData/*7:0*/ __Vdlyvval__CPU__DOT__vx__v2;
    CData/*0:0*/ __Vdlyvset__CPU__DOT__vx__v2;
    SData/*15:0*/ __Vdly__CPU__DOT__ir;
    SData/*11:0*/ __Vdly__CPU__DOT__pc_out;
    // Body
    vlTOPp->__Vdlyvset__CPU__DOT__gpu__DOT__framebuffer__v0 = 0U;
    __Vdly__CPU__DOT__state = vlTOPp->CPU__DOT__state;
    __Vdly__CPU__DOT__ir = vlTOPp->CPU__DOT__ir;
    __Vdly__CPU__DOT__pc_out = vlTOPp->CPU__DOT__pc_out;
    __Vdlyvset__CPU__DOT__vx__v0 = 0U;
    __Vdlyvset__CPU__DOT__vx__v1 = 0U;
    __Vdlyvset__CPU__DOT__vx__v2 = 0U;
    if (vlTOPp->rst) {
        vlTOPp->CPU__DOT__mem_in = 0U;
    }
    if (vlTOPp->CPU__DOT__gpu_we_stb) {
        vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v0 
            = (1U & (IData)(vlTOPp->CPU__DOT__gpu_sprite));
        vlTOPp->__Vdlyvset__CPU__DOT__gpu__DOT__framebuffer__v0 = 1U;
        vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v0 
            = vlTOPp->CPU__DOT__gpu_x_addr;
        vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v0 
            = vlTOPp->CPU__DOT__gpu_y_addr;
        vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v1 
            = (1U & ((IData)(vlTOPp->CPU__DOT__gpu_sprite) 
                     >> 1U));
        vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v1 
            = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->CPU__DOT__gpu_x_addr)));
        vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v1 
            = vlTOPp->CPU__DOT__gpu_y_addr;
        vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v2 
            = (1U & ((IData)(vlTOPp->CPU__DOT__gpu_sprite) 
                     >> 2U));
        vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v2 
            = (0x3fU & ((IData)(2U) + (IData)(vlTOPp->CPU__DOT__gpu_x_addr)));
        vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v2 
            = vlTOPp->CPU__DOT__gpu_y_addr;
        vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v3 
            = (1U & ((IData)(vlTOPp->CPU__DOT__gpu_sprite) 
                     >> 3U));
        vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v3 
            = (0x3fU & ((IData)(3U) + (IData)(vlTOPp->CPU__DOT__gpu_x_addr)));
        vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v3 
            = vlTOPp->CPU__DOT__gpu_y_addr;
        vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v4 
            = (1U & ((IData)(vlTOPp->CPU__DOT__gpu_sprite) 
                     >> 4U));
        vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v4 
            = (0x3fU & ((IData)(4U) + (IData)(vlTOPp->CPU__DOT__gpu_x_addr)));
        vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v4 
            = vlTOPp->CPU__DOT__gpu_y_addr;
        vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v5 
            = (1U & ((IData)(vlTOPp->CPU__DOT__gpu_sprite) 
                     >> 5U));
        vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v5 
            = (0x3fU & ((IData)(5U) + (IData)(vlTOPp->CPU__DOT__gpu_x_addr)));
        vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v5 
            = vlTOPp->CPU__DOT__gpu_y_addr;
        vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v6 
            = (1U & ((IData)(vlTOPp->CPU__DOT__gpu_sprite) 
                     >> 6U));
        vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v6 
            = (0x3fU & ((IData)(6U) + (IData)(vlTOPp->CPU__DOT__gpu_x_addr)));
        vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v6 
            = vlTOPp->CPU__DOT__gpu_y_addr;
        vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v7 
            = (1U & ((IData)(vlTOPp->CPU__DOT__gpu_sprite) 
                     >> 7U));
        vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v7 
            = (0x3fU & ((IData)(7U) + (IData)(vlTOPp->CPU__DOT__gpu_x_addr)));
        vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v7 
            = vlTOPp->CPU__DOT__gpu_y_addr;
    }
    vlTOPp->CPU__DOT__gpu__DOT__vga_clk = (1U & (~ (IData)(vlTOPp->CPU__DOT__gpu__DOT__vga_clk)));
    if (vlTOPp->rst) {
        __Vdly__CPU__DOT__pc_out = 0x200U;
    } else {
        if (vlTOPp->CPU__DOT__pc_preload_stb) {
            __Vdly__CPU__DOT__pc_out = vlTOPp->CPU__DOT__pc_preload;
        } else {
            if (vlTOPp->CPU__DOT__pc_jump_next_stb) {
                __Vdly__CPU__DOT__pc_out = (0xfffU 
                                            & ((IData)(2U) 
                                               + (IData)(vlTOPp->CPU__DOT__pc_out)));
            } else {
                if (((0U == (IData)(vlTOPp->CPU__DOT__state)) 
                     | (1U == (IData)(vlTOPp->CPU__DOT__state)))) {
                    __Vdly__CPU__DOT__pc_out = (0xfffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlTOPp->CPU__DOT__pc_out)));
                }
            }
        }
    }
    vlTOPp->CPU__DOT__pc_out = __Vdly__CPU__DOT__pc_out;
    if (vlTOPp->rst) {
        __Vdly__CPU__DOT__state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->CPU__DOT__state))) {
            vlTOPp->CPU__DOT__mem_we = 0U;
            __Vdly__CPU__DOT__ir = ((0xffU & (IData)(__Vdly__CPU__DOT__ir)) 
                                    | ((IData)(vlTOPp->CPU__DOT__mem_out) 
                                       << 8U));
            __Vdly__CPU__DOT__state = 1U;
        } else {
            if ((1U == (IData)(vlTOPp->CPU__DOT__state))) {
                vlTOPp->CPU__DOT__mem_we = 0U;
                __Vdly__CPU__DOT__ir = ((0xff00U & (IData)(__Vdly__CPU__DOT__ir)) 
                                        | (IData)(vlTOPp->CPU__DOT__mem_out));
                __Vdly__CPU__DOT__state = 2U;
            } else {
                if ((2U == (IData)(vlTOPp->CPU__DOT__state))) {
                    if ((0x8000U & (IData)(vlTOPp->CPU__DOT__ir))) {
                        if ((0x4000U & (IData)(vlTOPp->CPU__DOT__ir))) {
                            vlTOPp->useless = 1U;
                        } else {
                            if ((0x2000U & (IData)(vlTOPp->CPU__DOT__ir))) {
                                vlTOPp->useless = 1U;
                            } else {
                                if ((0x1000U & (IData)(vlTOPp->CPU__DOT__ir))) {
                                    vlTOPp->useless = 1U;
                                } else {
                                    __Vdlyvval__CPU__DOT__vx__v0 
                                        = vlTOPp->CPU__DOT__alu_out;
                                    __Vdlyvset__CPU__DOT__vx__v0 = 1U;
                                    __Vdlyvdim0__CPU__DOT__vx__v0 
                                        = (0xfU & ((IData)(vlTOPp->CPU__DOT__ir) 
                                                   >> 8U));
                                    if (vlTOPp->CPU__DOT__alu_vf_we) {
                                        __Vdlyvval__CPU__DOT__vx__v1 
                                            = vlTOPp->CPU__DOT__alu_carry_or_borrow;
                                        __Vdlyvset__CPU__DOT__vx__v1 = 1U;
                                    }
                                }
                            }
                        }
                    } else {
                        if ((0x4000U & (IData)(vlTOPp->CPU__DOT__ir))) {
                            if ((0x2000U & (IData)(vlTOPp->CPU__DOT__ir))) {
                                __Vdlyvval__CPU__DOT__vx__v2 
                                    = (0xffU & ((0x1000U 
                                                 & (IData)(vlTOPp->CPU__DOT__ir))
                                                 ? 
                                                (vlTOPp->CPU__DOT__vx
                                                 [(0xfU 
                                                   & ((IData)(vlTOPp->CPU__DOT__ir) 
                                                      >> 8U))] 
                                                 + (IData)(vlTOPp->CPU__DOT__ir))
                                                 : (IData)(vlTOPp->CPU__DOT__ir)));
                                __Vdlyvset__CPU__DOT__vx__v2 = 1U;
                                __Vdlyvdim0__CPU__DOT__vx__v2 
                                    = (0xfU & ((IData)(vlTOPp->CPU__DOT__ir) 
                                               >> 8U));
                            } else {
                                if ((0x1000U & (IData)(vlTOPp->CPU__DOT__ir))) {
                                    if ((vlTOPp->CPU__DOT__vx
                                         [(0xfU & ((IData)(vlTOPp->CPU__DOT__ir) 
                                                   >> 8U))] 
                                         == vlTOPp->CPU__DOT__vx
                                         [(0xfU & ((IData)(vlTOPp->CPU__DOT__ir) 
                                                   >> 4U))])) {
                                        vlTOPp->CPU__DOT__pc_jump_next_stb = 1U;
                                    }
                                } else {
                                    if ((vlTOPp->CPU__DOT__vx
                                         [(0xfU & ((IData)(vlTOPp->CPU__DOT__ir) 
                                                   >> 8U))] 
                                         != (0xffU 
                                             & (IData)(vlTOPp->CPU__DOT__ir)))) {
                                        vlTOPp->CPU__DOT__pc_jump_next_stb = 1U;
                                    }
                                }
                            }
                        } else {
                            if ((0x2000U & (IData)(vlTOPp->CPU__DOT__ir))) {
                                if ((0x1000U & (IData)(vlTOPp->CPU__DOT__ir))) {
                                    if ((vlTOPp->CPU__DOT__vx
                                         [(0xfU & ((IData)(vlTOPp->CPU__DOT__ir) 
                                                   >> 8U))] 
                                         == (0xffU 
                                             & (IData)(vlTOPp->CPU__DOT__ir)))) {
                                        vlTOPp->CPU__DOT__pc_jump_next_stb = 1U;
                                    }
                                } else {
                                    vlTOPp->useless = 0U;
                                }
                            } else {
                                if ((0x1000U & (IData)(vlTOPp->CPU__DOT__ir))) {
                                    vlTOPp->CPU__DOT__pc_preload 
                                        = (0xfffU & (IData)(vlTOPp->CPU__DOT__ir));
                                    vlTOPp->CPU__DOT__pc_preload_stb = 1U;
                                } else {
                                    vlTOPp->useless = 0U;
                                }
                            }
                        }
                    }
                    __Vdly__CPU__DOT__state = 3U;
                } else {
                    if ((3U == (IData)(vlTOPp->CPU__DOT__state))) {
                        vlTOPp->CPU__DOT__pc_jump_next_stb = 0U;
                        vlTOPp->CPU__DOT__pc_preload_stb = 0U;
                        __Vdly__CPU__DOT__state = 0U;
                    }
                }
            }
        }
    }
    vlTOPp->CPU__DOT__state = __Vdly__CPU__DOT__state;
    if (__Vdlyvset__CPU__DOT__vx__v0) {
        vlTOPp->CPU__DOT__vx[__Vdlyvdim0__CPU__DOT__vx__v0] 
            = __Vdlyvval__CPU__DOT__vx__v0;
    }
    if (__Vdlyvset__CPU__DOT__vx__v1) {
        vlTOPp->CPU__DOT__vx[0xfU] = __Vdlyvval__CPU__DOT__vx__v1;
    }
    if (__Vdlyvset__CPU__DOT__vx__v2) {
        vlTOPp->CPU__DOT__vx[__Vdlyvdim0__CPU__DOT__vx__v2] 
            = __Vdlyvval__CPU__DOT__vx__v2;
    }
    vlTOPp->CPU__DOT__ir = __Vdly__CPU__DOT__ir;
    vlTOPp->CPU__DOT__mem_addr = (((0U == (IData)(vlTOPp->CPU__DOT__state)) 
                                   | (1U == (IData)(vlTOPp->CPU__DOT__state)))
                                   ? (0xfffU & (IData)(vlTOPp->CPU__DOT__pc_out))
                                   : 0U);
    vlTOPp->CPU__DOT__alu_vf_we = (3U < (0xfU & (IData)(vlTOPp->CPU__DOT__ir)));
    vlTOPp->CPU__DOT__alu_a = vlTOPp->CPU__DOT__vx[
        (0xfU & ((IData)(vlTOPp->CPU__DOT__ir) >> 8U))];
    vlTOPp->CPU__DOT__alu_b = vlTOPp->CPU__DOT__vx[
        (0xfU & ((IData)(vlTOPp->CPU__DOT__ir) >> 4U))];
    vlTOPp->CPU__DOT__alu_out = (0xffU & (((((((((0U 
                                                  == 
                                                  (0xfU 
                                                   & (IData)(vlTOPp->CPU__DOT__ir))) 
                                                 | (1U 
                                                    == 
                                                    (0xfU 
                                                     & (IData)(vlTOPp->CPU__DOT__ir)))) 
                                                | (2U 
                                                   == 
                                                   (0xfU 
                                                    & (IData)(vlTOPp->CPU__DOT__ir)))) 
                                               | (3U 
                                                  == 
                                                  (0xfU 
                                                   & (IData)(vlTOPp->CPU__DOT__ir)))) 
                                              | (4U 
                                                 == 
                                                 (0xfU 
                                                  & (IData)(vlTOPp->CPU__DOT__ir)))) 
                                             | (5U 
                                                == 
                                                (0xfU 
                                                 & (IData)(vlTOPp->CPU__DOT__ir)))) 
                                            | (6U == 
                                               (0xfU 
                                                & (IData)(vlTOPp->CPU__DOT__ir)))) 
                                           | (7U == 
                                              (0xfU 
                                               & (IData)(vlTOPp->CPU__DOT__ir))))
                                           ? ((0U == 
                                               (0xfU 
                                                & (IData)(vlTOPp->CPU__DOT__ir)))
                                               ? (IData)(vlTOPp->CPU__DOT__alu_b)
                                               : ((1U 
                                                   == 
                                                   (0xfU 
                                                    & (IData)(vlTOPp->CPU__DOT__ir)))
                                                   ? 
                                                  ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                   | (IData)(vlTOPp->CPU__DOT__alu_b))
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (0xfU 
                                                     & (IData)(vlTOPp->CPU__DOT__ir)))
                                                    ? 
                                                   ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                    & (IData)(vlTOPp->CPU__DOT__alu_b))
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(vlTOPp->CPU__DOT__ir)))
                                                     ? 
                                                    ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                     ^ (IData)(vlTOPp->CPU__DOT__alu_b))
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (0xfU 
                                                       & (IData)(vlTOPp->CPU__DOT__ir)))
                                                      ? 
                                                     ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                      + (IData)(vlTOPp->CPU__DOT__alu_b))
                                                      : 
                                                     ((5U 
                                                       == 
                                                       (0xfU 
                                                        & (IData)(vlTOPp->CPU__DOT__ir)))
                                                       ? 
                                                      ((IData)(1U) 
                                                       + 
                                                       ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                        + 
                                                        (~ (IData)(vlTOPp->CPU__DOT__alu_b))))
                                                       : 
                                                      ((6U 
                                                        == 
                                                        (0xfU 
                                                         & (IData)(vlTOPp->CPU__DOT__ir)))
                                                        ? 
                                                       ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                        >> 1U)
                                                        : 
                                                       ((IData)(1U) 
                                                        + 
                                                        ((~ (IData)(vlTOPp->CPU__DOT__alu_a)) 
                                                         + (IData)(vlTOPp->CPU__DOT__alu_b))))))))))
                                           : ((0xeU 
                                               == (0xfU 
                                                   & (IData)(vlTOPp->CPU__DOT__ir)))
                                               ? ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                  << 1U)
                                               : 0U)));
    if (((((((((0U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir))) 
               | (1U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) 
              | (2U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) 
             | (3U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) 
            | (4U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) 
           | (5U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) 
          | (6U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) 
         | (7U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir))))) {
        if ((0U != (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) {
            if ((1U != (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) {
                if ((2U != (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) {
                    if ((3U != (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) {
                        vlTOPp->CPU__DOT__alu_carry_or_borrow 
                            = (1U & ((4U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))
                                      ? (1U & (((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                + (IData)(vlTOPp->CPU__DOT__alu_b)) 
                                               >> 8U))
                                      : ((5U == (0xfU 
                                                 & (IData)(vlTOPp->CPU__DOT__ir)))
                                          ? ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                             > (IData)(vlTOPp->CPU__DOT__alu_b))
                                          : ((6U == 
                                              (0xfU 
                                               & (IData)(vlTOPp->CPU__DOT__ir)))
                                              ? (IData)(vlTOPp->CPU__DOT__alu_a)
                                              : ((IData)(vlTOPp->CPU__DOT__alu_b) 
                                                 > (IData)(vlTOPp->CPU__DOT__alu_a))))));
                    }
                }
            }
        }
    } else {
        if ((0xeU == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) {
            vlTOPp->CPU__DOT__alu_carry_or_borrow = 
                (1U & ((IData)(vlTOPp->CPU__DOT__alu_a) 
                       >> 7U));
        }
    }
}

VL_INLINE_OPT void VCPU::_sequent__TOP__2(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_sequent__TOP__2\n"); );
    VCPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvval__CPU__DOT__memory__v0;
    CData/*0:0*/ __Vdlyvset__CPU__DOT__memory__v0;
    SData/*11:0*/ __Vdlyvdim0__CPU__DOT__memory__v0;
    // Body
    __Vdlyvset__CPU__DOT__memory__v0 = 0U;
    if ((1U & (~ (IData)(vlTOPp->CPU__DOT__mem_we)))) {
        vlTOPp->CPU__DOT__mem_out = vlTOPp->CPU__DOT__memory
            [vlTOPp->CPU__DOT__mem_addr];
    }
    if (vlTOPp->CPU__DOT__mem_we) {
        __Vdlyvval__CPU__DOT__memory__v0 = vlTOPp->CPU__DOT__mem_in;
        __Vdlyvset__CPU__DOT__memory__v0 = 1U;
        __Vdlyvdim0__CPU__DOT__memory__v0 = vlTOPp->CPU__DOT__mem_addr;
    }
    if (__Vdlyvset__CPU__DOT__memory__v0) {
        vlTOPp->CPU__DOT__memory[__Vdlyvdim0__CPU__DOT__memory__v0] 
            = __Vdlyvval__CPU__DOT__memory__v0;
    }
}

void VCPU::_settle__TOP__3(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_settle__TOP__3\n"); );
    VCPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->CPU__DOT__alu_vf_we = (3U < (0xfU & (IData)(vlTOPp->CPU__DOT__ir)));
    vlTOPp->CPU__DOT__alu_a = vlTOPp->CPU__DOT__vx[
        (0xfU & ((IData)(vlTOPp->CPU__DOT__ir) >> 8U))];
    vlTOPp->CPU__DOT__alu_b = vlTOPp->CPU__DOT__vx[
        (0xfU & ((IData)(vlTOPp->CPU__DOT__ir) >> 4U))];
    vlTOPp->CPU__DOT__mem_addr = (((0U == (IData)(vlTOPp->CPU__DOT__state)) 
                                   | (1U == (IData)(vlTOPp->CPU__DOT__state)))
                                   ? (0xfffU & (IData)(vlTOPp->CPU__DOT__pc_out))
                                   : 0U);
    vlTOPp->CPU__DOT__gpu__DOT__hcount_ov = (0x31fU 
                                             == (IData)(vlTOPp->CPU__DOT__gpu__DOT__hcount));
    vlTOPp->CPU__DOT__gpu__DOT__vcount_ov = (0x20cU 
                                             == (IData)(vlTOPp->CPU__DOT__gpu__DOT__vcount));
    vlTOPp->gpu_hsync = (0x5fU < (IData)(vlTOPp->CPU__DOT__gpu__DOT__hcount));
    vlTOPp->gpu_vsync = (1U < (IData)(vlTOPp->CPU__DOT__gpu__DOT__vcount));
    vlTOPp->gpu_disp_rgb = (7U & (- (IData)((IData)(vlTOPp->CPU__DOT__gpu__DOT__bw_bit))));
    vlTOPp->CPU__DOT__alu_out = (0xffU & (((((((((0U 
                                                  == 
                                                  (0xfU 
                                                   & (IData)(vlTOPp->CPU__DOT__ir))) 
                                                 | (1U 
                                                    == 
                                                    (0xfU 
                                                     & (IData)(vlTOPp->CPU__DOT__ir)))) 
                                                | (2U 
                                                   == 
                                                   (0xfU 
                                                    & (IData)(vlTOPp->CPU__DOT__ir)))) 
                                               | (3U 
                                                  == 
                                                  (0xfU 
                                                   & (IData)(vlTOPp->CPU__DOT__ir)))) 
                                              | (4U 
                                                 == 
                                                 (0xfU 
                                                  & (IData)(vlTOPp->CPU__DOT__ir)))) 
                                             | (5U 
                                                == 
                                                (0xfU 
                                                 & (IData)(vlTOPp->CPU__DOT__ir)))) 
                                            | (6U == 
                                               (0xfU 
                                                & (IData)(vlTOPp->CPU__DOT__ir)))) 
                                           | (7U == 
                                              (0xfU 
                                               & (IData)(vlTOPp->CPU__DOT__ir))))
                                           ? ((0U == 
                                               (0xfU 
                                                & (IData)(vlTOPp->CPU__DOT__ir)))
                                               ? (IData)(vlTOPp->CPU__DOT__alu_b)
                                               : ((1U 
                                                   == 
                                                   (0xfU 
                                                    & (IData)(vlTOPp->CPU__DOT__ir)))
                                                   ? 
                                                  ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                   | (IData)(vlTOPp->CPU__DOT__alu_b))
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (0xfU 
                                                     & (IData)(vlTOPp->CPU__DOT__ir)))
                                                    ? 
                                                   ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                    & (IData)(vlTOPp->CPU__DOT__alu_b))
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(vlTOPp->CPU__DOT__ir)))
                                                     ? 
                                                    ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                     ^ (IData)(vlTOPp->CPU__DOT__alu_b))
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (0xfU 
                                                       & (IData)(vlTOPp->CPU__DOT__ir)))
                                                      ? 
                                                     ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                      + (IData)(vlTOPp->CPU__DOT__alu_b))
                                                      : 
                                                     ((5U 
                                                       == 
                                                       (0xfU 
                                                        & (IData)(vlTOPp->CPU__DOT__ir)))
                                                       ? 
                                                      ((IData)(1U) 
                                                       + 
                                                       ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                        + 
                                                        (~ (IData)(vlTOPp->CPU__DOT__alu_b))))
                                                       : 
                                                      ((6U 
                                                        == 
                                                        (0xfU 
                                                         & (IData)(vlTOPp->CPU__DOT__ir)))
                                                        ? 
                                                       ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                        >> 1U)
                                                        : 
                                                       ((IData)(1U) 
                                                        + 
                                                        ((~ (IData)(vlTOPp->CPU__DOT__alu_a)) 
                                                         + (IData)(vlTOPp->CPU__DOT__alu_b))))))))))
                                           : ((0xeU 
                                               == (0xfU 
                                                   & (IData)(vlTOPp->CPU__DOT__ir)))
                                               ? ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                  << 1U)
                                               : 0U)));
    if (((((((((0U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir))) 
               | (1U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) 
              | (2U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) 
             | (3U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) 
            | (4U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) 
           | (5U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) 
          | (6U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) 
         | (7U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir))))) {
        if ((0U != (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) {
            if ((1U != (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) {
                if ((2U != (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) {
                    if ((3U != (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) {
                        vlTOPp->CPU__DOT__alu_carry_or_borrow 
                            = (1U & ((4U == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))
                                      ? (1U & (((IData)(vlTOPp->CPU__DOT__alu_a) 
                                                + (IData)(vlTOPp->CPU__DOT__alu_b)) 
                                               >> 8U))
                                      : ((5U == (0xfU 
                                                 & (IData)(vlTOPp->CPU__DOT__ir)))
                                          ? ((IData)(vlTOPp->CPU__DOT__alu_a) 
                                             > (IData)(vlTOPp->CPU__DOT__alu_b))
                                          : ((6U == 
                                              (0xfU 
                                               & (IData)(vlTOPp->CPU__DOT__ir)))
                                              ? (IData)(vlTOPp->CPU__DOT__alu_a)
                                              : ((IData)(vlTOPp->CPU__DOT__alu_b) 
                                                 > (IData)(vlTOPp->CPU__DOT__alu_a))))));
                    }
                }
            }
        }
    } else {
        if ((0xeU == (0xfU & (IData)(vlTOPp->CPU__DOT__ir)))) {
            vlTOPp->CPU__DOT__alu_carry_or_borrow = 
                (1U & ((IData)(vlTOPp->CPU__DOT__alu_a) 
                       >> 7U));
        }
    }
}

void VCPU::_initial__TOP__4(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_initial__TOP__4\n"); );
    VCPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp2[3];
    // Body
    __Vtemp2[0U] = 0x2e726f6dU;
    __Vtemp2[1U] = 0x68697038U;
    __Vtemp2[2U] = 0x63U;
    VL_READMEM_N(true, 8, 4096, 0, VL_CVT_PACK_STR_NW(3, __Vtemp2)
                 , vlTOPp->CPU__DOT__memory, 0, ~VL_ULL(0));
}

VL_INLINE_OPT void VCPU::_sequent__TOP__5(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_sequent__TOP__5\n"); );
    VCPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*9:0*/ __Vdly__CPU__DOT__gpu__DOT__hcount;
    // Body
    __Vdly__CPU__DOT__gpu__DOT__hcount = vlTOPp->CPU__DOT__gpu__DOT__hcount;
    __Vdly__CPU__DOT__gpu__DOT__hcount = ((IData)(vlTOPp->CPU__DOT__gpu__DOT__hcount_ov)
                                           ? 0U : (0x3ffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlTOPp->CPU__DOT__gpu__DOT__hcount))));
    vlTOPp->CPU__DOT__gpu__DOT__bw_bit = ((((0x8fU 
                                             <= (IData)(vlTOPp->CPU__DOT__gpu__DOT__hcount)) 
                                            & (0x30fU 
                                               > (IData)(vlTOPp->CPU__DOT__gpu__DOT__hcount))) 
                                           & ((0x22U 
                                               <= (IData)(vlTOPp->CPU__DOT__gpu__DOT__vcount)) 
                                              & (0x202U 
                                                 > (IData)(vlTOPp->CPU__DOT__gpu__DOT__vcount)))) 
                                          & (IData)(
                                                    (vlTOPp->CPU__DOT__gpu__DOT__framebuffer
                                                     [
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->CPU__DOT__gpu__DOT__vcount) 
                                                         - (IData)(2U)))] 
                                                     >> 
                                                     (0x3fU 
                                                      & ((IData)(vlTOPp->CPU__DOT__gpu__DOT__hcount) 
                                                         - (IData)(0xfU))))));
    if ((0x31fU == (IData)(vlTOPp->CPU__DOT__gpu__DOT__hcount))) {
        vlTOPp->CPU__DOT__gpu__DOT__vcount = ((IData)(vlTOPp->CPU__DOT__gpu__DOT__vcount_ov)
                                               ? 0U
                                               : (0x3ffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlTOPp->CPU__DOT__gpu__DOT__vcount))));
    }
    vlTOPp->CPU__DOT__gpu__DOT__hcount = __Vdly__CPU__DOT__gpu__DOT__hcount;
    vlTOPp->gpu_disp_rgb = (7U & (- (IData)((IData)(vlTOPp->CPU__DOT__gpu__DOT__bw_bit))));
    vlTOPp->CPU__DOT__gpu__DOT__vcount_ov = (0x20cU 
                                             == (IData)(vlTOPp->CPU__DOT__gpu__DOT__vcount));
    vlTOPp->gpu_vsync = (1U < (IData)(vlTOPp->CPU__DOT__gpu__DOT__vcount));
    vlTOPp->CPU__DOT__gpu__DOT__hcount_ov = (0x31fU 
                                             == (IData)(vlTOPp->CPU__DOT__gpu__DOT__hcount));
    vlTOPp->gpu_hsync = (0x5fU < (IData)(vlTOPp->CPU__DOT__gpu__DOT__hcount));
}

VL_INLINE_OPT void VCPU::_sequent__TOP__6(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_sequent__TOP__6\n"); );
    VCPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->__Vdlyvset__CPU__DOT__gpu__DOT__framebuffer__v0) {
        vlTOPp->CPU__DOT__gpu__DOT__framebuffer[vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v0] 
            = (((~ (VL_ULL(1) << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v0))) 
                & vlTOPp->CPU__DOT__gpu__DOT__framebuffer
                [vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v0]) 
               | ((QData)((IData)(vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v0)) 
                  << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v0)));
        vlTOPp->CPU__DOT__gpu__DOT__framebuffer[vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v1] 
            = (((~ (VL_ULL(1) << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v1))) 
                & vlTOPp->CPU__DOT__gpu__DOT__framebuffer
                [vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v1]) 
               | ((QData)((IData)(vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v1)) 
                  << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v1)));
        vlTOPp->CPU__DOT__gpu__DOT__framebuffer[vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v2] 
            = (((~ (VL_ULL(1) << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v2))) 
                & vlTOPp->CPU__DOT__gpu__DOT__framebuffer
                [vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v2]) 
               | ((QData)((IData)(vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v2)) 
                  << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v2)));
        vlTOPp->CPU__DOT__gpu__DOT__framebuffer[vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v3] 
            = (((~ (VL_ULL(1) << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v3))) 
                & vlTOPp->CPU__DOT__gpu__DOT__framebuffer
                [vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v3]) 
               | ((QData)((IData)(vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v3)) 
                  << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v3)));
        vlTOPp->CPU__DOT__gpu__DOT__framebuffer[vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v4] 
            = (((~ (VL_ULL(1) << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v4))) 
                & vlTOPp->CPU__DOT__gpu__DOT__framebuffer
                [vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v4]) 
               | ((QData)((IData)(vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v4)) 
                  << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v4)));
        vlTOPp->CPU__DOT__gpu__DOT__framebuffer[vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v5] 
            = (((~ (VL_ULL(1) << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v5))) 
                & vlTOPp->CPU__DOT__gpu__DOT__framebuffer
                [vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v5]) 
               | ((QData)((IData)(vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v5)) 
                  << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v5)));
        vlTOPp->CPU__DOT__gpu__DOT__framebuffer[vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v6] 
            = (((~ (VL_ULL(1) << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v6))) 
                & vlTOPp->CPU__DOT__gpu__DOT__framebuffer
                [vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v6]) 
               | ((QData)((IData)(vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v6)) 
                  << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v6)));
        vlTOPp->CPU__DOT__gpu__DOT__framebuffer[vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v7] 
            = (((~ (VL_ULL(1) << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v7))) 
                & vlTOPp->CPU__DOT__gpu__DOT__framebuffer
                [vlTOPp->__Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v7]) 
               | ((QData)((IData)(vlTOPp->__Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v7)) 
                  << (IData)(vlTOPp->__Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v7)));
    }
}

void VCPU::_eval(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_eval\n"); );
    VCPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->clk)) & (IData)(vlTOPp->__Vclklast__TOP__clk))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__CPU__DOT__gpu__DOT__vga_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__CPU__DOT__gpu__DOT__vga_clk)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__CPU__DOT__gpu__DOT__vga_clk 
        = vlTOPp->__VinpClk__TOP__CPU__DOT__gpu__DOT__vga_clk;
    vlTOPp->__VinpClk__TOP__CPU__DOT__gpu__DOT__vga_clk 
        = vlTOPp->CPU__DOT__gpu__DOT__vga_clk;
}

void VCPU::_eval_initial(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_eval_initial\n"); );
    VCPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__4(vlSymsp);
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__CPU__DOT__gpu__DOT__vga_clk 
        = vlTOPp->__VinpClk__TOP__CPU__DOT__gpu__DOT__vga_clk;
}

void VCPU::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::final\n"); );
    // Variables
    VCPU__Syms* __restrict vlSymsp = this->__VlSymsp;
    VCPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VCPU::_eval_settle(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_eval_settle\n"); );
    VCPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData VCPU::_change_request(VCPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_change_request\n"); );
    VCPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->CPU__DOT__gpu__DOT__vga_clk ^ vlTOPp->__Vchglast__TOP__CPU__DOT__gpu__DOT__vga_clk));
    VL_DEBUG_IF( if(__req && ((vlTOPp->CPU__DOT__gpu__DOT__vga_clk ^ vlTOPp->__Vchglast__TOP__CPU__DOT__gpu__DOT__vga_clk))) VL_DBG_MSGF("        CHANGE: src/GPU.v:13: CPU.gpu.vga_clk\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__CPU__DOT__gpu__DOT__vga_clk 
        = vlTOPp->CPU__DOT__gpu__DOT__vga_clk;
    return __req;
}

#ifdef VL_DEBUG
void VCPU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG

void VCPU::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    useless = VL_RAND_RESET_I(1);
    gpu_hsync = VL_RAND_RESET_I(1);
    gpu_vsync = VL_RAND_RESET_I(1);
    gpu_disp_rgb = VL_RAND_RESET_I(3);
    CPU__DOT__alu_a = VL_RAND_RESET_I(8);
    CPU__DOT__alu_b = VL_RAND_RESET_I(8);
    CPU__DOT__alu_out = VL_RAND_RESET_I(8);
    CPU__DOT__alu_carry_or_borrow = VL_RAND_RESET_I(1);
    CPU__DOT__alu_vf_we = VL_RAND_RESET_I(1);
    CPU__DOT__pc_preload = VL_RAND_RESET_I(12);
    CPU__DOT__pc_preload_stb = VL_RAND_RESET_I(1);
    CPU__DOT__pc_jump_next_stb = VL_RAND_RESET_I(1);
    CPU__DOT__pc_out = VL_RAND_RESET_I(12);
    CPU__DOT__gpu_x_addr = VL_RAND_RESET_I(6);
    CPU__DOT__gpu_y_addr = VL_RAND_RESET_I(5);
    CPU__DOT__gpu_sprite = VL_RAND_RESET_I(8);
    CPU__DOT__gpu_we_stb = VL_RAND_RESET_I(1);
    CPU__DOT__ir = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            CPU__DOT__vx[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<4096; ++__Vi0) {
            CPU__DOT__memory[__Vi0] = VL_RAND_RESET_I(8);
    }}
    CPU__DOT__mem_addr = VL_RAND_RESET_I(12);
    CPU__DOT__mem_in = VL_RAND_RESET_I(8);
    CPU__DOT__mem_out = VL_RAND_RESET_I(8);
    CPU__DOT__mem_we = VL_RAND_RESET_I(1);
    CPU__DOT__state = VL_RAND_RESET_I(4);
    CPU__DOT__gpu__DOT__vga_clk = VL_RAND_RESET_I(1);
    CPU__DOT__gpu__DOT__hcount = VL_RAND_RESET_I(10);
    CPU__DOT__gpu__DOT__vcount = VL_RAND_RESET_I(10);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            CPU__DOT__gpu__DOT__framebuffer[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    CPU__DOT__gpu__DOT__hcount_ov = VL_RAND_RESET_I(1);
    CPU__DOT__gpu__DOT__vcount_ov = VL_RAND_RESET_I(1);
    CPU__DOT__gpu__DOT__bw_bit = VL_RAND_RESET_I(1);
    __Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v0 = 0;
    __Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v0 = 0;
    __Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v0 = VL_RAND_RESET_I(1);
    __Vdlyvset__CPU__DOT__gpu__DOT__framebuffer__v0 = 0;
    __Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v1 = 0;
    __Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v1 = 0;
    __Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v1 = VL_RAND_RESET_I(1);
    __Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v2 = 0;
    __Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v2 = 0;
    __Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v2 = VL_RAND_RESET_I(1);
    __Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v3 = 0;
    __Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v3 = 0;
    __Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v3 = VL_RAND_RESET_I(1);
    __Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v4 = 0;
    __Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v4 = 0;
    __Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v4 = VL_RAND_RESET_I(1);
    __Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v5 = 0;
    __Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v5 = 0;
    __Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v5 = VL_RAND_RESET_I(1);
    __Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v6 = 0;
    __Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v6 = 0;
    __Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v6 = VL_RAND_RESET_I(1);
    __Vdlyvdim0__CPU__DOT__gpu__DOT__framebuffer__v7 = 0;
    __Vdlyvlsb__CPU__DOT__gpu__DOT__framebuffer__v7 = 0;
    __Vdlyvval__CPU__DOT__gpu__DOT__framebuffer__v7 = VL_RAND_RESET_I(1);
    __VinpClk__TOP__CPU__DOT__gpu__DOT__vga_clk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__CPU__DOT__gpu__DOT__vga_clk = VL_RAND_RESET_I(1);
}
