/*
 *    Copyright 2006 Intel Corporation
 * 
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 * 
 *        http://www.apache.org/licenses/LICENSE-2.0
 * 
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#ifndef _GETTIMEOFDAYCOMMAND_H_
#define _GETTIMEOFDAYCOMMAND_H_

#include "TclCommand.h"

namespace oasys {

/**
 * A command that returns the time in 'secs.usecs' format.
 */
class GettimeofdayCommand : public TclCommand {
public:
    GettimeofdayCommand();
    
    /**
     * Virtual from CommandModule.
     */
    virtual int exec(int argc, const char** argv, Tcl_Interp* interp);
};

} // namespace oasys

#endif /* _GETTIMEOFDAYCOMMAND_H_ */
