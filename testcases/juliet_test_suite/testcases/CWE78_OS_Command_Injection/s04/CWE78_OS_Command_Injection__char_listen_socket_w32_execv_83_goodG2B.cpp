/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_listen_socket_w32_execv_83_goodG2B.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Fixed string
 * Sinks: w32_execv
 *    BadSink : execute command with execv
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__char_listen_socket_w32_execv_83.h"

#include <process.h>
#define EXECV _execv

namespace CWE78_OS_Command_Injection__char_listen_socket_w32_execv_83
{
CWE78_OS_Command_Injection__char_listen_socket_w32_execv_83_goodG2B::CWE78_OS_Command_Injection__char_listen_socket_w32_execv_83_goodG2B(char * dataCopy)
{
    data = dataCopy;
    /* FIX: Append a fixed string to data (not user / external input) */
    strcat(data, "*.*");
}

CWE78_OS_Command_Injection__char_listen_socket_w32_execv_83_goodG2B::~CWE78_OS_Command_Injection__char_listen_socket_w32_execv_83_goodG2B()
{
    {
        char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL};
        /* execv - specify the path where the command is located */
        /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
        EXECV(COMMAND_INT_PATH, args);
    }
}
}
#endif /* OMITGOOD */
