// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VCPU__SYMS_H_
#define _VCPU__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "VCPU.h"

// SYMS CLASS
class VCPU__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VCPU*                          TOPp;
    
    // CREATORS
    VCPU__Syms(VCPU* topp, const char* namep);
    ~VCPU__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
