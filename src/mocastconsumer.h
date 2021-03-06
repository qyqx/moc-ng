/****************************************************************************
 *  Copyright (C) 2013 Woboq UG (haftungsbeschraenkt)
 *  Olivier Goffart <contact at woboq.com>
 *  http://woboq.com/
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <clang/Frontend/CompilerInstance.h>
#include <clang/AST/ASTConsumer.h>

#include "mocng.h"

class MocPPCallbacks;

class MocASTConsumer : public clang::ASTConsumer
{
protected:
    clang::CompilerInstance &ci;
    clang::ASTContext *ctx = nullptr;
    MocPPCallbacks *PPCallbacks = nullptr;

    std::vector<ClassDef> objects;
    MocNg Moc;

public:
    MocASTConsumer(clang::CompilerInstance &ci) :ci(ci)
    { }

    virtual void Initialize(clang::ASTContext& Ctx) override;
    void HandleTagDeclDefinition(clang::TagDecl* D) override;
};

