/*
* Copyright (c) 2019. tangzx(love.tangzx@qq.com)
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#pragma once

#include <string>
#include <vector>

enum class DebugAction {
	Break,
	Continue,
	StepOver,
	StepIn,
	StepOut,
	Stop,
};

class BreakPoint {
public:
	std::string file;
	std::string condition;
	std::vector<std::string> pathParts;
	int line;
};

class Variable {
public:
	std::string name;
	int nameType;
	std::string value;
	int valueType;
	std::string valueTypeName;
	std::vector<Variable*> children;
	Variable();
	~Variable();
};

class Stack {
public:
	std::string file;
	std::string functionName;
	int level;
	int line;
	std::vector<Variable*> localVariables;
	std::vector<Variable*> upvalueVariables;
public:
	Stack();
	~Stack();
	Variable* CreateVariable();
};

class EvalContext {
public:
	std::string expr;
	std::string error;
	int seq;
	int stackLevel;
	int depth;
	Variable result;
	bool success;
};