// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCPU_H_
#define _VCPU_H_  // guard

#include "verilated_heavy.h"

//==========

class VCPU__Syms;

//----------

VL_MODULE(VCPU) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(useless,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*7:0*/ CPU__DOT__alu_a;
    CData/*7:0*/ CPU__DOT__alu_b;
    CData/*7:0*/ CPU__DOT__alu_out;
    CData/*0:0*/ CPU__DOT__alu_carry_or_borrow;
    CData/*0:0*/ CPU__DOT__alu_vf_we;
    CData/*0:0*/ CPU__DOT__pc_preload_stb;
    CData/*0:0*/ CPU__DOT__pc_jump_next_stb;
    CData/*7:0*/ CPU__DOT__mem_in;
    CData/*7:0*/ CPU__DOT__mem_out;
    CData/*0:0*/ CPU__DOT__mem_we;
    CData/*3:0*/ CPU__DOT__state;
    SData/*11:0*/ CPU__DOT__pc_preload;
    SData/*11:0*/ CPU__DOT__pc_out;
    SData/*15:0*/ CPU__DOT__ir;
    SData/*11:0*/ CPU__DOT__mem_addr;
    CData/*7:0*/ CPU__DOT__vx[16];
    CData/*7:0*/ CPU__DOT__memory[4096];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VCPU__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VCPU);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VCPU(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VCPU();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VCPU__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VCPU__Syms* symsp, bool first);
  private:
    static QData _change_request(VCPU__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VCPU__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VCPU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VCPU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__4(VCPU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(VCPU__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(VCPU__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(VCPU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
