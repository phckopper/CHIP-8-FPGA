// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "VALU.h"
#include "VALU__Syms.h"

//==========

VL_CTOR_IMP(VALU) {
    VALU__Syms* __restrict vlSymsp = __VlSymsp = new VALU__Syms(this, name());
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VALU::__Vconfigure(VALU__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VALU::~VALU() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VALU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VALU::eval\n"); );
    VALU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("src/ALU.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VALU::_eval_initial_loop(VALU__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("src/ALU.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VALU::_combo__TOP__1(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_combo__TOP__1\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->vf_we = (3U < (IData)(vlTOPp->op));
    vlTOPp->out = (0xffU & (((((((((0U == (IData)(vlTOPp->op)) 
                                   | (1U == (IData)(vlTOPp->op))) 
                                  | (2U == (IData)(vlTOPp->op))) 
                                 | (3U == (IData)(vlTOPp->op))) 
                                | (4U == (IData)(vlTOPp->op))) 
                               | (5U == (IData)(vlTOPp->op))) 
                              | (6U == (IData)(vlTOPp->op))) 
                             | (7U == (IData)(vlTOPp->op)))
                             ? ((0U == (IData)(vlTOPp->op))
                                 ? (IData)(vlTOPp->b)
                                 : ((1U == (IData)(vlTOPp->op))
                                     ? ((IData)(vlTOPp->a) 
                                        | (IData)(vlTOPp->b))
                                     : ((2U == (IData)(vlTOPp->op))
                                         ? ((IData)(vlTOPp->a) 
                                            & (IData)(vlTOPp->b))
                                         : ((3U == (IData)(vlTOPp->op))
                                             ? ((IData)(vlTOPp->a) 
                                                ^ (IData)(vlTOPp->b))
                                             : ((4U 
                                                 == (IData)(vlTOPp->op))
                                                 ? 
                                                ((IData)(vlTOPp->a) 
                                                 + (IData)(vlTOPp->b))
                                                 : 
                                                ((5U 
                                                  == (IData)(vlTOPp->op))
                                                  ? 
                                                 ((IData)(1U) 
                                                  + 
                                                  ((IData)(vlTOPp->a) 
                                                   + 
                                                   (~ (IData)(vlTOPp->b))))
                                                  : 
                                                 ((6U 
                                                   == (IData)(vlTOPp->op))
                                                   ? 
                                                  ((IData)(vlTOPp->a) 
                                                   >> 1U)
                                                   : 
                                                  ((IData)(1U) 
                                                   + 
                                                   ((~ (IData)(vlTOPp->a)) 
                                                    + (IData)(vlTOPp->b))))))))))
                             : ((0xeU == (IData)(vlTOPp->op))
                                 ? ((IData)(vlTOPp->a) 
                                    << 1U) : 0U)));
    if (((((((((0U == (IData)(vlTOPp->op)) | (1U == (IData)(vlTOPp->op))) 
              | (2U == (IData)(vlTOPp->op))) | (3U 
                                                == (IData)(vlTOPp->op))) 
            | (4U == (IData)(vlTOPp->op))) | (5U == (IData)(vlTOPp->op))) 
          | (6U == (IData)(vlTOPp->op))) | (7U == (IData)(vlTOPp->op)))) {
        if ((0U != (IData)(vlTOPp->op))) {
            if ((1U != (IData)(vlTOPp->op))) {
                if ((2U != (IData)(vlTOPp->op))) {
                    if ((3U != (IData)(vlTOPp->op))) {
                        vlTOPp->carry_or_borrow = (1U 
                                                   & ((4U 
                                                       == (IData)(vlTOPp->op))
                                                       ? 
                                                      (1U 
                                                       & (((IData)(vlTOPp->a) 
                                                           + (IData)(vlTOPp->b)) 
                                                          >> 8U))
                                                       : 
                                                      ((5U 
                                                        == (IData)(vlTOPp->op))
                                                        ? 
                                                       ((IData)(vlTOPp->a) 
                                                        > (IData)(vlTOPp->b))
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlTOPp->op))
                                                         ? (IData)(vlTOPp->a)
                                                         : 
                                                        ((IData)(vlTOPp->b) 
                                                         > (IData)(vlTOPp->a))))));
                    }
                }
            }
        }
    } else {
        if ((0xeU == (IData)(vlTOPp->op))) {
            vlTOPp->carry_or_borrow = (1U & ((IData)(vlTOPp->a) 
                                             >> 7U));
        }
    }
}

void VALU::_eval(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VALU::_eval_initial(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_initial\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VALU::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::final\n"); );
    // Variables
    VALU__Syms* __restrict vlSymsp = this->__VlSymsp;
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VALU::_eval_settle(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_settle\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VALU::_change_request(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_change_request\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VALU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((op & 0xf0U))) {
        Verilated::overWidthError("op");}
}
#endif  // VL_DEBUG

void VALU::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_ctor_var_reset\n"); );
    // Body
    a = VL_RAND_RESET_I(8);
    b = VL_RAND_RESET_I(8);
    op = VL_RAND_RESET_I(4);
    out = VL_RAND_RESET_I(8);
    vf_we = VL_RAND_RESET_I(1);
    carry_or_borrow = VL_RAND_RESET_I(1);
}
