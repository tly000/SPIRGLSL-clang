//===- StaticStorageCtorLegalizer.cpp -Legalizer pass for static-*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//
//
// Copyright (c) 2015 The Khronos Group Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and/or associated documentation files (the
// "Materials"), to deal in the Materials without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Materials, and to
// permit persons to whom the Materials are furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Materials.
//
// THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
//
//===----------------------------------------------------------------------===//


#include "clang/CodeGen/OclCxxRewrite/StaticStorageCtorLegalizer.h"

#include "llvm/Pass.h"
#include "llvm/PassSupport.h"
#include "llvm/IR/Module.h"

#define DEBUG_TYPE "OclCxxStaticStorageCtorLegalizer"


namespace {

struct OclCxxStaticStorageCtorLegalizer : llvm::ModulePass {
  /// Identifier of the pass (its address).
  static char ID;

  OclCxxStaticStorageCtorLegalizer() : ModulePass(ID) {}


  bool runOnModule(llvm::Module &M) override {
    return false;
  }
};
}


char OclCxxStaticStorageCtorLegalizer::ID = 0;

using namespace llvm;
INITIALIZE_PASS(OclCxxStaticStorageCtorLegalizer,
                "oclcxx-static-ctor-legalizer",
                "Legalizer pass for static-storage-duration objects with"
                " non-trivial constructors in OpenCL C++",
                false, false)

ModulePass *llvm::createOclCxxStaticStorageCtorLegalizerPass() {
  return new OclCxxStaticStorageCtorLegalizer;
}
