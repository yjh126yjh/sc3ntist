#pragma once

#include <parser/SCXTypes.h>
#include <parser/SC3Expression.h>
#include <parser/SCXFile.h>
#include <utility>
#include <vector>
#include "enums.h"

struct VariableRef {
  VariableRefType type;
  int var;
};

int firstLabelForAddress(const SCXFile *file, SCXOffset address);

// this overload only searches the given label!
int instIdAtAddress(const SCXFile *file, int labelId, SCXOffset address);
std::pair<int, int> instIdAtAddress(const SCXFile *file, SCXOffset address);
const SC3Instruction *instructionAtAddress(const SCXFile *file,
                                           SCXOffset address);

std::vector<std::pair<VariableRefType, int>> variableRefsInInstruction(
    const SC3Instruction *inst);
std::vector<std::pair<VariableRefType, int>> variableRefsAtAddress(
    const SCXFile *file, SCXOffset address);
std::vector<std::pair<VariableRefType, int>> variableRefsInExpression(
    const SC3Expression &expr);

std::vector<int> localLabelRefsInInstruction(const SC3Instruction *inst);
std::vector<int> localLabelRefsAtAddress(const SCXFile *file,
                                         SCXOffset address);
std::vector<int> localLabelRefsInExpression(const SC3Expression &expr);

bool expressionIsConstant(const SC3Expression &expr);
int constantValueForExpression(const SC3Expression &expr);